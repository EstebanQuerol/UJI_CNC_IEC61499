/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_CompletedPartHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-04/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_CompletedPartHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_CompletedPartHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_CompletedPartHDLR, g_nStringIdL3_CompletedPartHDLR)

const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamilyIn, g_nStringIdTypeIn, g_nStringIdPartIDIn, g_nStringIdDeadlineIn};

const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdPartIDOut, g_nStringIdFamilyOut, g_nStringIdTypeOut, g_nStringIdDelay, g_nStringIdDeadlineOut};

const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdTIME, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_CompletedPartHDLR::scm_anEIWithIndexes[] = {0, 4, 6, -1};
const TDataIOID FORTE_L3_CompletedPartHDLR::scm_anEIWith[] = {0, 1, 2, 255, 3, 255, 4, 255};
const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP, g_nStringIdTimeout};

const TDataIOID FORTE_L3_CompletedPartHDLR::scm_anEOWith[] = {0, 2, 3, 255, 0, 5, 255, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_L3_CompletedPartHDLR::scm_anEOWithIndexes[] = {0, 4, 7, 11, -1, -1};
const CStringDictionary::TStringId FORTE_L3_CompletedPartHDLR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND, g_nStringIdStart, g_nStringIdStop};

const SFBInterfaceSpec FORTE_L3_CompletedPartHDLR::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  6,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L3_CompletedPartHDLR::alg_INIT(void){
if((QI() == true)){
	FamilyOut() = FamilyIn();
	TypeOut() = TypeIn();
	QO() = true;
}
else{
	QO() = false;
};
}

void FORTE_L3_CompletedPartHDLR::alg_REQ(void){
PartIDOut() = PartIDIn();
FamilyOut() = FamilyIn();
TypeOut() = TypeIn();
}

void FORTE_L3_CompletedPartHDLR::alg_RSP(void){
DeadlineOut() = DeadlineIn();
}

void FORTE_L3_CompletedPartHDLR::alg_TO(void){
Delay() = CIEC_TIME("1000ms");
}


void FORTE_L3_CompletedPartHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_CompletedPartHDLR::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L3_CompletedPartHDLR::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventINDID);
  alg_TO();
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_L3_CompletedPartHDLR::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
  sendOutputEvent( scm_nEventCNFID);
  sendOutputEvent( scm_nEventStopID);
}

void FORTE_L3_CompletedPartHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
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
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(1)
          enterStateSTART();
        else
        if(scm_nEventTimeoutID == pa_nEIID)
          enterStateREQ();
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


