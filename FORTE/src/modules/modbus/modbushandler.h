/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _MODBUSHANDLER_H_
#define _MODBUSHANDLER_H_

#include <config.h>
#include "extevhan.h"
#include "singlet.h"
#include "comcallback.h"
#include "fortelist.h"
#include <sync.h>

class CModbusHandler : public CExternalEventHandler{
  DECLARE_SINGLETON(CModbusHandler)
    ;
  public:
    typedef int TCallbackDescriptor;

    void enableHandler(void){
    }
    ;
    void disableHandler(void){
    }
    ;

    void setPriority(int){
      //currently we are doing nothing here.
      //TODO We should adjust the thread priority.
    }

    int getPriority(void) const{
      //the same as for setPriority
      return 0;
    }

    TCallbackDescriptor addComCallback(forte::com_infra::IComCallback* pa_pComCallback);
    void removeComCallback(TCallbackDescriptor pa_nCallbackDesc);

    void executeComCallback(TCallbackDescriptor pa_nCallbackDesc);

  private:
    struct TComContainer{
        TCallbackDescriptor m_nCallbackDesc;
        forte::com_infra::IComCallback* m_pCallback;
    };

    typedef CSinglyLinkedList<TComContainer> TCallbackList;
    TCallbackList m_lstComCallbacks;

    CSyncObject m_oSync;

    static TCallbackDescriptor m_nCallbackDescCount;
};

#endif // _MODBUSHANDLER_H_
