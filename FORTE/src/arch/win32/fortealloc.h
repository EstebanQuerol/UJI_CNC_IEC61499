/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef FORTEALLOC_H_
#define FORTEALLOC_H_

//on win32 environments use default new operator
#include <new>
#include <stdlib.h>

inline
void forte_free(void *pa_pvData){
  free(pa_pvData);
}

inline
void *forte_malloc(size_t pa_nSize){
  return malloc(pa_nSize);
}

inline
void *forte_realloc(void *pa_pvData, size_t pa_nSize){
  return realloc(pa_pvData, pa_nSize);
}


#endif /* FORTEALLOC_H_ */
