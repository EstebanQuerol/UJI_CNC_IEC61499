/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: WSTRING2WSTRING
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "WSTRING2WSTRING.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WSTRING2WSTRING_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(WSTRING2WSTRING, g_nStringIdWSTRING2WSTRING)

const CStringDictionary::TStringId WSTRING2WSTRING::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId WSTRING2WSTRING::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId WSTRING2WSTRING::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};
const CStringDictionary::TStringId WSTRING2WSTRING::scm_aunDODataTypeIds[] = {g_nStringIdWSTRING};

const TForteInt16 WSTRING2WSTRING::scm_anEIWithIndexes[] = {0};
const TDataIOID WSTRING2WSTRING::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId WSTRING2WSTRING::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID WSTRING2WSTRING::scm_anEOWith[] = {0, 255};
const TForteInt16 WSTRING2WSTRING::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId WSTRING2WSTRING::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec WSTRING2WSTRING::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void WSTRING2WSTRING::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

WSTRING2WSTRING::~WSTRING2WSTRING(){
}



