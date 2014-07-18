/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <cyg/kernel/kapi.h>

//current tests have shown that this works only if it is in the main.cpp file
//I don't know why. The best is to copy or include it into your specific main file

//Workaround for an ecos problem
extern "C" void
__cxa_pure_virtual(void) {
  //TODO maybe add some exception handling reporting here
}
