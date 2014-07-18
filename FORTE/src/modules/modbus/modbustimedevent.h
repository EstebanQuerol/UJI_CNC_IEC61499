/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _MODBUSTIMEDEVENT_H_
#define _MODBUSTIMEDEVENT_H_

#include "timerha.h"
#include <modbus.h>

class CModbusTimedEvent{
  public:
    CModbusTimedEvent(TForteUInt32 pa_nUpdateInterval); // UpdateInterval = 0 => single shot event
    virtual ~CModbusTimedEvent(){
    }

    void setUpdateInterval(TForteUInt32 pa_nUpdateInterval);
    TForteUInt32 getUpdateInterval() {
      return m_nUpdateInterval;
    }

    void activate();
    void deactivate();

    bool isStarted() const {
      return m_bIsStarted;
    }

    bool readyToExecute();

    // Classes impementing this should call restartTimer in executeEvent
    virtual int executeEvent(modbus_t* pa_pModbusConn, void* pa_pRetVal) = 0;

  protected:
    void restartTimer();

  private:
    SForteTime m_oStartTime;
    SForteTime m_oUpdateInterval;

    TForteUInt32 m_nUpdateInterval; // Polling interval in milliseconds (0 => single shot event)

    bool m_bSingleShotEvent;
    bool m_bIsStarted;
};

#endif // _MODBUSTIMEDEVENT_H_
