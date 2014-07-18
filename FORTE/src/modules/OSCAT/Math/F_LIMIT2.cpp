/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_LIMITx
 *** Description: limiter
 *** Version: 
 ***     0.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_LIMIT2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_LIMIT2_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_LIMIT2, g_nStringIdF_LIMIT2)

const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anDataInputNames[] = {g_nStringIdMN, g_nStringIdIN, g_nStringIdMX};

const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anDataInputTypeIds[] = {g_nStringIdANY_ELEMENTARY, g_nStringIdANY_ELEMENTARY, g_nStringIdANY_ELEMENTARY};

const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anDataOutputNames[] = {g_nStringIdLIM, g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdANY_ELEMENTARY};

const TForteInt16 FORTE_F_LIMIT2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_LIMIT2::scm_anEIWith[] = {0, 2, 1, 255};
const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_LIMIT2::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_F_LIMIT2::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_LIMIT2::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_LIMIT2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_LIMIT2::executeEvent(int pa_nEIID) {
  if (scm_nEventREQID == pa_nEIID) {
    anyElementaryFBHelper<FORTE_F_LIMIT2>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}

#ifdef FORTE_USE_WSTRING_DATATYPE
template<>
void FORTE_F_LIMIT2::calculateValue<CIEC_WSTRING>(){
  //TODO fill this function
}
#endif


