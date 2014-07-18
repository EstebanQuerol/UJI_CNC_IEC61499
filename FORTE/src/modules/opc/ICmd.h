/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef ICMD_H_
#define ICMD_H_

class ICmd{
  public:
    ICmd(){
    }
    ;
    virtual ~ICmd(){
    }
    ;

    virtual void runCommand() = 0;
    virtual const char* getCommandName() const = 0;
};

#endif //ICMD_H_
