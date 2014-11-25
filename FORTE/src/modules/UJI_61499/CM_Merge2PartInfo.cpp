/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_Merge2PartInfo
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "CM_Merge2PartInfo.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CM_Merge2PartInfo_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CM_Merge2PartInfo, g_nStringIdCM_Merge2PartInfo)

const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anDataInputNames[] = {g_nStringIdPartInfo1, g_nStringIdPartInfo2};

const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdARRAY, 3, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anDataOutputNames[] = {g_nStringIdPartInfoOut};

const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT};

const TForteInt16 FORTE_CM_Merge2PartInfo::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_CM_Merge2PartInfo::scm_anEIWith[] = {0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anEventInputNames[] = {g_nStringIdREQ1, g_nStringIdREQ2};

const TDataIOID FORTE_CM_Merge2PartInfo::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_CM_Merge2PartInfo::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_CM_Merge2PartInfo::scm_anEventOutputNames[] = {g_nStringIdCNF1, g_nStringIdCNF2};

const SFBInterfaceSpec FORTE_CM_Merge2PartInfo::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_CM_Merge2PartInfo::alg_REQ1(void){
PartInfoOut()[0] = PartInfo1()[0];
PartInfoOut()[1] = PartInfo1()[1];
PartInfoOut()[2] = PartInfo1()[2];
}

void FORTE_CM_Merge2PartInfo::alg_REQ2(void){
PartInfoOut()[0] = PartInfo2()[0];
PartInfoOut()[1] = PartInfo2()[1];
PartInfoOut()[2] = PartInfo2()[2];
}


void FORTE_CM_Merge2PartInfo::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_CM_Merge2PartInfo::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ1();
  sendOutputEvent( scm_nEventCNF1ID);
}

void FORTE_CM_Merge2PartInfo::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  alg_REQ2();
  sendOutputEvent( scm_nEventCNF2ID);
}

void FORTE_CM_Merge2PartInfo::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateREQ1();
        else
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateREQ2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ2:
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


