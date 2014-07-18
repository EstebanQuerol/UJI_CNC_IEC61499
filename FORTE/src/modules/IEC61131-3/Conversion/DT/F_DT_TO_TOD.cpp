/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_DT_TO_TOD
 *** Description: convert TIME to BOOL
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_DT_TO_TOD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_DT_TO_TOD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_DT_TO_TOD, g_nStringIdF_DT_TO_TOD)

const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anDataInputTypeIds[] = {g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anDataOutputTypeIds[] = {g_nStringIdTIME_OF_DAY};

const TForteInt16 FORTE_F_DT_TO_TOD::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_DT_TO_TOD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_DT_TO_TOD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_DT_TO_TOD::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_DT_TO_TOD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_DT_TO_TOD::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_DT_TO_TOD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = DT_TO_TOD(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
