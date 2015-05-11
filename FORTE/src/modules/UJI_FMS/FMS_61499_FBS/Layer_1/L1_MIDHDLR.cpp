/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_MIDHDLR
 *** Description: Layer 1 Multicast identifiers handler
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_MIDHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_MIDHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_MIDHDLR, g_nStringIdL1_MIDHDLR)

const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anDataInputNames[] = {g_nStringIdQI};

const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_L1_MIDHDLR::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_L1_MIDHDLR::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L1_MIDHDLR::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_L1_MIDHDLR::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L1_MIDHDLR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_MIDHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L1_MIDHDLR::alg_INIT(void){

}

void FORTE_L1_MIDHDLR::alg_REQ(void){

}


void FORTE_L1_MIDHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L1_MIDHDLR::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L1_MIDHDLR::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L1_MIDHDLR::executeEvent(int pa_nEIID){
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


