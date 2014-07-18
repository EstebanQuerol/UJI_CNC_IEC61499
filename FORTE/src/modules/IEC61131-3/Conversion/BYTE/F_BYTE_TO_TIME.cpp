/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_BYTE_TO_TIME
 *** Description: convert BYTE to TIME
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_BYTE_TO_TIME.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_BYTE_TO_TIME_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_BYTE_TO_TIME, g_nStringIdF_BYTE_TO_TIME)

const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anDataInputTypeIds[] = {g_nStringIdBYTE};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anDataOutputTypeIds[] = {g_nStringIdTIME};

const TForteInt16 FORTE_F_BYTE_TO_TIME::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_BYTE_TO_TIME::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_BYTE_TO_TIME::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_BYTE_TO_TIME::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_BYTE_TO_TIME::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_BYTE_TO_TIME::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_BYTE_TO_TIME::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = BYTE_TO_TIME(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
