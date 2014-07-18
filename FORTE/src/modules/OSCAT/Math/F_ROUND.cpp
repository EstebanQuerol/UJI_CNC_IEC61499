/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_ROUND
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_ROUND.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_ROUND_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_ROUND, g_nStringIdF_ROUND)

const CStringDictionary::TStringId FORTE_F_ROUND::scm_anDataInputNames[] = {g_nStringIdin, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_ROUND::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_F_ROUND::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_ROUND::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_ROUND::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_ROUND::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_ROUND::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_ROUND::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_ROUND::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_ROUND::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_ROUND::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_ROUND::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      OUT() = ROUND(in(),N());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



