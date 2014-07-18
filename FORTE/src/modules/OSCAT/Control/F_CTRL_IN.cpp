/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_CTRL_IN
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_CTRL_IN.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_CTRL_IN_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_CTRL_IN, g_nStringIdF_CTRL_IN)

const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anDataInputNames[] = {g_nStringIdSET_POINT, g_nStringIdACTUAL, g_nStringIdNOISE};

const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_CTRL_IN::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_CTRL_IN::scm_anEIWith[] = {1, 2, 0, 255};
const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_CTRL_IN::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_CTRL_IN::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_CTRL_IN::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_CTRL_IN::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_CTRL_IN::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = ::CTRL_IN(SET_POINT(), ACTUAL(), NOISE());
    sendOutputEvent(scm_nEventCNFID);
  }
}


