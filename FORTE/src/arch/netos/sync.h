/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _SYNC_H_
#define _SYNC_H_

#include <threadx/tx_api.h>

#define CSyncObject CTXSyncObject //allows that doxygen can generate better documenation

/*! \ingroup tnetos_hal 
 * \brief The sync object implementation for NET+OS.
 *
 * In the NET+OS version a mutex is used for the sync object.
 * 
 * @author AZ
 * @version 20051005/AZ - Initial implemenation of the netos version
 */
class CTXSyncObject{
  private:
  protected:
    TX_MUTEX m_stMutex;
  public:
    CTXSyncObject();
    ~CTXSyncObject();
  /*!\brief Lock the resource coming after the lock command  
   * 
   * This function blocks until it will get the lock for the coming critical section.
   */  
    void lock(void){
      tx_mutex_get(&m_stMutex, TX_WAIT_FOREVER);
      //TODO handle return value
    };
  //!Freee the resource coming after the lock command  
    void unlock(void){
      tx_mutex_put(&m_stMutex);
      //TODO handle return value
    };
};

#endif /*SYNC_H_*/
