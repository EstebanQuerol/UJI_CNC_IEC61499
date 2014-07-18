/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "sync.h"

CTXSyncObject::CTXSyncObject(){ 
  tx_mutex_create(&m_stMutex, "Test Mutex", TX_INHERIT);
  //TODO handle return value
}

CTXSyncObject::~CTXSyncObject(){
  tx_mutex_delete(&m_stMutex);
  //TODO handle return value
}
