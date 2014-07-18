/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: RT_E_PERMIT
 *** Description: Permissive propagation of an event
 *** Version: 
 ***     0.0: 2008-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "RT_E_PERMIT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RT_E_PERMIT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_RT_E_PERMIT, g_nStringIdRT_E_PERMIT)

const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPERMIT, g_nStringIdTmin, g_nStringIdDeadline, g_nStringIdWCET};

const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_RT_E_PERMIT::scm_anEIWithIndexes[] = {0, 5};
const TDataIOID FORTE_RT_E_PERMIT::scm_anEIWith[] = {0, 2, 3, 4, 255, 1, 255};
const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdEI};

const TDataIOID FORTE_RT_E_PERMIT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_RT_E_PERMIT::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_RT_E_PERMIT::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO};

const SFBInterfaceSpec FORTE_RT_E_PERMIT::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};



FORTE_RT_E_PERMIT::FORTE_RT_E_PERMIT(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CRTEventSingle(
           pa_poSrcRes,
           &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           m_anFBConnData, m_anFBVarsData) {
}

bool FORTE_RT_E_PERMIT::checkActivation(int ){
  return PERMIT();
}





