/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineCore
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_MachineCore.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_MachineCore_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_MachineCore, g_nStringIdL2_MachineCore)

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anDataInputNames[] = {g_nStringIdServiceState, g_nStringIdPartInfoIn, g_nStringIdENDOPID, g_nStringIdENDSetupID};

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anDataInputTypeIds[] = {g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anDataOutputNames[] = {g_nStringIdNextCode, g_nStringIdPartInfoOut, g_nStringIdENDID, g_nStringIdMachineState, g_nStringIdDelay};

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT, g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdBOOL, g_nStringIdTIME};

const TForteInt16 FORTE_L2_MachineCore::scm_anEIWithIndexes[] = {0, 2, -1, -1, 4, 6};
const TDataIOID FORTE_L2_MachineCore::scm_anEIWith[] = {0, 255, 1, 255, 2, 255, 3, 255};
const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anEventInputNames[] = {g_nStringIdUPDT, g_nStringIdREQ, g_nStringIdRSP, g_nStringIdtimeout, g_nStringIdCompletedOP, g_nStringIdCompletedSetup};

const TDataIOID FORTE_L2_MachineCore::scm_anEOWith[] = {0, 255, 1, 255, 1, 2, 255, 3, 255, 4, 255};
const TForteInt16 FORTE_L2_MachineCore::scm_anEOWithIndexes[] = {-1, 0, 2, 4, -1, 7, 9, -1, -1};
const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anEventOutputNames[] = {g_nStringIdRENEW, g_nStringIdNEXT, g_nStringIdCNF, g_nStringIdIND, g_nStringIdFREE, g_nStringIdERROR, g_nStringIdstart, g_nStringIdstop};

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anInternalsNames[] = {g_nStringIdState, g_nStringIdCurrentPart, g_nStringIdCurrentFamily, g_nStringIdCurrentType, g_nStringIdLostCNF, g_nStringIdinError};

const CStringDictionary::TStringId FORTE_L2_MachineCore::scm_anInternalsTypeIds[] = {g_nStringIdUSINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_L2_MachineCore::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  8,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_MachineCore::scm_stInternalVars = {6, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_MachineCore::setInitialValues(){
  ENDOPID() = 0;
  State() = 1;
  CurrentPart() = 0;
  CurrentFamily() = 0;
  CurrentType() = 0;
  LostCNF() = false;
  inError() = false;
}

void FORTE_L2_MachineCore::alg_REQ(void){
/* A new assignation request arrived*/
/* The machine is free, confirm the assignation and modify the state*/
CurrentPart() = PartInfoIn()[0];
CurrentFamily() = PartInfoIn()[1];
CurrentType() = PartInfoIn()[2];
ENDOPID() = 0;
PartInfoOut()[0] = CurrentPart();
PartInfoOut()[1] = CurrentFamily();
PartInfoOut()[2] = CurrentType();
}

void FORTE_L2_MachineCore::alg_UPDT(void){
if((ServiceState() == 1)){
	MachineState() = true;
	State() = 2;
}
else
  if((ServiceState() == 0)){
	MachineState() = false;
	State() = 1;
};
/* Reset inError flag every time this algo is called, It is only used in EIW*/
inError() = false;
}

void FORTE_L2_MachineCore::alg_SENDOP(void){
/* Post-incremented index*/
ENDOPID() = NextCode();
}

void FORTE_L2_MachineCore::alg_CNF(void){
PartInfoOut()[0] = CurrentPart();
PartInfoOut()[1] = CurrentFamily();
PartInfoOut()[2] = CurrentType();
}

void FORTE_L2_MachineCore::alg_NEWREQ(void){
/* A REQ event arrived while executing a setup*/
/* Verify if its a transmision problem or something else*/
if((CurrentPart() == PartInfoIn()[0])){
	/* Lost CNF event, retransmite it*/
	LostCNF() = true;
}
else{
	LostCNF() = false;
};
}

void FORTE_L2_MachineCore::alg_DT(void){
Delay() = CIEC_TIME("TIME#300ms");
}

void FORTE_L2_MachineCore::alg_IND(void){
PartInfoOut()[0] = CurrentPart();
PartInfoOut()[1] = CurrentFamily();
PartInfoOut()[2] = CurrentType();
ENDOPID() = ENDSetupID();
}

void FORTE_L2_MachineCore::alg_EIE(void){
/* An error occurred while executing a setup*/
/* We assume that the error is not related with the setup and that it can be redone*/
ENDID() = 1;
}

void FORTE_L2_MachineCore::alg_EIW(void){
/* An error occurred while waiting RSP*/
if((ServiceState() == 0)){
	inError() = true;
};
}


void FORTE_L2_MachineCore::enterStateNotReady(void){
  m_nECCState = scm_nStateNotReady;
}

void FORTE_L2_MachineCore::enterStateToReady(void){
  m_nECCState = scm_nStateToReady;
  alg_UPDT();
  sendOutputEvent( scm_nEventERRORID);
}

void FORTE_L2_MachineCore::enterStateReady(void){
  m_nECCState = scm_nStateReady;
}

void FORTE_L2_MachineCore::enterStatetoError(void){
  m_nECCState = scm_nStatetoError;
  alg_UPDT();
  sendOutputEvent( scm_nEventERRORID);
}

void FORTE_L2_MachineCore::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
  sendOutputEvent( scm_nEventRENEWID);
}

void FORTE_L2_MachineCore::enterStateExecuting(void){
  m_nECCState = scm_nStateExecuting;
}

void FORTE_L2_MachineCore::enterStateCompleted(void){
  m_nECCState = scm_nStateCompleted;
  alg_IND();
  sendOutputEvent( scm_nEventINDID);
  alg_DT();
  sendOutputEvent( scm_nEventstartID);
}

void FORTE_L2_MachineCore::enterStateSendNext(void){
  m_nECCState = scm_nStateSendNext;
  alg_SENDOP();
  sendOutputEvent( scm_nEventNEXTID);
}

void FORTE_L2_MachineCore::enterStateNewREQ(void){
  m_nECCState = scm_nStateNewREQ;
  alg_NEWREQ();
}

void FORTE_L2_MachineCore::enterStateLostCNF(void){
  m_nECCState = scm_nStateLostCNF;
  alg_CNF();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L2_MachineCore::enterStateWAIT(void){
  m_nECCState = scm_nStateWAIT;
  alg_EIW();
}

void FORTE_L2_MachineCore::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  sendOutputEvent( scm_nEventstopID);
  sendOutputEvent( scm_nEventFREEID);
}

void FORTE_L2_MachineCore::enterStateErroInExecution(void){
  m_nECCState = scm_nStateErroInExecution;
  alg_EIE();
  alg_IND();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L2_MachineCore::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateNotReady:
        if((scm_nEventUPDTID == pa_nEIID) && (ServiceState() == 1))
          enterStateToReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateToReady:
        if(1)
          enterStateReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReady:
        if((scm_nEventUPDTID == pa_nEIID) && (ServiceState() == 0))
          enterStatetoError();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatetoError:
        if(1)
          enterStateNotReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSendNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExecuting:
        if(scm_nEventREQID == pa_nEIID)
          enterStateNewREQ();
        else
        if((scm_nEventUPDTID == pa_nEIID) && (ServiceState() == 0))
          enterStateErroInExecution();
        else
        if(scm_nEventCompletedSetupID == pa_nEIID)
          enterStateCompleted();
        else
        if(scm_nEventCompletedOPID == pa_nEIID)
          enterStateSendNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCompleted:
        if(1)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSendNext:
        if(1)
          enterStateExecuting();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNewREQ:
        if(LostCNF() == true)
          enterStateLostCNF();
        else
        if(LostCNF() == false)
          enterStateExecuting();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLostCNF:
        if(1)
          enterStateExecuting();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWAIT:
        if(scm_nEventtimeoutID == pa_nEIID)
          enterStateCompleted();
        else
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
        if(scm_nEventUPDTID == pa_nEIID)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(inError() == false)
          enterStateReady();
        else
        if(inError() == true)
          enterStatetoError();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateErroInExecution:
        if(1)
          enterStatetoError();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 12.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


