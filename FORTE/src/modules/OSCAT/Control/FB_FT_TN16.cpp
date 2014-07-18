/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_TN16
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-28/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_TN16.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_TN16_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_TN16, g_nStringIdFB_FT_TN16)

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdT};

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_TN16::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_FB_FT_TN16::scm_anEIWith[] = {0, 1, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_TN16::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_FT_TN16::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anInternalsNames[] = {g_nStringIdlength, g_nStringIdX, g_nStringIdcnt, g_nStringIdlast, g_nStringIdtx};

const CStringDictionary::TStringId FORTE_FB_FT_TN16::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 16, g_nStringIdREAL, g_nStringIdINT, g_nStringIdTIME, g_nStringIdTIME};

const SFBInterfaceSpec FORTE_FB_FT_TN16::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_FT_TN16::scm_stInternalVars = {5, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_FB_FT_TN16::setInitialValues(){
  length() = 16;
}

void FORTE_FB_FT_TN16::alg_INIT(void){
X()[cnt()] = IN();
last() = TIME();
}

void FORTE_FB_FT_TN16::alg_REQ(void){
if((cnt() == length()-1)){
cnt() = 0;
}
else{
cnt() = cnt()+1;
};

OUT() = X()[cnt()];
X()[cnt()] = IN();
last() = tx();
}

void FORTE_FB_FT_TN16::alg_checkTime(void){
tx() = TIME();
}


void FORTE_FB_FT_TN16::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_FT_TN16::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_FT_TN16::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_TN16::enterStatecheckTime(void){
  m_nECCState = scm_nStatecheckTime;
  alg_checkTime();
}

void FORTE_FB_FT_TN16::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStatecheckTime();
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
      case scm_nStatecheckTime:
        if(scm_nEventREQID == pa_nEIID)
          enterStatecheckTime();
        else
        if(tx()-last() >= T()/length())
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


