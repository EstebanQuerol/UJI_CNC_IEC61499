/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_ChkService
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#include "CM_ChkService.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CM_ChkService_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CM_ChkService, g_nStringIdCM_ChkService)

const CStringDictionary::TStringId FORTE_CM_ChkService::scm_anDataInputNames[] = {g_nStringIdServiceState};

const CStringDictionary::TStringId FORTE_CM_ChkService::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_CM_ChkService::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_CM_ChkService::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_CM_ChkService::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const TForteInt16 FORTE_CM_ChkService::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_CM_ChkService::scm_anEventOutputNames[] = {g_nStringIdREQS, g_nStringIdUP, g_nStringIdDOWN, g_nStringIdBUSY};

const SFBInterfaceSpec FORTE_CM_ChkService::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

void FORTE_CM_ChkService::alg_INIT(void){

}

void FORTE_CM_ChkService::alg_REQ(void){

}


void FORTE_CM_ChkService::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_CM_ChkService::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  sendOutputEvent( scm_nEventREQSID);
}

void FORTE_CM_ChkService::enterStateUP(void){
  m_nECCState = scm_nStateUP;
  sendOutputEvent( scm_nEventUPID);
}

void FORTE_CM_ChkService::enterStateDOWN(void){
  m_nECCState = scm_nStateDOWN;
  sendOutputEvent( scm_nEventDOWNID);
}

void FORTE_CM_ChkService::enterStateBUSY(void){
  m_nECCState = scm_nStateBUSY;
  sendOutputEvent( scm_nEventBUSYID);
}

void FORTE_CM_ChkService::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if((scm_nEventRSPID == pa_nEIID) && (ServiceState() == 1))
          enterStateUP();
        else
        if((scm_nEventRSPID == pa_nEIID) && (ServiceState() == 0))
          enterStateDOWN();
        else
        if((scm_nEventRSPID == pa_nEIID) && (ServiceState() == 2))
          enterStateBUSY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDOWN:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateBUSY:
        if(1)
          enterStateSTART();
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


