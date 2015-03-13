/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SetupRouterF
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-19/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L3_SetupRouterF.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_SetupRouterF_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_SetupRouterF, g_nStringIdL3_SetupRouterF)

const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anDataInputNames[] = {g_nStringIdSelFamily};

const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anDataInputTypeIds[] = {g_nStringIdUINT};

const TForteInt16 FORTE_L3_SetupRouterF::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L3_SetupRouterF::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 FORTE_L3_SetupRouterF::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anEventOutputNames[] = {g_nStringIdINITO};

const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdSelect};

const CStringDictionary::TStringId FORTE_L3_SetupRouterF::scm_anInternalsTypeIds[] = {g_nStringIdUSINT, g_nStringIdBOOL};

const SAdapterInstanceDef FORTE_L3_SetupRouterF::scm_astAdapterInstances[] = {
{g_nStringIdL3_ASetup, g_nStringIdASetupC, true },
{g_nStringIdL3_ASetup, g_nStringIdASetup1, false },
{g_nStringIdL3_ASetup, g_nStringIdASetup2, false }};

const SFBInterfaceSpec FORTE_L3_SetupRouterF::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  3,scm_astAdapterInstances};


const SInternalVarsInformation FORTE_L3_SetupRouterF::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_L3_SetupRouterF::alg_REQ1(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (2))) ||
            ((!isi_Up) && (i() < (2))))){

	ASetupC().PartInfoP()[i()] = ASetup1().PartInfoP()[i()];

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
ASetupC().MID() = ASetup1().MID();
ASetupC().Setup() = ASetup1().Setup();
}

void FORTE_L3_SetupRouterF::alg_REQ2(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (2))) ||
            ((!isi_Up) && (i() < (2))))){

	ASetupC().PartInfoP()[i()] = ASetup2().PartInfoP()[i()];

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
ASetupC().MID() = ASetup2().MID();
ASetupC().Setup() = ASetup2().Setup();
}

void FORTE_L3_SetupRouterF::alg_RSP1(void){
ASetupC().MID() = ASetup1().MID();
}

void FORTE_L3_SetupRouterF::alg_RSP2(void){
ASetupC().MID() = ASetup2().MID();
}

void FORTE_L3_SetupRouterF::alg_CNF(void){
if((ASetupC().PartInfoS()[1] == SelFamily())){
	Select() = true;
	ASetup2().PartInfoS()[0] = ASetupC().PartInfoS()[0];
	ASetup2().PartInfoS()[1] = ASetupC().PartInfoS()[1];
	ASetup2().PartInfoS()[2] = ASetupC().PartInfoS()[2];
}
else{
	Select() = false;
	ASetup1().PartInfoS()[0] = ASetupC().PartInfoS()[0];
	ASetup1().PartInfoS()[1] = ASetupC().PartInfoS()[1];
	ASetup1().PartInfoS()[2] = ASetupC().PartInfoS()[2];	
};
}

void FORTE_L3_SetupRouterF::alg_IND(void){
if((ASetupC().PartInfoS()[1] == SelFamily())){
	Select() = true;
	ASetup2().PartInfoS()[0] = ASetupC().PartInfoS()[0];
	ASetup2().PartInfoS()[1] = ASetupC().PartInfoS()[1];
	ASetup2().PartInfoS()[2] = ASetupC().PartInfoS()[2];
	ASetup2().ENDID() = ASetupC().ENDID();
}
else{
	Select() = false;
	ASetup1().PartInfoS()[0] = ASetupC().PartInfoS()[0];
	ASetup1().PartInfoS()[1] = ASetupC().PartInfoS()[1];
	ASetup1().PartInfoS()[2] = ASetupC().PartInfoS()[2];
	ASetup1().ENDID() = ASetupC().ENDID();	
};
}


void FORTE_L3_SetupRouterF::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_SetupRouterF::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_SetupRouterF::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ1();
  sendAdapterEvent(scm_nASetupCAdpNum, FORTE_L3_ASetup::scm_nEventREQID);
}

void FORTE_L3_SetupRouterF::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  alg_REQ2();
  sendAdapterEvent(scm_nASetupCAdpNum, FORTE_L3_ASetup::scm_nEventREQID);
}

void FORTE_L3_SetupRouterF::enterStateRSP1(void){
  m_nECCState = scm_nStateRSP1;
  sendAdapterEvent(scm_nASetupCAdpNum, FORTE_L3_ASetup::scm_nEventRSPID);
}

void FORTE_L3_SetupRouterF::enterStateRSP2(void){
  m_nECCState = scm_nStateRSP2;
  sendAdapterEvent(scm_nASetupCAdpNum, FORTE_L3_ASetup::scm_nEventRSPID);
}

void FORTE_L3_SetupRouterF::enterStateCNF(void){
  m_nECCState = scm_nStateCNF;
  alg_CNF();
}

void FORTE_L3_SetupRouterF::enterStateCNF1(void){
  m_nECCState = scm_nStateCNF1;
  sendAdapterEvent(scm_nASetup1AdpNum, FORTE_L3_ASetup::scm_nEventCNFID);
}

void FORTE_L3_SetupRouterF::enterStateCNF2(void){
  m_nECCState = scm_nStateCNF2;
  sendAdapterEvent(scm_nASetup2AdpNum, FORTE_L3_ASetup::scm_nEventCNFID);
}

void FORTE_L3_SetupRouterF::enterStateIND(void){
  m_nECCState = scm_nStateIND;
  alg_IND();
}

void FORTE_L3_SetupRouterF::enterStateIND1(void){
  m_nECCState = scm_nStateIND1;
  sendAdapterEvent(scm_nASetup1AdpNum, FORTE_L3_ASetup::scm_nEventINDID);
}

void FORTE_L3_SetupRouterF::enterStateIND2(void){
  m_nECCState = scm_nStateIND2;
  sendAdapterEvent(scm_nASetup2AdpNum, FORTE_L3_ASetup::scm_nEventINDID);
}

void FORTE_L3_SetupRouterF::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(ASetup1().REQ() == pa_nEIID)
          enterStateREQ1();
        else
        if(ASetup2().REQ() == pa_nEIID)
          enterStateREQ2();
        else
        if(ASetup1().RSP() == pa_nEIID)
          enterStateRSP1();
        else
        if(ASetup2().RSP() == pa_nEIID)
          enterStateRSP2();
        else
        if(ASetupC().CNF() == pa_nEIID)
          enterStateCNF();
        else
        if(ASetupC().IND() == pa_nEIID)
          enterStateIND();
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
      case scm_nStateCNF:
        if(Select() == false)
          enterStateCNF1();
        else
        if(Select() == true)
          enterStateCNF2();
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
      case scm_nStateIND:
        if(Select() == false)
          enterStateIND1();
        else
        if(Select() == true)
          enterStateIND2();
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


