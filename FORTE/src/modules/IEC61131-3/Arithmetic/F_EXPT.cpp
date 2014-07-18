/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_EXPT
 *** Description: Adds two number values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_EXPT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_EXPT_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_EXPT, g_nStringIdF_EXPT)

const CStringDictionary::TStringId FORTE_F_EXPT::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_EXPT::scm_anDataInputTypeIds[] = {g_nStringIdANY_REAL, g_nStringIdANY_REAL};

const CStringDictionary::TStringId FORTE_F_EXPT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_EXPT::scm_anDataOutputTypeIds[] = {g_nStringIdANY_REAL};

const TForteInt16 FORTE_F_EXPT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_EXPT::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_F_EXPT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_EXPT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_EXPT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_EXPT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_EXPT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_EXPT::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
	anyRealFBHelper<FORTE_F_EXPT>(IN1().getDataTypeID(), *this);
	sendOutputEvent(scm_nEventCNFID);
  }
}

