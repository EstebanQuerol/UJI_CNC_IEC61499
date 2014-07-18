/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "RMT_RES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RMT_RES_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(RMT_RES, g_nStringIdRMT_RES);

const CStringDictionary::TStringId RMT_RES::scm_aunVarInputNameIds[] = {g_nStringIdMGR_ID};
const CStringDictionary::TStringId RMT_RES::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};


const SFBInterfaceSpec RMT_RES::scm_stRESInterfaceSpec = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  scm_aunVarInputNameIds,
  scm_aunDIDataTypeIds,
  0,
  0,
  0,
  0,
  0
  };

RMT_RES::RMT_RES(CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_poDevice):
       CResource(pa_poDevice, &scm_stRESInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){
  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdSTART, g_nStringIdE_RESTART, this));
  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdMGR_FF, g_nStringIdE_SR, this));
  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdKERNEL, g_nStringIdDM_KRNL, this));

  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdCOLD),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdS));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdWARM),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdS));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdSTOP),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdR));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdEO),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdKERNEL, g_nStringIdINIT));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdQ),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdKERNEL, g_nStringIdQI));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMGR_ID),
                   GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdKERNEL, g_nStringIdID));
}

RMT_RES::~RMT_RES(){
}



