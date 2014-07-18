/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_ROL
 *** Description: rotate left
 *** Version: 
 ***     0.0: 2013-04-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_ROL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_ROL_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_ROL, g_nStringIdF_ROL)

const CStringDictionary::TStringId FORTE_F_ROL::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdN};

const CStringDictionary::TStringId FORTE_F_ROL::scm_anDataInputTypeIds[] = {g_nStringIdANY_BIT, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_ROL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_ROL::scm_anDataOutputTypeIds[] = {g_nStringIdANY_BIT};

const TForteInt16 FORTE_F_ROL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_ROL::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_ROL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_ROL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_ROL::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_ROL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_ROL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_ROL::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
	anyBitFBHelper<FORTE_F_ROL>(IN().getDataTypeID(), *this);
	sendOutputEvent(scm_nEventCNFID);
  }
}



