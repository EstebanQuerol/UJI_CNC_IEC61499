/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PartDesEncap
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-24/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_PartDesEncap.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_PartDesEncap_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_PartDesEncap, g_nStringIdL3_PartDesEncap)

const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anDataInputNames[] = {g_nStringIdPartIDS, g_nStringIdFamilyS, g_nStringIdTypeS};

const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anDataOutputNames[] = {g_nStringIdPartIDP, g_nStringIdFamilyP, g_nStringIdTypeP, g_nStringIdLotsize, g_nStringIdDeadline};

const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_PartDesEncap::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_L3_PartDesEncap::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anEventInputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const TDataIOID FORTE_L3_PartDesEncap::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 1, 2, 4, 255};
const TForteInt16 FORTE_L3_PartDesEncap::scm_anEOWithIndexes[] = {0, 6, -1};
const CStringDictionary::TStringId FORTE_L3_PartDesEncap::scm_anEventOutputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const SAdapterInstanceDef FORTE_L3_PartDesEncap::scm_astAdapterInstances[] = {
{g_nStringIdL3_APart, g_nStringIdL3_APart, false }};

const SFBInterfaceSpec FORTE_L3_PartDesEncap::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};

void FORTE_L3_PartDesEncap::alg_REQ(void){
PartIDP() = L3_APart().PartIDP();
FamilyP() = L3_APart().FamilyP();
TypeP() = L3_APart().TypeP();
Lotsize() = L3_APart().Lotsize();
Deadline() = L3_APart().Deadline();
}

void FORTE_L3_PartDesEncap::alg_RSP(void){
FamilyP() = L3_APart().FamilyP();
TypeP() = L3_APart().TypeP();
Deadline() = L3_APart().Deadline();
}

void FORTE_L3_PartDesEncap::alg_IND(void){
L3_APart().PartIDS() = PartIDS();
L3_APart().FamilyS() = FamilyS();
L3_APart().TypeS() = TypeS();
}

void FORTE_L3_PartDesEncap::alg_CNF(void){
/* Nothing for now*/
}


void FORTE_L3_PartDesEncap::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_PartDesEncap::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventREQID);
}

void FORTE_L3_PartDesEncap::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
  sendOutputEvent( scm_nEventRSPID);
}

void FORTE_L3_PartDesEncap::enterStateCNF(void){
  m_nECCState = scm_nStateCNF;
  alg_CNF();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventCNFID);
}

void FORTE_L3_PartDesEncap::enterStateIND(void){
  m_nECCState = scm_nStateIND;
  alg_IND();
  sendAdapterEvent(scm_nL3_APartAdpNum, FORTE_L3_APart::scm_nEventINDID);
}

void FORTE_L3_PartDesEncap::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(L3_APart().REQ() == pa_nEIID)
          enterStateREQ();
        else
        if(L3_APart().RSP() == pa_nEIID)
          enterStateRSP();
        else
        if(scm_nEventCNFID == pa_nEIID)
          enterStateCNF();
        else
        if(scm_nEventINDID == pa_nEIID)
          enterStateIND();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCNF:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIND:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


