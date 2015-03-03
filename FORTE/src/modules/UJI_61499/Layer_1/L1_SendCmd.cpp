/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_SendCmd
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_SendCmd.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_SendCmd_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_SendCmd, g_nStringIdL1_SendCmd)

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anDataInputNames[] = {g_nStringIdCmdIn, g_nStringIdL1MID};

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anDataOutputNames[] = {g_nStringIdCmdOut, g_nStringIdDelay, g_nStringIdENDOPID};

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdTIME, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_SendCmd::scm_anEIWithIndexes[] = {0, -1, -1};
const TDataIOID FORTE_L1_SendCmd::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP, g_nStringIdTimeout};

const TDataIOID FORTE_L1_SendCmd::scm_anEOWith[] = {0, 255, 2, 255, 1, 255};
const TForteInt16 FORTE_L1_SendCmd::scm_anEOWithIndexes[] = {0, 2, 4, -1, -1};
const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND, g_nStringIdStart, g_nStringIdStop};

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anInternalsNames[] = {g_nStringIdTOCounter};

const CStringDictionary::TStringId FORTE_L1_SendCmd::scm_anInternalsTypeIds[] = {g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L1_SendCmd::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L1_SendCmd::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L1_SendCmd::setInitialValues(){
  TOCounter() = 0;
}

void FORTE_L1_SendCmd::alg_REQ(void){
CmdOut() = CmdIn();
}

void FORTE_L1_SendCmd::alg_START(void){
Delay() = CIEC_TIME("TIME#1500ms");
}

void FORTE_L1_SendCmd::alg_TO(void){
TOCounter() = TOCounter()+1;
}

void FORTE_L1_SendCmd::alg_RSP(void){
TOCounter() = 0;
}

void FORTE_L1_SendCmd::alg_FAIL(void){
TOCounter() = 0;
ENDOPID() = 1;
}


void FORTE_L1_SendCmd::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L1_SendCmd::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
  alg_START();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L1_SendCmd::enterStateWAIT(void){
  m_nECCState = scm_nStateWAIT;
}

void FORTE_L1_SendCmd::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L1_SendCmd::enterStateTIMEOUT(void){
  m_nECCState = scm_nStateTIMEOUT;
  alg_TO();
}

void FORTE_L1_SendCmd::enterStateRETRY(void){
  m_nECCState = scm_nStateRETRY;
}

void FORTE_L1_SendCmd::enterStateFAIL(void){
  m_nECCState = scm_nStateFAIL;
  alg_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L1_SendCmd::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventREQID == pa_nEIID) && (L1MID() == 150))
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWAIT:
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateTIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTIMEOUT:
        if(TOCounter() <= 3)
          enterStateRETRY();
        else
        if(TOCounter() > 3)
          enterStateFAIL();
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
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 6.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


