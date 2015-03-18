/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_Merge2Cmd
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-03-18/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_Merge2Cmd.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_Merge2Cmd_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_Merge2Cmd, g_nStringIdL1_Merge2Cmd)

const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anDataInputNames[] = {g_nStringIdCmd1, g_nStringIdL1MID1, g_nStringIdCmd2, g_nStringIdL1MID2};

const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anDataOutputNames[] = {g_nStringIdCmdOut, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_Merge2Cmd::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_L1_Merge2Cmd::scm_anEIWith[] = {0, 1, 255, 2, 3, 255};
const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anEventInputNames[] = {g_nStringIdE1, g_nStringIdE2};

const TDataIOID FORTE_L1_Merge2Cmd::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_Merge2Cmd::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_Merge2Cmd::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec FORTE_L1_Merge2Cmd::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L1_Merge2Cmd::alg_E1(void){
CmdOut() = Cmd1();
L1MIDOut() = L1MID1();
}

void FORTE_L1_Merge2Cmd::alg_E2(void){
CmdOut() = Cmd2();
L1MIDOut() = L1MID2();
}


void FORTE_L1_Merge2Cmd::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L1_Merge2Cmd::enterStateE1(void){
  m_nECCState = scm_nStateE1;
  alg_E1();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_L1_Merge2Cmd::enterStateE2(void){
  m_nECCState = scm_nStateE2;
  alg_E2();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_L1_Merge2Cmd::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventE1ID == pa_nEIID)
          enterStateE1();
        else
        if(scm_nEventE2ID == pa_nEIID)
          enterStateE2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateE1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateE2:
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


