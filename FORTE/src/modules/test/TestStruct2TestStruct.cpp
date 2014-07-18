/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "TestStruct2TestStruct.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "TestStruct2TestStruct_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(TestStruct2TestStruct, g_nStringIdTestStruct2TestStruct)

const CStringDictionary::TStringId TestStruct2TestStruct::scm_anDataInputNames[] = {g_nStringIdIN};
const CStringDictionary::TStringId TestStruct2TestStruct::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId TestStruct2TestStruct::scm_aunDIDataTypeIds[] = {g_nStringIdTestStruct};
const CStringDictionary::TStringId TestStruct2TestStruct::scm_aunDODataTypeIds[] = {g_nStringIdTestStruct};

const TForteInt16 TestStruct2TestStruct::scm_anEIWithIndexes[] = {0};
const TDataIOID TestStruct2TestStruct::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId TestStruct2TestStruct::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID TestStruct2TestStruct::scm_anEOWith[] = {0, 255};
const TForteInt16 TestStruct2TestStruct::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId TestStruct2TestStruct::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec TestStruct2TestStruct::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void TestStruct2TestStruct::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  CIEC_TestStruct* Test = new CIEC_TestStruct();
	  Test->setValue(IN());
    OUT().setValue(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}

TestStruct2TestStruct::~TestStruct2TestStruct(){
}



