/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_DERIV
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-07-04/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_DERIV.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_DERIV_gen.cpp"
#endif
#include "../Measurement/F_T_PLC_US.h"

DEFINE_FIRMWARE_FB(FORTE_FB_FT_DERIV, g_nStringIdFB_FT_DERIV)

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anDataInputNames[] = {g_nStringIdin, g_nStringIdK};

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anDataOutputNames[] = {g_nStringIdout};

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_DERIV::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_FB_FT_DERIV::scm_anEIWith[] = {0, 1, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdrun};

const TDataIOID FORTE_FB_FT_DERIV::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_FT_DERIV::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anInternalsNames[] = {g_nStringIdold, g_nStringIdtx, g_nStringIdlast, g_nStringIdtc};

const CStringDictionary::TStringId FORTE_FB_FT_DERIV::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdDWORD, g_nStringIdDWORD, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_FB_FT_DERIV::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_FT_DERIV::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_FB_FT_DERIV::setInitialValues(){
  K() = 1.0;
}

void FORTE_FB_FT_DERIV::alg_INIT(void){
old() = in();

}

void FORTE_FB_FT_DERIV::alg_run(void){
tx() = T_PLC_US();
tc() = DWORD_TO_REAL(tx() - last());
last() = tx();

if(tc() > 0.0){
	out() = (in() - old()) / tc() * 1000000.0f * K();
	old() = in();
}else{
	out() = 0.0;
}

}


void FORTE_FB_FT_DERIV::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_FT_DERIV::enterStateinitialize(void){
  m_nECCState = scm_nStateinitialize;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_FT_DERIV::enterStaterun(void){
  m_nECCState = scm_nStaterun;
  alg_run();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_DERIV::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateinitialize();
        else
        if(scm_nEventrunID == pa_nEIID)
          enterStaterun();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateinitialize:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStaterun:
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


