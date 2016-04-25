/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_StateTracker
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-12-04/EQUEROL - UJI - 
 ***     1.0: 2016-01-18/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_StateTracker.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_StateTracker_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_StateTracker, g_nStringIdL2_StateTracker)

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdServiceStateIn};

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdServiceStateOut, g_nStringIdDelay};

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdTIME};

const TForteInt16 FORTE_L2_StateTracker::scm_anEIWithIndexes[] = {0, 2, -1};
const TDataIOID FORTE_L2_StateTracker::scm_anEIWith[] = {0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdRSP, g_nStringIdTimeout};

const TDataIOID FORTE_L2_StateTracker::scm_anEOWith[] = {0, 255, 1, 255, 2, 255};
const TForteInt16 FORTE_L2_StateTracker::scm_anEOWithIndexes[] = {0, 2, -1, 4, -1, -1};
const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdUPDT, g_nStringIdIND, g_nStringIdStart, g_nStringIdStop};

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anInternalsNames[] = {g_nStringIdTOCounter, g_nStringIdMaxTO};

const CStringDictionary::TStringId FORTE_L2_StateTracker::scm_anInternalsTypeIds[] = {g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L2_StateTracker::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_StateTracker::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_StateTracker::setInitialValues(){
  TOCounter() = 0;
  MaxTO() = 10;
}

void FORTE_L2_StateTracker::alg_INIT_P(void){
QO() = true;
Delay() = CIEC_TIME("TIME#2000ms");
}

void FORTE_L2_StateTracker::alg_UPDT(void){
ServiceStateOut() = ServiceStateIn();
/* Reset timeouts counter*/
TOCounter() = 0;
}

void FORTE_L2_StateTracker::alg_DT1(void){
/* Periodic machine check*/
Delay() = CIEC_TIME("TIME#60000ms");
}

void FORTE_L2_StateTracker::alg_DT2(void){
/* A Machine is expected to answer within a second to a request state event*/
Delay() = CIEC_TIME("TIME#1000ms");
}

void FORTE_L2_StateTracker::alg_TO2(void){
TOCounter() = TOCounter()+1;
}

void FORTE_L2_StateTracker::alg_LOST(void){
/* We lost the communication with the Machine service*/
ServiceStateOut() = 0;

}

void FORTE_L2_StateTracker::alg_DINIT(void){
QO() = false;
}


void FORTE_L2_StateTracker::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_StateTracker::enterStateDINIT(void){
  m_nECCState = scm_nStateDINIT;
  alg_DINIT();
  sendOutputEvent( scm_nEventINITOID);
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L2_StateTracker::enterStateUPDT(void){
  m_nECCState = scm_nStateUPDT;
  sendOutputEvent( scm_nEventUPDTID);
}

void FORTE_L2_StateTracker::enterStateUPD(void){
  m_nECCState = scm_nStateUPD;
  alg_UPDT();
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L2_StateTracker::enterStateRequestState(void){
  m_nECCState = scm_nStateRequestState;
  sendOutputEvent( scm_nEventINDID);
  alg_DT2();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L2_StateTracker::enterStateKeepAlive(void){
  m_nECCState = scm_nStateKeepAlive;
  alg_DT1();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L2_StateTracker::enterStateRequesting(void){
  m_nECCState = scm_nStateRequesting;
}

void FORTE_L2_StateTracker::enterStateTO2(void){
  m_nECCState = scm_nStateTO2;
  alg_TO2();
}

void FORTE_L2_StateTracker::enterStateLostCommunication(void){
  m_nECCState = scm_nStateLostCommunication;
  alg_LOST();
}

void FORTE_L2_StateTracker::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT_P();
  sendOutputEvent( scm_nEventStartID);
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L2_StateTracker::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventINITID == pa_nEIID) && (QI()))
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUPDT:
        if(1)
          enterStateKeepAlive();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUPD:
        if(1)
          enterStateUPDT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRequestState:
        if(1)
          enterStateRequesting();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateKeepAlive:
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateRequestState();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateDINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRequesting:
        if(scm_nEventRSPID == pa_nEIID)
          enterStateUPD();
        else
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateTO2();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateDINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTO2:
        if(TOCounter() <= MaxTO())
          enterStateRequestState();
        else
        if(TOCounter() > MaxTO())
          enterStateLostCommunication();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLostCommunication:
        if(1)
          enterStateUPDT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateRequestState();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateDINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 9.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


