/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_State
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-08-25/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_State.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_State_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_State, g_nStringIdL0_State)

const CStringDictionary::TStringId FORTE_L0_State::scm_anDataInputNames[] = {g_nStringIdStateIn};

const CStringDictionary::TStringId FORTE_L0_State::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_State::scm_anDataOutputNames[] = {g_nStringIdStateOut, g_nStringIdServiceState};

const CStringDictionary::TStringId FORTE_L0_State::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_State::scm_anEIWithIndexes[] = {-1, -1, 0};
const TDataIOID FORTE_L0_State::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L0_State::scm_anEventInputNames[] = {g_nStringIdREQ1, g_nStringIdREQ2, g_nStringIdUPDT};

const TDataIOID FORTE_L0_State::scm_anEOWith[] = {1, 255, 1, 255, 0, 255};
const TForteInt16 FORTE_L0_State::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_L0_State::scm_anEventOutputNames[] = {g_nStringIdCNF1, g_nStringIdCNF2, g_nStringIdUPDTO};

const CStringDictionary::TStringId FORTE_L0_State::scm_anInternalsNames[] = {g_nStringIdCNCState, g_nStringIdCurrentServiceState};

const CStringDictionary::TStringId FORTE_L0_State::scm_anInternalsTypeIds[] = {g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L0_State::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L0_State::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L0_State::setInitialValues(){
  StateOut() = 0;
  ServiceState() = 0;
  CNCState() = 0;
  CurrentServiceState() = 0;
}

void FORTE_L0_State::alg_REQ(void){
ServiceState() = CurrentServiceState();
}

void FORTE_L0_State::alg_UPDT(void){
CNCState() = StateIn();
StateOut() = CNCState();
if((((CNCState() == 1)))){
	CurrentServiceState() = 1;
}
else
  if((((CNCState() == 2)))){
	CurrentServiceState() = 2;
}
else{
	CurrentServiceState() = 0;
};
}


void FORTE_L0_State::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L0_State::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ();
  sendOutputEvent( scm_nEventCNF1ID);
}

void FORTE_L0_State::enterStateUPDT(void){
  m_nECCState = scm_nStateUPDT;
  alg_UPDT();
  sendOutputEvent( scm_nEventUPDTOID);
}

void FORTE_L0_State::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  alg_REQ();
  sendOutputEvent( scm_nEventCNF2ID);
}

void FORTE_L0_State::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateREQ1();
        else
        if(scm_nEventUPDTID == pa_nEIID)
          enterStateUPDT();
        else
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateREQ2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUPDT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


