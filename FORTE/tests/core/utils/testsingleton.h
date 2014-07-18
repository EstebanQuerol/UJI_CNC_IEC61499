/*******************************************************************************
 * Copyright (c) 2007-2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "../../../src/core/utils/singlet.h"

#ifndef TESTSINGLETON_H_
#define TESTSINGLETON_H_

class TestSingleton{
    DECLARE_SINGLETON(TestSingleton);

  public:

    int getSingletonID() {
      return m_unSingletonID;
    }

  private:
    static unsigned int sm_unInstanceCount;

    unsigned int m_unSingletonID;
};

#endif /* TESTSINGLETON_H_ */
