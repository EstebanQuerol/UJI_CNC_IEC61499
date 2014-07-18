/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_FT_LIMIT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2013-10-19/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_FT_LIMIT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_FT_LIMIT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_FT_LIMIT, g_nStringIdF_FT_LIMIT)

const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anDataInputNames[] = {g_nStringIdVAL, g_nStringIdLIM_L, g_nStringIdLIM_H};

const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anDataOutputNames[] = {g_nStringIdOUT, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_F_FT_LIMIT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_FT_LIMIT::scm_anEIWith[] = {1, 0, 2, 255};
const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_FT_LIMIT::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_F_FT_LIMIT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_FT_LIMIT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_FT_LIMIT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_FT_LIMIT::setInitialValues(){
  LIM_L() = -1.0E38;
  LIM_H() = 1.0E38;
}

void FORTE_F_FT_LIMIT::alg_REQ(void){

OUT() = VAL();

/*  limit the output */
if((OUT() < LIM_L())){
	LIM() = true;
	OUT() = LIM_L();
}
else
  if((OUT() > LIM_H())){
	LIM() = true;
	OUT() = LIM_H();
}
else{
	LIM() = false;
};
}


void FORTE_F_FT_LIMIT::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_F_FT_LIMIT::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_F_FT_LIMIT::executeEvent(int pa_nEIID){
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


