/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "E_PERMIT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_PERMIT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(E_PERMIT, g_nStringIdE_PERMIT)

const CStringDictionary::TStringId E_PERMIT::scm_anDataInputNames[] = {g_nStringIdPERMIT};
const CStringDictionary::TStringId E_PERMIT::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 E_PERMIT::scm_anEIWithIndexes[] = { 0 };
const TDataIOID E_PERMIT::scm_anEIWith[] = { 0, 255 };
const CStringDictionary::TStringId E_PERMIT::scm_anEventInputNames[] = { g_nStringIdEI };

const CStringDictionary::TStringId E_PERMIT::scm_anEventOutputNames[] = { g_nStringIdEO };

const SFBInterfaceSpec
    E_PERMIT::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1,
      scm_anEventOutputNames, 0, 0, 1, scm_anDataInputNames, scm_aunDIDataTypeIds, 0, 0, 0,
      0,
      0
};

void E_PERMIT::executeEvent(int pa_nEIID){
  if((scm_nEventEIID == pa_nEIID) && (PERMIT())){
    sendOutputEvent(scm_nEventEOID);
  }
}

