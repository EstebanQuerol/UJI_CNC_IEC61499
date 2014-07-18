/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: EMB_RMT_DEV
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2010-01-20/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/
#include "EMB_RMT_DEV.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EMB_RMT_DEV_gen.cpp"
#endif
#include <stringdict.h>

const SFBInterfaceSpec EMB_RMT_DEV::scm_stFBInterfaceSpec = { 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0,
    0};

EMB_RMT_DEV::EMB_RMT_DEV(const char * pa_acId) :
  CDevice(&scm_stFBInterfaceSpec, CStringDictionary::scm_nInvalidStringId, 0, 0),
      MGR(g_nStringIdMGR, this, pa_acId){
}

EMB_RMT_DEV::~EMB_RMT_DEV(){
}

int EMB_RMT_DEV::startDevice(void){
  CDevice::startDevice();
  MGR.changeFBExecutionState(cg_nMGM_CMD_Start);
  return 0;
}

EMGMResponse EMB_RMT_DEV::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse eRetVal = CDevice::changeFBExecutionState(pa_unCommand);
  if((e_RDY == eRetVal) && (cg_nMGM_CMD_Kill == pa_unCommand)){
    MGR.changeFBExecutionState(cg_nMGM_CMD_Kill);
  }
  return eRetVal;
}
