/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "E_RESTART.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_RESTART_gen.cpp"
#endif
#include "../../core/device.h"

DEFINE_FIRMWARE_FB(E_RESTART, g_nStringIdE_RESTART)

const CStringDictionary::TStringId E_RESTART::scm_aunEONameIds[] = {g_nStringIdCOLD, g_nStringIdWARM, g_nStringIdSTOP};

const SFBInterfaceSpec E_RESTART::scm_stFBInterfaceSpec = {
  0,
  0,
  0,
  0,
  3,
  scm_aunEONameIds,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

void E_RESTART::executeEvent(int pa_nEIID){
  if(cg_nExternalEventID == pa_nEIID){
    switch(getState()){
      case e_RUNNING:  {
    	  TEventID nBuffer = csm_nWARMID;
    	  if (!m_bStartedOnce)  {
    		  nBuffer = csm_nCOLDID;
    	  }
        sendOutputEvent(nBuffer);
        m_bStartedOnce =  true;
        break;
      }
      case e_STOPPED:
        sendOutputEvent(csm_nSTOPID);
        break;
      default:
        break;
    }
  }
}

EMGMResponse E_RESTART::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse eRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  if(e_RDY == eRetVal){
    switch(pa_unCommand){
      case cg_nMGM_CMD_Start:
      case cg_nMGM_CMD_Stop:
        getResource().getDevice().getDeviceExecution().startNewEventChain(this);
        break;
      case cg_nMGM_CMD_Reset:
        m_bStartedOnce =  false;
        break;
      default:
        break;
    }
  }
  return eRetVal;
}
