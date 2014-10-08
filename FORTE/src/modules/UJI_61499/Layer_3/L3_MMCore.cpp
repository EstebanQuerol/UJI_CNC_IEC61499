/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MMCore
 *** Description: Machine manager core
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_MMCore.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_MMCore_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_MMCore, g_nStringIdL3_MMCore)

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdMReleased, g_nStringIdMFaulty, g_nStringIdMAssignS, g_nStringIdMFinalAssignS};

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdMStateP, g_nStringIdMPriority, g_nStringIdMAssignP, g_nStringIdMFinalAssignP};

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const TForteInt16 FORTE_L3_MMCore::scm_anEIWithIndexes[] = {0, 2, 4, 6, 8, -1};
const TDataIOID FORTE_L3_MMCore::scm_anEIWith[] = {0, 255, 1, 255, 2, 255, 3, 255, 4, 255};
const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdRSP1, g_nStringIdRSP2, g_nStringIdRSP3, g_nStringIdRSP4, g_nStringIdTimeOut};

const TDataIOID FORTE_L3_MMCore::scm_anEOWith[] = {0, 255, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_L3_MMCore::scm_anEOWithIndexes[] = {0, -1, -1, 2, 6, -1, -1, -1};
const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND1, g_nStringIdIND2, g_nStringIdIND3, g_nStringIdIND4, g_nStringIdStart, g_nStringIdStop};

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anInternalsNames[] = {g_nStringIdMState, g_nStringIdi, g_nStringIdMachineCounter};

const CStringDictionary::TStringId FORTE_L3_MMCore::scm_anInternalsTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_MMCore::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  7,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_MMCore::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_MMCore::setInitialValues(){
  MState_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
  MachineCounter() = 0;
}

void FORTE_L3_MMCore::alg_INIT(void){
/* Reset internal variables*/
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	MState()[i()] = 0;
	MAssignP()[i()] = 0;
	MPriority()[i()] = 0;

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
MachineCounter() = 0;
QI() = true;
}

void FORTE_L3_MMCore::alg_RSP1(void){
/* This algo is in charge of updating the released machines since last time that CORE sequence was executed*/
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	if((MReleased()[i()] == 2)){
		/* Machine was released*/
		MState()[i()] = 2;
	};

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

void FORTE_L3_MMCore::alg_RSP2(void){
MachineCounter() = 0;
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	if((MFaulty()[i()] == 1)){
		/* Machine breakdown*/
		MState()[i()] = 1;
	}
else
  if((MFaulty()[i()] == 2)){
		/* Machine was repaired*/
		MState()[i()] = 2;
	};
		
	if((MState()[i()] == 2)){
		MachineCounter() = MachineCounter()+1;
	};

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

void FORTE_L3_MMCore::alg_RSP3(void){
/* MAssignS[i] contains 0 if the machine wasn't requested, otherwise the ID of the PP that requested the machine*/
MachineCounter() = 0;
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	MFinalAssignP()[i()] = MAssignS()[i()];
	if((MFinalAssignS()[i()] != 0)){
		MState()[i()] = 3;
		MachineCounter() = MachineCounter()+1;
	};

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

void FORTE_L3_MMCore::alg_RSP4(void){
/* MFinalAssignS[i] is 0 if the machine assignation succeed, otherwise the assignation failed*/
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	if((MFinalAssignS()[i()] == 0)){
		/* Assignation succeed*/
		MState()[i()] = 4;
	}
else{
		/* Assignation failed, mark machine as free, will handle its real state in next cycle*/
		MState()[i()] = 2;
	};

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

void FORTE_L3_MMCore::alg_UINIT(void){
QO() = false;
}


void FORTE_L3_MMCore::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_MMCore::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_MMCore::enterStateSTEP1(void){
  m_nECCState = scm_nStateSTEP1;
  sendOutputEvent( scm_nEventIND1ID);
}

void FORTE_L3_MMCore::enterStateRSP1(void){
  m_nECCState = scm_nStateRSP1;
  alg_RSP1();
  sendOutputEvent( scm_nEventIND2ID);
}

void FORTE_L3_MMCore::enterStateNOFREEMACHINE(void){
  m_nECCState = scm_nStateNOFREEMACHINE;
}

void FORTE_L3_MMCore::enterStateRSP2(void){
  m_nECCState = scm_nStateRSP2;
  alg_RSP2();
}

void FORTE_L3_MMCore::enterStateFREEMACHINE(void){
  m_nECCState = scm_nStateFREEMACHINE;
  sendOutputEvent( scm_nEventIND3ID);
}

void FORTE_L3_MMCore::enterStateRSP3(void){
  m_nECCState = scm_nStateRSP3;
  alg_RSP3();
}

void FORTE_L3_MMCore::enterStateRSP4(void){
  m_nECCState = scm_nStateRSP4;
  alg_RSP4();
}

void FORTE_L3_MMCore::enterStateSTARTTIMER(void){
  m_nECCState = scm_nStateSTARTTIMER;
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L3_MMCore::enterStateSTOPTIMER(void){
  m_nECCState = scm_nStateSTOPTIMER;
  alg_UINIT();
  sendOutputEvent( scm_nEventStopID);
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_MMCore::enterStateMACHINESTOBEASSIGNED(void){
  m_nECCState = scm_nStateMACHINESTOBEASSIGNED;
  sendOutputEvent( scm_nEventIND4ID);
}

void FORTE_L3_MMCore::enterStateNONEEDEDMACHINE(void){
  m_nECCState = scm_nStateNONEEDEDMACHINE;
}

void FORTE_L3_MMCore::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventTimeOutID == pa_nEIID)
          enterStateSTEP1();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateSTOPTIMER();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == true))
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTARTTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTEP1:
        if(scm_nEventRSP1ID == pa_nEIID)
          enterStateRSP1();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateSTOPTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP1:
        if(scm_nEventRSP2ID == pa_nEIID)
          enterStateRSP2();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateSTOPTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNOFREEMACHINE:
        if(1)
          enterStateSTARTTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP2:
        if(MachineCounter() > 0)
          enterStateFREEMACHINE();
        else
        if(MachineCounter() == 0)
          enterStateNOFREEMACHINE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateFREEMACHINE:
        if(scm_nEventRSP3ID == pa_nEIID)
          enterStateRSP3();
        else
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateSTOPTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP3:
        if((scm_nEventINITID == pa_nEIID) && (QI() == false))
          enterStateSTOPTIMER();
        else
        if(MachineCounter() == 0)
          enterStateNONEEDEDMACHINE();
        else
        if(MachineCounter() > 0)
          enterStateMACHINESTOBEASSIGNED();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP4:
        if(1)
          enterStateSTARTTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTARTTIMER:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTOPTIMER:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateMACHINESTOBEASSIGNED:
        if(scm_nEventRSP4ID == pa_nEIID)
          enterStateRSP4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNONEEDEDMACHINE:
        if(1)
          enterStateSTARTTIMER();
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


