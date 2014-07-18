/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "adapterconn.h"
#include "funcbloc.h"
#include "adapter.h"

CAdapterConnection::CAdapterConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB) :
  CConnection(pa_nSrcId, pa_nDstId), m_poPlug(0), m_poSocket(0){
  TAdapterPtr poPlug = pa_roSrcFB.getAdapter(getOutputNameId());
  TAdapterPtr poSocket = pa_roDstFB.getAdapter(extractPortNameId(pa_nDstId));

  if((poSocket != 0) && (poPlug != 0)){
    if((poSocket->isSocket()) && (poPlug->isPlug())){
      if(poSocket->isCompatible(poPlug)){
        if(((poPlug->connect(poSocket, this)) && (poSocket->connect(poPlug, this)))){
          m_poPlug = poPlug;
          m_poSocket = poSocket;
        }
        else{
          poPlug->disconnect();
          poSocket->disconnect();
        }
      }
    }
  }
}

CAdapterConnection::~CAdapterConnection(){
  performDisconnect();
}

EMGMResponse CAdapterConnection::connectFannedOut(TConnectionID, CFunctionBlock&, CFunctionBlock&){
  //fanned-out connections not allowed for adapter connections!
  return e_NOT_READY;
}

#ifndef FORTE_CLASS_0
EMGMResponse CAdapterConnection::disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB){
  EMGMResponse retval = CConnection::disconnect(pa_nDstId, pa_roSrcFB, pa_roDstFB);

  if(e_RDY == retval){
    // the CConnection class didn't respond an error
    performDisconnect();
  }
  return retval;
}
#endif

void CAdapterConnection::performDisconnect(){
  if(m_poPlug != 0){
    m_poPlug->disconnect(this);
    m_poPlug = 0;
  }

  if(m_poSocket != 0){
    m_poSocket->disconnect(this);
    m_poSocket = 0;
  }
}
