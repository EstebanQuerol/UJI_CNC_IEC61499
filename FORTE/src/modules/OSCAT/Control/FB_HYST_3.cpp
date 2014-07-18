/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_HYST_3
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-31/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_HYST_3.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_HYST_3_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_HYST_3, g_nStringIdFB_HYST_3)

const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdHYS, g_nStringIdVAL1, g_nStringIdVAL2};

const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anDataOutputNames[] = {g_nStringIdQ1, g_nStringIdQ2, g_nStringIdWIN};

const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_HYST_3::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_FB_HYST_3::scm_anEIWith[] = {0, 2, 1, 3, 255};
const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_FB_HYST_3::scm_anEOWith[] = {2, 0, 1, 255};
const TForteInt16 FORTE_FB_HYST_3::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_HYST_3::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_HYST_3::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_FB_HYST_3::alg_REQ(void){
  CIEC_REAL X;

X = HYS()*0.5f;

if((IN() < VAL1()-X)){
	Q1() = true;
}
else
  if((IN() > VAL1() + X)){
	Q1() = false;
};

if((IN() < VAL2()-X)){
	Q2() = false;
}
else
  if((IN() > VAL2()+X)){
	Q2() = true;
};
}


void FORTE_FB_HYST_3::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_HYST_3::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_HYST_3::executeEvent(int pa_nEIID){
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


