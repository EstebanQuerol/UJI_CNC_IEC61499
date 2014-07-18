/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_TRUNC
 *** Description: truncation toward zero
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_TRUNC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_TRUNC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_TRUNC, g_nStringIdF_TRUNC)

const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anDataInputTypeIds[] = {g_nStringIdANY_REAL};

const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anDataOutputTypeIds[] = {g_nStringIdANY_INT};

const TForteInt16 FORTE_F_TRUNC::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_TRUNC::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_TRUNC::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_TRUNC::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_TRUNC::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_TRUNC::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_TRUNC::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    switch(IN().getDataTypeID()){
      case CIEC_ANY::e_REAL:
        OUT().setSignedValue(TRUNC(static_cast<CIEC_REAL &>(IN())));
        break;
      default:
        OUT().setSignedValue(TRUNC(static_cast<CIEC_LREAL &>(IN())));
        break;
    }
    sendOutputEvent(scm_nEventCNFID);
  }
}

