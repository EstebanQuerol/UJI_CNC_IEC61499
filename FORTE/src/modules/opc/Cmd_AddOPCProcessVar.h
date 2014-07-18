/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef CMDADDPROCESSVAR_H_
#define CMDADDPROCESSVAR_H_
#include "ICmd.h"

class COpcConnectionImpl;
class COpcProcessVar;

class CCmd_AddOPCProcessVar : public ICmd{
  public:
    CCmd_AddOPCProcessVar(COpcConnectionImpl *pa_pConnection, COpcProcessVar* pa_pNewItem);
    virtual ~CCmd_AddOPCProcessVar(void);

    virtual void runCommand();
    virtual const char* getCommandName() const;

  private:
    COpcConnectionImpl *m_pOpcConn;
    COpcProcessVar* m_pNewProcessVar;
};

#endif //CMDADDPROCESSVAR_H_
