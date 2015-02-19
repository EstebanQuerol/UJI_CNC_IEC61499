/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_ExecutionManager
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-01-08/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_ExecutionManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_ExecutionManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_ExecutionManager, g_nStringIdL2_ExecutionManager)

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdSetup, g_nStringIdNextCode};

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdOperation, g_nStringIdSetupENDID};

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L2_ExecutionManager::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_L2_ExecutionManager::scm_anEIWith[] = {0, 255, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdRENEW, g_nStringIdNEXT};

const TDataIOID FORTE_L2_ExecutionManager::scm_anEOWith[] = {0, 255, 1, 255, 2, 255};
const TForteInt16 FORTE_L2_ExecutionManager::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdExecuteOP, g_nStringIdCompleted};

const SFBInterfaceSpec FORTE_L2_ExecutionManager::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L2_ExecutionManager::DeleteCurrentWP(){
	//After deserialization new objects are created once they are used they must be deleted
	GlobalUtils::utils_SerFree();
	m_poIArchive->delete_created_pointers();
	delete m_poIArchive;
	m_poIArchive = NULL;
}

void FORTE_L2_ExecutionManager::RetreiveWP(){
	if (m_bSetupLoaded){
		// A plan is currently loaded but a new renew event arrived
		// Delete the old one before setting up the new
		DeleteCurrentWP();
	}
	std::istringstream iss;
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (Setup().length() + 1));
	if (pacTempString != NULL){
		if (-1 != Setup().toString(pacTempString, static_cast<unsigned int>(Setup().length() + 1), 1)){
			iss.str(std::string(pacTempString));
			m_poIArchive = new boost::archive::text_iarchive(iss);
			(*m_poIArchive) >> m_poCurrentWP;
			m_bSetupLoaded = TRUE;
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while desirealizing in L3_ExecutionManager\n");
	}
}

void FORTE_L2_ExecutionManager::executeEvent(int pa_nEIID){
setup * st;
  switch(pa_nEIID){
    case scm_nEventINITID:
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
    case scm_nEventRENEWID:
		RetreiveWP();
		//No putput event is generated
		break;
    case scm_nEventNEXTID:
//#error add code for NEXT event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
  }
}



