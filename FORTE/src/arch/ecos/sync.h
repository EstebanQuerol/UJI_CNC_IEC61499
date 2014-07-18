/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _SYNC_H_
#define _SYNC_H_

#include <cyg/kernel/kapi.h>

#define CSyncObject CECOSSyncObject //allows that doxygen can generate better documenation

/*! \ingroup ECOS-HAL
 * \brief The sync object implementation for eCos.
 *
 * In the eCos version a mutex is used for the sync object.
 * 
 * @author AZ
 * @version 20051005/AZ - Initial implementation
 */
class CECOSSyncObject{
  private:
  protected:
  //! The posix thread mutex handle of the operating system.
    cyg_mutex_t m_oMutexHandle;
  public:
    CECOSSyncObject();
    ~CECOSSyncObject();
  /*!\brief Lock the resource coming after the lock command  
   * 
   * This function blocks until it will get the lock for the coming critical section.
   */  
    void lock(void){
      cyg_mutex_lock(&m_oMutexHandle);
    };
  //!Freee the resource coming after the lock command  
    void unlock(void){
      cyg_mutex_unlock(&m_oMutexHandle);
    };
};

#endif /*SYNC_H_*/
