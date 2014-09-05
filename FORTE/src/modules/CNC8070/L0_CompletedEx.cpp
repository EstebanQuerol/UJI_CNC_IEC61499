/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CompletedEx
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_CompletedEx.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_CompletedEx_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_CompletedEx, g_nStringIdL0_CompletedEx)

const CStringDictionary::TStringId FORTE_L0_CompletedEx::scm_anDataOutputNames[] = {g_nStringIdRID};

const CStringDictionary::TStringId FORTE_L0_CompletedEx::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_L0_CompletedEx::scm_anEIWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_L0_CompletedEx::scm_anEventInputNames[] = {g_nStringIdOnReady, g_nStringIdOnExecuting, g_nStringIdOnNotReady};

const TDataIOID FORTE_L0_CompletedEx::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L0_CompletedEx::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L0_CompletedEx::scm_anEventOutputNames[] = {g_nStringIdSuccess};

const SFBInterfaceSpec FORTE_L0_CompletedEx::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L0_CompletedEx::alg_Ready(void){
RID() = 0;
}


void FORTE_L0_CompletedEx::enterStateNotReady(void){
  m_nECCState = scm_nStateNotReady;
}

void FORTE_L0_CompletedEx::enterStateReady(void){
  m_nECCState = scm_nStateReady;
  alg_Ready();
  sendOutputEvent( scm_nEventSuccessID);
}

void FORTE_L0_CompletedEx::enterStateExecuting(void){
  m_nECCState = scm_nStateExecuting;
}

void FORTE_L0_CompletedEx::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateNotReady:
        if(scm_nEventOnReadyID == pa_nEIID)
          enterStateReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReady:
        if(scm_nEventOnExecutingID == pa_nEIID)
          enterStateExecuting();
        else
        if(scm_nEventOnNotReadyID == pa_nEIID)
          enterStateNotReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecuting:
        if(scm_nEventOnReadyID == pa_nEIID)
          enterStateReady();
        else
        if(scm_nEventOnNotReadyID == pa_nEIID)
          enterStateNotReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


