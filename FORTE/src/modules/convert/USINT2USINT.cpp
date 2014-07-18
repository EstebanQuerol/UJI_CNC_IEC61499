/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: USINT2USINT
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "USINT2USINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "USINT2USINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(USINT2USINT, g_nStringIdUSINT2USINT)

const CStringDictionary::TStringId USINT2USINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId USINT2USINT::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId USINT2USINT::scm_aunDIDataTypeIds[] = {g_nStringIdUSINT};
const CStringDictionary::TStringId USINT2USINT::scm_aunDODataTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 USINT2USINT::scm_anEIWithIndexes[] = {0};
const TDataIOID USINT2USINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId USINT2USINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID USINT2USINT::scm_anEOWith[] = {0, 255};
const TForteInt16 USINT2USINT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId USINT2USINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec USINT2USINT::scm_stFBInterfaceSpec = {
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

void USINT2USINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

USINT2USINT::~USINT2USINT(){
}



