/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <config.h>
#include <fortealloc.h>
#include "ecet.h"
#include "esfb.h"

CEventChainExecutionThread::CEventChainExecutionThread() :
    CThread(){
  clear();
}

CEventChainExecutionThread::~CEventChainExecutionThread(){
}

void CEventChainExecutionThread::run(void){
  while(isAlive()){ //thread is allowed to execute
    if(externalEventOccured()){
      transferExternalEvents();
    }
    if(m_pstEventListEnd == m_pstEventListStart){
      selfSuspend();
    }
    else{
      if(0 != *m_pstEventListStart){
        (*m_pstEventListStart)->m_poFB->receiveInputEvent((*m_pstEventListStart)->m_nEIID, *this);
      }
      *m_pstEventListStart = 0;

      if(m_pstEventListStart == &m_astEventList[0]){
        //wrap the ringbuffer
        m_pstEventListStart = &m_astEventList[cg_nEventChainEventListSize - 1];
      }
      else{
        m_pstEventListStart--;
      }
    }
  }
}

void CEventChainExecutionThread::clear(void){
  memset(m_astEventList, 0, cg_nEventChainEventListSize * sizeof(TEventEntryPtr));
  m_pstEventListEnd = m_pstEventListStart = &m_astEventList[cg_nEventChainEventListSize - 1];

  m_oExternalEventListSync.lock();
  memset(m_astExternalEventList, 0, cg_nEventChainExternalEventListSize * sizeof(TEventEntryPtr));
  m_pstExternalEventListEnd = m_pstExternalEventListStart = &m_astExternalEventList[cg_nEventChainExternalEventListSize - 1];
  m_oExternalEventListSync.unlock();
}

void CEventChainExecutionThread::transferExternalEvents(){
  m_oExternalEventListSync.lock();
  //this while is built in a way that it checks also if we got here by accident
  while(m_pstExternalEventListStart != m_pstExternalEventListEnd){
    if(0 != *m_pstExternalEventListStart){
      //add only valid entries
      addEventEntry(*m_pstExternalEventListStart);
      *m_pstExternalEventListStart = 0;

      if(m_pstExternalEventListStart == &m_astExternalEventList[0]){
        //wrap the ringbuffer
        m_pstExternalEventListStart = &m_astExternalEventList[cg_nEventChainExternalEventListSize - 1];
      }
      else{
        m_pstExternalEventListStart--;
      }
    }
  }
  m_oExternalEventListSync.unlock();
}

void CEventChainExecutionThread::startEventChain(SEventEntry *pa_poEventToAdd){
  FORTE_TRACE("CEventChainExecutionThread::startEventChain\n");
  m_oExternalEventListSync.lock();
  if(0 == *m_pstExternalEventListEnd){
    *m_pstExternalEventListEnd = pa_poEventToAdd;
    TEventEntryPtr* pstNextEventListElem;

    if(m_pstExternalEventListEnd == &m_astExternalEventList[0]){
      //wrap the ringbuffer
      pstNextEventListElem = &m_astExternalEventList[cg_nEventChainExternalEventListSize - 1];
    }
    else{
      pstNextEventListElem = (m_pstExternalEventListEnd - 1);
    }

    if(m_pstExternalEventListStart != pstNextEventListElem){
      //the list is not full
      m_pstExternalEventListEnd = pstNextEventListElem;
    }
  }
  else{
    DEVLOG_ERROR("External event queue is full, external event dropped!\n");
  }
  m_oExternalEventListSync.unlock();
  resumeSelfSuspend();
}

void CEventChainExecutionThread::addEventEntry(SEventEntry *pa_poEventToAdd){
  if(0 == *m_pstEventListEnd){
    *m_pstEventListEnd = pa_poEventToAdd;
    TEventEntryPtr* pstNextEventListElem;

    if(m_pstEventListEnd == &m_astEventList[0]){
      //wrap the ringbuffer
      pstNextEventListElem = &m_astEventList[cg_nEventChainEventListSize - 1];
    }
    else{
      pstNextEventListElem = (m_pstEventListEnd - 1);
    }

    if(m_pstEventListStart != pstNextEventListElem){
      //the list is not full
      m_pstEventListEnd = pstNextEventListElem;
    }
  }
  else{
    DEVLOG_ERROR("Event queue is full, event dropped!\n");
  }
}

void CEventChainExecutionThread::changeExecutionState(EMGMCommandType pa_unCommand){
  switch (pa_unCommand){
    case cg_nMGM_CMD_Start:
      if(!isAlive()){
        //only start the thread when we are not already running
        start();
      }
      break;
    case cg_nMGM_CMD_Kill:
      clear();
	  end();
      break;
    case cg_nMGM_CMD_Stop:
      end();
      break;
    default:
      break;
  }
}

