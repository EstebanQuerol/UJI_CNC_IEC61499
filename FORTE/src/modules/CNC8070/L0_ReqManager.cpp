/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_ReqManager
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - 
 ***     1.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L0_ReqManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_ReqManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_ReqManager, g_nStringIdL0_ReqManager)

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdRIDIn, g_nStringIdServiceState};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdENDOPID};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_ReqManager::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_L0_ReqManager::scm_anEIWith[] = {0, 255, 2, 255, 1, 255};
const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdUPDT};

const TDataIOID FORTE_L0_ReqManager::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_L0_ReqManager::scm_anEOWithIndexes[] = {0, -1, 2, -1, -1};
const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND, g_nStringIdCompleted, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anInternalsNames[] = {g_nStringIdExecutionRequested};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_L0_ReqManager::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L0_ReqManager::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L0_ReqManager::setInitialValues(){
  ExecutionRequested() = false;
}

void FORTE_L0_ReqManager::alg_INIT(void){
if((((ExecutionRequested() == true)))){
	ExecutionRequested() = false;
	/* TODO: Complete this algorithm to enable service recovery*/
	/* In process action will be lost*/
};
QO() = QI();
}

void FORTE_L0_ReqManager::alg_REQ(void){
// Verify if service is upif((ServiceState() == 1)){
	ExecutionRequested() = true;
}
else{
	// Service is not up or busy, reject execution request	// Mark operation as failed but repeatable; TODO: HANDLE the service down case in upper layers	ExecutionRequested() = false;
	ENDOPID() = 1;
};

}

void FORTE_L0_ReqManager::alg_UPDT(void){
/* TODO: improve error handling, add other states*/
if((RIDIn() == 0)){
	/* Execution success*/
	ENDOPID() = 0;
}
else
  if((RIDIn() == 1)){
	/* Execution interrupted*/
	ENDOPID() = 1;
}
else{
	/* Execution failed*/
	ENDOPID() = 2;
};
ExecutionRequested() = false;
}


void FORTE_L0_ReqManager::enterStateIDLE(void){
  m_nECCState = scm_nStateIDLE;
}

void FORTE_L0_ReqManager::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L0_ReqManager::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L0_ReqManager::enterStateExecutionRequested(void){
  m_nECCState = scm_nStateExecutionRequested;
}

void FORTE_L0_ReqManager::enterStateExecutionDone(void){
  m_nECCState = scm_nStateExecutionDone;
  alg_UPDT();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L0_ReqManager::enterStateServiceDown(void){
  m_nECCState = scm_nStateServiceDown;
  sendOutputEvent( scm_nEventCompletedID);
}

void FORTE_L0_ReqManager::enterStateStartExecution(void){
  m_nECCState = scm_nStateStartExecution;
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L0_ReqManager::enterStateLostIND(void){
  m_nECCState = scm_nStateLostIND;
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L0_ReqManager::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateIDLE:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(ExecutionRequested() == false)
          enterStateServiceDown();
        else
        if(ExecutionRequested() == true)
          enterStateStartExecution();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecutionRequested:
        if(scm_nEventUPDTID == pa_nEIID)
          enterStateExecutionDone();
        else
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateLostIND();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecutionDone:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateServiceDown:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateStartExecution:
        if(1)
          enterStateExecutionRequested();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLostIND:
        if(1)
          enterStateExecutionRequested();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 7.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


