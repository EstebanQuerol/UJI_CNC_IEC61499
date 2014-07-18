/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: BOOL2BOOL
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "BOOL2BOOL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BOOL2BOOL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(BOOL2BOOL, g_nStringIdBOOL2BOOL)

const CStringDictionary::TStringId BOOL2BOOL::scm_anDataInputNames[] = {g_nStringIdIN};
const CStringDictionary::TStringId BOOL2BOOL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId BOOL2BOOL::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL};
const CStringDictionary::TStringId BOOL2BOOL::scm_aunDODataTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 BOOL2BOOL::scm_anEIWithIndexes[] = {0};
const TDataIOID BOOL2BOOL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId BOOL2BOOL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID BOOL2BOOL::scm_anEOWith[] = {0, 255};
const TForteInt16 BOOL2BOOL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId BOOL2BOOL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec BOOL2BOOL::scm_stFBInterfaceSpec = {
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

void BOOL2BOOL::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

BOOL2BOOL::~BOOL2BOOL(){
}



