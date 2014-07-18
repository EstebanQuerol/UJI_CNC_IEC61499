/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "txtimeha.h"
#include "../../core/devexec.h"


void CTimerHandler::createTimerHandler(void){
  if(0 == sm_poFORTETimer) 
    sm_poFORTETimer = new CTXTimerHandler();
}

CTXTimerHandler::CTXTimerHandler(){
// setup the handler for recieving the timer calls  
  //TODO handle ticks per second correctly here
  UINT status = tx_timer_create(&m_stTimer, "FORTE timer", &timerHandlerFunc, 0, 1, 1, TX_NO_ACTIVATE); 
  if (status == TX_SUCCESS)
    DEVLOG_DEBUG("Timer created\n");
  else
    DEVLOG_DEBUG("Error creating timer\n");
  
  //TODO handle retval
}

CTXTimerHandler::~CTXTimerHandler(){
  disableHandler();
  tx_timer_delete(&m_stTimer);
}

void CTXTimerHandler::enableHandler(void){
  UINT status = tx_timer_activate(&m_stTimer);
  if (status == TX_SUCCESS)
    DEVLOG_DEBUG("Timer activated\n");
  else
    DEVLOG_DEBUG("Error activating timer\n");
  
  //TODO handle retval
}

void CTXTimerHandler::disableHandler(void){
  tx_timer_deactivate(&m_stTimer);
  //TODO handle retval
}

void CTXTimerHandler::setPriority(int pa_nPriority){
}

int CTXTimerHandler::getPriority(void) const {
  return 0;
}
