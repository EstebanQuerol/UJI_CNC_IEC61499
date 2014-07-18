/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_INTEGRATE
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-07-12/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_INTEGRATE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_INTEGRATE_gen.cpp"
#endif
#include "../Measurement/F_T_PLC_MS.h"

DEFINE_FIRMWARE_FB(FORTE_FB_INTEGRATE, g_nStringIdFB_INTEGRATE)

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdK, g_nStringIdreset};

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anDataOutputNames[] = {g_nStringIdY_OUT};

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_INTEGRATE::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_FB_INTEGRATE::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_INTEGRATE::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_INTEGRATE::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anInternalsNames[] = {g_nStringIdX_last, g_nStringIdlast, g_nStringIdtx, g_nStringIdY_intern};

const CStringDictionary::TStringId FORTE_FB_INTEGRATE::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdDWORD, g_nStringIdDWORD, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_FB_INTEGRATE::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_INTEGRATE::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_FB_INTEGRATE::setInitialValues(){
  K() = 1.0f;
}

void FORTE_FB_INTEGRATE::alg_INIT(void){
X_last() = X();
}

void FORTE_FB_INTEGRATE::alg_REQ(void){
if((reset())){
	Y_intern() = 0.0;
}
else{
	tx() = T_PLC_MS();
	Y_intern() = ((X()+X_last()))*0.5E-3f*DWORD_TO_REAL((tx()-last()))*K()+Y_intern();
	X_last() = X();
	last() = tx();
};

Y_OUT() = Y_intern();
}


void FORTE_FB_INTEGRATE::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_INTEGRATE::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_INTEGRATE::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_INTEGRATE::executeEvent(int pa_nEIID){
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


