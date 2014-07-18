/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "basicfb.h"

CBasicFB::CBasicFB(CResource *pa_poSrcRes,
           const SFBInterfaceSpec *pa_pstInterfaceSpec,
           const CStringDictionary::TStringId pa_nInstanceNameId,
           const SInternalVarsInformation *pa_pstVarInternals,
           TForteByte *pa_acFBConnData, TForteByte *pa_acBasicFBVarsData):
    CFunctionBlock( pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acBasicFBVarsData),
    m_nECCState(0),
    cm_pstVarInternals(pa_pstVarInternals){

  if((0 != cm_pstVarInternals)&& (0 != pa_acBasicFBVarsData)){
    if(cm_pstVarInternals->m_nNumIntVars){
      pa_acBasicFBVarsData += genFBVarsDataSize(m_pstInterfaceSpec->m_nNumDIs, m_pstInterfaceSpec->m_nNumDOs, m_pstInterfaceSpec->m_nNumAdapters);

      m_aoInternals = reinterpret_cast<CIEC_ANY *>(pa_acBasicFBVarsData);

      const CStringDictionary::TStringId *pnDataIds = cm_pstVarInternals->m_aunIntVarsDataTypeNames;
      for(int i = 0; i < cm_pstVarInternals->m_nNumIntVars; ++i){
        createDataPoint(&pnDataIds, pa_acBasicFBVarsData);
        pa_acBasicFBVarsData += sizeof(CIEC_ANY);
      }
    }
  }
  else{
    m_aoInternals = 0;
  }
}

CBasicFB::~CBasicFB(){
  if(0 != m_aoInternals){
    for(int i = 0; i < cm_pstVarInternals->m_nNumIntVars; ++i){
      getVarInternal(i)->~CIEC_ANY();
    }
  }
}

CIEC_ANY *CBasicFB::getVar(const char *pa_acVarName){
  CIEC_ANY *poRetVal = CFunctionBlock::getVar(pa_acVarName);
  if(0 == poRetVal){
    poRetVal = getInternalVar(CStringDictionary::getInstance().getId(pa_acVarName));
    if( 0 == poRetVal){
      if(!strcmp("$ECC", pa_acVarName)){
        poRetVal =  &m_nECCState;
      }
    }
  }
  return poRetVal;
}

EMGMResponse CBasicFB::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse nRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  if((e_RDY == nRetVal) && (cg_nMGM_CMD_Reset == pa_unCommand)){
    m_nECCState = 0;
  }
  return nRetVal;
}

