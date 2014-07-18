/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MUL
 *** Description: Multiplies two values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_MUL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_MUL_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_MUL, g_nStringIdF_MUL)

const CStringDictionary::TStringId FORTE_F_MUL::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_MUL::scm_anDataInputTypeIds[] = {g_nStringIdANY_NUM, g_nStringIdANY_NUM};

const CStringDictionary::TStringId FORTE_F_MUL::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_MUL::scm_anDataOutputTypeIds[] = {g_nStringIdANY_NUM};

const TForteInt16 FORTE_F_MUL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_MUL::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_MUL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_MUL::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_MUL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_MUL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_MUL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_MUL::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
      anyMagnitudeFBHelper<FORTE_F_MUL>(IN1().getDataTypeID(), *this);
      sendOutputEvent(scm_nEventCNFID);
  }
}



