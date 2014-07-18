/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "E_SELECT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_SELECT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(E_SELECT, g_nStringIdE_SELECT)

const CStringDictionary::TStringId E_SELECT::scm_anDataInputNames[] = {g_nStringIdG};
const CStringDictionary::TStringId E_SELECT::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 E_SELECT::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID E_SELECT::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId E_SELECT::scm_anEventInputNames[] = {g_nStringIdEI0, g_nStringIdEI1};

const CStringDictionary::TStringId E_SELECT::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec E_SELECT::scm_stFBInterfaceSpec = {
  2,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  0,
  0,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  0,
  0,
  0,
  0,
  0
};

void E_SELECT::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventEI0ID:
      if(false == G()){
        sendOutputEvent( scm_nEventEOID);
      }
      break;
    case scm_nEventEI1ID:
      if(true == G()){
        sendOutputEvent( scm_nEventEOID);
      }
      break;
    default:
      break;
  }
}



