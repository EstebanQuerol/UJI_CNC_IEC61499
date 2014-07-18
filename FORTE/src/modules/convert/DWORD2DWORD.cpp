/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: DWORD2DWORD
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "DWORD2DWORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DWORD2DWORD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(DWORD2DWORD, g_nStringIdDWORD2DWORD)


const CStringDictionary::TStringId DWORD2DWORD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId DWORD2DWORD::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId DWORD2DWORD::scm_aunDIDataTypeIds[] = {g_nStringIdDWORD};
const CStringDictionary::TStringId DWORD2DWORD::scm_aunDODataTypeIds[] = {g_nStringIdDWORD};

const TForteInt16 DWORD2DWORD::scm_anEIWithIndexes[] = {0};
const TDataIOID DWORD2DWORD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId DWORD2DWORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID DWORD2DWORD::scm_anEOWith[] = {0, 255};
const TForteInt16 DWORD2DWORD::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId DWORD2DWORD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec DWORD2DWORD::scm_stFBInterfaceSpec = {
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

void DWORD2DWORD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

DWORD2DWORD::~DWORD2DWORD(){
}



