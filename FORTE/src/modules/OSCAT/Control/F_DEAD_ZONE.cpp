/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_DEAD_ZONE
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_DEAD_ZONE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_DEAD_ZONE_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_DEAD_ZONE, g_nStringIdF_DEAD_ZONE)

const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdL};

const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_DEAD_ZONE::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_DEAD_ZONE::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_DEAD_ZONE::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_DEAD_ZONE::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_DEAD_ZONE::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_DEAD_ZONE::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_F_DEAD_ZONE::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = ::DEAD_ZONE(X(), L());
    sendOutputEvent(scm_nEventCNFID);
  }
}


