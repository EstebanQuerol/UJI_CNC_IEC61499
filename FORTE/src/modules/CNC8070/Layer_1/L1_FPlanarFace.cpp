/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FPlanarFace
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-05-12/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L1_FPlanarFace.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FPlanarFace_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FPlanarFace, g_nStringIdL1_FPlanarFace)

const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anDataInputNames[] = { g_nStringIdOperation, g_nStringIdL1MIDIn };

const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FPlanarFace::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FPlanarFace::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_FPlanarFace::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_FPlanarFace::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_FPlanarFace::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_FPlanarFace::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L1_FPlanarFace::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventREQID:
		if (L1MIDIn() == L1MID_PLANAR_FACE){
			using namespace iso14649;
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			std::string sTempString;
			std::list<std::string> CmdList;
			int j, i;//Loop variables
			double nSecurityZ; //Above this Z-point the movements are safe
			Eigen::Vector3d vFOrigin;//Feature origin
			Eigen::Vector3d vOPStart;//Operation start point
			Eigen::Vector3d vRealStart;//Operation real start point once approach strategy is calculated
			Eigen::Vector3d vDepthNormal;//Feautre depth's normal vector
			Eigen::Vector3d vCTDir;//Course of travel displacement unitary vector
			Eigen::Vector3d vRBDir;//Removal boundary displacement unitary vector
			Eigen::Vector3d vCTInc;//Course of travel displacement vector
			Eigen::Vector3d vRBInc;//Removal boundary displacement vector
			Eigen::Vector3d vCurrentXYZ;//This vector is used to hold the XYZ where tool is heading
			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));
			if (TheWS != NULL){
				//Retreive the feature
				planarFace * TheFeature = (planarFace *)TheWS->get_itsFeature();
				//Change the tool and compensate tool lenght with D1
				sTempString = std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId());
				const Tool * theTool = Tool_Table::getTool(sTempString);
				if (theTool == NULL){
					//Tool info can't be retreived
					DEVLOG_DEBUG("Tool can not be found on the DDBB\n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				if (theTool->getToolPosition() > 0){
					//If returned position is 0 the tool is already in the spindle
					sprintf(acBuffer, "T%u D1", theTool->getLocalID());
					CmdList.push_back(std::string(acBuffer));
					CmdList.push_back(std::string("M6"));
				}
				else if (theTool->getToolPosition() < 0){
					//Tool not available
					DEVLOG_DEBUG("Trying to use a not available tool \n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				const double nRadius = theTool->getRadius();

				//Set the feature origin
				vFOrigin = GlobalUtils::V3DFromRealIter(TheFeature->get_featurePlacement()->get_location()->get_coordinates());
				nSecurityZ = TheWS->get_itsSecplane()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
				sprintf(acBuffer, "G00 X=%f Y=%f Z=%f", vFOrigin.x(), vFOrigin.y(), vFOrigin.z() + nSecurityZ);
				CmdList.push_back(std::string(acBuffer));
				sprintf(acBuffer, "G92 X0 Y0 Z%f", nSecurityZ);
				CmdList.push_back(std::string(acBuffer));

				//Retreive feature dimmensions
				double nDepth = TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
				vDepthNormal = GlobalUtils::V3DFromRealIter(TheFeature->get_depth()->get_position()->get_axis()->get_directionRatios());
				double nCTLength = TheFeature->get_courseOfTravel()->get_distance()->get_theoreticalSize();
				double nRBLength = TheFeature->get_removalBoundary()->get_profileLength()->get_itsParameterValue();
				vCTDir = GlobalUtils::V3DFromRealIter(TheFeature->get_courseOfTravel()->get_itsDirection()->get_directionRatios());
				vCTDir.normalize();
				vRBDir = GlobalUtils::V3DFromRealIter(TheFeature->get_removalBoundary()->get_placement()->get_refDirection()->get_directionRatios());
				vRBDir.normalize();

				//verify that feature coordinate system Z axis is parallel to machine Z axis
				if ((vDepthNormal.cross(Eigen::Vector3d(0,0,1))).norm() != 0.0){
					//Feature depth is leaning, not supported 
					DEVLOG_DEBUG("Planar face feature error; Leaning surfaces are not supported \n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				//verify that Course of travel and removal boundary start points are equal and match the feature origin
				if (!GlobalUtils::isPlacementEqual(TheFeature->get_courseOfTravel()->get_placement()->get_location(),
					TheFeature->get_removalBoundary()->get_placement()->get_location())){
					//Feature parameters error; Removal boundary and course of travel location must be equal
					DEVLOG_DEBUG("Planar face feature parameters error; CT and RB origin must be equal \n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				if (!GlobalUtils::isPlacementEqual(TheFeature->get_courseOfTravel()->get_placement()->get_location(),
					0.0, 0.0, 0.0)){
					//Feature parameters error; RB and CT origin must be equal to feature origin
					DEVLOG_DEBUG("Planar face feature parameters error; CT and RB origin must be equal to feature origin \n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}

				//Retreive the operation parameters
				if (TheWS->get_itsOperation()->isA(bottomAndSideMilling_E)){
					//Finish and rough milling classes are equal from c++ perspective
					bottomAndSideMilling * TheOperation = (bottomAndSideMilling *)TheWS->get_itsOperation();
					//Retreive the start_point of the operation
					vOPStart = GlobalUtils::V3DFromRealIter(TheWS->get_itsOperation()->get_startPoint()->get_coordinates());

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
					//Verify if the start point is within the rectangle to be machined
					//TODO

					//Calculate the number of layers to remove
					double nAxialStep = nRealDepth;
					int nLayers = 1;
					if (nRealDepth > nAxialMax){
						//Several layers needed
						//TODO: Add other splitting polices
						nLayers = ceil(((nRealDepth - abs(vOPStart.z())) / nAxialMax));
						nAxialStep = (nRealDepth - abs(vOPStart.z())) / nLayers++;
					}

					//Retreive approach strategy information
					double nAPAngle = 0.0;
					double nAPTravel = 0.0;
					std::vector<std::string> approachSequence;//Vector to hold the approach sequence
					if (TheOperation->get_approach()->isA(apRetractAngle_E)){
						apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
						nAPAngle = TheApproach->get_angle();
						nAPTravel = TheApproach->get_travelLength();
						vRealStart = vCTDir * nAPTravel;
						vRealStart.z() = -1.0 * sin(nAPAngle / 180.0 * pi)*nAPTravel;
						vRealStart = vOPStart - vRealStart;
						//Fast movement to XY operation start point in the security plane
						sprintf(acBuffer, "G00 X%f Y%f Z%f", vRealStart.x(), vRealStart.y(), nSecurityZ);
						approachSequence.push_back(std::string(acBuffer));
						//Fast movement in Z to the point where approach movement starts
						sprintf(acBuffer, "G00 Z%f", vRealStart.z());
						approachSequence.push_back(std::string(acBuffer));
						//Move tool to the start point
						sprintf(acBuffer, "G01 X%f Y%f Z%f", vOPStart.x(), vOPStart.y(), vOPStart.z());
						approachSequence.push_back(std::string(acBuffer));
					}else{
						//Approach strategy not supported
						DEVLOG_DEBUG("Trying to use a not supported approach strategy \n");
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
					CmdList.insert(CmdList.end(), approachSequence.begin(), approachSequence.end());

					//Calculate the offset of the start point in both CT and RB directions using sinus theorem
					double nAlpha;//angle between OP start point vector and course of travel director vector
					double nGamma;//angle between OP start point vector and removal boundary director vector
					double nDelta;//andgle 180º minus the angle between CT and RB director vectors
					double nCTOffset = 0.0;//Offset of the start point in CT direction
					double nRBOffset = 0.0;//offset of the start point in RB direction
					double nStartXYNorm = 0.0;//To calcule offset XY projection of the vector must be used
					nStartXYNorm = sqrt(vOPStart.x() * vOPStart.x() + vOPStart.y() * vOPStart.y());
					if (nStartXYNorm > 0.0){
						nAlpha = acos(vCTDir.dot(vOPStart) / nStartXYNorm);
						nGamma = acos(vRBDir.dot(vOPStart) / nStartXYNorm);
						nDelta = pi - nGamma - nAlpha;
						nCTOffset = nStartXYNorm* sin(nGamma) / sin(nDelta);
						nRBOffset = nStartXYNorm* sin(nAlpha) / sin(nDelta);
					}

					//Retreive the milling strategy info
					if (TheOperation->get_itsMachiningStrategy() == NULL){
						//Missing milling strategy
						DEVLOG_DEBUG("Missing milling strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

					int nSweeps = 1;//Number of sweeps need to machine the feature
					double nRadialStep;//distance between two neighbouring cutting movements
					double nLastRadialStep;//distance of the final sweep
					//Calculate the distance between to neighbouring cutting movements using overlap parameter
					//overlap is given as percentage of the tool diameter, therefore RadialStep is 2R(1-overlap)
					nRadialStep = (1 - TheOperation->get_itsMachiningStrategy()->get_overlap()->get_val()) * nRadius * 2;
					if ((nRBLength - nRBOffset) > nRadius){
						//Several sweeps needed
						if (nRadialStep > nRadialMax){
							//Strategy and operation parameters are not coherent. Operation parameter max radial takes precedence
							nSweeps = ceil(((nRBLength - nRadius - nRBOffset) / nRadialMax));
							nRadialStep = (nRBLength - nRadius - nRBOffset) / nSweeps++;
							nLastRadialStep = nRadialStep;
						}
						else{
							nSweeps = floor(((nRBLength - nRadius - nRBOffset) / nRadialStep));
							//Last step is different
							nLastRadialStep = (((nRBLength - nRadius - nRBOffset) / nRadialStep) - nSweeps) * nRadialStep;
							//+1 for 1st;+1 for last
							nSweeps += 2;
						}
					}
					//Generate path's G code according to the strategy
					//After approaching G01 is active and tool is at start point
					vCurrentXYZ = vOPStart;
					if (TheOperation->get_itsMachiningStrategy()->isA(unidirectionalMilling_E)){
						unidirectionalMilling* TheStrategy = (unidirectionalMilling*)TheOperation->get_itsMachiningStrategy();
						vCTInc = vCTDir * (nCTLength - 2 * nRadius);//Compensate tool radius
						vRBInc = vRBDir * nRadialStep;
						for (i = 1; i <= nLayers; i++){
							//First movement is different because it depens on the start point offset
							vCurrentXYZ = vCurrentXYZ + vCTDir*(nCTLength - nCTOffset - nRadius);
							sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
							CmdList.push_back(std::string(acBuffer));
							for (j = 2; j <= nSweeps;j++){
								sprintf(acBuffer, "G00 Z%f", nSecurityZ);
								CmdList.push_back(std::string(acBuffer));
								if (j == nSweeps){
									//Last is different
									vCurrentXYZ = vCurrentXYZ - vCTInc + vRBDir * nLastRadialStep;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									sprintf(acBuffer, "G01 Z%f", vCurrentXYZ.z());
									CmdList.push_back(std::string(acBuffer));
									vCurrentXYZ += vCTInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									sprintf(acBuffer, "G00 Z%f", nSecurityZ);
									CmdList.push_back(std::string(acBuffer));
								}
								else{
									vCurrentXYZ = vCurrentXYZ - vCTInc + vRBInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									sprintf(acBuffer, "G01 Z%f", vCurrentXYZ.z());
									CmdList.push_back(std::string(acBuffer));
									vCurrentXYZ += vCTInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));								
								}
								
							}
							if (i == nLayers){
								//Last is different
								CmdList.push_back("X0 Y0");
							}
							else{
								vCurrentXYZ = Eigen::Vector3d(vOPStart.x(), vOPStart.y(), vCurrentXYZ.z() - nAxialStep);
								sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
								CmdList.push_back(std::string(acBuffer));
								sprintf(acBuffer, "G01 Z%f", vCurrentXYZ.z());
								CmdList.push_back(std::string(acBuffer));
							}
						}
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){
						bidirectionalMilling  * TheStrategy = (bidirectionalMilling *)TheOperation->get_itsMachiningStrategy();
						vCTInc = vCTDir * (nCTLength - 2 * nRadius);//Compensate tool radius
						vRBInc = vRBDir * nRadialStep;
						for (i = 1; i <= nLayers; i++){
							//First movement is different because it depens on the start point offset
							vCurrentXYZ = vCurrentXYZ + vCTDir*(nCTLength - nCTOffset -nRadius);
							sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
							CmdList.push_back(std::string(acBuffer));
							for (j = 2; j <= nSweeps; j++){
								if (j == nSweeps){
									//Last is different
									vCurrentXYZ = vCurrentXYZ + vRBDir * nLastRadialStep;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									(j & 1) ? vCurrentXYZ += vCTInc : vCurrentXYZ -= vCTInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									sprintf(acBuffer, "G00 Z%f", nSecurityZ);
									CmdList.push_back(std::string(acBuffer));
								}
								else{
									vCurrentXYZ += vRBInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
									(j & 1) ? vCurrentXYZ += vCTInc : vCurrentXYZ -= vCTInc;
									sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
									CmdList.push_back(std::string(acBuffer));
								}
							}
							if (i == nLayers){
								//Last is different
								CmdList.push_back("X0 Y0");
							}
							else{
								vCurrentXYZ = Eigen::Vector3d(vOPStart.x(), vOPStart.y(), vCurrentXYZ.z() - nAxialStep);
								sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
								CmdList.push_back(std::string(acBuffer));
								sprintf(acBuffer, "G01 Z%f", vCurrentXYZ.z());
								CmdList.push_back(std::string(acBuffer));
							}
						}
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourParallel_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalContour_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourBidirectional_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourSpiral_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(explicitStrategy_E)){
						//This strategy is not supported for this feature
						DEVLOG_DEBUG("Not supported strategy \n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}

				}
				else{
					//Can not do a planar face w/o bottom and side milling
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
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
			CleanIArchive();
			sendOutputEvent(scm_nEventCNFID);
		}
		break;
	}
}



