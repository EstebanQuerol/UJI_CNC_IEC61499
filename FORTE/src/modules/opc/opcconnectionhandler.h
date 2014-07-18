/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef OPCCONNECTIONHANDLER_H_
#define OPCCONNECTIONHANDLER_H_

#include "singlet.h"
#include "fortelist.h"
#include "comcallback.h"

class COpcConnection;

class COpcConnectionHandler{
  DECLARE_SINGLETON(COpcConnectionHandler)
    ;
  public:
    /*! \brief returns existing or creates new OpcConnection
     *
     *  If a connection to the specified server already exist a pointer to this is returned. Otherwise a
     *  new connection is created. The returned connection includes the group with the specified settings.
     */
    COpcConnection* getOpcConnection(const char *pa_acHost, const char *pa_acServerName, const char* pa_acGroupName, unsigned long pa_nReqUpdateRate, float pa_nDeadBand, forte::com_infra::IComCallback* pa_pComCallback);

    void removeOpcConnection(const char *pa_acHost, const char *pa_acServerName, const char* pa_acGroupName);

  private:
    COpcConnection* findOpcConnection(const char* pa_acHost, const char* pa_acServerName);
    void deleteOpcConnection(const char* pa_acHost, const char* pa_acServerName);

    typedef CSinglyLinkedList<COpcConnection*> TOpcConnectionList;
    TOpcConnectionList m_lOpcConnectionList;

};

#endif // OPCCONNECTIONHANDLER_H_
