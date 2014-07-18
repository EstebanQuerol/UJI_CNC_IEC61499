/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/
#include "E_D_FF.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_D_FF_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(E_D_FF, g_nStringIdE_D_FF)

const CStringDictionary::TStringId E_D_FF::scm_anDataInputNames[] = {g_nStringIdD};

const CStringDictionary::TStringId E_D_FF::scm_anDataOutputNames[] = {g_nStringIdQ};
const CStringDictionary::TStringId E_D_FF::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL};
const CStringDictionary::TStringId E_D_FF::scm_aunDODataTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 E_D_FF::scm_anEIWithIndexes[] = {0};
const TDataIOID E_D_FF::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId E_D_FF::scm_anEventInputNames[] = {g_nStringIdCLK};

const TDataIOID E_D_FF::scm_anEOWith[] = {0, 255};
const TForteInt16 E_D_FF::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId E_D_FF::scm_anEventOutputNames[] = {g_nStringIdEO};

void E_D_FF::executeEvent(int pa_nEIID){
  if(scm_nEventCLKID == pa_nEIID){
    if(D() != Q()){
      Q() = D();
      sendOutputEvent( scm_nEventEOID);
    }
  }
}

const SFBInterfaceSpec E_D_FF::scm_stFBInterfaceSpec = {
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



