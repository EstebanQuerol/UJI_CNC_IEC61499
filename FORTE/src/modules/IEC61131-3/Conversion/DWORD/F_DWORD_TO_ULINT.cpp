/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_DWORD_TO_ULINT
 *** Description: convert DWORD to ULINT
 *** Version: 
 ***     0.0: 2011-12-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_DWORD_TO_ULINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_DWORD_TO_ULINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_DWORD_TO_ULINT, g_nStringIdF_DWORD_TO_ULINT)

const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anDataInputTypeIds[] = {g_nStringIdDWORD};

const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anDataOutputTypeIds[] = {g_nStringIdULINT};

const TForteInt16 FORTE_F_DWORD_TO_ULINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_DWORD_TO_ULINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_DWORD_TO_ULINT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_DWORD_TO_ULINT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_DWORD_TO_ULINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_DWORD_TO_ULINT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_DWORD_TO_ULINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = DWORD_TO_ULINT(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



