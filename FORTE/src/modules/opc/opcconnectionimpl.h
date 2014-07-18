/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef OPCCONNECTIONIMPL_H_
#define OPCCONNECTIONIMPL_H_

#include "comcallback.h"
#include "fortelist.h"

#include "opcprocessvar.h"

// Includes from OPC library
#include "windows.h"
#include "opcda.h"
#include "OPCClient.h"

class COpcConnection;

class COpcConnectionImpl : public IAsynchDataCallback{
  public:
    COpcConnectionImpl(const char *pa_acHost, const char *pa_acServerName, COpcConnection* pa_pOpcConn);
    ~COpcConnectionImpl();

    void connect();
    void addItem(COpcProcessVar* pa_pNewItem);
    void addGroup(const char* pa_acGroupName, unsigned long pa_nReqUpdateRate, float pa_nDeadBand);

    int sendItemData(COpcProcessVar* pa_pNewItem);
    int receiveData(const char* pa_acRecvBuffer);

    const char* getHost(){
      return m_acHost;
    }
    const char* getServerName(){
      return m_acServerName;
    }

    virtual void OnDataChange(COPCGroup & group, CAtlMap<COPCItem *, OPCItemData *> & changes);

  private:
    COPCGroup* getOpcGroup(const char *pa_acGroupName, COpcProcessVar::EOpcProcessVarFunctions pa_eFunction);

    struct SOpcGroupSettings{
        COPCGroup* m_pOpcGroupRead;
        COPCGroup* m_pOpcGroupWrite;
        const char* m_acGroupName;
        unsigned long m_nReqUpdateRate;
        unsigned long m_nRevisedUpdateRate;
        float m_nDeadBand;
        bool m_bReadGroupAdded;
        bool m_bWriteGroupAdded;

        SOpcGroupSettings(const char* pa_acGroupName, unsigned long pa_nReqUpdateRate, float pa_nDeadBand) :
            m_acGroupName(pa_acGroupName), m_nReqUpdateRate(pa_nReqUpdateRate), m_nDeadBand(pa_nDeadBand), m_bReadGroupAdded(false), m_bWriteGroupAdded(false){
        }
    };

    typedef CSinglyLinkedList<SOpcGroupSettings*> TOpcGroupSettingsList;
    TOpcGroupSettingsList m_lOpcGroupSettingsList;

    COpcConnection* m_pOpcConn;

    COPCHost* m_pOpcHost;
    COPCServer *m_pOpcServer;

    const char* m_acHost;
    const char* m_acServerName;
    const char* m_acGroupName;
    unsigned long m_nReqUpdateRate;
    unsigned long m_nRealUpdateRate;
    float m_nDeadBand;
};

#endif // OPCCONNECTIONIMPL_H_
