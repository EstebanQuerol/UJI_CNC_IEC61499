/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _EPLCNCALLBACK_H_
#define _EPLCNCALLBACK_H_

class IEplCNCallback{
  public:

    virtual void cnSynchCallback() = 0;

  protected:
    virtual ~IEplCNCallback(){
    }
    ;

};

#endif //_EPLCNCALLBACK_H_
