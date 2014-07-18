/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_LWORD_TO_WSTRING
 *** Description: convert LWORD to WSTRING
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_LWORD_TO_WSTRING.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_LWORD_TO_WSTRING_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_LWORD_TO_WSTRING, g_nStringIdF_LWORD_TO_WSTRING)

const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anDataInputTypeIds[] = {g_nStringIdLWORD};

const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anDataOutputTypeIds[] = {g_nStringIdWSTRING};

const TForteInt16 FORTE_F_LWORD_TO_WSTRING::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_LWORD_TO_WSTRING::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_LWORD_TO_WSTRING::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_LWORD_TO_WSTRING::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_LWORD_TO_WSTRING::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_LWORD_TO_WSTRING::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_LWORD_TO_WSTRING::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = LWORD_TO_WSTRING(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
