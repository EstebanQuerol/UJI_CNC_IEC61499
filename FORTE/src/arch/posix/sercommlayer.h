/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _SERCOMMLAYER_H_
#define _SERCOMMLAYER_H_

#include "comlayer.h"
#include "comcallback.h"
#include "../fdselecthand.h"
#include <termios.h>

class CSerCommLayer : public forte::com_infra::CComLayer, public forte::com_infra::IComCallback{
  public:
    CSerCommLayer(forte::com_infra::CComLayer* pa_poUpperLayer, forte::com_infra::CCommFB * pa_poFB);
    virtual ~CSerCommLayer();

    virtual void closeConnection();
    virtual forte::com_infra::EComResponse sendData(void *pa_pvData, unsigned int pa_unSize);
    virtual forte::com_infra::EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize);

    virtual CEventSourceFB *onComEvent();
    virtual forte::com_infra::EComResponse processComEvent();

  protected:
  private:
    virtual forte::com_infra::EComResponse openConnection(char *pa_acLayerParameter);

    CFDSelectHandler::TFileDescriptor m_nFD; //!< file descriptor for accessing the serial device

    forte::com_infra::EComResponse m_eInterruptResp;
    char m_acRecvBuffer[cg_unIPLayerRecvBufferSize];
    unsigned int m_unBufFillSize;
    struct termios m_stOldTIO;    //!< buffer for the existing sercom settings

};

#endif /* CSERCOMMLAYER_H_ */
