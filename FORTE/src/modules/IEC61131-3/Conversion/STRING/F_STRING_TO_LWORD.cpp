/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_STRING_TO_LWORD
 *** Description: convert STRING to LWORD
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_STRING_TO_LWORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_STRING_TO_LWORD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_STRING_TO_LWORD, g_nStringIdF_STRING_TO_LWORD)

const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anDataOutputTypeIds[] = {g_nStringIdLWORD};

const TForteInt16 FORTE_F_STRING_TO_LWORD::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_STRING_TO_LWORD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_STRING_TO_LWORD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_STRING_TO_LWORD::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_STRING_TO_LWORD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_STRING_TO_LWORD::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_STRING_TO_LWORD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = STRING_TO_LWORD(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
