/*******************************************************************************
 * Copyright (c) 2007-2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef LMSUSBLAYER_H_
#define LMSUSBLAYER_H_

#include "comlayer.h"
#include "comcallback.h"
#include "extevhan.h"
#include "thread.h"
#include "fortelist.h"

class CLMSUSBLayer : public forte::com_infra::CComLayer,  public forte::com_infra::IComCallback{
  public:
    CLMSUSBLayer(forte::com_infra::CComLayer* pa_poUpperLayer, forte::com_infra::CCommFB* pa_poComFB);
    virtual ~CLMSUSBLayer();

    virtual void closeConnection();

    virtual forte::com_infra::EComResponse sendData(void *pa_pvData, unsigned int pa_unSize);
    virtual forte::com_infra::EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize);

    virtual CEventSourceFB *onComEvent();

    virtual forte::com_infra::EComResponse processComEvent();

    static void sendUSBData(TForteUInt8 pa_unMsgId, const void *pa_pvData, unsigned int pa_unSize);

    TForteUInt8 getUSBId() const {
      return m_unUSBID;
    }

  private:
    virtual forte::com_infra::EComResponse openConnection(char *pa_acLayerParameter);

    TForteUInt8 m_unUSBID;

    char m_acRecvBuffer[cg_unIPLayerRecvBufferSize];
    unsigned int m_unBufFillSize;
    forte::com_infra::EComResponse m_eInterruptResp;

    class CLMSUSBManager : public CExternalEventHandler, private CThread{

      public:

        void addComCallback(CLMSUSBLayer *pa_poComCallBack);
        void removeComCallback(CLMSUSBLayer *pa_poComCallBack);

        virtual void enableHandler(void){

        }

        virtual void disableHandler(void){
        }

        virtual void setPriority(int){
        }

        virtual int getPriority(void) const{
          return 0;
        }

      protected:
        virtual void run(void);

      private:
        CLMSUSBManager(): CThread(3500){
        }

        typedef CSinglyLinkedList<CLMSUSBLayer *> TConnectionContainer;
        TConnectionContainer m_lstConnectionsList;

        CSyncObject m_oSync;

        //needed so that CLMSUSBLayer can have a static membervariable holding the manager.
        friend class CLMSUSBLayer;

        //not to be implemented
        CLMSUSBManager(const CLMSUSBManager &);
        CLMSUSBManager &operator =(const CLMSUSBManager&);
    };

    static CLMSUSBManager sm_oLMSUSBManager;
};

#endif /* LMSUSBLAYER_H_ */
