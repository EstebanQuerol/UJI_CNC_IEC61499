/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_SHR
 *** Description: shift right
 *** Version: 
 ***     0.0: 2013-04-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_SHR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_SHR_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_SHR, g_nStringIdF_SHR)

const CStringDictionary::TStringId FORTE_F_SHR::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_SHR::scm_anDataInputTypeIds[] = {g_nStringIdANY_BIT, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_SHR::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_SHR::scm_anDataOutputTypeIds[] = {g_nStringIdANY_BIT};

const TForteInt16 FORTE_F_SHR::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_SHR::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_SHR::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_SHR::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_SHR::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_SHR::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_SHR::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_SHR::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
	anyBitFBHelper<FORTE_F_SHR>(IN().getDataTypeID(), *this);
	sendOutputEvent(scm_nEventCNFID);
  }
}



