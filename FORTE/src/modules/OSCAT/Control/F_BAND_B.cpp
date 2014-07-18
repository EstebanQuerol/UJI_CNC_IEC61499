/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_BAND_B
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_BAND_B.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_BAND_B_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_BAND_B, g_nStringIdF_BAND_B)

const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdB};

const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anDataInputTypeIds[] = {g_nStringIdBYTE, g_nStringIdBYTE};

const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anDataOutputTypeIds[] = {g_nStringIdBYTE};

const TForteInt16 FORTE_F_BAND_B::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_BAND_B::scm_anEIWith[] = {1, 0, 255};
const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_BAND_B::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_BAND_B::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_BAND_B::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_BAND_B::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_F_BAND_B::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
      OUT() = ::BAND_B(X(), B());
      sendOutputEvent(scm_nEventCNFID);
  }
}


