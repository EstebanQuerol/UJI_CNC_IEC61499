/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef OPCCONNECTION_H_
#define OPCCONNECTION_H_

#include "comcallback.h"
#include "fortelist.h"
#include "sync.h"
#include "windows.h"
#include "Variant.h"

class COpcConnectionImpl;
class COpcProcessVar;

struct SOpcItemData{
    const char* m_acItemName;
    Variant m_oItemData;

    SOpcItemData(const char* pa_acItemName) :
        m_acItemName(pa_acItemName){
      m_oItemData.set<SHORT>(0);
    }
    SOpcItemData(const char* pa_acItemName, Variant pa_oItemData) :
        m_acItemName(pa_acItemName), m_oItemData(pa_oItemData){
    }
};
typedef CSinglyLinkedList<SOpcItemData*> TItemDataList;

class COpcConnection{
  public:

    COpcConnection(const char *pa_acHost, const char *pa_acServerName);
    ~COpcConnection();

    /*** Functions for OpcConnectionHandler ****************************************/
    void addGroup(const char* pa_acGroupName, unsigned long pa_nReqUpdateRate, float pa_nDeadBand, forte::com_infra::IComCallback* pa_pComCallback);
    void removeGroup(const char* pa_acGroupName);
    /*** END ***********************************************************************/

    /*** Functions for OpcComLayer *************************************************/
    int send_connect();
    int send_connect(bool pa_bBlocking);
    int send_addItem(COpcProcessVar* pa_pNewItem);
    int send_sendItemData(COpcProcessVar* pa_pItem);

    typedef CSinglyLinkedList<COpcProcessVar*> TOpcProcessVarList;
    int receiveData(const char* pa_acGroupName, TOpcProcessVarList * pa_lOpcProcessVarList);

    bool isConnected() const {
      return m_bIsConnected;
    }
    /*** END ***********************************************************************/

    /*** Functions for OpcConnectionImpl *******************************************/
    void response_connect(bool pa_bConnectionState);
    void response_dataReceived(const char *pa_acGroupName, TItemDataList & pa_lItemDataList);
    void response_itemAdded(COpcProcessVar* pa_pOpcItem);
    /*** END ***********************************************************************/

    /*** Common Functions **********************************************************/
    enum EOpcConnectionEvents{
      e_Disconnected, e_Connecting, e_ConnectionFailed, e_Connected, e_ItemAddedOk, e_ItemAddedFailed, e_DataReceived
    };

    const char* getHost() const {
      return m_acHost;
    }

    const char* getServerName() const {
      return m_acServerName;
    }

    unsigned int getGroupCount() const {
      return m_nGroupCount;
    }

    EOpcConnectionEvents getConnectionState() const {
      return m_eConnectionEvent;
    }

    /*** END ***********************************************************************/

  private:
    struct SOpcGroupMap{
        const char* m_acGroupName;
        int m_nCallbackDesc;
        TItemDataList m_lReadItemsList;
        TItemDataList m_lWriteItemsList;

        SOpcGroupMap(const char* pa_acGroupName, int pa_nCallbackDesc) :
            m_acGroupName(pa_acGroupName), m_nCallbackDesc(pa_nCallbackDesc){
        }
    };

    typedef CSinglyLinkedList<SOpcGroupMap*> TOpcGroupMapList;
    TOpcGroupMapList m_lOpcGroupMapList;

    unsigned int m_nGroupCount;

    COpcConnectionImpl *m_pOpcConnectionImpl;

    EOpcConnectionEvents m_eConnectionEvent;

    const char* m_acHost;
    const char* m_acServerName;
    const char* m_acGroupName;
    unsigned long m_nReqUpdateRate;
    unsigned long m_nRealUpdateRate;
    float m_nDeadBand;

    bool m_bIsConnected;
    bool m_bBlockingConnect;

    CSyncObject m_oSync;
};

#endif // OPCCONNECTION_H_
