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

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdOperation, g_nStringIdL1MID, g_nStringIdSetupENDID};

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdUSINT};

const TForteInt16 FORTE_L2_ExecutionManager::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_L2_ExecutionManager::scm_anEIWith[] = {0, 255, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdRENEW, g_nStringIdNEXT};

const TDataIOID FORTE_L2_ExecutionManager::scm_anEOWith[] = {0, 255, 1, 2, 255, 3, 255};
const TForteInt16 FORTE_L2_ExecutionManager::scm_anEOWithIndexes[] = {0, 2, 5, -1};
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
	//Reset internal variables
	m_nPartState = PART_NOT_FIXED;
	m_nExecutionErrors = 0;
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
			m_itCurrentElement = m_poCurrentWP->get_itsElements()->get_theList()->begin();
			m_bSetupLoaded = TRUE;
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while desirealizing in L3_ExecutionManager\n");
	}
}

workingstep * FORTE_L2_ExecutionManager::GetWorkingStep(){
	const std::type_info &type = typeid((*m_itCurrentElement));
	if (type == typeid(workingstep))
		return (workingstep *)(*m_itCurrentElement);
	//Default return
	return NULL;
}

TForteUInt8 FORTE_L2_ExecutionManager::GetWSL1MID(const iso14649CppBase * obj){
	const std::type_info &type = typeid((*obj));
	if (type == typeid(planarFace))
		return L1MID_PLANAR_FACE;
	if (type == typeid(closedPocket))
		return L1MID_CLOSED_POCKET;
	if (type == typeid(openPocket))
		return L1MID_OPEN_POCKET;
	//Send not valid as default if the type is not supported
	return L1MID_NOT_VALID;
}

std::string FORTE_L2_ExecutionManager::stringSerialize(const iso14649CppBase * obj){
	//Boost Serialization
	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << obj;
	return oss.str().c_str();
}

void FORTE_L2_ExecutionManager::executeEvent(int pa_nEIID){
  iso14649CppBase * tempobj = NULL;
  switch(pa_nEIID){
    case scm_nEventINITID:
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
    case scm_nEventRENEWID:
		RetreiveWP();
		//No output event is generated
		break;
    case scm_nEventNEXTID:
		switch (NextCode()){
		case 0:
			//Last action executed correctly
			m_nExecutionErrors = 0; //Reset errors counter
			switch (m_nPartState){
			case PART_NOT_FIXED:
				//1st action is to fix the part
				m_nPartState = PART_BEING_FIXED;
				tempobj = GetSetup();
				if (tempobj != NULL){
					Operation() = stringSerialize(tempobj).c_str();
					L1MID() = L1MID_SETUP;
				}
				else{
					DEVLOG_ERROR("L2_ExecutionManager can't retreive the setup\n");
					Operation() = "";
					L1MID() = L1MID_NOT_VALID;
				}
				break;
			case PART_BEING_FIXED:
				//Part fixing succeed, start machining it
				m_nPartState = PART_FIXED;
				//Don't break and do next case
			case PART_FIXED:
				if (ElementsToDo()){
					tempobj = GetWorkingStep();
					if (tempobj != NULL){
						Operation() = stringSerialize(tempobj).c_str();
						L1MID() = GetWSL1MID(tempobj);
						m_itCurrentElement++; //Advance fordward in the elements list
					}else{
						DEVLOG_ERROR("L2_ExecutionManager can't retrieve the workingstep\n");
						Operation() = "";
						L1MID() = L1MID_NOT_VALID;
					}
				}
				else{
					// Current setup is completed
					DeleteCurrentWP();
					SetupENDID() = 0;
					sendOutputEvent(scm_nEventCompletedID);
				}
				break;
			default:
				break;
			}
			break;

		case 1:
			//Last action didnt succeed but it can be redone
			//TODO:Check for other options?other tools, etc to fix the problem
			m_nExecutionErrors++;
			if (m_nExecutionErrors < MAX_EXECUTION_RETRY){		
				sendOutputEvent(scm_nEventExecuteOPID);
				break;
			}
			// if execution failed too many times mark part as failed
			// Dont break and go into case 2

		case 2:
			//Last action failed and it cant be redone
			//Delete the current WP
			DeleteCurrentWP();
			//TODO: ENDID codes should be reviewed, but for now this feature is not supported so..
			SetupENDID() = 2;
			sendOutputEvent(scm_nEventCompletedID);
			break;

		default:
			//Wrong NextCode ID, shouldn't get here
			DEVLOG_ERROR("Wrong NextCode ID at L2_ExecutionManager \n");
			break;
		}
      break;
  }
}



