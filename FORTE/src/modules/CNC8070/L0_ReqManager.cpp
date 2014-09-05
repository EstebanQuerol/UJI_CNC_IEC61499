/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_ReqManager
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_ReqManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_ReqManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_ReqManager, g_nStringIdL0_ReqManager)

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdRIDIn};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdRIDOut};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_ReqManager::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_L0_ReqManager::scm_anEIWith[] = {0, 255, 0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdUPDT};

const TDataIOID FORTE_L0_ReqManager::scm_anEOWith[] = {0, 255, 0, 255, 0, 1, 255};
const TForteInt16 FORTE_L0_ReqManager::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anInternalsNames[] = {g_nStringIdExecutionRequested};

const CStringDictionary::TStringId FORTE_L0_ReqManager::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_L0_ReqManager::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
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
ExecutionRequested() = true;
}

void FORTE_L0_ReqManager::alg_UPDT(void){
if((((ExecutionRequested() == true) && (RIDIn() == 0)))){
	/* Execution success*/
	ExecutionRequested() = false;
}
else{
	/* Execution failed*/
};
RIDOut() = RIDIn();
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
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L0_ReqManager::enterStateExecutionRequested(void){
  m_nECCState = scm_nStateExecutionRequested;
}

void FORTE_L0_ReqManager::enterStateExecutionDone(void){
  m_nECCState = scm_nStateExecutionDone;
  alg_UPDT();
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
        if(1)
          enterStateExecutionRequested();
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
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecutionDone:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


