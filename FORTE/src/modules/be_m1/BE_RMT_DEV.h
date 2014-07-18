/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef BE_RMT_DEV_H_
#define BE_RMT_DEV_H_

#include "../../../stdfblib/ita/RMT_DEV.h"
#include <arch/be_m1/fortemodule.h>

class BE_RMT_DEV : public RMT_DEV{
  public:
    BE_RMT_DEV(CFORTEModule &pa_roModule);

    virtual ~BE_RMT_DEV();

    CFORTEModule & getModule() const{
      return m_roModule;
    }
  protected:
  private:
    CFORTEModule & m_roModule;
};

#endif /* BE_RMT_DEV_H_ */
