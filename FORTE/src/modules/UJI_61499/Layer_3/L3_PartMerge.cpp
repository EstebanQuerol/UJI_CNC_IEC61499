/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PartMerge
 *** Description: Part adapter encapculation
 *** Version: 
 ***     0.0: 2014-09-24/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_PartMerge.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_PartMerge_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_PartMerge, g_nStringIdL3_PartMerge)

const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anDataInputNames[] = {g_nStringIdPartIDP1, g_nStringIdFamilyP1, g_nStringIdTypeP1, g_nStringIdLotsize1, g_nStringIdDeadline1, g_nStringIdFamilyP2, g_nStringIdTypeP2, g_nStringIdDeadline2};

const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anDataOutputNames[] = {g_nStringIdPartIDP, g_nStringIdFamilyP, g_nStringIdTypeP, g_nStringIdLotsize, g_nStringIdDeadline};

const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_PartMerge::scm_anEIWithIndexes[] = {0, 6};
const TDataIOID FORTE_L3_PartMerge::scm_anEIWith[] = {1, 2, 3, 4, 0, 255, 5, 6, 7, 255};
const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anEventInputNames[] = {g_nStringIdREQIN, g_nStringIdRSPIN};

const TDataIOID FORTE_L3_PartMerge::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_L3_PartMerge::scm_anEOWithIndexes[] = {0, 6, -1};
const CStringDictionary::TStringId FORTE_L3_PartMerge::scm_anEventOutputNames[] = {g_nStringIdREQOUT, g_nStringIdRSPOUT};

const SFBInterfaceSpec FORTE_L3_PartMerge::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L3_PartMerge::alg_REQ(void){
/* Map input data into the adapter*/
PartIDP() = PartIDP1();
FamilyP() = FamilyP1();
TypeP() = TypeP1();
Lotsize() = Lotsize1();
Deadline() = Deadline1();
}

void FORTE_L3_PartMerge::alg_RSP(void){
/* Map input data into the adapter*/
FamilyP() = FamilyP2();
TypeP() = TypeP2();
Deadline() = Deadline2();
}


void FORTE_L3_PartMerge::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_PartMerge::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventREQOUTID);
}

void FORTE_L3_PartMerge::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
  sendOutputEvent( scm_nEventRSPOUTID);
}

void FORTE_L3_PartMerge::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQINID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventRSPINID == pa_nEIID)
          enterStateRSP();
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
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


