/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_SHL
 *** Description: shift left
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_SHL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_SHL_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_SHL, g_nStringIdF_SHL)

const CStringDictionary::TStringId FORTE_F_SHL::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_SHL::scm_anDataInputTypeIds[] = {g_nStringIdANY_BIT, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_SHL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_SHL::scm_anDataOutputTypeIds[] = {g_nStringIdANY_BIT};

const TForteInt16 FORTE_F_SHL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_SHL::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_SHL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_SHL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_SHL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_SHL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_SHL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

 void FORTE_F_SHL::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyBitFBHelper<FORTE_F_SHL>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}
 
