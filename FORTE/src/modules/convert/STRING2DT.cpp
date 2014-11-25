/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: STRING2DT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-11-24/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "STRING2DT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "STRING2DT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_STRING2DT, g_nStringIdSTRING2DT)

const CStringDictionary::TStringId FORTE_STRING2DT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_STRING2DT::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_STRING2DT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_STRING2DT::scm_anDataOutputTypeIds[] = {g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_STRING2DT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_STRING2DT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_STRING2DT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_STRING2DT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_STRING2DT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_STRING2DT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_STRING2DT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_STRING2DT::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
		char acBuffer[30];
		IN().toString(&acBuffer[0], 30, 3);
		OUT().fromString(acBuffer);
		sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



