/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTRL_OUT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_CTRL_OUT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CTRL_OUT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_CTRL_OUT, g_nStringIdFB_CTRL_OUT)

const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anDataInputNames[] = {g_nStringIdCI, g_nStringIdOFFSET, g_nStringIdMAN_IN, g_nStringIdLIM_L, g_nStringIdLIM_H, g_nStringIdMANUAL};

const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_CTRL_OUT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_FB_CTRL_OUT::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_FB_CTRL_OUT::scm_anEOWith[] = {1, 0, 255};
const TForteInt16 FORTE_FB_CTRL_OUT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_CTRL_OUT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_CTRL_OUT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_FB_CTRL_OUT::alg_REQ(void){
  Y() = SEL(MANUAL(),CI(),MAN_IN())+OFFSET();

  /*  Limit the output */
  if((Y() > LIM_L()) && (Y() < LIM_H())){
    LIM() = false;
  }
  else{
    Y() = LIMIT(LIM_L(),Y(),LIM_H());
    LIM() = true;
  };
}


void FORTE_FB_CTRL_OUT::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_CTRL_OUT::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_CTRL_OUT::executeEvent(int pa_nEIID){
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
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


