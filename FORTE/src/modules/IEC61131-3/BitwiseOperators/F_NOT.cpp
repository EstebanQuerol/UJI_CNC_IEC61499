/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_NOT
 *** Description: standard bitwise boolean function (not)
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_NOT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_NOT_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_NOT, g_nStringIdF_NOT)

const CStringDictionary::TStringId FORTE_F_NOT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_NOT::scm_anDataInputTypeIds[] = {g_nStringIdANY_BIT};

const CStringDictionary::TStringId FORTE_F_NOT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_NOT::scm_anDataOutputTypeIds[] = {g_nStringIdANY_BIT};

const TForteInt16 FORTE_F_NOT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_NOT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_NOT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_NOT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_NOT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_NOT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_NOT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_NOT::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyBitFBHelper<FORTE_F_NOT>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



