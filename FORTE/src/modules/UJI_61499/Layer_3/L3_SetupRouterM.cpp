/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SetupRouterM
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-19/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L3_SetupRouterM.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_SetupRouterM_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_SetupRouterM, g_nStringIdL3_SetupRouterM)

const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anDataInputNames[] = {g_nStringIdSelMachine};

const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_L3_SetupRouterM::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L3_SetupRouterM::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 FORTE_L3_SetupRouterM::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anEventOutputNames[] = {g_nStringIdINITO};

const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdSelect};

const CStringDictionary::TStringId FORTE_L3_SetupRouterM::scm_anInternalsTypeIds[] = {g_nStringIdUSINT, g_nStringIdBOOL};

const SAdapterInstanceDef FORTE_L3_SetupRouterM::scm_astAdapterInstances[] = {
{g_nStringIdL3_ASetup, g_nStringIdASetup1, true },
{g_nStringIdL3_ASetup, g_nStringIdASetup2, true },
{g_nStringIdL3_ASetup, g_nStringIdASetup, false }};

const SFBInterfaceSpec FORTE_L3_SetupRouterM::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  3,scm_astAdapterInstances};


const SInternalVarsInformation FORTE_L3_SetupRouterM::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_L3_SetupRouterM::alg_REQ(void){
if((ASetup().MID() == SelMachine())){
	Select() = true;
	  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (2))) ||
            ((!isi_Up) && (i() < (2))))){

		ASetup1().PartInfoP()[i()] = ASetup().PartInfoP()[i()];
	
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
	ASetup1().MID() = ASetup().MID();
	ASetup1().Setup() = ASetup().Setup();
}
else{
	Select() = false;
	  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (2))) ||
            ((!isi_Up) && (i() < (2))))){

		ASetup2().PartInfoP()[i()] = ASetup().PartInfoP()[i()];
	
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
	ASetup2().MID() = ASetup().MID();
ASetup2().Setup() = ASetup().Setup();
};
}

void FORTE_L3_SetupRouterM::alg_RSP(void){
if((ASetup().MID() == SelMachine())){
	Select() = true;
	ASetup1().MID() = ASetup().MID();
}
else{
	Select() = false;
	ASetup2().MID() = ASetup().MID();
};
}

void FORTE_L3_SetupRouterM::alg_CNF1(void){
ASetup().PartInfoS()[0] = ASetup1().PartInfoS()[0];
ASetup().PartInfoS()[1] = ASetup1().PartInfoS()[1];
ASetup().PartInfoS()[2] = ASetup1().PartInfoS()[2];
}

void FORTE_L3_SetupRouterM::alg_CNF2(void){
ASetup().PartInfoS()[0] = ASetup2().PartInfoS()[0];
ASetup().PartInfoS()[1] = ASetup2().PartInfoS()[1];
ASetup().PartInfoS()[2] = ASetup2().PartInfoS()[2];
}

void FORTE_L3_SetupRouterM::alg_IND1(void){
ASetup().PartInfoS()[0] = ASetup1().PartInfoS()[0];
ASetup().PartInfoS()[1] = ASetup1().PartInfoS()[1];
ASetup().PartInfoS()[2] = ASetup1().PartInfoS()[2];
ASetup().ENDID() = ASetup1().ENDID();
}

void FORTE_L3_SetupRouterM::alg_IND2(void){
ASetup().PartInfoS()[0] = ASetup2().PartInfoS()[0];
ASetup().PartInfoS()[1] = ASetup2().PartInfoS()[1];
ASetup().PartInfoS()[2] = ASetup2().PartInfoS()[2];
ASetup().ENDID() = ASetup2().ENDID();
}


void FORTE_L3_SetupRouterM::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_SetupRouterM::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_L3_SetupRouterM::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_SetupRouterM::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  sendAdapterEvent(scm_nASetup1AdpNum, FORTE_L3_ASetup::scm_nEventREQID);
}

void FORTE_L3_SetupRouterM::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  sendAdapterEvent(scm_nASetup2AdpNum, FORTE_L3_ASetup::scm_nEventREQID);
}

void FORTE_L3_SetupRouterM::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
}

void FORTE_L3_SetupRouterM::enterStateRSP1(void){
  m_nECCState = scm_nStateRSP1;
  sendAdapterEvent(scm_nASetup1AdpNum, FORTE_L3_ASetup::scm_nEventRSPID);
}

void FORTE_L3_SetupRouterM::enterStateRSP2(void){
  m_nECCState = scm_nStateRSP2;
  sendAdapterEvent(scm_nASetup2AdpNum, FORTE_L3_ASetup::scm_nEventRSPID);
}

void FORTE_L3_SetupRouterM::enterStateCNF1(void){
  m_nECCState = scm_nStateCNF1;
  alg_CNF1();
  sendAdapterEvent(scm_nASetupAdpNum, FORTE_L3_ASetup::scm_nEventCNFID);
}

void FORTE_L3_SetupRouterM::enterStateCNF2(void){
  m_nECCState = scm_nStateCNF2;
  alg_CNF2();
  sendAdapterEvent(scm_nASetupAdpNum, FORTE_L3_ASetup::scm_nEventCNFID);
}

void FORTE_L3_SetupRouterM::enterStateIND1(void){
  m_nECCState = scm_nStateIND1;
  alg_IND1();
  sendAdapterEvent(scm_nASetupAdpNum, FORTE_L3_ASetup::scm_nEventINDID);
}

void FORTE_L3_SetupRouterM::enterStateIND2(void){
  m_nECCState = scm_nStateIND2;
  alg_IND2();
  sendAdapterEvent(scm_nASetupAdpNum, FORTE_L3_ASetup::scm_nEventINDID);
}

void FORTE_L3_SetupRouterM::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(ASetup().REQ() == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(ASetup().RSP() == pa_nEIID)
          enterStateRSP();
        else
        if(ASetup1().IND() == pa_nEIID)
          enterStateIND1();
        else
        if(ASetup2().IND() == pa_nEIID)
          enterStateIND2();
        else
        if(ASetup2().CNF() == pa_nEIID)
          enterStateCNF2();
        else
        if(ASetup1().CNF() == pa_nEIID)
          enterStateCNF1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
        if(Select() == true)
          enterStateREQ1();
        else
        if(Select() == false)
          enterStateREQ2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ1:
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
      case scm_nStateRSP:
        if(Select() == true)
          enterStateRSP1();
        else
        if(Select() == false)
          enterStateRSP2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCNF1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCNF2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIND1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIND2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 11.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


