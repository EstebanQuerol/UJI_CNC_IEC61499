/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_HYST_2
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-31/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_HYST_2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_HYST_2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_HYST_2, g_nStringIdFB_HYST_2)

const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdVAL, g_nStringIdHYS};

const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdWIN};

const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_HYST_2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_FB_HYST_2::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_FB_HYST_2::scm_anEOWith[] = {1, 0, 255};
const TForteInt16 FORTE_FB_HYST_2::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_HYST_2::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_HYST_2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_FB_HYST_2::alg_REQ(void){
	CIEC_REAL tmp;

tmp = VAL()-HYS()*0.5f;
if((IN() < tmp)){
	Q() = false;
	WIN() = false;
}
else
  if((IN() > tmp+HYS())){
	Q() = true;
	WIN() = false;
}
else{
	WIN() = true;
};
}


void FORTE_FB_HYST_2::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_HYST_2::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_HYST_2::executeEvent(int pa_nEIID){
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


