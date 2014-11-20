/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PartRouterF
 *** Description: Part Router based on part family
 *** Version: 
 ***     0.0: 2014-09-24/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_PartRouterF.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_PartRouterF_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_PartRouterF, g_nStringIdL3_PartRouterF)

const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anDataInputNames[] = {g_nStringIdSelFamily};

const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anDataInputTypeIds[] = {g_nStringIdUINT};

const TForteInt16 FORTE_L3_PartRouterF::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L3_PartRouterF::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 FORTE_L3_PartRouterF::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anEventOutputNames[] = {g_nStringIdINITO};

const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anInternalsNames[] = {g_nStringIdSelect};

const CStringDictionary::TStringId FORTE_L3_PartRouterF::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SAdapterInstanceDef FORTE_L3_PartRouterF::scm_astAdapterInstances[] = {
{g_nStringIdL3_APart, g_nStringIdL3_APart1, true },
{g_nStringIdL3_APart, g_nStringIdL3_APart2, true },
{g_nStringIdL3_APart, g_nStringIdL3_APart, false }};

const SFBInterfaceSpec FORTE_L3_PartRouterF::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  3,scm_astAdapterInstances};


const SInternalVarsInformation FORTE_L3_PartRouterF::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_PartRouterF::setInitialValues(){
  Select() = false;
}

void FORTE_L3_PartRouterF::alg_REQ(void){
if((L3_APart().FamilyP() == SelFamily())){
/* Map input request to output 1*/
L3_APart1().PartIDP() = L3_APart().PartIDP();
L3_APart1().FamilyP() = L3_APart().FamilyP();
L3_APart1().TypeP() = L3_APart().TypeP();
L3_APart1().Lotsize() = L3_APart().Lotsize();
L3_APart1().Deadline() = L3_APart().Deadline();
Select() = true;

}
else{
/* Map input request to output 2*/
L3_APart2().PartIDP() = L3_APart().PartIDP();
L3_APart2().FamilyP() = L3_APart().FamilyP();
L3_APart2().TypeP() = L3_APart().TypeP();
L3_APart2().Lotsize() = L3_APart().Lotsize();
L3_APart2().Deadline() = L3_APart().Deadline();
Select() = false;

};
}

void FORTE_L3_PartRouterF::alg_RSP(void){
if((L3_APart().FamilyP() == SelFamily())){
/* Map input request to output 1*/
L3_APart1().FamilyP() = L3_APart().FamilyP();
L3_APart1().TypeP() = L3_APart().TypeP();
L3_APart1().Deadline() = L3_APart().Deadline();
Select() = true;

}
else{
/* Map input request to output 2*/
L3_APart2().FamilyP() = L3_APart().FamilyP();
L3_APart2().TypeP() = L3_APart().TypeP();
L3_APart2().Deadline() = L3_APart().Deadline();
Select() = false;

};
}

void FORTE_L3_PartRouterF::alg_CNF1(void){
/* No data needs to be mapped in this case*/
/* To be used in the future if is needed to return any data with CNF event*/
}

void FORTE_L3_PartRouterF::alg_IND1(void){
/* Map input IND1 to common output*/
L3_APart().PartIDS() = L3_APart1().PartIDS();
L3_APart().FamilyS() = L3_APart1().FamilyS();
L3_APart().TypeS() = L3_APart1().TypeS();
}

void FORTE_L3_PartRouterF::alg_CNF2(void){
/* No data needs to be mapped in this case*/
/* To be used in the future if is needed to return any data with CNF event*/
}

void FORTE_L3_PartRouterF::alg_IND2(void){
/* Map input IND2 to common output*/
L3_APart().PartIDS() = L3_APart2().PartIDS();
L3_APart().FamilyS() = L3_APart2().FamilyS();
L3_APart().TypeS() = L3_APart2().TypeS();

}


void FORTE_L3_PartRouterF::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_PartRouterF::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_PartRouterF::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_L3_PartRouterF::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  sendAdapterEvent(scm_nL3_APart1AdpNum, FORTE_L3_APart::scm_nEventREQID);
}

void FORTE_L3_PartRouterF::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  sendAdapterEvent(scm_nL3_APart2AdpNum, FORTE_L3_APart::scm_nEventREQID);
}

void FORTE_L3_PartRouterF::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
}

void FORTE_L3_PartRouterF::enterStateRSP1(void){
  m_nECCState = scm_nStateRSP1;
  sendAdapterEvent(scm_nL3_APart1AdpNum, FORTE_L3_APart::scm_nEventRSPID);
}

void FORTE_L3_PartRouterF::enterStateRSP2(void){
  m_nECCState = scm_nStateRSP2;
  sendAdapterEvent(scm_nL3_APart2AdpNum, FORTE_L3_APart::scm_nEventRSPID);
}

void FORTE_L3_PartRouterF::enterStateCNF1(void){
  m_nECCState = scm_nStateCNF1;
  alg_CNF1();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventCNFID);
}

void FORTE_L3_PartRouterF::enterStateIND1(void){
  m_nECCState = scm_nStateIND1;
  alg_IND1();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventINDID);
}

void FORTE_L3_PartRouterF::enterStateCNF2(void){
  m_nECCState = scm_nStateCNF2;
  alg_CNF2();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventCNFID);
}

void FORTE_L3_PartRouterF::enterStateIND2(void){
  m_nECCState = scm_nStateIND2;
  alg_IND2();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventINDID);
}

void FORTE_L3_PartRouterF::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(L3_APart().REQ() == pa_nEIID)
          enterStateREQ();
        else
        if(L3_APart().RSP() == pa_nEIID)
          enterStateRSP();
        else
        if(L3_APart1().CNF() == pa_nEIID)
          enterStateCNF1();
        else
        if(L3_APart1().IND() == pa_nEIID)
          enterStateIND1();
        else
        if(L3_APart2().CNF() == pa_nEIID)
          enterStateCNF2();
        else
        if(L3_APart2().IND() == pa_nEIID)
          enterStateIND2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(Select() == true)
          enterStateREQ1();
        else
        if(Select() == false)
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
      case scm_nStateIND1:
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


