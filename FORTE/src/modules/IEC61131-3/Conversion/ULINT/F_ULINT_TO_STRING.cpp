/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_ULINT_TO_STRING
 *** Description: convert ULINT to STRING
 *** Version: 
 ***     0.0: 2012-01-18/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_ULINT_TO_STRING.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_ULINT_TO_STRING_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_ULINT_TO_STRING, g_nStringIdF_ULINT_TO_STRING)

const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anDataInputTypeIds[] = {g_nStringIdULINT};

const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_F_ULINT_TO_STRING::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_ULINT_TO_STRING::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_ULINT_TO_STRING::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_ULINT_TO_STRING::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_ULINT_TO_STRING::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_ULINT_TO_STRING::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_ULINT_TO_STRING::executeEvent(int pa_nEIID){
	if(scm_nEventREQID == pa_nEIID){
		OUT() = ULINT_TO_STRING(IN());
		sendOutputEvent(scm_nEventCNFID);
	}
}



