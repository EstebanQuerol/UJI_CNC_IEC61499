/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_INT_TO_DWORD
 *** Description: convert INT to DWORD
 *** Version: 
 ***     0.0: 2011-12-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_INT_TO_DWORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_INT_TO_DWORD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_INT_TO_DWORD, g_nStringIdF_INT_TO_DWORD)

const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anDataOutputTypeIds[] = {g_nStringIdDWORD};

const TForteInt16 FORTE_F_INT_TO_DWORD::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_INT_TO_DWORD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_INT_TO_DWORD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_INT_TO_DWORD::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_INT_TO_DWORD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_INT_TO_DWORD::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_INT_TO_DWORD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = INT_TO_DWORD(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



