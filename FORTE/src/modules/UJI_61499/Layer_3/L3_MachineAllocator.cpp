/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineAllocator
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-06/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_MachineAllocator.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_MachineAllocator_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_MachineAllocator, g_nStringIdL3_MachineAllocator)

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anDataInputNames[] = {g_nStringIdMFinalAssignIn, g_nStringIdPartIDIn, g_nStringIdSetupIDIn};

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anDataOutputNames[] = {g_nStringIdPartIDOut, g_nStringIdSetupID, g_nStringIdMID, g_nStringIdDelay, g_nStringIdMFinalAssignOut};

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdTIME, g_nStringIdARRAY, 15, g_nStringIdUINT};

const TForteInt16 FORTE_L3_MachineAllocator::scm_anEIWithIndexes[] = {0, 2, -1, -1, -1};
const TDataIOID FORTE_L3_MachineAllocator::scm_anEIWith[] = {0, 255, 2, 1, 255};
const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdREQ2, g_nStringIdRSP2, g_nStringIdRSP1, g_nStringIdTimeout};

const TDataIOID FORTE_L3_MachineAllocator::scm_anEOWith[] = {4, 255, 0, 255, 2, 1, 0, 255, 3, 255};
const TForteInt16 FORTE_L3_MachineAllocator::scm_anEOWithIndexes[] = {0, 2, 4, 8, -1, -1};
const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND2, g_nStringIdIND1, g_nStringIdStart, g_nStringIdStop};

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anInternalsNames[] = {g_nStringIdAssignRemaining, g_nStringIdi, g_nStringIdIFinalAssign, g_nStringIdCurrentPartID, g_nStringIdCurrentSetupID, g_nStringIdTOCounter};

const CStringDictionary::TStringId FORTE_L3_MachineAllocator::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_MachineAllocator::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_MachineAllocator::scm_stInternalVars = {6, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_MachineAllocator::setInitialValues(){
  AssignRemaining() = false;
  IFinalAssign_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
  CurrentPartID() = 0;
  CurrentSetupID() = 0;
  TOCounter() = 0;
}

void FORTE_L3_MachineAllocator::alg_REQ(void){
AssignRemaining() = false;
while((((i() < 15) && (!AssignRemaining())))){

	/* Check if any part can be assigned to a machine*/
	if((IFinalAssign()[i()] == PartIDIn()[i()])){
		/* This part can be assigned*/
		CurrentPartID() = PartIDIn()[i()];
		CurrentSetupID() = SetupIDIn()[i()];
		AssignRemaining() = true;
	};
	i() = i()+1;
};
}

void FORTE_L3_MachineAllocator::alg_SETTO(void){
Delay() = CIEC_TIME("1000ms");
}

void FORTE_L3_MachineAllocator::alg_PREREQ(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	IFinalAssign()[i()] = MFinalAssignIn()[i()];

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;
i() = 0;
}

void FORTE_L3_MachineAllocator::alg_NM(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	MFinalAssignOut()[i()] = IFinalAssign()[i()];

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;
}

void FORTE_L3_MachineAllocator::alg_SEND(void){
/* A setup needs to be assigned*/
PartIDOut() = CurrentPartID();
SetupID() = CurrentSetupID();
MID() = i();
}

void FORTE_L3_MachineAllocator::alg_RSP1(void){
TOCounter() = 0;
PartIDOut() = CurrentPartID();
}

void FORTE_L3_MachineAllocator::alg_TO(void){
TOCounter() = TOCounter()+1;
}

void FORTE_L3_MachineAllocator::alg_FAILED(void){
TOCounter() = 0;
}

void FORTE_L3_MachineAllocator::alg_RSP2(void){
/* Setup was succesfully assigned*/
IFinalAssign()[i()] = 0;
}


void FORTE_L3_MachineAllocator::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_MachineAllocator::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_L3_MachineAllocator::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
}

void FORTE_L3_MachineAllocator::enterStateSEND(void){
  m_nECCState = scm_nStateSEND;
  alg_SEND();
  sendOutputEvent( scm_nEventIND1ID);
  alg_SETTO();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L3_MachineAllocator::enterStatePREREQ(void){
  m_nECCState = scm_nStatePREREQ;
  alg_PREREQ();
}

void FORTE_L3_MachineAllocator::enterStateNOMACHINE(void){
  m_nECCState = scm_nStateNOMACHINE;
  alg_NM();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_MachineAllocator::enterStateWAIT(void){
  m_nECCState = scm_nStateWAIT;
}

void FORTE_L3_MachineAllocator::enterStateRSP1(void){
  m_nECCState = scm_nStateRSP1;
  alg_RSP1();
  sendOutputEvent( scm_nEventIND2ID);
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L3_MachineAllocator::enterStateTIMEOUT(void){
  m_nECCState = scm_nStateTIMEOUT;
  alg_TO();
}

void FORTE_L3_MachineAllocator::enterStateFAILED(void){
  m_nECCState = scm_nStateFAILED;
  alg_FAILED();
}

void FORTE_L3_MachineAllocator::enterStateRSP2(void){
  m_nECCState = scm_nStateRSP2;
  alg_RSP2();
}

void FORTE_L3_MachineAllocator::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateREQ2();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStatePREREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(AssignRemaining() == false)
          enterStateNOMACHINE();
        else
        if(AssignRemaining() == true)
          enterStateSEND();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSEND:
        if(1)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePREREQ:
        if(1)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNOMACHINE:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWAIT:
        if(scm_nEventRSP1ID == pa_nEIID)
          enterStateRSP1();
        else
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateTIMEOUT();
        else
        if(scm_nEventRSP2ID == pa_nEIID)
          enterStateRSP2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP1:
        if(1)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTIMEOUT:
        if(TOCounter() <= 3)
          enterStateSEND();
        else
        if(TOCounter() > 4)
          enterStateFAILED();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateFAILED:
        if(1)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP2:
        if(1)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 10.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


