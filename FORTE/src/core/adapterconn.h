/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ADAPTERCONN_H_
#define _ADAPTERCONN_H_

#include "./datatypes/forte_any.h"
#include "conn.h"

class CAdapter;

/*! \ingroup CORE\brief Class for handling a adapter connection.
 */
class CAdapterConnection : public CConnection{
  public:
    CAdapterConnection(TConnectionID pa_nSrcId, CFunctionBlock & pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock & pa_roDstFB);
    virtual ~CAdapterConnection();
    virtual EMGMResponse connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock & pa_roSrcFB, CFunctionBlock & pa_roDstFB);
#ifndef FORTE_CLASS_0
    virtual EMGMResponse disconnect(TConnectionID pa_nDstId, CFunctionBlock & pa_roSrcFB, CFunctionBlock & pa_roDstFB);
#endif

    void setPlug(CAdapter *pa_poPlug){
      m_poPlug = pa_poPlug;
    }

    CAdapter *getPlug(){
      return m_poPlug;
    }

    void setSocket(CAdapter *pa_poSocket){
      m_poSocket = pa_poSocket;
    }

    CAdapter *getSocket(){
      return m_poSocket;
    }

  private:
    CAdapter *m_poPlug;
    CAdapter *m_poSocket;
    void performDisconnect();

};

typedef CAdapterConnection *TAdapterConnectionPtr;

#endif /*_ADAPTERCONN_H_*/
