/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_STRING_TO_UINT
 *** Description: convert STRING to UINT
 *** Version: 
 ***     0.0: 2012-02-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_STRING_TO_UINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_STRING_TO_UINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_STRING_TO_UINT, g_nStringIdF_STRING_TO_UINT)

const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anDataOutputTypeIds[] = {g_nStringIdUINT};

const TForteInt16 FORTE_F_STRING_TO_UINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_STRING_TO_UINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_STRING_TO_UINT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_STRING_TO_UINT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_STRING_TO_UINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_STRING_TO_UINT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_STRING_TO_UINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = STRING_TO_UINT(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}



