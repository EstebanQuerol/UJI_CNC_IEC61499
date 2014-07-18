/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PT1
 *** Description: low pass filter with a programmable time T and faktor K
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PT1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PT1_gen.cpp"
#endif
#include "../Measurement/F_T_PLC_US.h"

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PT1, g_nStringIdFB_FT_PT1)

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdT, g_nStringIdK};

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdTIME, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_PT1::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_FB_FT_PT1::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_PT1::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_FT_PT1::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anInternalsNames[] = {g_nStringIdtx, g_nStringIdlast};

const CStringDictionary::TStringId FORTE_FB_FT_PT1::scm_anInternalsTypeIds[] = {g_nStringIdDWORD, g_nStringIdDWORD};

const SFBInterfaceSpec FORTE_FB_FT_PT1::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_FT_PT1::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_FB_FT_PT1::setInitialValues(){
  T().fromString("T#1s");
  K() = 1.0;
}

void FORTE_FB_FT_PT1::alg_REQ(void){
tx() = T_PLC_US();
OUT() = OUT() + (IN() * K() - OUT()) * DWORD_TO_REAL(tx() - last()) / (TIME_TO_REAL(T()) * 1.0E6f);
last() = tx();

}

void FORTE_FB_FT_PT1::alg_INIT(void){
tx() = T_PLC_US();
OUT() = K() * IN();
last() = tx();

}


void FORTE_FB_FT_PT1::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_FT_PT1::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_FT_PT1::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_PT1::enterStateREQt0(void){
  m_nECCState = scm_nStateREQt0;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_PT1::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if((scm_nEventREQID == pa_nEIID) && (T() != 0))
          enterStateREQ();
        else
        if((scm_nEventREQID == pa_nEIID) && (T() == 0))
          enterStateREQt0();
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
      case scm_nStateREQt0:
        if(1)
          enterStateSTART();
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


