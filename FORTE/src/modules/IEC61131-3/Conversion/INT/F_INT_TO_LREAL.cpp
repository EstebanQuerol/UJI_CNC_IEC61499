/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_INT_TO_LREAL
 *** Description: convert INT to LREAL
 *** Version: 
 ***     0.0: 2011-06-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_INT_TO_LREAL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_INT_TO_LREAL_gen.cpp"
#endif

#ifdef FORTE_USE_REAL_DATATYPE

#ifdef FORTE_USE_64BIT_DATATYPES


DEFINE_FIRMWARE_FB(FORTE_F_INT_TO_LREAL, g_nStringIdF_INT_TO_LREAL)

const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anDataOutputTypeIds[] = {g_nStringIdLREAL};

const TForteInt16 FORTE_F_INT_TO_LREAL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_INT_TO_LREAL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_INT_TO_LREAL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_INT_TO_LREAL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_INT_TO_LREAL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_INT_TO_LREAL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_INT_TO_LREAL::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = INT_TO_LREAL(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}

#endif
#endif

