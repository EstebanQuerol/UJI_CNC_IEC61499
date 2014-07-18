/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_ADD_TOD_TIME
 *** Description: Adds two number values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_ADD_TOD_TIME.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_ADD_TOD_TIME_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_ADD_TOD_TIME, g_nStringIdF_ADD_TOD_TIME)

const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anDataInputTypeIds[] = {g_nStringIdTIME_OF_DAY, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anDataOutputTypeIds[] = {g_nStringIdTIME_OF_DAY};

const TForteInt16 FORTE_F_ADD_TOD_TIME::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_ADD_TOD_TIME::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_ADD_TOD_TIME::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_ADD_TOD_TIME::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_ADD_TOD_TIME::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_ADD_TOD_TIME::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_ADD_TOD_TIME::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = ADD_TOD_TIME(IN1(), IN2());
    sendOutputEvent(scm_nEventCNFID);
  }
}
