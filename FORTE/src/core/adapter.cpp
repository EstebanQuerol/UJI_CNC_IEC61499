/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "adapter.h"
#include "adapterconn.h"
#include "ecet.h"

CAdapter::CAdapter(CResource *pa_poSrcRes,
    const SFBInterfaceSpec *pa_pstInterfaceSpecSocket, const CStringDictionary::TStringId pa_nInstanceNameId, const SFBInterfaceSpec *pa_pstInterfaceSpecPlug,
     bool pa_bIsPlug, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
     CFunctionBlock( pa_poSrcRes,
      (pa_bIsPlug) ? pa_pstInterfaceSpecPlug : pa_pstInterfaceSpecSocket, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData),
      m_bIsPlug(pa_bIsPlug),
  m_poPeer(0),
  m_aoLocalDIs(m_aoDIs),
  m_poAdapterConn(0){

  setupEventEntryList();
}

CAdapter::~CAdapter() {
  if (m_bIsPlug) {
    if (m_poAdapterConn != 0) {
      m_poAdapterConn->setPlug(0);
    }
  }
  else {
    if (m_poAdapterConn != 0) {
      m_poAdapterConn->setSocket(0);
    }
  }
  delete[] m_astEventEntry;
}

void CAdapter::setParentFB(CFunctionBlock *pa_poParentFB, TForteUInt8 pa_nParentAdapterlistID) {
  m_nParentAdapterListEventID = static_cast<TForteUInt16>((pa_nParentAdapterlistID+1)<<8);;

  for(TForteUInt16 i = 0; i < m_pstInterfaceSpec->m_nNumEOs; ++i){
    m_astEventEntry[i].m_poFB = pa_poParentFB;
    m_astEventEntry[i].m_nEIID = m_nParentAdapterListEventID + i;
  }
}

bool CAdapter::connect(CAdapter *pa_poPeer, CAdapterConnection *pa_poAdConn) {
  bool bRetVal = false;
  if (m_poPeer == 0) {
    m_poPeer = pa_poPeer;
    m_aoDIs = pa_poPeer->m_aoDOs; //TODO: change is adapters of subtypes may be connected
    m_poAdapterConn = pa_poAdConn;
    bRetVal = true;
  }

  return bRetVal;
}

bool CAdapter::disconnect(CAdapterConnection *pa_poAdConn) {
  if ((pa_poAdConn!=0) && (pa_poAdConn != m_poAdapterConn))
    return false; //connection requesting disconnect is not equal to established connection
  m_poPeer=0;
  m_aoDIs = m_aoLocalDIs;
  m_poAdapterConn = 0;
  return true;
}

void CAdapter::executeEvent(int pa_nEIID) {
  if (0 != m_poPeer) {
    if (0 != m_poPeer->m_astEventEntry[pa_nEIID].m_poFB) {
      m_poInvokingExecEnv->addEventEntry(&(m_poPeer->m_astEventEntry[pa_nEIID]));
    } else {
      m_poPeer->m_poInvokingExecEnv = m_poInvokingExecEnv;
      m_poPeer->sendOutputEvent(pa_nEIID);
    }
  }
}

void CAdapter::setupEventEntryList(){
  m_astEventEntry = new SEventEntry[m_pstInterfaceSpec->m_nNumEOs];
}
