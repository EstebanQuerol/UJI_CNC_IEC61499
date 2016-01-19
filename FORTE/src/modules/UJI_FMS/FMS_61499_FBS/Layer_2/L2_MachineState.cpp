/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineState
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-01-18/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_MachineState.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_MachineState_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_MachineState, g_nStringIdL2_MachineState)

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anDataInputNames[] = {g_nStringIdEXT_INIT_QI, g_nStringIdM_INIT_QI, g_nStringIdM_INIT_STATE, g_nStringIdCURRENT_PARTINFO, g_nStringIdM_ERROR_STATE};

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anDataOutputNames[] = {g_nStringIdMUI_STATE, g_nStringIdMUI_MSG, g_nStringIdMUI_PART_ID, g_nStringIdMUI_PART_FAMILY, g_nStringIdMUI_PART_TYPE, g_nStringIdM_INIT_QO, g_nStringIdERROR_STATE};

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_L2_MachineState::scm_anEIWithIndexes[] = {0, 2, 5, -1, 7};
const TDataIOID FORTE_L2_MachineState::scm_anEIWith[] = {0, 255, 1, 2, 255, 3, 255, 4, 255};
const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anEventInputNames[] = {g_nStringIdEXT_INIT, g_nStringIdM_INIT_RSP, g_nStringIdM_BUSY, g_nStringIdM_FREE, g_nStringIdM_ERROR};

const TDataIOID FORTE_L2_MachineState::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 5, 255, 6, 255};
const TForteInt16 FORTE_L2_MachineState::scm_anEOWithIndexes[] = {0, 6, -1, 8, -1};
const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anEventOutputNames[] = {g_nStringIdMUI_IND, g_nStringIdM_INIT, g_nStringIdFREE, g_nStringIdERROR};

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anInternalsNames[] = {g_nStringIdinitRequested};

const CStringDictionary::TStringId FORTE_L2_MachineState::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_L2_MachineState::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  7,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_MachineState::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_MachineState::setInitialValues(){
  initRequested() = false;
}

void FORTE_L2_MachineState::alg_INIT_START(void){
M_INIT_QO() = true;
MUI_STATE() = "Initializing";
MUI_MSG() = "Initializing machine...";
}

void FORTE_L2_MachineState::alg_INIT_END(void){
MUI_MSG() = M_INIT_STATE();
MUI_PART_ID() = 0;
MUI_PART_FAMILY() = 0;
MUI_PART_TYPE() = 0;
}

void FORTE_L2_MachineState::alg_IDLE_ENTER(void){
MUI_STATE() = "IDLE";
}

void FORTE_L2_MachineState::alg_ERROR_ENTER(void){
MUI_STATE() = "ERROR";
}

void FORTE_L2_MachineState::alg_DINIT_START(void){
M_INIT_QO() = false;
MUI_STATE() = "Desinitializing";
MUI_MSG() = "Desinitializing machine...";
ERROR_STATE() = false;
}

void FORTE_L2_MachineState::alg_ENTER_HALT(void){
MUI_STATE() = "HALT";
}

void FORTE_L2_MachineState::alg_DINIT_END(void){
MUI_MSG() = M_INIT_STATE();
}

void FORTE_L2_MachineState::alg_ENTER_BUSY(void){
MUI_STATE() = "BUSY";
}

void FORTE_L2_MachineState::alg_ERROR_KO(void){
ERROR_STATE() = M_ERROR_STATE();
MUI_MSG() = "An error occurred";
}

void FORTE_L2_MachineState::alg_HOLD_INIT(void){
initRequested() = true;
MUI_MSG() = "Desinitialization request registered";
}

void FORTE_L2_MachineState::alg_TO_FREE(void){
MUI_MSG() = "Part completed";
MUI_PART_ID() = 0;
MUI_PART_FAMILY() = 0;
MUI_PART_TYPE() = 0;
}

void FORTE_L2_MachineState::alg_ERROR_OK(void){
ERROR_STATE() = M_ERROR_STATE();
MUI_MSG() = "Recovered from an error";
}

void FORTE_L2_MachineState::alg_TO_BUSY(void){
MUI_MSG() = "New part arrived";
MUI_PART_ID() = CURRENT_PARTINFO()[0];
MUI_PART_FAMILY() = CURRENT_PARTINFO()[1];
MUI_PART_TYPE() = CURRENT_PARTINFO()[2];
}

void FORTE_L2_MachineState::alg_TO_DINIT(void){
MUI_PART_ID() = 0;
MUI_PART_FAMILY() = 0;
MUI_PART_TYPE() = 0;
}


void FORTE_L2_MachineState::enterStateHALT(void){
  m_nECCState = scm_nStateHALT;
  alg_ENTER_HALT();
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateDESINITIALIZING(void){
  m_nECCState = scm_nStateDESINITIALIZING;
  alg_DINIT_START();
  sendOutputEvent( scm_nEventERRORID);
  sendOutputEvent( scm_nEventM_INITID);
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateIDLE(void){
  m_nECCState = scm_nStateIDLE;
  alg_IDLE_ENTER();
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateBUSY(void){
  m_nECCState = scm_nStateBUSY;
  alg_ENTER_BUSY();
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateERROR(void){
  m_nECCState = scm_nStateERROR;
  alg_ERROR_ENTER();
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateINITIALIZING_COMPLETE(void){
  m_nECCState = scm_nStateINITIALIZING_COMPLETE;
  alg_INIT_END();
}

void FORTE_L2_MachineState::enterStateINITIALIZING_START(void){
  m_nECCState = scm_nStateINITIALIZING_START;
  alg_INIT_START();
  sendOutputEvent( scm_nEventM_INITID);
  sendOutputEvent( scm_nEventMUI_INDID);
}

void FORTE_L2_MachineState::enterStateDINIT_COMPLETE(void){
  m_nECCState = scm_nStateDINIT_COMPLETE;
  alg_DINIT_END();
}

void FORTE_L2_MachineState::enterStateSEND_FREE(void){
  m_nECCState = scm_nStateSEND_FREE;
  alg_TO_FREE();
  sendOutputEvent( scm_nEventFREEID);
}

void FORTE_L2_MachineState::enterStateERROR_OK(void){
  m_nECCState = scm_nStateERROR_OK;
  alg_ERROR_OK();
  sendOutputEvent( scm_nEventERRORID);
}

void FORTE_L2_MachineState::enterStateERROR_KO(void){
  m_nECCState = scm_nStateERROR_KO;
  alg_ERROR_KO();
  sendOutputEvent( scm_nEventERRORID);
}

void FORTE_L2_MachineState::enterStateHOLD_INIT(void){
  m_nECCState = scm_nStateHOLD_INIT;
  alg_HOLD_INIT();
}

void FORTE_L2_MachineState::enterStateTO_BUSY(void){
  m_nECCState = scm_nStateTO_BUSY;
  alg_TO_BUSY();
}

void FORTE_L2_MachineState::enterStateTO_DINIT(void){
  m_nECCState = scm_nStateTO_DINIT;
  alg_TO_DINIT();
}

void FORTE_L2_MachineState::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateHALT:
        if((scm_nEventEXT_INITID == pa_nEIID) && (EXT_INIT_QI()))
          enterStateINITIALIZING_START();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDESINITIALIZING:
        if(scm_nEventM_INIT_RSPID == pa_nEIID)
          enterStateDINIT_COMPLETE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIDLE:
        if((scm_nEventEXT_INITID == pa_nEIID) && (EXT_INIT_QI() == false))
          enterStateDESINITIALIZING();
        else
        if((scm_nEventM_ERRORID == pa_nEIID) && (M_ERROR_STATE() == false))
          enterStateERROR_KO();
        else
        if((scm_nEventM_ERRORID == pa_nEIID) && (M_ERROR_STATE()))
          enterStateERROR_OK();
        else
        if(scm_nEventM_BUSYID == pa_nEIID)
          enterStateTO_BUSY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateBUSY:
        if((scm_nEventM_FREEID == pa_nEIID) && (initRequested() == false))
          enterStateSEND_FREE();
        else
        if((scm_nEventM_ERRORID == pa_nEIID) && (M_ERROR_STATE() == false))
          enterStateERROR_KO();
        else
        if((scm_nEventEXT_INITID == pa_nEIID) && (EXT_INIT_QI() == false))
          enterStateHOLD_INIT();
        else
        if((scm_nEventM_FREEID == pa_nEIID) && (initRequested()))
          enterStateTO_DINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateERROR:
        if((scm_nEventEXT_INITID == pa_nEIID) && (EXT_INIT_QI() == false))
          enterStateDESINITIALIZING();
        else
        if((scm_nEventM_ERRORID == pa_nEIID) && (M_ERROR_STATE()))
          enterStateERROR_OK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINITIALIZING_COMPLETE:
        if(M_INIT_QI())
          enterStateIDLE();
        else
        if(M_INIT_QI() == false)
          enterStateERROR();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINITIALIZING_START:
        if(scm_nEventM_INIT_RSPID == pa_nEIID)
          enterStateINITIALIZING_COMPLETE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDINIT_COMPLETE:
        if(M_INIT_QI() == false)
          enterStateHALT();
        else
        if(M_INIT_QI())
          enterStateERROR();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSEND_FREE:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateERROR_OK:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateERROR_KO:
        if(1)
          enterStateERROR();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateHOLD_INIT:
        if(1)
          enterStateBUSY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTO_BUSY:
        if(1)
          enterStateBUSY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTO_DINIT:
        if(1)
          enterStateDESINITIALIZING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 13.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


