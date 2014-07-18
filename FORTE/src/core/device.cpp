/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "device.h"
#include "resource.h"
#include "if2indco.h"
#include "class1objhand.h"

EMGMResponse CDevice::executeMGMCommand(SManagementCMD &pa_oCommand){
  EMGMResponse retval = e_INVALID_DST;

  if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nDestination){
    retval = m_oObjectHandler.executeMGMCommand(pa_oCommand);
  }
  else{
    //FIXME if other destinations than resources need to be supported the name of the resource has to be extracted here
    CResource *res = (CResource *)m_oObjectHandler.getFB(pa_oCommand.m_nDestination);
    if(0 != res){
      pa_oCommand.m_nDestination = CStringDictionary::scm_nInvalidStringId;
      retval = (res->getObjectHandler()).executeMGMCommand(pa_oCommand);
    }
  }
  return retval;
}


