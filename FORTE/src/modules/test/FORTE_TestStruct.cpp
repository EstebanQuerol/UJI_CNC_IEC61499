/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "FORTE_TestStruct.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FORTE_TestStruct_gen.cpp"
#endif

DEFINE_FIRMWARE_DATATYPE(TestStruct, g_nStringIdTestStruct)

const CStringDictionary::TStringId CIEC_TestStruct::scm_unElementTypes[] = {g_nStringIdBOOL, g_nStringIdINT};
const CStringDictionary::TStringId CIEC_TestStruct::scm_unElementNames[] = {g_nStringIdFOO, g_nStringIdBAR};

CIEC_TestStruct::CIEC_TestStruct() :
  CIEC_STRUCT(g_nStringIdTestStruct, 2, scm_unElementTypes, scm_unElementNames, e_APPLICATION+e_CONSTRUCTED+1)
  {

  }
