/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "resource.h"
#include "class1objhand.h"
#include "device.h"

CResource::CResource(CResource* pa_poDevice, const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
    CFunctionBlock(pa_poDevice, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData), m_oObjectHandler(*this), m_poResourceEventExecution(new CEventChainExecutionThread){
}

CResource::CResource(const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
    CFunctionBlock(0, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData), m_oObjectHandler(*this), m_poResourceEventExecution(0){

}

EMGMResponse CResource::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse nRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  if(e_RDY == nRetVal){
    if(e_RDY == (nRetVal = m_oObjectHandler.changeFBExecutionState(pa_unCommand))){
      if(cg_nMGM_CMD_Start == pa_unCommand){
        //on start sample inputs
        if(0 != m_pstInterfaceSpec){
          for(int i = 0; i < m_pstInterfaceSpec->m_nNumDIs; ++i){
            if(0 != m_apoDIConns[i]){
              m_apoDIConns[i]->readData(getDI(i));
            }
          }
        }
      }
      if(0 != m_poResourceEventExecution){
        // if we have a m_poResourceEventExecution handle it
        m_poResourceEventExecution->changeExecutionState(pa_unCommand);
      }
    }
  }
  return nRetVal;
}

