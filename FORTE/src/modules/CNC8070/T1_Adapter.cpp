/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_Adapter
 *** Description: null
 *** Version: 
 *************************************************************************/

#include "T1_Adapter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T1_Adapter_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(FORTE_T1_Adapter, g_nStringIdT1_Adapter)

const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anDataInputNames[] = {g_nStringIdREQD, g_nStringIdRSPD};

const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anDataOutputNames[] = {g_nStringIdCNFD, g_nStringIdINDD};

const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const TDataIOID FORTE_T1_Adapter::scm_anEIWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_T1_Adapter::scm_anEIWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_T1_Adapter::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_T1_Adapter::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_T1_Adapter::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_T1_Adapter::scm_stFBInterfaceSpecSocket = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SFBInterfaceSpec FORTE_T1_Adapter::scm_stFBInterfaceSpecPlug = {
  2,  scm_anEventOutputNames,  scm_anEOWith,  scm_anEOWithIndexes,
  2,  scm_anEventInputNames,  scm_anEIWith, scm_anEIWithIndexes,  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0, 0
};



