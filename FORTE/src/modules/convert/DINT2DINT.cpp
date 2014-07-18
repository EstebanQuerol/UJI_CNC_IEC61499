/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: DINT2DINT
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "DINT2DINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DINT2DINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(DINT2DINT, g_nStringIdDINT2DINT)

const CStringDictionary::TStringId DINT2DINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId DINT2DINT::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId DINT2DINT::scm_aunDIDataTypeIds[] = {g_nStringIdDINT};
const CStringDictionary::TStringId DINT2DINT::scm_aunDODataTypeIds[] = {g_nStringIdDINT};

const TForteInt16 DINT2DINT::scm_anEIWithIndexes[] = {0};
const TDataIOID DINT2DINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId DINT2DINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID DINT2DINT::scm_anEOWith[] = {0, 255};
const TForteInt16 DINT2DINT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId DINT2DINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec DINT2DINT::scm_stFBInterfaceSpec = {
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

void DINT2DINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}


DINT2DINT::~DINT2DINT(){
}



