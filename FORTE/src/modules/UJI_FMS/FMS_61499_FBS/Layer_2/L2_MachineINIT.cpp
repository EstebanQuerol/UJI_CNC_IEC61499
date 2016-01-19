/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineINIT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-01-15/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_MachineINIT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_MachineINIT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_MachineINIT, g_nStringIdL2_MachineINIT)

const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anDataInputNames[] = {g_nStringIdINIT_QI, g_nStringIdCOM_INIT_QI, g_nStringIdL0_INIT_QI, g_nStringIdL2_INIT_QI};

const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anDataOutputNames[] = {g_nStringIdINIT_STATE, g_nStringIdINIT_QO, g_nStringIdCOM_INIT_QO, g_nStringIdL0_INIT_QO, g_nStringIdL2_INIT_QO, g_nStringIdTODelay};

const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdTIME};

const TForteInt16 FORTE_L2_MachineINIT::scm_anEIWithIndexes[] = {0, 2, 4, 6, -1};
const TDataIOID FORTE_L2_MachineINIT::scm_anEIWith[] = {0, 255, 1, 255, 2, 255, 3, 255};
const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCOM_INIT_RSP, g_nStringIdL0_INIT_RSP, g_nStringIdL2_INIT_RSP, g_nStringIdTimeOut};

const TDataIOID FORTE_L2_MachineINIT::scm_anEOWith[] = {0, 1, 255, 2, 255, 3, 255, 4, 255, 5, 255};
const TForteInt16 FORTE_L2_MachineINIT::scm_anEOWithIndexes[] = {0, 3, 5, 7, 9, -1, -1};
const CStringDictionary::TStringId FORTE_L2_MachineINIT::scm_anEventOutputNames[] = {g_nStringIdIND, g_nStringIdCOM_INIT, g_nStringIdL0_INIT, g_nStringIdL2_INIT, g_nStringIdStart, g_nStringIdStop};

const SFBInterfaceSpec FORTE_L2_MachineINIT::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  6,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  6,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L2_MachineINIT::alg_COM_INIT_P(void){
COM_INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_COM_INIT_FAIL(void){
INIT_STATE() = "Unable to start communications with L3,L1 and L0";
INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_L0_INIT_P(void){
L0_INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_L0_INIT_FAIL(void){
INIT_STATE() = "Unable to initialize L0 device";
INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_L2_INIT_P(void){
L2_INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_L2_INIT_FAIL(void){
INIT_STATE() = "Unable to initialize machine own FBs";
INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_INIT_OK(void){
INIT_STATE() = "Initialization OK";
INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_Delay(void){
TODelay() = CIEC_TIME("TIME#30s");
}

void FORTE_L2_MachineINIT::alg_INIT_P_TO(void){
INIT_STATE() = "Initialization timeout (30s timer expired)";
INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_L2_INIT_M(void){
L2_INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_L2_DINT_FAIL(void){
INIT_STATE() = "Unable to stop machine own FBs";
INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_L0_INIT_M(void){
L0_INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_L0_DINT_FAIL(void){
INIT_STATE() = "Unable to desinitialize L0 device";
INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_COM_INIT_M(void){
COM_INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_COM_DINT_FAIL(void){
INIT_STATE() = "Unable to stop communications with L3,L1 and L0";
INIT_QO() = true;
}

void FORTE_L2_MachineINIT::alg_DINT_OK(void){
INIT_STATE() = "Desinitialization OK";
INIT_QO() = false;
}

void FORTE_L2_MachineINIT::alg_INIT_M_TO(void){
INIT_STATE() = "Desinitialization timeout (30s timer expired)";
INIT_QO() = true;
}


void FORTE_L2_MachineINIT::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_MachineINIT::enterStateINITIALIZING_COM(void){
  m_nECCState = scm_nStateINITIALIZING_COM;
  alg_COM_INIT_P();
  sendOutputEvent( scm_nEventCOM_INITID);
}

void FORTE_L2_MachineINIT::enterStateDESINITIALIZING_L0(void){
  m_nECCState = scm_nStateDESINITIALIZING_L0;
  alg_L0_INIT_M();
  sendOutputEvent( scm_nEventL0_INITID);
}

void FORTE_L2_MachineINIT::enterStateINIT_COMPLETE(void){
  m_nECCState = scm_nStateINIT_COMPLETE;
  alg_INIT_OK();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateINIT_SINK(void){
  m_nECCState = scm_nStateINIT_SINK;
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L2_MachineINIT::enterStateINITIALIZING_L0(void){
  m_nECCState = scm_nStateINITIALIZING_L0;
  alg_L0_INIT_P();
  sendOutputEvent( scm_nEventL0_INITID);
}

void FORTE_L2_MachineINIT::enterStateCOM_INIT_FAIL(void){
  m_nECCState = scm_nStateCOM_INIT_FAIL;
  alg_COM_INIT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateL0_INIT_FAIL(void){
  m_nECCState = scm_nStateL0_INIT_FAIL;
  alg_L0_INIT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateINITIALIZING_L2(void){
  m_nECCState = scm_nStateINITIALIZING_L2;
  alg_L2_INIT_P();
  sendOutputEvent( scm_nEventL2_INITID);
}

void FORTE_L2_MachineINIT::enterStateL2_INIT_FAIL(void){
  m_nECCState = scm_nStateL2_INIT_FAIL;
  alg_L2_INIT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateDESINITIALIZING_COM(void){
  m_nECCState = scm_nStateDESINITIALIZING_COM;
  alg_COM_INIT_M();
  sendOutputEvent( scm_nEventCOM_INITID);
}

void FORTE_L2_MachineINIT::enterStateDESINITIALIZING_L2(void){
  m_nECCState = scm_nStateDESINITIALIZING_L2;
  alg_L2_INIT_M();
  sendOutputEvent( scm_nEventL2_INITID);
}

void FORTE_L2_MachineINIT::enterStateStartTimer(void){
  m_nECCState = scm_nStateStartTimer;
  alg_Delay();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L2_MachineINIT::enterStateINIT_TIMEOUT(void){
  m_nECCState = scm_nStateINIT_TIMEOUT;
  alg_INIT_P_TO();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateDINIT_COMPLETE(void){
  m_nECCState = scm_nStateDINIT_COMPLETE;
  alg_DINT_OK();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateState(void){
  m_nECCState = scm_nStateState;
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L2_MachineINIT::enterStateDINIT_L2_FAIL(void){
  m_nECCState = scm_nStateDINIT_L2_FAIL;
  alg_L2_DINT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateDINT_L0_FAIL(void){
  m_nECCState = scm_nStateDINT_L0_FAIL;
  alg_L0_DINT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateDINT_COM_FAIL(void){
  m_nECCState = scm_nStateDINT_COM_FAIL;
  alg_COM_DINT_FAIL();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::enterStateDINT_TIMEOUT(void){
  m_nECCState = scm_nStateDINT_TIMEOUT;
  alg_INIT_M_TO();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineINIT::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateStartTimer();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINITIALIZING_COM:
        if((scm_nEventCOM_INIT_RSPID == pa_nEIID) && (COM_INIT_QI()))
          enterStateINITIALIZING_L0();
        else
        if((scm_nEventCOM_INIT_RSPID == pa_nEIID) && (COM_INIT_QI() == false))
          enterStateCOM_INIT_FAIL();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateINIT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDESINITIALIZING_L0:
        if((scm_nEventL0_INIT_RSPID == pa_nEIID) && (L0_INIT_QI() == false))
          enterStateDESINITIALIZING_COM();
        else
        if(scm_nEventL0_INIT_RSPID == pa_nEIID)
          enterStateDINT_L0_FAIL();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateDINT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT_COMPLETE:
        if(1)
          enterStateINIT_SINK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT_SINK:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINITIALIZING_L0:
        if((scm_nEventL0_INIT_RSPID == pa_nEIID) && (L0_INIT_QI()))
          enterStateINITIALIZING_L2();
        else
        if((scm_nEventL0_INIT_RSPID == pa_nEIID) && (L0_INIT_QI() == false))
          enterStateL0_INIT_FAIL();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateINIT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCOM_INIT_FAIL:
        if(1)
          enterStateINIT_SINK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateL0_INIT_FAIL:
        if(1)
          enterStateINIT_SINK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINITIALIZING_L2:
        if((scm_nEventL2_INIT_RSPID == pa_nEIID) && (L0_INIT_QI() == false))
          enterStateL2_INIT_FAIL();
        else
        if((scm_nEventL2_INIT_RSPID == pa_nEIID) && (L2_INIT_QI()))
          enterStateINIT_COMPLETE();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateINIT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateL2_INIT_FAIL:
        if(1)
          enterStateINIT_SINK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDESINITIALIZING_COM:
        if((scm_nEventCOM_INIT_RSPID == pa_nEIID) && (COM_INIT_QI() == false))
          enterStateDINIT_COMPLETE();
        else
        if((scm_nEventCOM_INIT_RSPID == pa_nEIID) && (COM_INIT_QI()))
          enterStateDINT_COM_FAIL();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateDINT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDESINITIALIZING_L2:
        if((scm_nEventL2_INIT_RSPID == pa_nEIID) && (L2_INIT_QI() == false))
          enterStateDESINITIALIZING_L0();
        else
        if((scm_nEventL2_INIT_RSPID == pa_nEIID) && (L2_INIT_QI()))
          enterStateDINIT_L2_FAIL();
        else
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateDINT_TIMEOUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateStartTimer:
        if(INIT_QI())
          enterStateINITIALIZING_COM();
        else
        if(INIT_QI() == false)
          enterStateDESINITIALIZING_L2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT_TIMEOUT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINIT_COMPLETE:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINIT_L2_FAIL:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINT_L0_FAIL:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINT_COM_FAIL:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINT_TIMEOUT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 19.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


