/*******************************************************************************
 * Copyright (c) 2007-2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "LMSUSBLayer.h"
#include <cyg/io/usb/usbs_serial.h>
#include "commfb.h"
#include "devexec.h"

using namespace forte::com_infra;

CLMSUSBLayer::CLMSUSBManager CLMSUSBLayer::sm_oLMSUSBManager;

CLMSUSBLayer::CLMSUSBLayer(CComLayer* pa_poUpperLayer, CCommFB* pa_poComFB) :
    CComLayer(pa_poUpperLayer, pa_poComFB), m_unBufFillSize(0){
}

CLMSUSBLayer::~CLMSUSBLayer(){
}

EComResponse CLMSUSBLayer::openConnection(char *pa_acLayerParameter){
  EComResponse eRetVal = e_InitInvalidId;
  if(0 != pa_acLayerParameter){
    m_unUSBID = forte::core::util::strtoul(pa_acLayerParameter, 0, 10);
    if(e_Publisher != m_poFb->getComServiceType()){
      sm_oLMSUSBManager.addComCallback(this);
    }
    eRetVal = e_InitOk;
  }

  return eRetVal;
}

void CLMSUSBLayer::closeConnection(){
  sm_oLMSUSBManager.removeComCallback(this);
  m_unUSBID = 0;
}

EComResponse CLMSUSBLayer::sendData(void *pa_pvData, unsigned int pa_unSize){
  sendUSBData(m_unUSBID, pa_pvData, pa_unSize);
  return e_ProcessDataOk;
}

void CLMSUSBLayer::sendUSBData(TForteUInt8 pa_unMsgId, const void *pa_pvData, unsigned int pa_unSize){
  usbs_serial_tx(&usbs_ser0, &pa_unMsgId, 1);
  usbs_serial_tx(&usbs_ser0, pa_pvData, pa_unSize);
}

EComResponse CLMSUSBLayer::recvData(const void *, unsigned int ){
  return e_Nothing;
}

CEventSourceFB *CLMSUSBLayer::onComEvent(){
  CEventSourceFB *poFB = 0;
  int nRetVal = usbs_serial_rx(&usbs_ser0, &m_acRecvBuffer[m_unBufFillSize], cg_unIPLayerRecvBufferSize - m_unBufFillSize);
  //we successfully received data
  if(nRetVal > 0){
    m_unBufFillSize += nRetVal;
    m_eInterruptResp = e_ProcessDataOk;
    m_poFb->interruptCommFB(this);
    poFB = m_poFb;
  }

  return poFB;
}

forte::com_infra::EComResponse CLMSUSBLayer::processComEvent(){
  m_eInterruptResp = m_poTopLayer->recvData(m_acRecvBuffer, m_unBufFillSize);
  m_unBufFillSize = 0;
  return m_eInterruptResp;
}

/*************************** CLMSUSBLayer::CLMSUSBManager **************************************************/
void CLMSUSBLayer::CLMSUSBManager::addComCallback(CLMSUSBLayer *pa_poComCallBack){
  m_oSync.lock();
  if(m_lstConnectionsList.isEmpty()){
    start();
  }
  m_lstConnectionsList.push_back(pa_poComCallBack);
  m_oSync.unlock();
}

void CLMSUSBLayer::CLMSUSBManager::removeComCallback(CLMSUSBLayer *pa_poComCallBack){
  m_oSync.lock();

  TConnectionContainer::Iterator itRunner(m_lstConnectionsList.begin());

  if((*itRunner) == pa_poComCallBack){
    m_lstConnectionsList.pop_front();
  }
  else{
    TConnectionContainer::Iterator itLastPos(itRunner);
    TConnectionContainer::Iterator itEnd(m_lstConnectionsList.end());
    ++itRunner;
    while(itRunner != itEnd){
      if((*itRunner) == pa_poComCallBack){
        m_lstConnectionsList.eraseAfter(itLastPos);
        break;
      }
      itLastPos = itRunner;
      ++itRunner;
    }
  }
  m_oSync.unlock();
}

void CLMSUSBLayer::CLMSUSBManager::run(){
  usbs_serial_start();
  usbs_serial_wait_until_configured();
  TForteInt8 unID;
  while((isAlive()) && (usbs_serial_is_configured())){
    if(0 < usbs_serial_rx(&usbs_ser0, &unID, 1)){
      m_oSync.lock();
      TConnectionContainer::Iterator itEnd(m_lstConnectionsList.end());
      for(TConnectionContainer::Iterator itRunner = m_lstConnectionsList.begin(), itCurrent = m_lstConnectionsList.begin(); itRunner != itEnd; ){
        itCurrent = itRunner;
        ++itRunner;
        CLMSUSBLayer *poCurrent = (*itCurrent);
        if(poCurrent->getUSBId() == unID){
          CEventSourceFB *poESFB = poCurrent->onComEvent();
          if(0 != poESFB){
            startNewEventChain(poESFB);
          }
          break;
        }
      }
      m_oSync.unlock();
    }
  }
}
