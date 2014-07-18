/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_TIME_TO_REAL
 *** Description: convert TIME to REAL
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_TIME_TO_REAL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_TIME_TO_REAL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_TIME_TO_REAL, g_nStringIdF_TIME_TO_REAL)

const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anDataInputTypeIds[] = {g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_TIME_TO_REAL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_TIME_TO_REAL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_TIME_TO_REAL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_TIME_TO_REAL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_TIME_TO_REAL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_TIME_TO_REAL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_TIME_TO_REAL::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = TIME_TO_REAL(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



