/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_UDINT_TO_WORD
 *** Description: convert UDINT to WORD
 *** Version: 
 ***     0.0: 2011-12-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_UDINT_TO_WORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_UDINT_TO_WORD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_UDINT_TO_WORD, g_nStringIdF_UDINT_TO_WORD)

const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anDataInputTypeIds[] = {g_nStringIdUDINT};

const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anDataOutputTypeIds[] = {g_nStringIdWORD};

const TForteInt16 FORTE_F_UDINT_TO_WORD::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_UDINT_TO_WORD::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_UDINT_TO_WORD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_UDINT_TO_WORD::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_UDINT_TO_WORD::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_UDINT_TO_WORD::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_UDINT_TO_WORD::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = UDINT_TO_WORD(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



