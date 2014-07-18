/*******************************************************************************
 * Copyright (c) 2007-2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FDHAND_H_
#define _FDHAND_H_

#include "../core/fortelist.h"
#include "../core/cominfra/comcallback.h"
#include "../core/extevhan.h"
#include "../core/utils/singlet.h"
#include <thread.h>
#include <sync.h>

#if !defined(WIN32) && !defined(NET_OS) && !defined(VXWORKS)
#include <sys/select.h>
#endif

/*!\brief An external event handler for file descriptor based external events.
 *
 * This handler uses a thread and the select function to monitor given file descriptors on
 * data reception. Examples for possible file descriptors are sockets or com re
 */

class CFDSelectHandler : public CExternalEventHandler, private CThread{
  DECLARE_SINGLETON(CFDSelectHandler)
    ;
  public:
    typedef int TFileDescriptor; //!< General type definition for a file descriptor. To be used by the callback classes.
    static const TFileDescriptor scm_nInvalidFileDescriptor = -1;

    void addComCallback(TFileDescriptor pa_nFD, forte::com_infra::IComCallback *pa_poComCallBack);
    void removeComCallback(TFileDescriptor pa_nFD);

    /* functions needed for the external event handler interface */
    void enableHandler(void){
      start();
    }

    void disableHandler(void){
      end();
    }

    void setPriority(int ){
      //currently we are doing nothing here.
      //TODO We should adjust the thread priority.
    }

    int getPriority(void) const {
      //the same as for setPriority
      return 0;
    }

  protected:
    virtual void run(void);

  private:
    struct TConnContType{
        TFileDescriptor m_nSockDes;
        forte::com_infra::IComCallback * m_poCallee;
    };

    typedef CSinglyLinkedList<TConnContType> TConnectionContainer;

    TFileDescriptor createFDSet(fd_set *m_panFDSet);

    TConnectionContainer m_lstConnectionsList;
    CSyncObject m_oSync;
    bool m_bConnectionListChanged;
};

#endif
