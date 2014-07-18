/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "ipcomlayer.h"
#include "../../arch/devlog.h"
#include "commfb.h"
#include "../../core/datatypes/forte_dint.h"

using namespace forte::com_infra;

CIPComLayer::CIPComLayer(CComLayer* pa_poUpperLayer, CCommFB* pa_poComFB) :
    CComLayer(pa_poUpperLayer, pa_poComFB), m_nSocketID(CIPComSocketHandler::scm_nInvalidSocketDescriptor), m_nListeningID(CIPComSocketHandler::scm_nInvalidSocketDescriptor), m_unBufFillSize(0){
}

CIPComLayer::~CIPComLayer(){
}

void CIPComLayer::closeConnection(){
  DEVLOG_DEBUG("CSocketBaseLayer::closeConnection() \n");
  closeSocket(&m_nSocketID);
  closeSocket(&m_nListeningID);

  m_eConnectionState = e_Disconnected;
}

EComResponse CIPComLayer::sendData(void *pa_pvData, unsigned int pa_unSize){
  EComResponse eRetVal = e_ProcessDataOk;

  if((0 != m_poFb) && (CIPComSocketHandler::scm_nInvalidSocketDescriptor != m_nSocketID)){
    switch (m_poFb->getComServiceType()){
      case e_Server:
        if(0 >= CIPComSocketHandler::sendDataOnTCP(m_nSocketID, static_cast<char*>(pa_pvData), pa_unSize)){
          closeSocket(&m_nSocketID);
          m_eConnectionState = e_Listening;
          eRetVal = e_InitTerminated;
        }
        break;
      case e_Client:
        if(0 >= CIPComSocketHandler::sendDataOnTCP(m_nSocketID, static_cast<char*>(pa_pvData), pa_unSize)){
          eRetVal = e_InitTerminated;
        }
        break;
      case e_Publisher:
        if(0 >= CIPComSocketHandler::sendDataOnUDP(m_nSocketID, &m_tDestAddr, static_cast<char*>(pa_pvData), pa_unSize)){
          eRetVal = e_InitTerminated;
        }
        break;
      case e_Subscriber:
        //do nothing as subscribers do not send data
        break;
    }
  }
  return eRetVal;
}

EComResponse CIPComLayer::recvData(const void *, unsigned int){
  return e_Nothing;
}

EComResponse CIPComLayer::processComEvent(){
  if(e_ProcessDataOk == m_eInterruptResp){
    switch (m_eConnectionState){
      case e_Connected:
        if((0 < m_unBufFillSize) && (0 != m_poTopLayer)){
          m_eInterruptResp = m_poTopLayer->recvData(m_acRecvBuffer, m_unBufFillSize);
          m_unBufFillSize = 0;
        }
        break;
      case e_Disconnected:
      case e_Listening:
      case E_ConnectedAndListening:
      default:
        break;
    }
  }
  return m_eInterruptResp;
}

CEventSourceFB *CIPComLayer::onComEvent(){
  CEventSourceFB *poFB = 0;
  switch (m_eConnectionState){
    case e_Listening:
      //TODO move this to the processComEvent()
      m_nSocketID = CIPComSocketHandler::acceptTCPConnection(m_nListeningID);
      if(CIPComSocketHandler::scm_nInvalidSocketDescriptor != m_nSocketID){
        CIPComSocketHandler::getInstance().addComCallback(m_nSocketID, this);
        m_eConnectionState = e_Connected;
      }
      break;
    case e_Connected:
      // in case of fragmented packets, it can occur that the buffer is full,
      // to avoid calling receiveDataFromTCP with a buffer size of 0 wait until buffer is larger 0
      while((cg_unIPLayerRecvBufferSize - m_unBufFillSize) <= 0){
#ifdef WIN32
        Sleep(0);
#else
        sleep(0);
#endif
      }
      if(CIPComSocketHandler::scm_nInvalidSocketDescriptor != m_nSocketID){
        // TODO: sync buffer and bufFillSize
        int nRetVal = 0;
        switch (m_poFb->getComServiceType()){
          case e_Server:
          case e_Client:
            nRetVal = CIPComSocketHandler::receiveDataFromTCP(m_nSocketID, &m_acRecvBuffer[m_unBufFillSize], cg_unIPLayerRecvBufferSize - m_unBufFillSize);
            break;
          case e_Publisher:
            //do nothing as subscribers cannot receive data
          case e_Subscriber:
            nRetVal = CIPComSocketHandler::receiveDataFromUDP(m_nSocketID, &m_acRecvBuffer[m_unBufFillSize], cg_unIPLayerRecvBufferSize - m_unBufFillSize);
            break;
        }
        switch (nRetVal){
          case 0:
            DEVLOG_INFO("Connection closed by peer\n");
            m_eInterruptResp = e_InitTerminated;
            closeSocket(&m_nSocketID);
            if(e_Server == m_poFb->getComServiceType()){
              //Move server into listening mode again
              m_eConnectionState = e_Listening;
            }
            break;
          case -1:
            m_eInterruptResp = e_ProcessDataRecvFaild;
            break;
          default:
            //we successfully received data
            m_unBufFillSize += nRetVal;
            m_eInterruptResp = e_ProcessDataOk;
            break;
        }
        m_poFb->interruptCommFB(this);
        poFB = m_poFb;
      }
      break;
    case E_ConnectedAndListening:
    case e_Disconnected:
    default:
      break;
  }
  return poFB;
}

EComResponse CIPComLayer::openConnection(char *pa_acLayerParameter){
  EComResponse eRetVal = e_InitInvalidId;
  char *acPort = strchr(pa_acLayerParameter, ':');
  if(0 != acPort){
    *acPort = '\0';
    ++acPort;

    TForteUInt16 nPort = static_cast<TForteUInt16>(forte::core::util::strtoul(acPort, 0, 10));

    CIPComSocketHandler::TSocketDescriptor nSockDes = CIPComSocketHandler::scm_nInvalidSocketDescriptor;
    m_eConnectionState = e_Connected;

    switch (m_poFb->getComServiceType()){
      case e_Server:
        nSockDes = m_nListeningID = CIPComSocketHandler::openTCPServerConnection(pa_acLayerParameter, nPort);
        m_eConnectionState = e_Listening;
        break;
      case e_Client:
        nSockDes = m_nSocketID = CIPComSocketHandler::openTCPClientConnection(pa_acLayerParameter, nPort);
        break;
      case e_Publisher:
        nSockDes = m_nSocketID = CIPComSocketHandler::openUDPSendPort(pa_acLayerParameter, nPort, &m_tDestAddr);
        break;
      case e_Subscriber:
        nSockDes = m_nSocketID = CIPComSocketHandler::openUDPReceivePort(pa_acLayerParameter, nPort);
        break;
    }

    if(CIPComSocketHandler::scm_nInvalidSocketDescriptor != nSockDes){
      if(e_Publisher != m_poFb->getComServiceType()){
        //Publishers should not be registered for receiving data
        CIPComSocketHandler::getInstance().addComCallback(nSockDes, this);
      }
      eRetVal = e_InitOk;
    }
    else{
      m_eConnectionState = e_Disconnected;
    }
  }
  return eRetVal;
}

void CIPComLayer::closeSocket(CIPComSocketHandler::TSocketDescriptor *pa_nSocketID){
  if(CIPComSocketHandler::scm_nInvalidSocketDescriptor != *pa_nSocketID){
    CIPComSocketHandler::getInstance().removeComCallback(*pa_nSocketID);
    CIPComSocketHandler::closeSocket(*pa_nSocketID);
    *pa_nSocketID = CIPComSocketHandler::scm_nInvalidSocketDescriptor;
  }
}
