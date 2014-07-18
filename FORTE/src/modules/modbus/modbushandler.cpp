/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "modbushandler.h"
#include "devlog.h"
#include "../core/devexec.h"

DEFINE_SINGLETON(CModbusHandler);

CModbusHandler::TCallbackDescriptor CModbusHandler::m_nCallbackDescCount = 0;

CModbusHandler::CModbusHandler(){
}

CModbusHandler::~CModbusHandler(){

}

CModbusHandler::TCallbackDescriptor CModbusHandler::addComCallback(forte::com_infra::IComCallback* pa_pComCallback){
  m_oSync.lock();
  m_nCallbackDescCount++;
  TComContainer stNewNode = { m_nCallbackDescCount, pa_pComCallback };
  m_lstComCallbacks.push_back(stNewNode);
  m_oSync.unlock();

  return m_nCallbackDescCount;
}

void CModbusHandler::removeComCallback(CModbusHandler::TCallbackDescriptor pa_nCallbackDesc){
  m_oSync.lock();

  TCallbackList::Iterator itRunner(m_lstComCallbacks.begin());

  if(itRunner->m_nCallbackDesc == pa_nCallbackDesc){
    m_lstComCallbacks.pop_front();
  }
  else{
    TCallbackList::Iterator itLastPos(itRunner);
    TCallbackList::Iterator itEnd(m_lstComCallbacks.end());
    ++itRunner;
    while(itRunner != itEnd){
      if(itRunner->m_nCallbackDesc == pa_nCallbackDesc){
        m_lstComCallbacks.eraseAfter(itLastPos);
        break;
      }
      itLastPos = itRunner;
      ++itRunner;
    }
  }
  m_oSync.unlock();
}

void CModbusHandler::executeComCallback(CModbusHandler::TCallbackDescriptor pa_nCallbackDesc){
  m_oSync.lock();
  TCallbackList::Iterator itEnd(m_lstComCallbacks.end());
  for(TCallbackList::Iterator itCallback = m_lstComCallbacks.begin(); itCallback != itEnd; ++itCallback){
    if(itCallback->m_nCallbackDesc == pa_nCallbackDesc){
      CEventSourceFB *poESFB = itCallback->m_pCallback->onComEvent();
      startNewEventChain(poESFB);
      break;
    }
  }
  m_oSync.unlock();
}
