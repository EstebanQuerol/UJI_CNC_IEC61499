/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef IPCOMLAYER_H_
#define IPCOMLAYER_H_

#include <config.h>
#include "comlayer.h"
#include "comcallback.h"
#include <sockhand.h>

namespace forte {

  namespace com_infra {

    class CIPComLayer : public CComLayer, public IComCallback{
      public:
        CIPComLayer(CComLayer* pa_poUpperLayer, CCommFB* pa_poComFB);
        virtual ~CIPComLayer();

        EComResponse sendData(void *pa_pvData, unsigned int pa_unSize); // top interface, called from top
        EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize);

        CEventSourceFB *onComEvent();
        EComResponse processComEvent();

      protected:
        void closeConnection();

      private:
        static void closeSocket(CIPComSocketHandler::TSocketDescriptor *pa_nSocketID);

        EComResponse openConnection(char *pa_acLayerParameter);

        CIPComSocketHandler::TSocketDescriptor m_nSocketID;
        CIPComSocketHandler::TSocketDescriptor m_nListeningID; //!> to be used by server type connections. there the m_nSocketID will be used for the accepted connection.
        CIPComSocketHandler::TUDPDestAddr m_tDestAddr;
        EComResponse m_eInterruptResp;
        char m_acRecvBuffer[cg_unIPLayerRecvBufferSize];
        unsigned int m_unBufFillSize;
    };

  }

}

#endif /* IPCOMLAYER_H_ */
