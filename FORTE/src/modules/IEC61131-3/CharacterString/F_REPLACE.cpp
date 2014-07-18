/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_REPLACE
 *** Description: replace L characters of IN1 by IN2 starting at the P-th character position
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_REPLACE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_REPLACE_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_REPLACE, g_nStringIdF_REPLACE)

const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2, g_nStringIdL, g_nStringIdP};

const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anDataInputTypeIds[] = {g_nStringIdANY_STRING, g_nStringIdANY_STRING, g_nStringIdANY_INT, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anDataOutputTypeIds[] = {g_nStringIdANY_STRING};

const TForteInt16 FORTE_F_REPLACE::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_REPLACE::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_REPLACE::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_REPLACE::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_REPLACE::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_REPLACE::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_REPLACE::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyStringFBHelper<FORTE_F_REPLACE>(IN1().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}
