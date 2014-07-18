/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_FIND
 *** Description: find the character position of the beginning of the first occurrence of IN2 in IN1, no occurrence returns 0
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_FIND.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_FIND_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_FIND, g_nStringIdF_FIND)

const CStringDictionary::TStringId FORTE_F_FIND::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_FIND::scm_anDataInputTypeIds[] = {g_nStringIdANY_STRING, g_nStringIdANY_STRING};

const CStringDictionary::TStringId FORTE_F_FIND::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_FIND::scm_anDataOutputTypeIds[] = {g_nStringIdANY_INT};

const TForteInt16 FORTE_F_FIND::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_FIND::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_FIND::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_FIND::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_FIND::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_FIND::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_FIND::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_FIND::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyStringFBHelper<FORTE_F_FIND>(IN1().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}
