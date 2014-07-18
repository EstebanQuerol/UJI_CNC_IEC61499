/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_XOR
 *** Description: standard bitwise boolean function (xor)
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_XOR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_XOR_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_XOR, g_nStringIdF_XOR)

const CStringDictionary::TStringId FORTE_F_XOR::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_XOR::scm_anDataInputTypeIds[] = {g_nStringIdANY_BIT, g_nStringIdANY_BIT};

const CStringDictionary::TStringId FORTE_F_XOR::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_XOR::scm_anDataOutputTypeIds[] = {g_nStringIdANY_BIT};

const TForteInt16 FORTE_F_XOR::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_XOR::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_XOR::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_XOR::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_XOR::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_XOR::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_XOR::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_XOR::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyBitFBHelper<FORTE_F_XOR>(IN1().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



