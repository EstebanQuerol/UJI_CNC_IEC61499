/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_SQRT
 *** Description: square root
 *** Version: 
 ***     0.0: 2013-04-24/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_SQRT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_SQRT_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_SQRT, g_nStringIdF_SQRT)

const CStringDictionary::TStringId FORTE_F_SQRT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_SQRT::scm_anDataInputTypeIds[] = {g_nStringIdANY_REAL};

const CStringDictionary::TStringId FORTE_F_SQRT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_SQRT::scm_anDataOutputTypeIds[] = {g_nStringIdANY_REAL};

const TForteInt16 FORTE_F_SQRT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_SQRT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_SQRT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_SQRT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_SQRT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_SQRT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_SQRT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_SQRT::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyRealFBHelper<FORTE_F_SQRT>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



