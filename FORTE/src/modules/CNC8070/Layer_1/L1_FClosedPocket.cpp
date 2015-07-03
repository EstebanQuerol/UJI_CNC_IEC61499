/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FClosedPocket
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L1_FClosedPocket.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FClosedPocket_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FClosedPocket, g_nStringIdL1_FClosedPocket)

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataInputNames[] = { g_nStringIdOperation, g_nStringIdL1MIDIn };

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataInputTypeIds[] = { g_nStringIdSTRING, g_nStringIdUSINT };

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataOutputNames[] = { g_nStringIdCmd, g_nStringIdL1MIDOut };

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataOutputTypeIds[] = { g_nStringIdSTRING, g_nStringIdUSINT };

const TForteInt16 FORTE_L1_FClosedPocket::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_L1_FClosedPocket::scm_anEIWith[] = { 0, 1, 255 };
const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_L1_FClosedPocket::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_L1_FClosedPocket::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L1_FClosedPocket::scm_stFBInterfaceSpec = {
	1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
	1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds,
	2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
	0, 0
};


void FORTE_L1_FClosedPocket::executeEvent(int pa_nEIID){
	using namespace iso14649;
	switch (pa_nEIID){
	case scm_nEventREQID:
		if (L1MIDIn() == L1MID_CLOSED_POCKET){
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			std::string sTempString;
			std::stringstream ss;
			std::list<std::string> CmdList;
			std::list<real *>::const_iterator reallistIter;
			double nX, nY, nZ;
			double nSecurityZ; //Above this Z-point the movements are safe
			int nToolPos;

			machiningWorkingstep * TheWS = (machiningWorkingstep *)(DeserializeWorkingstep(Operation()));
			if (TheWS == NULL){
				//Null workingstep
				DEVLOG_DEBUG("Null workingstep found\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}
			closedPocket * TheFeature = (closedPocket *)TheWS->get_itsFeature();
			//Change the tool
			sTempString = std::string(TheWS->get_itsOperation()->get_itsTool()->get_itsId());
			nToolPos = Tool_Table::isAvailable(sTempString);
			if (nToolPos > 0){
				//If returned position is 0 the tool is already in the spindle
				sprintf(acBuffer, "T%u D1", Tool_Table::getToolLocalID(sTempString));
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

			//Move tool to the star point
			reallistIter = TheWS->get_itsOperation()->get_startPoint()->get_coordinates()->get_theList()->begin();
			nX = (*reallistIter++)->get_val();
			nY = (*reallistIter)->get_val();
			sprintf(acBuffer, "G00 X%f Y%f Z%f", nX, nY, nSecurityZ);
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

			//Build the feature path
			if (TheFeature->get_featureBoundary()->isA(rectangularClosedProfile_E)){
				//Using FAGOR 8070 Rectangular pocket cycle
				ss << "G87 G99";
				ss << " Z" << nSecurityZ;
				ss << " I" << TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
				ss << " D" << nSecurityZ;//Feature placement Z is at the highest plane of the piece
				rectangularClosedProfile * Theprofile = (rectangularClosedProfile *)TheFeature->get_featureBoundary();
				double nWidth = Theprofile->get_profileWidth()->get_theoreticalSize();
				double nLength = Theprofile->get_profileLength()->get_theoreticalSize();
				ss << " J+" << (nLength / 2.0) << " K" << (nWidth / 2.0);
				double nORadius = TheFeature->get_orthogonalRadius()->get_theoreticalSize();
				if (nORadius > 0.0){
					ss << " M1" << " Q" << nORadius;
				}
				if (TheWS->get_itsOperation()->isA(bottomAndSideRoughMilling_E)){
					bottomAndSideRoughMilling * TheOperation = (bottomAndSideRoughMilling *)TheWS->get_itsOperation();
					ss << " B-" << TheOperation->get_axialCuttingDepth()->get_val();
					ss << " C" << TheOperation->get_radialCuttingDepth()->get_val();
				}
				else{
					//Cant do a pocket w/o bottom and side milling
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				CmdList.push_back(ss.str());
				//Cancel the cycle
				CmdList.push_back("G80");
			}
			else if (TheFeature->get_featureBoundary()->isA(circularClosedProfile_E)){
				//Using FAGOR 8070 circular pocket cycle
				ss << "G88 G99";
				ss << " Z" << nSecurityZ;
				ss << " I" << TheFeature->get_depth()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
				ss << " D" << nSecurityZ;//Feature placement Z is at the highest plane of the piece
				circularClosedProfile * Theprofile = (circularClosedProfile *)TheFeature->get_featureBoundary();
				double nRadius = Theprofile->get_diameter()->get_theoreticalSize();
				ss << " J+" << (nRadius / 2.0);
				double nORadius = TheFeature->get_orthogonalRadius()->get_theoreticalSize();
				if (TheWS->get_itsOperation()->isA(bottomAndSideRoughMilling_E)){
					bottomAndSideRoughMilling * TheOperation = (bottomAndSideRoughMilling *)TheWS->get_itsOperation();
					ss << " B-" << TheOperation->get_axialCuttingDepth()->get_val();
					ss << " C" << TheOperation->get_radialCuttingDepth()->get_val();
				}
				else{
					//Cant do a pocket w/o bottom and side milling
					forte_free(acBuffer);
					acBuffer = NULL;
					PARAM_ERROR_EXIT
				}
				CmdList.push_back(ss.str());
				//Cancel the cycle
				CmdList.push_back("G80");

			}
			else if (TheFeature->get_featureBoundary()->isA(ngonClosedProfile_E)){

			}
			else{
				DEVLOG_DEBUG("Not supported profile\n");
				forte_free(acBuffer);
				acBuffer = NULL;
				PARAM_ERROR_EXIT
			}

			//Stop the spindle
			CmdList.push_back("M05");
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



