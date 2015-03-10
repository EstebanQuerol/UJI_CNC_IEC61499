/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_L1Comm
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-02-25/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_L1Comm.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_L1Comm_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_L1Comm, g_nStringIdL2_L1Comm)

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anDataInputNames[] = {g_nStringIdOperationIn, g_nStringIdL1MIDIn, g_nStringIdENDOPIDIn};

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anDataOutputNames[] = {g_nStringIdOperationOut, g_nStringIdL1MIDOut, g_nStringIdDelay, g_nStringIdENDOPIDOut};

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdTIME, g_nStringIdUSINT};

const TForteInt16 FORTE_L2_L1Comm::scm_anEIWithIndexes[] = {0, -1, -1, 3};
const TDataIOID FORTE_L2_L1Comm::scm_anEIWith[] = {0, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP, g_nStringIdTimeout, g_nStringIdIND};

const TDataIOID FORTE_L2_L1Comm::scm_anEOWith[] = {0, 1, 255, 2, 255, 3, 255};
const TForteInt16 FORTE_L2_L1Comm::scm_anEOWithIndexes[] = {0, 3, -1, 5, -1};
const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anEventOutputNames[] = {g_nStringIdSend, g_nStringIdStart, g_nStringIdStop, g_nStringIdCompletedOP};

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anInternalsNames[] = {g_nStringIdTOCounter};

const CStringDictionary::TStringId FORTE_L2_L1Comm::scm_anInternalsTypeIds[] = {g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L2_L1Comm::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_L1Comm::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_L1Comm::setInitialValues(){
  TOCounter() = 0;
}

void FORTE_L2_L1Comm::alg_SEND(void){
OperationOut() = OperationIn();
L1MIDOut() = L1MIDIn();
}

void FORTE_L2_L1Comm::alg_DT(void){
Delay() = CIEC_TIME("TIME#1500ms");
}

void FORTE_L2_L1Comm::alg_RESET(void){
TOCounter() = 0;
}

void FORTE_L2_L1Comm::alg_TO(void){
TOCounter() = TOCounter()+1;
}

void FORTE_L2_L1Comm::alg_FAIL(void){
TOCounter() = 0;
/* Mark operation as failed but repeatable*/
ENDOPIDOut() = 1;
}

void FORTE_L2_L1Comm::alg_IND(void){
ENDOPIDOut() = ENDOPIDIn();
}


void FORTE_L2_L1Comm::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_L1Comm::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_SEND();
  sendOutputEvent( scm_nEventSendID);
  alg_DT();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L2_L1Comm::enterStateWait(void){
  m_nECCState = scm_nStateWait;
}

void FORTE_L2_L1Comm::enterStateSEND_OK(void){
  m_nECCState = scm_nStateSEND_OK;
  alg_RESET();
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L2_L1Comm::enterStateTimeout(void){
  m_nECCState = scm_nStateTimeout;
  alg_TO();
}

void FORTE_L2_L1Comm::enterStateRETRY(void){
  m_nECCState = scm_nStateRETRY;
}

void FORTE_L2_L1Comm::enterStateFAIL(void){
  m_nECCState = scm_nStateFAIL;
  alg_FAIL();
  sendOutputEvent( scm_nEventCompletedOPID);
}

void FORTE_L2_L1Comm::enterStateIND(void){
  m_nECCState = scm_nStateIND;
  alg_IND();
  sendOutputEvent( scm_nEventCompletedOPID);
}

void FORTE_L2_L1Comm::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventINDID == pa_nEIID)
          enterStateIND();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateWait();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWait:
        if(scm_nEventRSPID == pa_nEIID)
          enterStateSEND_OK();
        else
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateTimeout();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSEND_OK:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTimeout:
        if(TOCounter() > 3)
          enterStateFAIL();
        else
        if(TOCounter() <= 3)
          enterStateRETRY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRETRY:
        if(1)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateFAIL:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIND:
        if(1)
          enterStateSTART();
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


