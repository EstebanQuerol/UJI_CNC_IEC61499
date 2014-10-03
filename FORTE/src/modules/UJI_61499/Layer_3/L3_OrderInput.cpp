/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_OrderInput
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_OrderInput.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_OrderInput_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_OrderInput, g_nStringIdL3_OrderInput)

const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anDataInputNames[] = {g_nStringIdFamilyIn, g_nStringIdTypeIn, g_nStringIdLotsizeIn, g_nStringIdDeadlineIn};

const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anDataOutputNames[] = {g_nStringIdFamilyOut, g_nStringIdTypeOut, g_nStringIdLotsizeOut, g_nStringIdDeadlineOut};

const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_OrderInput::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_L3_OrderInput::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_L3_OrderInput::scm_anEOWith[] = {1, 2, 3, 0, 255};
const TForteInt16 FORTE_L3_OrderInput::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_L3_OrderInput::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_L3_OrderInput::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L3_OrderInput::alg_REQ(void){
FamilyOut() = FamilyIn();
TypeOut() = TypeIn();
LotsizeOut() = LotsizeIn();
DeadlineOut() = DeadlineIn();
}


void FORTE_L3_OrderInput::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_OrderInput::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_OrderInput::enterStatePROCESSING(void){
  m_nECCState = scm_nStatePROCESSING;
}

void FORTE_L3_OrderInput::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L3_OrderInput::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStatePROCESSING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePROCESSING:
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


