/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "RMT_DEV.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RMT_DEV_gen.cpp"
#endif
#include <stringdict.h>

const CStringDictionary::TStringId RMT_DEV::scm_aunDINameIds[] = { g_nStringIdMGR_ID };
const CStringDictionary::TStringId RMT_DEV::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};

const SFBInterfaceSpec RMT_DEV::scm_stFBInterfaceSpec = { 0, 0, 0, 0, 0, 0, 0,
    0, 1, scm_aunDINameIds, scm_aunDIDataTypeIds, 0, 0, 0,
    0,
    0};

RMT_DEV::RMT_DEV() :
  CDevice(&scm_stFBInterfaceSpec, CStringDictionary::scm_nInvalidStringId, m_anFBConnData, m_anFBVarsData),
      MGR(g_nStringIdMGR, this),
      m_oDConnMGR_ID(GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMGR_ID), *this, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdMGR_ID), MGR){
  MGR_ID().fromString("localhost:61499");
  //TODO use mgm commands to create connection and resource maybe
}

RMT_DEV::~RMT_DEV(){
}

int RMT_DEV::startDevice(void){
  CDevice::startDevice();
  MGR.changeFBExecutionState(cg_nMGM_CMD_Start);
  return 0;
}

EMGMResponse RMT_DEV::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse eRetVal = CDevice::changeFBExecutionState(pa_unCommand);
  if((e_RDY == eRetVal) && (cg_nMGM_CMD_Kill == pa_unCommand)){
    MGR.changeFBExecutionState(cg_nMGM_CMD_Kill);
  }
  return eRetVal;
}

void RMT_DEV::setMGR_ID(const char * const pa_acConn){
  MGR_ID().fromString(pa_acConn);
}
