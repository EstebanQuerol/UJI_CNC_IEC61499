/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "thread.h"

TCECOSThreadPtr CECOSThread::sm_aoThreadList[CECOSThread::scm_nThreadListSize] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
CSyncObject CECOSThread::sm_oThreadListLock;

bool CECOSThread::create(void){
 // Get new Thread 
  cyg_thread_create(scm_nThreadListSize + 2, //lowest priority in ecos 
                    threadFunction, (cyg_addrword_t)(this), 
                    "Test Name", m_cStack, 
                    m_nStackSize, 
                    &m_stHandle, 
                    &m_stThread);

//setup the signals for the join implementation
  return true;
}

void CECOSThread::threadFunction(cyg_addrword_t data){
 // Get pointer to CThread object out of void pointer
  CECOSThread *pThread = (CECOSThread *)(data);

  // if pointer is ok
  if (pThread){
    pThread->m_stResLock.lock();
    pThread->m_bAlive = true;
    pThread->run();
    pThread->m_bAlive = false;
    pThread->m_stResLock.unlock();
  }
  cyg_thread_exit();
}

CECOSThread::CECOSThread(long pa_nStackSize){
  m_bAlive     = false;
  m_nStackSize = pa_nStackSize;
  m_cStack = new unsigned char[m_nStackSize];
  cyg_semaphore_init(&m_stSuspendSem, 0);
}

CECOSThread::~CECOSThread(){
  end();
  cyg_semaphore_destroy(&m_stSuspendSem); 
  delete[] m_cStack;
}

void CECOSThread::setDeadline(const CIEC_TIME &pa_roVal){
  int i, ii;
  sm_oThreadListLock.lock();
  DEVLOG_DEBUG(">>>>Thread: Set Deadline: %lu\n", pa_roVal.operator TValueType ());
  m_oDeadLine = pa_roVal;
  //first of all check if this thread is already in the list and remove it from the list
  for(i = 0; i < scm_nThreadListSize; i++){
    if(0 == sm_aoThreadList[i])
      break;
    else
      if(this == sm_aoThreadList[i]){
        for(ii = i; ii < scm_nThreadListSize - 1; ii++){
          if(0 == sm_aoThreadList[ii + 1])
            break;
          sm_aoThreadList[ii + 1]->setPriority(ii + 2);
          sm_aoThreadList[ii] = sm_aoThreadList[ii + 1];  
        }
        break;
      }  
  }

  if(0 == m_oDeadLine)
    setPriority(scm_nThreadListSize + 2); // use the lowest user priority
  else{
    for(i = 0; i < scm_nThreadListSize; i++){
      if(0 == sm_aoThreadList[i]){
        sm_aoThreadList[i] = this;
        setPriority( i + 2);
        break;
      }  
      else
        if(m_oDeadLine < sm_aoThreadList[i]->getDeadline()){
          CECOSThread *poRBuf, *poSBuf= sm_aoThreadList[i];
          sm_aoThreadList[i] =  this;
          setPriority( i + 2);
          for(ii = i + 1; ii < scm_nThreadListSize; ii++){
            poSBuf->setPriority(ii + 2);
            poRBuf = sm_aoThreadList[ii];
            sm_aoThreadList[ii] = poSBuf;
            if(0 == poRBuf)
              break;
            poSBuf = poRBuf;  
          }  
          break;
        }
    }      
  }  
  sm_oThreadListLock.unlock();
}
  
void CECOSThread::join(void){
  if(isAlive()){
    m_stResLock.lock();
    m_stResLock.unlock();
    cyg_thread_delete(m_stHandle);
  }   
}
