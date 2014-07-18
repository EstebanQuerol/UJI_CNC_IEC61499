/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_BYTE_TO_BOOL
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-04-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_BYTE_TO_BOOL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_BYTE_TO_BOOL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_BYTE_TO_BOOL, g_nStringIdF_BYTE_TO_BOOL)

const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anDataInputTypeIds[] = {g_nStringIdBYTE};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_F_BYTE_TO_BOOL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_BYTE_TO_BOOL::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_BYTE_TO_BOOL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_BYTE_TO_BOOL::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_BYTE_TO_BOOL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_BYTE_TO_BOOL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_BYTE_TO_BOOL::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = BYTE_TO_BOOL(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



