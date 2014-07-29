/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_InsArray
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-07-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "T1_InsArray.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T1_InsArray_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_T1_InsArray, g_nStringIdT1_InsArray)

const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anDataInputNames[] = {g_nStringIdQI};

const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdInsArray};

const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 8, g_nStringIdSTRING};

const TForteInt16 FORTE_T1_InsArray::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_T1_InsArray::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_T1_InsArray::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_T1_InsArray::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_T1_InsArray::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_T1_InsArray::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_T1_InsArray::setInitialValues(){
  InsArray_Array().fromString("['T4 D1','M6','G0 G17 G90 G94 F1000','S1000 M3','Z100','G88 G99 X0 Y0 Z2 I-10 D2 J35 B3 L0.5 H500 V50','G87 G98 X105 Y0 Z2 I-10 D2 J21 K28 M1 Q8  B3 L1 H480 V30','G0 G80 Z100']");
}

void FORTE_T1_InsArray::alg_INIT(void){

}

void FORTE_T1_InsArray::alg_REQ(void){

}


void FORTE_T1_InsArray::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_T1_InsArray::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_T1_InsArray::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_T1_InsArray::executeEvent(int pa_nEIID){
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


