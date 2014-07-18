/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_LEFT
 *** Description: leftmost L characters of IN
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_LEFT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_LEFT_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_LEFT, g_nStringIdF_LEFT)

const CStringDictionary::TStringId FORTE_F_LEFT::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdL};

const CStringDictionary::TStringId FORTE_F_LEFT::scm_anDataInputTypeIds[] = {g_nStringIdANY_STRING, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_LEFT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_LEFT::scm_anDataOutputTypeIds[] = {g_nStringIdANY_STRING};

const TForteInt16 FORTE_F_LEFT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_LEFT::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_LEFT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_LEFT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_LEFT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_LEFT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_LEFT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_LEFT::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyStringFBHelper<FORTE_F_LEFT>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



