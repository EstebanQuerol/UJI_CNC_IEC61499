/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _MODBUSCLIENTCONNECTION_H_
#define _MODBUSCLIENTCONNECTION_H_

#include "modbusconnection.h"
#include "modbustimedevent.h"
#include "fortelist.h"

class CModbusPoll;

namespace modbus_connection_event {
  class CModbusConnectionEvent : public CModbusTimedEvent{
    public:
      CModbusConnectionEvent(long pa_nReconnectInterval); //ReconnectInterval = 0 => only one connection try
      ~CModbusConnectionEvent(){
      }
      ;

      int executeEvent(modbus_t *pa_pModbusConn, void *pa_pRetVal);
  };
}

class CModbusClientConnection : public CModbusConnection{
  public:
    CModbusClientConnection();
    ~CModbusClientConnection();

    int readData(uint8_t *pa_pData);
    int writeData(uint16_t *pa_pData, unsigned int pa_nDataSize);
    int connect();
    void disconnect();

    void addNewPoll(TForteUInt32 pa_nPollInterval, unsigned int pa_nFunctionCode, unsigned int pa_nStartAddress, unsigned int pa_nNrAddresses);
    void addNewSend(unsigned int pa_nStartAddress, unsigned int pa_nNrAddresses);

    void setSlaveId(unsigned int pa_nSlaveId);

  protected:
    virtual void run();

  private:
    void tryConnect();
    void tryPolling();

    struct SSendInformation {
      unsigned int m_nStartAddress;
      unsigned int m_nNrAddresses;
    };

    modbus_connection_event::CModbusConnectionEvent *m_pModbusConnEvent;

    typedef CSinglyLinkedList<CModbusPoll*> TModbusPollList;
    TModbusPollList m_lstPollList;

    typedef CSinglyLinkedList<SSendInformation> TModbusSendList;
    TModbusSendList m_lstSendList;

    unsigned int m_nNrOfPolls;
    unsigned int m_anRecvBuffPosition[100];

    unsigned int m_nSlaveId;

    uint8_t m_acRecvBuffer[cg_unIPLayerRecvBufferSize];
    unsigned int m_unBufFillSize;

};

#endif
