/*******************************************************************************
 * Copyright (c) 2007-2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "testsingleton.h"

DEFINE_SINGLETON(TestSingleton);

unsigned int TestSingleton::sm_unInstanceCount = 0;

TestSingleton::TestSingleton(){
  sm_unInstanceCount++;
  m_unSingletonID = sm_unInstanceCount;
}

TestSingleton::~TestSingleton(){
}

