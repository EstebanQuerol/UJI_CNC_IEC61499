/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _SYNC_H_
#define _SYNC_H_

#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"

#define CSyncObject CVXWorksSyncObject //allows that doxygen can generate better documentation

/*! \ingroup bem1_hal
 * \brief The sync object implementation for the Bachmann electronic M1 interface
 *
 * In the Bachmann electronic M1 version we use a binary semaphore provided from vxWorks
 *
 */

class CVXWorksSyncObject{
  public:
    CVXWorksSyncObject();
    virtual ~CVXWorksSyncObject();

    void lock(void){
      semTake(m_oSemBinary, WAIT_FOREVER);
    }

    void unlock(void){
      semGive(m_oSemBinary);
    }

  private:
    SEM_ID m_oSemBinary;

};

#endif /*SYNC_H_*/
