/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "E_MERGE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_MERGE_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(E_MERGE, g_nStringIdE_MERGE)

const CStringDictionary::TStringId E_MERGE::scm_anEventInputNames[] = {g_nStringIdEI1, g_nStringIdEI2};

const CStringDictionary::TStringId E_MERGE::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec E_MERGE::scm_stFBInterfaceSpec = {
  2,
  scm_anEventInputNames,
  0,
  0,
  1,
  scm_anEventOutputNames,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};



