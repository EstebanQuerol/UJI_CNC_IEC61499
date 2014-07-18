/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: E_TimeOut
 *** Description: Simple implementation of the timeout services
 *** Version: 
 ***     1.0: 2012-12-18/AZ - 4DIAC-Consortium - null
 *************************************************************************/

#include "E_TimeOut.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_TimeOut_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_E_TimeOut, g_nStringIdE_TimeOut)

const TForteInt16 FORTE_E_TimeOut::scm_anEOWithIndexes[] = { -1 };
const SAdapterInstanceDef FORTE_E_TimeOut::scm_astAdapterInstances[] = { { g_nStringIdATimeOut, g_nStringIdTimeOutSocket, false } };

const SFBInterfaceSpec FORTE_E_TimeOut::scm_stFBInterfaceSpec = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, scm_astAdapterInstances };

void FORTE_E_TimeOut::executeEvent(int pa_nEIID){
  if(cg_nExternalEventID == pa_nEIID){
    m_bActive = false;
    sendAdapterEvent(scm_nTimeOutSocketAdpNum, FORTE_ATimeOut::scm_nEventTimeOutID);
  }
  else if(TimeOutSocket().START() == pa_nEIID){
    if(!m_bActive){
      setEventChainExecutor(m_poInvokingExecEnv);  // delay notification should be execute in the same thread on as from where it has been triggered.
      CTimerHandler::sm_poFORTETimer->registerTimedFB(&m_stTimeListEntry, TimeOutSocket().DT());
      m_bActive = true;
    }
  }
  else if(TimeOutSocket().STOP() == pa_nEIID){
    if(m_bActive){
      CTimerHandler::sm_poFORTETimer->unregisterTimedFB(this);
      m_bActive = false;
    }
  }
}

EMGMResponse FORTE_E_TimeOut::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse eRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  if((e_RDY == eRetVal) && ((cg_nMGM_CMD_Stop == pa_unCommand) || (cg_nMGM_CMD_Kill == pa_unCommand))){
    if(m_bActive){
      CTimerHandler::sm_poFORTETimer->unregisterTimedFB(this);
      m_bActive = false;
    }
  }
  return eRetVal;
}

