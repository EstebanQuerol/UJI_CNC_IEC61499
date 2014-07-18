/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: REAL2REAL
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "REAL2REAL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "REAL2REAL_gen.cpp"
#endif

#ifdef FORTE_USE_REAL_DATATYPE

DEFINE_FIRMWARE_FB(REAL2REAL, g_nStringIdREAL2REAL)

const CStringDictionary::TStringId REAL2REAL::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId REAL2REAL::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId REAL2REAL::scm_aunDIDataTypeIds[] = {g_nStringIdREAL};
const CStringDictionary::TStringId REAL2REAL::scm_aunDODataTypeIds[] = {g_nStringIdREAL};

const TForteInt16 REAL2REAL::scm_anEIWithIndexes[] = {0};
const TDataIOID REAL2REAL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId REAL2REAL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID REAL2REAL::scm_anEOWith[] = {0, 255};
const TForteInt16 REAL2REAL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId REAL2REAL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec REAL2REAL::scm_stFBInterfaceSpec = {
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

void REAL2REAL::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

REAL2REAL::~REAL2REAL(){
}

#endif

