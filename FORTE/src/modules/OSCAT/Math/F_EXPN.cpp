/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_EXPN
 *** Description: calculates X to the power of N (Y = X^N)
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_EXPN.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_EXPN_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_EXPN, g_nStringIdF_EXPN)

const CStringDictionary::TStringId FORTE_F_EXPN::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_EXPN::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_F_EXPN::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_EXPN::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_EXPN::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_EXPN::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_EXPN::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_EXPN::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_EXPN::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_EXPN::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_EXPN::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_EXPN::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      OUT() = EXPN(X(),N());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



