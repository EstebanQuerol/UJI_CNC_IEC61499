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
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			std::string sTempString;
			std::stringstream ss;
			std::list<std::string> CmdList;
			std::list<real *>::const_iterator reallistIter;
			double nX, nY, nZ;
			double nSecurityZ; //Above this Z-point the movements are safe
			int nToolPos;

			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));
			if (TheWS != NULL){
				planarFace * TheFeature = (planarFace *)TheWS->get_itsFeature();
				//Change the tool and compensate tool lenght with D1
				sTempString = std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId());
				nToolPos = Tool_Table::isAvailable(sTempString);
				if (nToolPos > 0){
					//If returned position is 0 the tool is already in the spindle
					sprintf(acBuffer, "T%u D1", Tool_Table::getToolID(sTempString));
					CmdList.push_back(std::string(acBuffer));
					CmdList.push_back(std::string("M6"));
				}
				else if (nToolPos < 0){
					//Tool not available
					DEVLOG_DEBUG("Trying to use a not available tool \n");
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}

				//Set the feature origin
				reallistIter = TheFeature->get_featurePlacement()->get_location()->get_coordinates()->get_theList()->begin();
				nX = (*reallistIter++)->get_val();
				nY = (*reallistIter++)->get_val();
				nZ = (*reallistIter)->get_val();
				nSecurityZ = TheWS->get_itsSecplane()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
				sprintf(acBuffer, "G00 X=%f Y=%f Z=%f", nX, nY, nZ + nSecurityZ);
				CmdList.push_back(std::string(acBuffer));
				sprintf(acBuffer, "G92 X0 Y0 Z%f", nSecurityZ);
				CmdList.push_back(std::string(acBuffer));

				//Build the tool path
				if (TheWS->get_itsOperation()->isA(bottomAndSideRoughMilling_E)){
					bottomAndSideRoughMilling * TheOperation = (bottomAndSideRoughMilling *)TheWS->get_itsOperation();

					//Retreive the start_point of the operation
					reallistIter = TheWS->get_itsOperation()->get_startPoint()->get_coordinates()->get_theList()->begin();
					double nXStart = (*reallistIter++)->get_val();
					double nYStart = (*reallistIter++)->get_val();
					double nZStart = (*reallistIter)->get_val();

					//Retrive feature dimmensions and Calculate the number of layers to remove
					double nDepth = TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
					double nCTLength = TheFeature->get_courseOfTravel()->get_distance()->get_theoreticalSize();
					double nRBLength = TheFeature->get_removalBoundary()->get_profileLength()->get_itsParameterValue();
					double nAxialMax = TheOperation->get_axialCuttingDepth()->get_val();
					double nRadialMax = TheOperation->get_radialCuttingDepth()->get_val();
					double nAxialAllowance = TheOperation->get_allowanceBottom()->get_val();
					double nRealDepth = nDepth - nAxialAllowance;
					double nAxialStep = nRealDepth;
					double nRadialStep = nRBLength;
					int nLayers = 1;
					double nSweeps = 1;

					if (nRBLength > nRadialMax){
						//Several sweeps  needed
						//TODO: Add other splitting polices
						nSweeps = ceil((nRBLength / nRadialMax));
						nRadialStep = nRBLength / nSweeps;
					}


					//Verify that the start point is correct
					if (abs(nZStart) > nAxialMax){
						//CAM Error; start point is lower than max axial cut
						//abort
						DEVLOG_DEBUG("Operation start point error\n");
						forte_free(acBuffer);
						acBuffer = NULL;
						PARAM_ERROR_EXIT
					}
					if (nRealDepth > nAxialMax){
						//Several layers needed
						//TODO: Add other splitting polices
						nLayers = ceil(((nRealDepth - abs(nZStart)) / nAxialMax));
						nAxialStep = (nRealDepth - abs(nZStart)) / nLayers;
					}
					//
					reallistIter = TheFeature->get_courseOfTravel()->get_itsDirection()->get_directionRatios()->get_theList()->begin();
					double nXDir = (*reallistIter++)->get_val();
					double nYDir = (*reallistIter++)->get_val();
					double nZDir = (*reallistIter)->get_val();
					double nDirMod = sqrt(nXDir*nXDir + nYDir*nYDir + nZDir*nZDir);
					double nXInc = nXDir * nCTLength / nDirMod;
					double nYInc = nYDir * nCTLength / nDirMod;
					double nZInc = nZDir * nCTLength / nDirMod;
					reallistIter = TheFeature->get_removalBoundary()->get_placement()->get_refDirection()->get_directionRatios()->get_theList()->begin();
					double nXRBDir = (*reallistIter++)->get_val();
					double nYRBDir = (*reallistIter++)->get_val();
					double nZRBDir = (*reallistIter)->get_val();
					double nRBDirMod = sqrt(nXRBDir*nXRBDir + nYRBDir*nYRBDir + nZRBDir*nZRBDir);
					double nXRBInc = nXRBDir * nRadialStep / nRBDirMod;
					double nYRBInc = nYRBDir * nRadialStep / nRBDirMod;
					double nZRBInc = nZRBDir * nRadialStep / nRBDirMod;

					//Retreive approach strategy information
					double nAPAngle = 0.0;
					double nAPTravel = 0;
					//TODO: Only one approach strategy supported for now
					if (TheOperation->get_approach()->isA(apRetractAngle_E)){
						apRetractAngle * TheApproach = (apRetractAngle *)TheOperation->get_approach();
						nAPAngle = TheApproach->get_angle();
						nAPTravel = TheApproach->get_travelLength();


						//Fast movement to XY operation start point in the security plane
						sprintf(acBuffer, "G00 X%f Y%f Z%f", nXStart, nYStart + cos(nAPAngle / 180.0 * pi)*nAPTravel, nSecurityZ);
						CmdList.push_back(std::string(acBuffer));
						//Fast movement in Z to the point where approach movement starts
						sprintf(acBuffer, "G00 Z%f", nZStart + sin(nAPAngle / 180.0 * pi)*nAPTravel);
						CmdList.push_back(std::string(acBuffer));
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

						//Move tool to the start point
						sprintf(acBuffer, "G01 X%f Y%f Z%f", nXStart, nYStart, nZStart);
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
						unidirectionalMilling  * TheStrategy = (unidirectionalMilling *)TheOperation->get_itsMachiningStrategy();
						double nCurrentX = nXStart;
						double nCurrentY = nYStart;
						double nCurrentZ = nZStart;
						for (int i = 0; i <= nLayers; i++){
							for (int j = 0; j < nSweeps - 1; j++){
								sprintf(acBuffer, "X%f Y%f", nCurrentX + nXInc, nCurrentY + nYInc);
								CmdList.push_back(std::string(acBuffer));
								sprintf(acBuffer, "G00 Z%f", nSecurityZ);
								CmdList.push_back(std::string(acBuffer));
								sprintf(acBuffer, "X%f Y%f", nCurrentX + nXRBInc, nCurrentY + nYRBInc);
								CmdList.push_back(std::string(acBuffer));
								sprintf(acBuffer, "G01 Z%f", nCurrentZ);
								CmdList.push_back(std::string(acBuffer));
								nCurrentX += nXRBInc;
								nCurrentY += nYRBInc;
							}
							sprintf(acBuffer, "X%f Y%f", nCurrentX + nXInc, nCurrentY + nYInc);
							CmdList.push_back(std::string(acBuffer));
							sprintf(acBuffer, "G00 Z%f", nSecurityZ);
							CmdList.push_back(std::string(acBuffer));
							nCurrentX = nXStart;
							nCurrentY = nYStart;
							if (i == nLayers){
								//Last is different
								CmdList.push_back("X0 Y0");
							}
							else{
								sprintf(acBuffer, "X%f Y%f", nCurrentX, nCurrentY);
								CmdList.push_back(std::string(acBuffer));
								nCurrentZ = nZStart - (nAxialStep*(i + 1));
								sprintf(acBuffer, "G01 Z%f", nCurrentZ);
								CmdList.push_back(std::string(acBuffer));
							}
						}
					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalMilling_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourParallel_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(bidirectionalContour_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourBidirectional_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(contourSpiral_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(centerMilling_E)){

					}
					else if (TheOperation->get_itsMachiningStrategy()->isA(explicitStrategy_E)){

					}

				}
				else{
					//Cant do a planar face w/o bottom and side milling
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



