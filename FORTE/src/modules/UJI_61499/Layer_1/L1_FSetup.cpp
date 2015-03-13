/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FSetup
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_FSetup.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FSetup_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FSetup, g_nStringIdL1_FSetup)

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataInputNames[] = {g_nStringIdOperation, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FSetup::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FSetup::scm_anEIWith[] = {1, 0, 255};
const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_FSetup::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_FSetup::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_FSetup::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L1_FSetup::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
    case scm_nEventREQID:
		if (L1MIDIn() == L1MID_SETUP){
			char * acBuffer = (char *)forte_malloc(sizeof(char)* 100);
			double nX, nY, nZ;
			std::list<std::string> CmdList;
			setup * TheSetup = DeserializeSetup(Operation());
			//Set the fixture origin
			std::list<real *>::const_iterator listIter = TheSetup->get_itsOrigin()->get_location()->get_coordinates()->get_theList()->begin();
			nX = (*listIter++)->get_val();
			nY = (*listIter++)->get_val();
			nZ = (*listIter)->get_val();
			sprintf(acBuffer, "V.A.FIXT[1].X=%f V.A.FIXT[1].Y=%f V.A.FIXT[1].Z=%f V.G.FIX = 1", nX, nY, nZ);
			CmdList.push_back(std::string(acBuffer));
			//Move spindle above security plane
			nZ = TheSetup->get_itsSecplane()->get_position()->get_location()->get_coordinates()->get_theList()->back()->get_val();
			sprintf(acBuffer, "G00 X0 Y0 Z%f", nZ);
			CmdList.push_back(std::string(acBuffer));
			//Set the workpiece origin
			listIter = TheSetup->get_itsWorkpieceSetup()->get_theList()->front()->get_itsOrigin()->get_location()->get_coordinates()->get_theList()->begin();
			nX = (*listIter++)->get_val();
			nY = (*listIter++)->get_val();
			nZ = (*listIter)->get_val();
			sprintf(acBuffer, "V.A.ORGT[1].X=%f V.A.ORGT[1].Y=%f V.A.ORGT[1].Z=%f G159=1", nX, nY, nZ);
			CmdList.push_back(std::string(acBuffer));


#ifdef SIMULATED_8070
			block * theblock = (block *) TheSetup->get_itsWorkpieceSetup()->get_theList()->front()->get_itsWorkpiece()->get_itsBoundingGeometry();
			sprintf(acBuffer, "#DGWZ[0,%f,0,%f,0,%f]", theblock->get_x(), theblock->get_y(), theblock->get_z());
			CmdList.push_back(std::string(acBuffer));
#endif
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



