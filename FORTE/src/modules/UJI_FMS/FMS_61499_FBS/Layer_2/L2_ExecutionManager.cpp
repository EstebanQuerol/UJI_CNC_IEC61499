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

const CStringDictionary::TStringId FORTE_L2_ExecutionManager::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdOperation, g_nStringIdL1MID, g_nStringIdENDSetupID};

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
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L2_ExecutionManager::DeleteCurrentWP(){
	//After deserialization new objects are created once they are used they must be deleted
	if (m_poIArchive != NULL){
		m_poIArchive->delete_created_pointers();
		delete m_poIArchive;
		m_poIArchive = NULL;
	}
	//Reset input string stream
	m_ssIStringStream.clear();
	m_ssIStringStream.seekg(0);
	//Reset internal variables
	m_nPartState = PART_NOT_FIXED;
	m_nExecutionErrors = 0;
	m_bSetupLoaded = FALSE;
}

void FORTE_L2_ExecutionManager::RetrieveWP(){
	if (m_bSetupLoaded){
		// A plan is currently loaded but a new renew event arrived
		// Delete the old one before setting up the new
		DeleteCurrentWP();
	}
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (Setup().length() + 1));
	if (pacTempString != NULL){
		if (-1 != Setup().toString(pacTempString, static_cast<unsigned int>(Setup().length() + 1), 1)){
			m_ssIStringStream.str(std::string(pacTempString));
			m_poIArchive = new boost::archive::text_iarchive(m_ssIStringStream);
			if (m_poIArchive != NULL){
				(*m_poIArchive) >> m_poCurrentWP;
				m_itCurrentElement = m_poCurrentWP->get_itsElements()->get_theList()->begin();
				m_bSetupLoaded = TRUE;
			}
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while deserializing in L3_ExecutionManager\n");
	}
}

iso14649::workingstep * FORTE_L2_ExecutionManager::GetWorkingStep(){
	const std::type_info &type = typeid((**m_itCurrentElement));
	if (type == typeid(iso14649::machiningWorkingstep))
		return (iso14649::machiningWorkingstep *)(*m_itCurrentElement);
	if (type == typeid(iso14649::workplan)){
		//TODO
	}
	return NULL;
}

TForteUInt8 FORTE_L2_ExecutionManager::GetWSL1MID(iso14649::workingstep * obj){
	iso14649::machiningWorkingstep * l_machinigWS;
	iso14649::rapidMovement * l_rapidmovWS;
	l_machinigWS = dynamic_cast<iso14649::machiningWorkingstep *>(obj);
	if (l_machinigWS != NULL){
		if (l_machinigWS->get_itsFeature()->isA(iso14649::planarFace_E))
			return L1MID_PLANAR_FACE;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::openPocket_E))
			return L1MID_OPEN_POCKET;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::closedPocket_E))
			return L1MID_CLOSED_POCKET;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::roundHole_E))
			return L1MID_ROUND_HOLE;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::slot_E))
			return L1MID_SLOT;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::step_E))
			return L1MID_STEP;
		if (l_machinigWS->get_itsFeature()->isA(iso14649::generalOutsideProfile_E))
			return L1MID_GENERAL_OUT_PROFILE;
	}
	l_rapidmovWS = dynamic_cast<iso14649::rapidMovement *>(obj);
	if (l_rapidmovWS != NULL){
		//TODO
	}
	//Send not valid as default if the type is not supported
	return L1MID_NOT_VALID;
}
std::string FORTE_L2_ExecutionManager::stringSerialize(const iso14649::setup * obj){
	//Boost Serialization
	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << obj;
	return oss.str();
}

std::string FORTE_L2_ExecutionManager::stringSerialize(const iso14649::workingstep * obj){
	//Boost Serialization
	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << obj;
	return oss.str();
}
void FORTE_L2_ExecutionManager::executeEvent(int pa_nEIID){
	iso14649::setup * l_setup = NULL;
	iso14649::workingstep * l_workingstep = NULL;
  switch(pa_nEIID){
    case scm_nEventINITID:
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
    case scm_nEventRENEWID:
		RetrieveWP();
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
				l_setup = GetSetup();
				if (l_setup != NULL){
					Operation() = stringSerialize(l_setup).c_str();
					L1MID() = L1MID_SETUP;
				}
				else{
					DEVLOG_ERROR("L2_ExecutionManager can't retrieve the setup\n");
					Operation() = "";
					L1MID() = L1MID_NOT_VALID;
				}
				sendOutputEvent(scm_nEventExecuteOPID);
				break;
			case PART_BEING_FIXED:
				//Part fixing succeed, start machining it
				m_nPartState = PART_FIXED;
				//Don't break and do next case
			case PART_FIXED:
				if (ElementsToDo()){
					l_workingstep = GetWorkingStep();
					if (l_workingstep != NULL){
						Operation() = stringSerialize(l_workingstep).c_str();
						L1MID() = GetWSL1MID(l_workingstep);
						m_itCurrentElement++; //Advance fordward in the elements list
					}else{
						DEVLOG_ERROR("L2_ExecutionManager can't retrieve the workingstep\n");
						Operation() = "";
						L1MID() = L1MID_NOT_VALID;
					}
					sendOutputEvent(scm_nEventExecuteOPID);
				}
				else{
					// Current setup is completed
					DeleteCurrentWP();
					ENDSetupID() = 0;
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
			ENDSetupID() = 2;
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



