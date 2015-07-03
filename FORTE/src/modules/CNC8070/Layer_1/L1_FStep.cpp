/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FStep
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-07-01/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_FStep.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FStep_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FStep, g_nStringIdL1_FStep)

const CStringDictionary::TStringId FORTE_L1_FStep::scm_anDataInputNames[] = {g_nStringIdOperation, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_FStep::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FStep::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FStep::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FStep::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FStep::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_FStep::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_FStep::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_FStep::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_FStep::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_FStep::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L1_FStep::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventREQID:
		if (L1MIDIn() == L1MID_STEP){
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
			Eigen::Vector3d vOBDir;//Course of travel displacement unitary vector

			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));
			if (TheWS == NULL){
				//Null workingstep
				DEVLOG_DEBUG("Null workingstep found\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Change the tool and compensate tool lenght with D1
			const Tool * TheTool = Tool_Table::getTool(std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId()));
			if (TheTool == NULL){
				//Tool info can't be Retrieved
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

			//Retrieve the feature
			step * TheFeature = (step *)TheWS->get_itsFeature();

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
			linearPath * TheOB = TheFeature->get_openBoundary();
			double nOBLength = TheOB->get_distance()->get_theoreticalSize();
			vOBDir = GlobalUtils::V3DFromRealIter(TheOB->get_itsDirection()->get_directionRatios());
			vOBDir.normalize();
			veeProfile	* TheWB = TheFeature->get_wallBoundary();

			if (TheOB == NULL || TheWB == NULL){
				//Missing parameters
				DEVLOG_DEBUG("Feature error; Missing parameters \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//Verify that the V profile shape; For now only rectangular profiles are supported
			if (TheWB->get_profileRadius()->get_theoreticalSize() != 0.0 || TheWB->get_tiltAngle() != 90.0 || TheWB->get_profileAngle() != 90.0){
				//Only rectangular steps are supported
				DEVLOG_DEBUG("Feature error; Only rectangular steps are supported \n");
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
			//verify that open boundary and wall boundary start points are equal and match the feature origin
			if (!GlobalUtils::isPlacementEqual(TheOB->get_placement()->get_location(),
				TheWB->get_placement()->get_location())){
				//Feature parameters error; Open boundary and wall boundary location must be equal
				DEVLOG_DEBUG("Step feature parameters error; OB and WB origin must be equal \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			if (!GlobalUtils::isPlacementEqual(TheOB->get_placement()->get_location(),
				0.0, 0.0, 0.0)){
				//Feature parameters error; RB and CT origin must be equal to feature origin
				DEVLOG_DEBUG("Step feature parameters error; OB and WB origin must be equal to feature origin \n");
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

				//Retrieve approach strategy information
				double nAPAngle = 0.0;
				double nAPTravel = 0.0;
				std::vector<std::string> approachSequence;//Vector to hold the approach sequence
				if (TheOperation->get_approach()->isA(apRetractAngle_E)){
					apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
					nAPAngle = TheApproach->get_angle();
					nAPTravel = TheApproach->get_travelLength();
					vRealStart = vOBDir * nAPTravel;
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
				}
				else{
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

				/*For now we cant calculate the width of the step and therefore strategies can not be applied
				* At the moment steps are machined as a straight line that starts at the operation start point
				* and follows the open boundary direction
				*/
				//After approaching G01 is active and tool is at start point
				vCurrentXYZ = vOPStart;
				for (int i = 1; i <= nLayers; i++){
					//First movement is different because it depens on the start point offset
					vCurrentXYZ = vCurrentXYZ + vOBDir * nOBLength;
					sprintf(acBuffer, "X%f Y%f", vCurrentXYZ.x(), vCurrentXYZ.y());
					CmdList.push_back(std::string(acBuffer));
					sprintf(acBuffer, "G00 Z%f", nSecurityZ);
					CmdList.push_back(std::string(acBuffer));
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
			else{
				//Can not do a step face w/o bottom and side milling
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
			CleanIArchive();
			sendOutputEvent(scm_nEventCNFID);
			break;
		}
	}
}