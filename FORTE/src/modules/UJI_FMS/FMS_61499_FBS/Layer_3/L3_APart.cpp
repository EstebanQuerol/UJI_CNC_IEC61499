/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_APart
 *** Description: null
 *** Version: 
 *************************************************************************/

#include "L3_APart.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_APart_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(FORTE_L3_APart, g_nStringIdL3_APart)

const CStringDictionary::TStringId FORTE_L3_APart::scm_anDataInputNames[] = {g_nStringIdPartIDS, g_nStringIdFamilyS, g_nStringIdTypeS};

const CStringDictionary::TStringId FORTE_L3_APart::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_APart::scm_anDataOutputNames[] = {g_nStringIdPartIDP, g_nStringIdFamilyP, g_nStringIdTypeP, g_nStringIdLotsize, g_nStringIdDeadline};

const CStringDictionary::TStringId FORTE_L3_APart::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TDataIOID FORTE_L3_APart::scm_anEIWith[] = {2, 1, 0, 255};
const TForteInt16 FORTE_L3_APart::scm_anEIWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_L3_APart::scm_anEventInputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const TDataIOID FORTE_L3_APart::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 4, 1, 2, 255};
const TForteInt16 FORTE_L3_APart::scm_anEOWithIndexes[] = {0, 6, -1};
const CStringDictionary::TStringId FORTE_L3_APart::scm_anEventOutputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const SFBInterfaceSpec FORTE_L3_APart::scm_stFBInterfaceSpecSocket = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SFBInterfaceSpec FORTE_L3_APart::scm_stFBInterfaceSpecPlug = {
  2,  scm_anEventOutputNames,  scm_anEOWith,  scm_anEOWithIndexes,
  2,  scm_anEventInputNames,  scm_anEIWith, scm_anEIWithIndexes,  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0, 0
};



