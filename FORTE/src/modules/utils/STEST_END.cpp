/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: STEST_END
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-02-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "STEST_END.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "STEST_END_gen.cpp"
#endif
#include <RMT_DEV.h>

DEFINE_FIRMWARE_FB(FORTE_STEST_END, g_nStringIdSTEST_END)

const TForteInt16 FORTE_STEST_END::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_STEST_END::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_STEST_END::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_STEST_END::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_STEST_END::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};

void FORTE_STEST_END::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  getResource().getDevice().changeFBExecutionState(cg_nMGM_CMD_Kill);
	}
}



