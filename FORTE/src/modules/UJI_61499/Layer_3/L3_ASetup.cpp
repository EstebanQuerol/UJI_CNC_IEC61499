/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ASetup
 *** Description: null
 *** Version: 
 *************************************************************************/

#include "L3_ASetup.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_ASetup_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(FORTE_L3_ASetup, g_nStringIdL3_ASetup)

const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anDataInputNames[] = {g_nStringIdPartInfoS, g_nStringIdENDID};

const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anDataOutputNames[] = {g_nStringIdPartInfoP, g_nStringIdMID, g_nStringIdSetup};

const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdSTRING};

const TDataIOID FORTE_L3_ASetup::scm_anEIWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_L3_ASetup::scm_anEIWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anEventInputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const TDataIOID FORTE_L3_ASetup::scm_anEOWith[] = {0, 1, 2, 255, 1, 255};
const TForteInt16 FORTE_L3_ASetup::scm_anEOWithIndexes[] = {0, 4, -1};
const CStringDictionary::TStringId FORTE_L3_ASetup::scm_anEventOutputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const SFBInterfaceSpec FORTE_L3_ASetup::scm_stFBInterfaceSpecSocket = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SFBInterfaceSpec FORTE_L3_ASetup::scm_stFBInterfaceSpecPlug = {
  2,  scm_anEventOutputNames,  scm_anEOWith,  scm_anEOWithIndexes,
  2,  scm_anEventInputNames,  scm_anEIWith, scm_anEIWithIndexes,  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0, 0
};



