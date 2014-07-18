/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_RND
 *** Description: rounds a real down to n digits total, round(3.1415,2) = 3.1
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_RND.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_RND_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_RND, g_nStringIdF_RND)

const CStringDictionary::TStringId FORTE_F_RND::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_RND::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_F_RND::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_RND::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_RND::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_RND::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_RND::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_RND::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_RND::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_RND::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_RND::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_RND::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      OUT() = RND(X(),N());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



