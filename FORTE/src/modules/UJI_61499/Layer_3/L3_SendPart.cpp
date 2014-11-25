/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SendPart
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_SendPart.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_SendPart_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_SendPart, g_nStringIdL3_SendPart)

const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anDataInputNames[] = {g_nStringIdPartIDIn, g_nStringIdFamilyIn, g_nStringIdTypeIn, g_nStringIdLotsizeIn, g_nStringIdDeadlineIn};

const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anDataOutputNames[] = {g_nStringIdTimeoutDT, g_nStringIdPartIDP, g_nStringIdFamilyP, g_nStringIdTypeP, g_nStringIdLotsizeP, g_nStringIdDeadlineP};

const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anDataOutputTypeIds[] = {g_nStringIdTIME, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_SendPart::scm_anEIWithIndexes[] = {0, -1, -1};
const TDataIOID FORTE_L3_SendPart::scm_anEIWith[] = {0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP, g_nStringIdTimeout};

const TDataIOID FORTE_L3_SendPart::scm_anEOWith[] = {1, 2, 3, 4, 5, 255, 0, 255};
const TForteInt16 FORTE_L3_SendPart::scm_anEOWithIndexes[] = {0, -1, 6, -1, -1};
const CStringDictionary::TStringId FORTE_L3_SendPart::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND, g_nStringIdStart, g_nStringIdStop};

const SFBInterfaceSpec FORTE_L3_SendPart::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  6,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L3_SendPart::alg_REQ(void){
PartIDP() = PartIDIn();
FamilyP() = FamilyIn();
TypeP() = TypeIn();
LotsizeP() = LotsizeIn();
DeadlineP() = DeadlineIn();
}

void FORTE_L3_SendPart::alg_TO(void){
TimeoutDT() = CIEC_TIME("2000ms");
}


void FORTE_L3_SendPart::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_SendPart::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
  alg_TO();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L3_SendPart::enterStateSENDING(void){
  m_nECCState = scm_nStateSENDING;
}

void FORTE_L3_SendPart::enterStateTimeOut(void){
  m_nECCState = scm_nStateTimeOut;
  sendOutputEvent( scm_nEventCNFID);
  alg_TO();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L3_SendPart::enterStateSTOPTIMER(void){
  m_nECCState = scm_nStateSTOPTIMER;
  sendOutputEvent( scm_nEventStopID);
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L3_SendPart::executeEvent(int pa_nEIID){
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
          enterStateSENDING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSENDING:
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateTimeOut();
        else
        if(scm_nEventRSPID == pa_nEIID)
          enterStateSTOPTIMER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTimeOut:
        if(1)
          enterStateSENDING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTOPTIMER:
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


