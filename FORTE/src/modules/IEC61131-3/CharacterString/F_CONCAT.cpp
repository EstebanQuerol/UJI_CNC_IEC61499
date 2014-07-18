/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_CONCAT
 *** Description: concatenation
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_CONCAT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_CONCAT_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_CONCAT, g_nStringIdF_CONCAT)

const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anDataInputTypeIds[] = {g_nStringIdANY_STRING, g_nStringIdANY_STRING};

const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anDataOutputTypeIds[] = {g_nStringIdANY_STRING};

const TForteInt16 FORTE_F_CONCAT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_CONCAT::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_CONCAT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_CONCAT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_CONCAT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_CONCAT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_CONCAT::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyStringFBHelper<FORTE_F_CONCAT>(IN1().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}
