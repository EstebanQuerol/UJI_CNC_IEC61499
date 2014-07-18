/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_SUB_DT_DT
 *** Description: Subtracts two time data types
 *** Version: 
 ***     1.0: 2013-09-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_SUB_DT_DT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_SUB_DT_DT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_SUB_DT_DT, g_nStringIdF_SUB_DT_DT)

const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anDataInputTypeIds[] = {g_nStringIdDATE_AND_TIME, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anDataOutputTypeIds[] = {g_nStringIdTIME};

const TForteInt16 FORTE_F_SUB_DT_DT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_SUB_DT_DT::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_SUB_DT_DT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_SUB_DT_DT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_SUB_DT_DT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_SUB_DT_DT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_SUB_DT_DT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = SUB_DT_DT(IN1(), IN2());
    sendOutputEvent(scm_nEventCNFID);
  }
}
