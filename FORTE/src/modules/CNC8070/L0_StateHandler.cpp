/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_StateHandler
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_StateHandler.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_StateHandler_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_StateHandler, g_nStringIdL0_StateHandler)

const CStringDictionary::TStringId FORTE_L0_StateHandler::scm_anDataInputNames[] = {g_nStringIdCNCState};

const CStringDictionary::TStringId FORTE_L0_StateHandler::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_L0_StateHandler::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L0_StateHandler::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L0_StateHandler::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_L0_StateHandler::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_L0_StateHandler::scm_anEventOutputNames[] = {g_nStringIdOnReady, g_nStringIdOnNotReady, g_nStringIdOnInterrupted, g_nStringIdOnIntError, g_nStringIdOnExecution};

const SFBInterfaceSpec FORTE_L0_StateHandler::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

void FORTE_L0_StateHandler::alg_REQ(void){

}


void FORTE_L0_StateHandler::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L0_StateHandler::enterStateReady(void){
  m_nECCState = scm_nStateReady;
  alg_REQ();
  sendOutputEvent( scm_nEventOnReadyID);
}

void FORTE_L0_StateHandler::enterStateNotReady(void){
  m_nECCState = scm_nStateNotReady;
  alg_REQ();
  sendOutputEvent( scm_nEventOnNotReadyID);
}

void FORTE_L0_StateHandler::enterStateInterrupted(void){
  m_nECCState = scm_nStateInterrupted;
  alg_REQ();
  sendOutputEvent( scm_nEventOnInterruptedID);
}

void FORTE_L0_StateHandler::enterStateError(void){
  m_nECCState = scm_nStateError;
  alg_REQ();
  sendOutputEvent( scm_nEventOnIntErrorID);
}

void FORTE_L0_StateHandler::enterStateExecution(void){
  m_nECCState = scm_nStateExecution;
  alg_REQ();
  sendOutputEvent( scm_nEventOnExecutionID);
}

void FORTE_L0_StateHandler::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventREQID == pa_nEIID) && (CNCState() == 1))
          enterStateReady();
        else
        if((scm_nEventREQID == pa_nEIID) && (CNCState() == 0))
          enterStateNotReady();
        else
        if((scm_nEventREQID == pa_nEIID) && (CNCState() == 3))
          enterStateInterrupted();
        else
        if((scm_nEventREQID == pa_nEIID) && (CNCState() == 4))
          enterStateError();
        else
        if((scm_nEventREQID == pa_nEIID) && (CNCState() == 2))
          enterStateExecution();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReady:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNotReady:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInterrupted:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateError:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecution:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


