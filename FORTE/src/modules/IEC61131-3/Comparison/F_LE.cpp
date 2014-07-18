/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_LE
 *** Description: equality
 *** Version: 
 ***     1.0: 2011-09-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_LE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_LE_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_LE, g_nStringIdF_LE)

const CStringDictionary::TStringId FORTE_F_LE::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_LE::scm_anDataInputTypeIds[] = {g_nStringIdANY_ELEMENTARY, g_nStringIdANY_ELEMENTARY};

const CStringDictionary::TStringId FORTE_F_LE::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_LE::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_F_LE::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_LE::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_LE::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_LE::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_LE::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_LE::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_LE::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_LE::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyElementaryFBHelper<FORTE_F_LE>(IN1().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



