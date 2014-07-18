/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "sync.h"

CECOSSyncObject::CECOSSyncObject(){
  cyg_mutex_init(&m_oMutexHandle);
  cyg_mutex_set_protocol(&m_oMutexHandle, CYG_MUTEX_NONE);
}

CECOSSyncObject::~CECOSSyncObject(){
  cyg_mutex_destroy(&m_oMutexHandle);
}
