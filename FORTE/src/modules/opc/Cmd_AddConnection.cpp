/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "Cmd_AddConnection.h"
#include "opcconnectionimpl.h"

CCmd_AddConnection::CCmd_AddConnection(COpcConnectionImpl *pa_pConnection) :
    m_pConnection(pa_pConnection){
}

CCmd_AddConnection::~CCmd_AddConnection(void){
}

void CCmd_AddConnection::runCommand(){
  m_pConnection->connect();
}
const char* CCmd_AddConnection::getCommandName() const{
  return "Cmd_AddConnection";
}
