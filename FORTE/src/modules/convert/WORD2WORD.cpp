/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: WORD2WORD
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "WORD2WORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WORD2WORD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(WORD2WORD, g_nStringIdWORD2WORD)

const CStringDictionary::TStringId WORD2WORD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId WORD2WORD::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId WORD2WORD::scm_aunDIDataTypeIds[] = {g_nStringIdWORD};
const CStringDictionary::TStringId WORD2WORD::scm_aunDODataTypeIds[] = {g_nStringIdWORD};

const TForteInt16 WORD2WORD::scm_anEIWithIndexes[] = {0};
const TDataIOID WORD2WORD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId WORD2WORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID WORD2WORD::scm_anEOWith[] = {0, 255};
const TForteInt16 WORD2WORD::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId WORD2WORD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec WORD2WORD::scm_stFBInterfaceSpec = {
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

void WORD2WORD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

WORD2WORD::~WORD2WORD(){
}



