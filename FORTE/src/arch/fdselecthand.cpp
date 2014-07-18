/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/

#include <sockhand.h>      //needs to be first pulls in the platform specific includes
#include "fdselecthand.h"
#include "../core/devexec.h"
#include "devlog.h"


DEFINE_SINGLETON(CFDSelectHandler);

CFDSelectHandler::CFDSelectHandler(){
  m_bConnectionListChanged = false;
#ifdef WIN32
  // Windows Socket Startupcode
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;

  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
  wVersionRequested = MAKEWORD(2, 2);

  err = WSAStartup(wVersionRequested, &wsaData);
#endif
}

CFDSelectHandler::~CFDSelectHandler(){
  this->end();
#ifdef WIN32
  WSACleanup();
#endif
}

// single-threaded-network-code
void CFDSelectHandler::run(void){

  struct timeval tv;
  fd_set anFDSet;
  fd_set anFDSetMaster;

  int nHighestFDID = 0;
  int retval = 0;

  FD_ZERO(&anFDSetMaster);

  while(isAlive()){
    // TODO: create method to prevent 100ms timeout on reconnection
    m_oSync.lock();
    if(m_lstConnectionsList.isEmpty()){
      m_oSync.unlock();
      selfSuspend();
      m_oSync.lock();
    }

    if(true == m_bConnectionListChanged){
      nHighestFDID = createFDSet(&anFDSetMaster);
    }
    anFDSet = anFDSetMaster;
    m_oSync.unlock();

    tv.tv_sec = 1; //TODO : To be set!
    tv.tv_usec = 1000;

    if(0 != nHighestFDID){
      retval = select(nHighestFDID + 1, &anFDSet, NULL, NULL, &tv);
    }
    else{
      retval = 0;
    }

    if(retval > 0){
      m_oSync.lock();
      TConnectionContainer::Iterator itEnd(m_lstConnectionsList.end());
      for(TConnectionContainer::Iterator itRunner = m_lstConnectionsList.begin(), itCurrent = m_lstConnectionsList.begin(); itRunner != itEnd;){
        itCurrent = itRunner;
        ++itRunner;

        if((0 != FD_ISSET(itCurrent->m_nSockDes, &anFDSet)) && (0 != itCurrent->m_poCallee)){
          m_oSync.unlock();
          CEventSourceFB *poESFB = itCurrent->m_poCallee->onComEvent();
          if(0 != poESFB){
            startNewEventChain(poESFB);
          }
          m_oSync.lock();
        }
      }
      m_oSync.unlock();
    }
    else{
      if(retval == 0){
//        printf(".");
      }
      else{
#ifdef WIN32
        DEVLOG_ERROR("Select failed: %d", WSAGetLastError());
#else
        DEVLOG_ERROR("Select failed: %s", strerror(errno));
#endif
      }
    }
  }
}

void CFDSelectHandler::addComCallback(TFileDescriptor pa_nFD, forte::com_infra::IComCallback *pa_poComCallBack){
  m_oSync.lock();
  TConnContType stNewNode = { pa_nFD, pa_poComCallBack };
  m_lstConnectionsList.push_back(stNewNode);
  m_bConnectionListChanged = true;
  m_oSync.unlock();
  if(!isAlive()){
    this->start();
  }
  resumeSelfSuspend();
}

void CFDSelectHandler::removeComCallback(TFileDescriptor pa_nFD){
  m_oSync.lock();

  TConnectionContainer::Iterator itRunner(m_lstConnectionsList.begin());
  TConnectionContainer::Iterator itRefNode(m_lstConnectionsList.end());
  TConnectionContainer::Iterator itEnd(m_lstConnectionsList.end());

  while(itRunner != itEnd){
    if(itRunner->m_nSockDes == pa_nFD){
      if(itRefNode ==itEnd){
        m_lstConnectionsList.pop_front();
      }
      else{
        m_lstConnectionsList.eraseAfter(itRefNode);
      }
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }

  m_bConnectionListChanged = true;
  m_oSync.unlock();
}

CFDSelectHandler::TFileDescriptor CFDSelectHandler::createFDSet(fd_set *m_panFDSet){
  TFileDescriptor nRetVal = 0;
  FD_ZERO(m_panFDSet);
  TConnectionContainer::Iterator itEnd(m_lstConnectionsList.end());
  for(TConnectionContainer::Iterator itRunner = m_lstConnectionsList.begin(); itRunner != itEnd; ++itRunner){
    FD_SET(itRunner->m_nSockDes, m_panFDSet);
    if(itRunner->m_nSockDes > nRetVal){
      nRetVal = itRunner->m_nSockDes;
    }
  }
  m_bConnectionListChanged = false;
  return nRetVal;
}
