/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_Merge2E2USINT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#include "CM_Merge2E2USINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CM_Merge2E2USINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CM_Merge2E2USINT, g_nStringIdCM_Merge2E2USINT)

const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anDataInputNames[] = {g_nStringIdE1In, g_nStringIdE2In};

const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anDataInputTypeIds[] = {g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anDataOutputNames[] = {g_nStringIdOut};

const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_CM_Merge2E2USINT::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_CM_Merge2E2USINT::scm_anEIWith[] = {0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anEventInputNames[] = {g_nStringIdE1, g_nStringIdE2};

const TDataIOID FORTE_CM_Merge2E2USINT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_CM_Merge2E2USINT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_CM_Merge2E2USINT::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec FORTE_CM_Merge2E2USINT::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_CM_Merge2E2USINT::alg_E1(void){
Out() = E1In();
}

void FORTE_CM_Merge2E2USINT::alg_E2(void){
Out() = E2In();
}


void FORTE_CM_Merge2E2USINT::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_CM_Merge2E2USINT::enterStateIN1(void){
  m_nECCState = scm_nStateIN1;
  alg_E1();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_CM_Merge2E2USINT::enterStateIN2(void){
  m_nECCState = scm_nStateIN2;
  alg_E2();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_CM_Merge2E2USINT::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventE1ID == pa_nEIID)
          enterStateIN1();
        else
        if(scm_nEventE2ID == pa_nEIID)
          enterStateIN2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIN1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIN2:
        if(1)
          enterStateSTART();
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


