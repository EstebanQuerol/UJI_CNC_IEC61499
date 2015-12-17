/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FSlot
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-06-22/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_FSlot.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FSlot_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FSlot, g_nStringIdL1_FSlot)

const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anDataInputNames[] = {g_nStringIdOperation, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FSlot::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FSlot::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_L1_FSlot::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_L1_FSlot::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_L1_FSlot::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L1_FSlot::scm_stFBInterfaceSpec = {
	1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
	1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds,
	2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
	0, 0
};


void FORTE_L1_FSlot::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventREQID:
		if (L1MIDIn() == L1MID_SLOT){
			using namespace iso14649;
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			std::list<std::string> CmdList;
			std::string sTempString;
			double nSecurityZ; //Above this Z-point the movements are safe
			Eigen::Vector3d vFOrigin;//Feature origin
			Eigen::Vector3d vOPStart;//Operation start point
			Eigen::Vector3d vRealStart;//Operation real start point once approach strategy is calculated
			Eigen::Vector3d vDepthNormal;//Feautre depth's normal vector
			Eigen::Vector3d vCurrentXYZ;//This vector is used to hold the XYZ where tool is heading
			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));

			if (TheWS == NULL){
				//Null workingstep
				DEVLOG_DEBUG("Null workingstep found\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Retrieve the feature
			slot * TheFeature = (slot *)TheWS->get_itsFeature();

			//Change the tool and compensate tool lenght with D1
			const Tool * TheTool = Tool_Table::getTool(std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId()));
			if (TheTool == NULL){
				//Tool info can't be retrieved
				DEVLOG_DEBUG("Tool can not be found on the DDBB\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			if (TheTool->getToolPosition() > 0){
				//If returned position is 0 the tool is already in the spindle
				sprintf(acBuffer, "T%u D1", TheTool->getLocalID());
				CmdList.push_back(std::string(acBuffer));
				CmdList.push_back(std::string("M6"));
			}
			else if (TheTool->getToolPosition() < 0){
				//Tool not available
				DEVLOG_DEBUG("Trying to use a not available tool \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			const double nRadius = TheTool->getRadius();

			//Set the feature origin
			vFOrigin = GlobalUtils::V3DFromRealIter(TheFeature->get_featurePlacement()->get_location()->get_coordinates());
			nSecurityZ = TheWS->get_itsSecplane()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
			sprintf(acBuffer, "G00 X=%f Y=%f Z=%f", vFOrigin.x(), vFOrigin.y(), vFOrigin.z() + nSecurityZ);
			CmdList.push_back(std::string(acBuffer));
			sprintf(acBuffer, "G92 X0 Y0 Z%f", nSecurityZ);
			CmdList.push_back(std::string(acBuffer));

			//Retrieve feature dimmensions
			double nDepth = abs(TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val());
			vDepthNormal = GlobalUtils::V3DFromRealIter(TheFeature->get_depth()->get_position()->get_axis()->get_directionRatios());
			if (TheFeature->get_courseOfTravel() == NULL || TheFeature->get_sweptShape() == NULL){
				//Missing parameters
				DEVLOG_DEBUG("Feature error; Missing parameters \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//verify that feature coordinate system Z axis is parallel to machine Z axis
			if ((vDepthNormal.cross(Eigen::Vector3d(0, 0, 1))).norm() != 0.0){
				//Feature depth is leaning, not supported 
				DEVLOG_DEBUG("Feature error; Leaning surfaces are not supported \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Retrieve the operation parameters
			if (TheWS->get_itsOperation()->isA(bottomAndSideMilling_E)){
				//Finish and rough milling classes are equal from c++ perspective
				bottomAndSideMilling * TheOperation = (bottomAndSideMilling *)TheWS->get_itsOperation();

				//Retrieve the start_point of the operation
				vOPStart = GlobalUtils::V3DFromRealIter(TheWS->get_itsOperation()->get_startPoint()->get_coordinates());

				double nWidth = 0.0;
				if (TheFeature->get_sweptShape()->isA(squareUProfile_E)){
					squareUProfile * TheProfile = (squareUProfile *)TheFeature->get_sweptShape();
					nWidth = TheProfile->get_width()->get_theoreticalSize();
				}
				else{
					//Swept profile not supported
					DEVLOG_DEBUG("Trying to use an unsupported swept profile\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}

				//Operation parameters
				double nAxialMax = TheOperation->get_axialCuttingDepth()->get_val();
				double nRadialMax = TheOperation->get_radialCuttingDepth()->get_val();
				double nAxialAllowance = TheOperation->get_allowanceBottom()->get_val();
				double nRadialAllowance = TheOperation->get_allowanceSide()->get_val();
				double nRealDepth = nDepth - nAxialAllowance;

				//Verify that the start point is correct
				if (vOPStart.z() > 0.0){
					//CAM Error; start point is higher than the surface to machine; Abort operation
					DEVLOG_DEBUG("Operation start point error\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				else if (abs(vOPStart.z()) > nAxialMax){
					//CAM Error; start point is lower than max axial cut; Abort operation
					DEVLOG_DEBUG("Operation start point error\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				//Verify if the start point is within the surface to be machined
				//TODO

				//Calculate the number of layers to remove
				double nAxialStep = nRealDepth;
				//int nLayers = 1;
				if (nRealDepth > nAxialMax){
					//Several layers needed
					//TODO: For now multiple layers are not supported for slots
					//nLayers = ceil(((nRealDepth - abs(vOPStart.z())) / nAxialMax));
					//nAxialStep = (nRealDepth - abs(vOPStart.z())) / nLayers++;
					DEVLOG_DEBUG("Slots can not be machined in multiple layers\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}

				//Configure the feed and rot speed and start the spindle
				millingTechnology * TheTechnology = (millingTechnology *)TheWS->get_itsOperation()->get_itsTechnology();
				double nRotSpeed = TheTechnology->get_spindle()->get_val();
				double nFeedSpeed = TheTechnology->get_feedrate()->get_val();
				int nRotSens = 4; //3: clockwise 4: counter-clockwise
				if (nRotSpeed <= 0.0){
					nRotSens = 3;
					nRotSpeed *= -1.0;
				}
				sprintf(acBuffer, "G17 G90 G94 F%f", nFeedSpeed);
				CmdList.push_back(std::string(acBuffer));
				sprintf(acBuffer, "S%f M0%i", nRotSpeed, nRotSens);
				CmdList.push_back(std::string(acBuffer));

				vCurrentXYZ = vOPStart;
				if (TheFeature->get_courseOfTravel()->isA(generalPath_E)){
					generalPath * ThePath = (generalPath *)TheFeature->get_courseOfTravel();

					if (ThePath->get_sweptPath()->isA(polyline_E)){
						polyline * ThePoly = (polyline *)ThePath->get_sweptPath();
						std::list<cartesianPoint *>::const_iterator pointsIter = ThePoly->get_points()->get_theList()->begin();
						//Check if the list is empty
						if (pointsIter == ThePoly->get_points()->get_theList()->end()){
							//Invalid polyline
							DEVLOG_DEBUG("Trying to use aan invalid polyline \n");
							forte_free(acBuffer);
							acBuffer = NULL;
							PARAM_ERROR_EXIT
						}
						//The 1st point of the polyline must be equal to operation start point
						if (!GlobalUtils::isPlacementEqual((*pointsIter), vOPStart.x(), vOPStart.y())){
							//Invalid polyline start point
							DEVLOG_DEBUG("Operation and polyline start point must be equal \n");
							forte_free(acBuffer);
							acBuffer = NULL;
							PARAM_ERROR_EXIT
						}
						//Generate path's G code according to the strategy
						if (TheOperation->get_itsMachiningStrategy()->isA(unidirectionalMilling_E)){
							//This strategy is not supported for this feature
							DEVLOG_DEBUG("Not supported strategy \n");
							forte_free(acBuffer);
							acBuffer = NULL;
							PARAM_ERROR_EXIT
						}
						else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){
							//This strategy is not supported for this feature
							DEVLOG_DEBUG("Not supported strategy \n");
							forte_free(acBuffer);
							acBuffer = NULL;
							PARAM_ERROR_EXIT
						}
						else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){
							if (++pointsIter != ThePoly->get_points()->get_theList()->end()){
								vCurrentXYZ = GlobalUtils::V3DFromRealIter((*pointsIter)->get_coordinates());
								//Retrieve approach strategy information
								if (TheOperation->get_approach()->isA(apRetractAngle_E)){
									apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
									double nAPAngle = TheApproach->get_angle();
									double nAPTravel = TheApproach->get_travelLength();
									Eigen::Vector2d vCTTangent;//Vector that goes from 1st to 2nd point of the polyline
									vCTTangent = Eigen::Vector2d(vCurrentXYZ.x() - vOPStart.x(), vCurrentXYZ.y() - vOPStart.y());
									vCTTangent.normalize();
									vRealStart = Eigen::Vector3d(vCTTangent.x() * nAPTravel, vCTTangent.y() * nAPTravel, -1.0 * sin(nAPAngle / 180.0 * pi)*nAPTravel);
									vRealStart = vOPStart - vRealStart;
									//Fast movement to XY operation start point in the security plane
									sprintf(acBuffer, "G00 X%f Y%f Z%f", vRealStart.x(), vRealStart.y(), nSecurityZ);
									CmdList.push_back(std::string(acBuffer));
									//Fast movement in Z to the point where approach movement starts
									sprintf(acBuffer, "G00 Z%f", vRealStart.z());
									CmdList.push_back(std::string(acBuffer));
									//Move tool to the start point
									sprintf(acBuffer, "G01 X%f Y%f Z%f", vOPStart.x(), vOPStart.y(), vOPStart.z());
									CmdList.push_back(std::string(acBuffer));
								}
								else{
									//Approach strategy not supported
									DEVLOG_DEBUG("Trying to use a not supported approach strategy \n");
									forte_free(acBuffer);
									acBuffer = NULL;
									PARAM_ERROR_EXIT
								}
							}
							else{
								//Invalid polyline; It must have 2 points at least
								DEVLOG_DEBUG("Invalid polyline; It must have 2 points at least \n");
								forte_free(acBuffer);
								acBuffer = NULL;
								PARAM_ERROR_EXIT
							}
							sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
							CmdList.push_back(std::string(acBuffer));
							++pointsIter;
							for (; pointsIter != ThePoly->get_points()->get_theList()->end(); ++pointsIter){
								vCurrentXYZ = GlobalUtils::V3DFromRealIter((*pointsIter)->get_coordinates());
								sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
								CmdList.push_back(std::string(acBuffer));
							}
						}
						else {
							//This strategy is not supported for this feature
							DEVLOG_DEBUG("Not supported strategy \n");
							forte_free(acBuffer);
							acBuffer = NULL;
							PARAM_ERROR_EXIT
						}
					}
					else{
						//Not supported travel path in SLOT feature
						DEVLOG_DEBUG("Not supported travel path in SLOT feature\n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
				}
				else if (TheFeature->get_courseOfTravel()->isA(linearPath_E)){
					linearPath * ThePath = (linearPath *)TheFeature->get_courseOfTravel();
					//Retrieve the linear path direction
					Eigen::Vector3d vPDir = GlobalUtils::V3DFromRealIter(ThePath->get_itsDirection()->get_directionRatios());
					vPDir.normalize();

					//Retrieve approach strategy information
					if (TheOperation->get_approach()->isA(apRetractAngle_E)){
						apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
						double nAPAngle = TheApproach->get_angle();
						double nAPTravel = TheApproach->get_travelLength();
						vRealStart = vPDir * nAPTravel;
						vRealStart.z() = -1.0 * sin(nAPAngle / 180.0 * pi)*nAPTravel;
						vRealStart = vOPStart - vRealStart;
						//Fast movement to XY operation start point in the security plane
						sprintf(acBuffer, "G00 X%f Y%f Z%f", vRealStart.x(), vRealStart.y(), nSecurityZ);
						CmdList.push_back(std::string(acBuffer));
						//Fast movement in Z to the point where approach movement starts
						sprintf(acBuffer, "G00 Z%f", vRealStart.z());
						CmdList.push_back(std::string(acBuffer));
						//Move tool to the start point
						sprintf(acBuffer, "G01 X%f Y%f Z%f", vOPStart.x(), vOPStart.y(), vOPStart.z());
						CmdList.push_back(std::string(acBuffer));
					}
					else{
						//Approach strategy not supported
						DEVLOG_DEBUG("Trying to use a not supported approach strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

					//Generate path's G code according to the strategy
					//After approaching G01 is active and tool is at start point
					if (TheOperation->get_itsMachiningStrategy()->isA(unidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){
						vCurrentXYZ = vCurrentXYZ + vPDir * ThePath->get_distance()->get_theoreticalSize();
						sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
						CmdList.push_back(std::string(acBuffer));
					}
					else {
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
				}
				else if (TheFeature->get_courseOfTravel()->isA(completeCircularPath_E)){
					completeCircularPath * ThePath = (completeCircularPath *)TheFeature->get_courseOfTravel();
					//Retrieve the path Z axis 
					Eigen::Vector3d vPZAxis = GlobalUtils::V3DFromRealIter(ThePath->get_placement()->get_axis()->get_directionRatios());
					Eigen::Vector3d vPOrigin = GlobalUtils::V3DFromRealIter(ThePath->get_placement()->get_location()->get_coordinates());
					Eigen::Vector2d vPRRadius;//Vector in XY plane from profile center to the start point
					vPRRadius = Eigen::Vector2d(vOPStart.x() - vPOrigin.x(), vOPStart.y() - vPOrigin.y());
					Eigen::Vector2d vPTangent;//Vector tangentto the path			
					double nPathRadius = ThePath->get_radius()->get_theoreticalSize();

					//Verify that the start point is correct; since we work with double leave a 1% margin for rounding errors
					if (vPRRadius.norm() < nPathRadius * 0.99 || vPRRadius.norm() > nPathRadius*1.01){
						//Start point error
						DEVLOG_DEBUG("Start point error for the circular path \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					//If Z axis is positive conunter clockwise rotation; if negative clockwise rotation
					if (vPZAxis.z() >= 0.0){
						sTempString = std::string("G03");
						vPTangent = Eigen::Vector2d(-1.0 * vPRRadius.y(), vPRRadius.x());
					}
					else{
						sTempString = std::string("G02");
						vPTangent = Eigen::Vector2d(vPRRadius.y(), -1.0 * vPRRadius.x());
					}
					vPTangent.normalize();

					//Retrieve approach strategy information
					if (TheOperation->get_approach()->isA(apRetractAngle_E)){
						apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
						double nAPAngle = TheApproach->get_angle();
						double nAPTravel = TheApproach->get_travelLength();
						vRealStart = Eigen::Vector3d(vPTangent.x() * nAPTravel, vPTangent.y() * nAPTravel, -1.0 * sin(nAPAngle / 180.0 * pi)*nAPTravel);
						vRealStart = vOPStart - vRealStart;
						//Fast movement to XY operation start point in the security plane
						sprintf(acBuffer, "G00 X%f Y%f Z%f", vRealStart.x(), vRealStart.y(), nSecurityZ);
						CmdList.push_back(std::string(acBuffer));
						//Fast movement in Z to the point where approach movement starts
						sprintf(acBuffer, "G00 Z%f", vRealStart.z());
						CmdList.push_back(std::string(acBuffer));
						//Move tool to the start point
						sprintf(acBuffer, "G01 X%f Y%f Z%f", vOPStart.x(), vOPStart.y(), vOPStart.z());
						CmdList.push_back(std::string(acBuffer));
					}
					else{
						//Approach strategy not supported
						DEVLOG_DEBUG("Trying to use a not supported approach strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

					if (TheOperation->get_itsMachiningStrategy()->isA(unidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){
						sprintf(acBuffer, "%s X%f Y%f I%f J%f", sTempString.c_str(), vCurrentXYZ.x(), vCurrentXYZ.y(), vPOrigin.x() - vCurrentXYZ.x(), vPOrigin.y() - vCurrentXYZ.y());
						CmdList.push_back(std::string(acBuffer));
					}
					else {
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
				}
				else if (TheFeature->get_courseOfTravel()->isA(partialCircularPath_E)){
					partialCircularPath * ThePath = (partialCircularPath *)TheFeature->get_courseOfTravel();
					//Retrieve the path Z axis 
					Eigen::Vector3d vPDir = GlobalUtils::V3DFromRealIter(ThePath->get_placement()->get_axis()->get_directionRatios());
					Eigen::Vector3d vPOrigin = GlobalUtils::V3DFromRealIter(ThePath->get_placement()->get_location()->get_coordinates());
					Eigen::Vector2d vPRRadius;//Vector in XY plane from profile center to the start point
					vPRRadius = Eigen::Vector2d(vOPStart.x() - vPOrigin.x(), vOPStart.y() - vPOrigin.y());
					Eigen::Vector2d vPTangent;//Vector tangentto the path	
					double nPathRadius = ThePath->get_radius()->get_theoreticalSize();
					//Calculate the start point absolute angle respecto to X-axis
					double nSPangle = atan2(vOPStart.y() - vPOrigin.y(), vOPStart.x() - vPOrigin.x());
					//If Z axis is positive conunter clockwise rotation; if negative clockwise rotation
					if (vPDir.z() >= 0.0){
						sTempString = std::string("G03");
						nSPangle += ThePath->get_sweepAngle() * pi / 180.0;
						vPTangent = Eigen::Vector2d(-1.0 * vPRRadius.y(), vPRRadius.x());
					}
					else{
						sTempString = std::string("G02");
						nSPangle -= ThePath->get_sweepAngle() * pi / 180.0;
						vPTangent = Eigen::Vector2d(vPRRadius.y(), -1.0 * vPRRadius.x());
					}
					vPTangent.normalize();

					if (vPRRadius.norm() < nPathRadius * 0.99 || vPRRadius.norm() > nPathRadius*1.01){
						//Start point error
						DEVLOG_DEBUG("Start point error for the circular path \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

					//Retrieve approach strategy information
					if (TheOperation->get_approach()->isA(apRetractAngle_E)){
						apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
						double nAPAngle = TheApproach->get_angle();
						double nAPTravel = TheApproach->get_travelLength();
						vRealStart = Eigen::Vector3d(vPTangent.x() * nAPTravel, vPTangent.y() * nAPTravel, -1.0 * sin(nAPAngle / 180.0 * pi)*nAPTravel);
						vRealStart = vOPStart - vRealStart;
						//Fast movement to XY operation start point in the security plane
						sprintf(acBuffer, "G00 X%f Y%f Z%f", vRealStart.x(), vRealStart.y(), nSecurityZ);
						CmdList.push_back(std::string(acBuffer));
						//Fast movement in Z to the point where approach movement starts
						sprintf(acBuffer, "G00 Z%f", vRealStart.z());
						CmdList.push_back(std::string(acBuffer));
						//Move tool to the start point
						sprintf(acBuffer, "G01 X%f Y%f Z%f", vOPStart.x(), vOPStart.y(), vOPStart.z());
						CmdList.push_back(std::string(acBuffer));
					}
					else{
						//Approach strategy not supported
						DEVLOG_DEBUG("Trying to use a not supported approach strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

					if (TheOperation->get_itsMachiningStrategy()->isA(unidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){
						sprintf(acBuffer, "%s X%f Y%f I%f J%f", sTempString.c_str(), vPOrigin.x() + nPathRadius * cos(nSPangle), vPOrigin.y() + nPathRadius * sin(nSPangle),
							vPOrigin.x() - vOPStart.x(), vPOrigin.y() - vOPStart.y());
						CmdList.push_back(std::string(acBuffer));
					}
					else {
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
				}
				else{
					//Unkonwn travel path
					DEVLOG_DEBUG("Trying to use an unkown travel path\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
			}
			else{
				//Can not do a slot w/o bottom and side milling
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//Stop the spindle
			CmdList.push_back("M05");
			//Move above the security plane
			sprintf(acBuffer, "G00 Z%f", nSecurityZ);
			CmdList.push_back(std::string(acBuffer));
			//Cancel the feature origin
			CmdList.push_back("G159=1");
			//Return home
			CmdList.push_back("G00 X0 Y0");

			Cmd() = SerializeCmdList(CmdList);
			L1MIDOut() = L1MID_SENDCMD;

			//Clean memory
			forte_free(acBuffer);
			acBuffer = NULL;
			sendOutputEvent(scm_nEventCNFID);
		}
      break;
  }
}



