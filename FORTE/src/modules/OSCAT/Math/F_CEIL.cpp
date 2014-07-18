/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_CEIL
 *** Description: returns the smallest possible integer which is greater or equal to X
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_CEIL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_CEIL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_CEIL, g_nStringIdF_CEIL)

const CStringDictionary::TStringId FORTE_F_CEIL::scm_anDataInputNames[] = {g_nStringIdX};

const CStringDictionary::TStringId FORTE_F_CEIL::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_CEIL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_CEIL::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_F_CEIL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_CEIL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_CEIL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_CEIL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_CEIL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_CEIL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_CEIL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_CEIL::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      OUT() = CEIL(X());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



