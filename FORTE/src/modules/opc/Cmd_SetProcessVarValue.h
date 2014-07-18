/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef CMDSETPROCESSVARVALUE_H_
#define CMDSETPROCESSVARVALUE_H_

#include "ICmd.h"

#include <Windows.h>
#include "Variant.h"

class COpcProcessVar;
class COpcConnectionImpl;

class CCmd_SetProcessVarValue : public ICmd{
  public:
    CCmd_SetProcessVarValue(COpcProcessVar * pa_pOpcVar);
    virtual ~CCmd_SetProcessVarValue(void);

    virtual void runCommand();
    virtual const char* getCommandName() const;

  private:
    COpcProcessVar* m_pOpcVar;
};

#endif //CMDSETPROCESSVARVALUE_H_
