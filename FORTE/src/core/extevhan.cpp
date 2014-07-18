/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "extevhan.h"
#include "devexec.h"
#include <devlog.h>

CDeviceExecution *CExternalEventHandler::sm_poDeviceExecution = 0;

CExternalEventHandler::CExternalEventHandler() :
    m_nExtEvHandID(-1){
  // register at the device Execution
  m_nExtEvHandID = sm_poDeviceExecution->registerExternalEventHandler(this);
}

bool CExternalEventHandler::isAllowed(){
  return getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID);
}

void CExternalEventHandler::startNewEventChain(CEventSourceFB *pa_poECStartFB){
  if(isAllowed()){
    FORTE_TRACE("Starting EC");
    getDeviceExecution()->startNewEventChain(pa_poECStartFB);
  }
  else{
    //TODO: handle this !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    DEVLOG_DEBUG("Starting EC NOT ALLOWED !!!!!!!!!!!!!!!1\n");
  }
}
