/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     <date>: <author>, <author email> - changes
 *******************************************************************************/
#include "TestAdapter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "TestAdapter_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(TESTADAPTER, g_nStringIdTESTADAPTER)

const CStringDictionary::TStringId TESTADAPTER::scm_anDataInputNamesSocket[] = {g_nStringIdREQD,g_nStringIdRSPD};

const CStringDictionary::TStringId TESTADAPTER::scm_anDataOutputNamesSocket[] = {g_nStringIdCNFD, g_nStringIdINDD};
const CStringDictionary::TStringId TESTADAPTER::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING, g_nStringIdWSTRING};
const CStringDictionary::TStringId TESTADAPTER::scm_aunDODataTypeIds[] = {g_nStringIdWSTRING, g_nStringIdWSTRING};


const TForteInt16 TESTADAPTER::scm_anEIWithIndexesSocket[] = {0,2, -1};
const TDataIOID TESTADAPTER::scm_anEIWithSocket[] = {0, 255,1,255};
const CStringDictionary::TStringId TESTADAPTER::scm_anEventInputNamesSocket[] = {g_nStringIdREQ,g_nStringIdRSP};

const TForteInt16 TESTADAPTER::scm_anEOWithIndexesSocket[] = {0,2};
const TDataIOID TESTADAPTER::scm_anEOWithSocket[] = {0, 255,1,255};
const CStringDictionary::TStringId TESTADAPTER::scm_anEventOutputNamesSocket[] = {g_nStringIdCNF,g_nStringIdIND};


const SFBInterfaceSpec TESTADAPTER::scm_stFBInterfaceSpecSocket = {
  2,
  scm_anEventInputNamesSocket,
  scm_anEIWithSocket,
  scm_anEIWithIndexesSocket,
  2,
  scm_anEventOutputNamesSocket,
  scm_anEOWithSocket,
  scm_anEOWithIndexesSocket,
  2,
  scm_anDataInputNamesSocket,
  scm_aunDIDataTypeIds,
  2,
  scm_anDataOutputNamesSocket, scm_aunDODataTypeIds,
  0,
  0
  };

const SFBInterfaceSpec TESTADAPTER::scm_stFBInterfaceSpecPlug = {
  2,
  scm_anEventOutputNamesSocket,
  scm_anEOWithSocket,
  scm_anEOWithIndexesSocket,
  2,
  scm_anEventInputNamesSocket,
  scm_anEIWithSocket,
  scm_anEIWithIndexesSocket,
  2,
  scm_anDataOutputNamesSocket, scm_aunDODataTypeIds,
  2,
  scm_anDataInputNamesSocket, scm_aunDIDataTypeIds,
  0,
  0
  };


TESTADAPTER::~TESTADAPTER(){
}



