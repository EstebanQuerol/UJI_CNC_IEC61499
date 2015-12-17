/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FGeneralOutProfile
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-07-01/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L1_FGeneralOutProfile.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FGeneralOutProfile_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FGeneralOutProfile, g_nStringIdL1_FGeneralOutProfile)

const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anDataInputNames[] = {g_nStringIdOperation, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FGeneralOutProfile::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FGeneralOutProfile::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_FGeneralOutProfile::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_FGeneralOutProfile::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_FGeneralOutProfile::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_FGeneralOutProfile::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L1_FGeneralOutProfile::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventREQID:
		if (L1MIDIn() == L1MID_GENERAL_OUT_PROFILE){
			using namespace iso14649;
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			std::list<std::string> CmdList;
			std::string sTempString;
			double nSecurityZ; //Above this Z-point the movements are safe
			Eigen::Vector3d vFOrigin;//Feature origin
			Eigen::Vector3d vOPStart;//Operation start point
			Eigen::Vector3d vProfileOrigin;//Operation start point
			Eigen::Vector3d vRealStart;//Operation real start point once approach strategy is calculated
			Eigen::Vector3d vDepthNormal;//Feautre depth's normal vector
			Eigen::Vector3d vCurrentXYZ;//This vector is used to hold the XYZ where tool is heading
			double nAxialMax;//Maximal axial cutting allowed
			double nRadialMax;//Maximal radial cutting allowed
			double nAxialAllowance;//bottom allowance for finishing operations
			double nRadialAllowance;//Side allowance for finishing operations
			double nRealDepth;//Real depth to mahcine, taking into account bottom allowance
			bool bOPStartExist = false;//Bool to indicate if the operation start point is defined
			approachRetractStrategy * TheApproach = NULL;
			//Deserialize the workingstep
			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));
			if (TheWS == NULL){
				//Null workingstep
				DEVLOG_DEBUG("L1_GeneralOutProfiler: Null workingstep found\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Retrieve the tool information
			const Tool * TheTool = Tool_Table::getTool(std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId()));
			const double nRadius = TheTool->getRadius();
			const double nMaxAxialcut = TheTool->getLengthCut();
			//Change the tool and compensate tool lenght with D1
			if (TheTool == NULL){
				//Tool info can't be Retrieved
				DEVLOG_DEBUG("L1_GeneralOutProfiler: Tool can not be found on the DDBB\n");
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
				DEVLOG_DEBUG("L1_GeneralOutProfiler: Trying to use a not available tool \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Retrieve the feature
			generalOutsideProfile * TheFeature = (generalOutsideProfile *)TheWS->get_itsFeature();

			//Set the feature origin
			vFOrigin = GlobalUtils::V3DFromRealIter(TheFeature->get_featurePlacement()->get_location()->get_coordinates());
			nSecurityZ = TheWS->get_itsSecplane()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
			sprintf(acBuffer, "G00 X=%f Y=%f Z=%f", vFOrigin.x(), vFOrigin.y(), vFOrigin.z() + nSecurityZ);
			CmdList.push_back(std::string(acBuffer));
			sprintf(acBuffer, "G92 X0 Y0 Z%f", nSecurityZ);
			CmdList.push_back(std::string(acBuffer));

			//check for null members
			if (TheFeature->get_featureBoundary() == NULL){
				//Missing parameters
				DEVLOG_DEBUG("L1_GeneralOutProfiler: Missing feature parameters \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Retrieve feature dimmensions
			double nDepth = abs(TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val());
			vDepthNormal = GlobalUtils::V3DFromRealIter(TheFeature->get_depth()->get_position()->get_axis()->get_directionRatios());
			
			//verify that feature coordinate system Z axis is parallel to machine Z axis
			if ((vDepthNormal.cross(Eigen::Vector3d(0, 0, 1))).norm() != 0.0){
				//Feature depth is leaning, not supported 
				DEVLOG_DEBUG("L1_GeneralOutProfiler: Leaning surfaces are not supported \n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//Retrieve the operation parameters
			if (TheWS->get_itsOperation()->isA(bottomAndSideMilling_E)){
				//Finish and rough milling classes are equal from c++ perspective
				bottomAndSideMilling * TheOperation = (bottomAndSideMilling *)TheWS->get_itsOperation();
				TheApproach = TheOperation->get_approach();
				//Retrieve the start_point of the operation
				if (TheWS->get_itsOperation()->get_startPoint() != NULL){
					vOPStart = GlobalUtils::V3DFromRealIter(TheWS->get_itsOperation()->get_startPoint()->get_coordinates());
					bOPStartExist = true;
				}
				
				//Operation parameters
				nAxialMax = TheOperation->get_axialCuttingDepth()->get_val();
				nRadialMax = TheOperation->get_radialCuttingDepth()->get_val();
				nAxialAllowance = TheOperation->get_allowanceBottom()->get_val();
				nRadialAllowance = TheOperation->get_allowanceSide()->get_val();
				nRealDepth = nDepth - nAxialAllowance;
			}
			else if (TheWS->get_itsOperation()->isA(sideMilling_E)){
				//Finish and roughside  milling classes are equal from c++ perspective
				sideMilling * TheOperation = (sideMilling *)TheWS->get_itsOperation();
				TheApproach = TheOperation->get_approach();
				//Retrieve the start_point of the operation
				if (TheWS->get_itsOperation()->get_startPoint() != NULL){
					vOPStart = GlobalUtils::V3DFromRealIter(TheWS->get_itsOperation()->get_startPoint()->get_coordinates());
					bOPStartExist = true;
				}
				//Operation parameters
				nAxialMax = TheOperation->get_axialCuttingDepth()->get_val();
				nRadialMax = TheOperation->get_radialCuttingDepth()->get_val();
				nAxialAllowance = 0.0;
				nRadialAllowance = TheOperation->get_allowanceSide()->get_val();
				nRealDepth = nDepth - nAxialAllowance;
			}
			else{
				//Not valid operation for a profile feature
				DEVLOG_DEBUG("L1_GeneralOutProfile: Not valid operation for a profile feature\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//Verify that the tool can be used to machine the feature
			if (nAxialMax > nMaxAxialcut){
				//AxialMax is greater than tool's maximal cutting lenght, adjust it
				nAxialMax = nMaxAxialcut;
			}
			//Verify that the start point is correct
			if (bOPStartExist && (vOPStart.z() > 0.0 || abs(vOPStart.z()) > nAxialMax)){
				//CAM Error; start point is higher than the surface to machine or depther than max axial length; Abort operation
				DEVLOG_DEBUG("L1_GeneralOutProfile: Operation start point error\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			//Calculate the number of layers to remove
			double nAxialStep = nRealDepth;
			int nLayers = 1;
			if (nRealDepth > nAxialMax){
				//Several layers needed. By default all layers' depth is equal
				if (bOPStartExist){
					nLayers = ceil(((nRealDepth - abs(vOPStart.z())) / nAxialMax));
					nAxialStep = (nRealDepth - abs(vOPStart.z())) / nLayers++;
				}
				else{
					nLayers = ceil((nRealDepth / nAxialMax));
					nAxialStep = nRealDepth / nLayers;
				}
			}
			vProfileOrigin = Eigen::Vector3d(0.0, 0.0, 0.0);//By default profile placement is 0.0,0.0,0.0
			if (TheFeature->get_featureBoundary()->isA(ngonClosedProfile_E)){
				DEVLOG_DEBUG("L1_GeneralOutProfile: Not supported profile\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			else if (TheFeature->get_featureBoundary()->isA(rectangularClosedProfile_E)){
				rectangularClosedProfile * TheProfile = (rectangularClosedProfile *)TheFeature->get_featureBoundary();
				double nSemiWidth = TheProfile->get_profileWidth()->get_theoreticalSize() / 2.0;
				double nSemiLength = TheProfile->get_profileLength()->get_theoreticalSize() / 2.0;
				// Profile path offset due to tool compensation and allowance
				nSemiWidth += nRadius + nRadialAllowance;
				nSemiLength += nRadius + nRadialAllowance;
				if (TheProfile->get_placement() != NULL){
					vProfileOrigin = GlobalUtils::V3DFromRealIter(TheProfile->get_placement()->get_location()->get_coordinates());
				}
				std::vector<Eigen::Vector3d> ThePoints; //Vector used to hold profile vertices
				Eigen::Vector3d vAux2DPoint;
				ThePoints.reserve(4);
				//Calculate the position of each vertice taking into side offset
				vAux2DPoint = Eigen::Vector3d(-nSemiLength, nSemiWidth, 0.0);
				//TODO: Here we can apply a rotation if coordinate systems are not parallel
				vAux2DPoint = Eigen::Vector3d(vAux2DPoint.x() + vProfileOrigin.x(), vAux2DPoint.y() + vProfileOrigin.y(), 0.0);
				ThePoints.push_back(vAux2DPoint);
				vAux2DPoint = Eigen::Vector3d(nSemiLength, nSemiWidth, 0.0);
				vAux2DPoint = Eigen::Vector3d(vAux2DPoint.x() + vProfileOrigin.x(), vAux2DPoint.y() + vProfileOrigin.y(), 0.0);
				ThePoints.push_back(vAux2DPoint);
				vAux2DPoint = Eigen::Vector3d(nSemiLength, -nSemiWidth, 0.0);
				vAux2DPoint = Eigen::Vector3d(vAux2DPoint.x() + vProfileOrigin.x(), vAux2DPoint.y() + vProfileOrigin.y(), 0.0);
				ThePoints.push_back(vAux2DPoint);
				vAux2DPoint = Eigen::Vector3d(-nSemiLength, -nSemiWidth, 0.0);
				vAux2DPoint = Eigen::Vector3d(vAux2DPoint.x() + vProfileOrigin.x(), vAux2DPoint.y() + vProfileOrigin.y(), 0.0);
				ThePoints.push_back(vAux2DPoint);
				int i = 0;
				int nSPPosition = 0;//Start point position within the vector
				if (bOPStartExist){
					//The start point must coincide with any of the vertices
					//If none of the calculated points concides with the given start point it will be ignored and by default 1st point will be [0]
					for (; i < 4; i++){
						if (ThePoints[i].x() == vOPStart.x() && ThePoints[i].y() == vOPStart.y()) {
							nSPPosition = i;
							break;
						}
					}
					if (i == 4){
						//Invalid start point, build the default one keeping the Z coordinate
						vOPStart.x() = ThePoints[0].x();
						vOPStart.y() = ThePoints[0].y();
					}
				}
				else{
					//Missing start point, build the default one
					vOPStart = Eigen::Vector3d(ThePoints[0].x(), ThePoints[0].y(), -nAxialStep);
				}
				//Generate the tool path
				//Retrieve approach strategy information
				if (TheApproach != NULL && TheApproach->isA(apRetractAngle_E)){
					apRetractAngle * TheApproachRA = (apRetractAngle *)TheApproach;
					double nAPAngle = TheApproachRA->get_angle();
					double nAPTravel = TheApproachRA->get_travelLength();
					Eigen::Vector3d vPDir;
					if (nSPPosition == 3){
						vPDir = Eigen::Vector3d(ThePoints[0].x() - ThePoints[nSPPosition].x(), ThePoints[0].y() - ThePoints[nSPPosition].y(), 0.0);
					}
					else{
						vPDir = Eigen::Vector3d(ThePoints[nSPPosition + 1].x() - ThePoints[nSPPosition].x(),
							ThePoints[nSPPosition + 1].y() - ThePoints[nSPPosition].y(), 0.0);
					}
					vPDir.normalize();
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
					//Approach strategy null or not supported; Using default strategy
					//Fast movement to XY operation start point in the security plane
					sprintf(acBuffer, "G00 X%f Y%f Z%f", ThePoints[nSPPosition].x(), ThePoints[nSPPosition].y(), nSecurityZ);
					CmdList.push_back(std::string(acBuffer));
					//Move tool to the start point
					sprintf(acBuffer, "G01 Z%f", vOPStart.z());
					CmdList.push_back(std::string(acBuffer));
				}
				++nSPPosition %= 4;
				for (int j = 1; j <= nLayers; j++){
					for (i = 0; i < 4; i++){
						sprintf(acBuffer, "X=%f Y=%f", ThePoints[nSPPosition].x(), ThePoints[nSPPosition].y());
						CmdList.push_back(std::string(acBuffer));
						++nSPPosition %= 4;
					}
					if (j == nLayers){
						//Last is different
						sprintf(acBuffer, "Z=%f", nSecurityZ);
						CmdList.push_back(std::string(acBuffer));
						CmdList.push_back("X0 Y0");
					}
					else{
						sprintf(acBuffer, "G91 Z=%f", -nAxialStep);
						CmdList.push_back(std::string(acBuffer));
						CmdList.push_back("G90");
					}
				}
			}
			else if (TheFeature->get_featureBoundary()->isA(partialCircularProfile_E)){
				partialCircularProfile* TheProfile = (partialCircularProfile *)TheFeature->get_featureBoundary();
				double nProfileRadius = TheProfile->get_radius()->get_theoreticalSize();
				double nProfileAngle = TheProfile->get_sweepAngle();
				if (TheProfile->get_placement() != NULL){
					vProfileOrigin = GlobalUtils::V3DFromRealIter(TheProfile->get_placement()->get_location()->get_coordinates());
				}
			}
			else{
				DEVLOG_DEBUG("L1_GeneralOutProfile: Not supported profile\n");
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
			break;
		}
	}
}