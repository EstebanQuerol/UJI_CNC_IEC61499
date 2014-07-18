/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "E_CTU.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_CTU_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(E_CTU, g_nStringIdE_CTU)

const CStringDictionary::TStringId E_CTU::scm_anDataInputNames[] = {g_nStringIdPV};

const CStringDictionary::TStringId E_CTU::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdCV};
const CStringDictionary::TStringId E_CTU::scm_aunDODataTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT};
const CStringDictionary::TStringId E_CTU::scm_aunDIDataTypeIds[] = {g_nStringIdUINT};

const TForteInt16 E_CTU::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID E_CTU::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId E_CTU::scm_anEventInputNames[] = {g_nStringIdCU, g_nStringIdR};

const TDataIOID E_CTU::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 E_CTU::scm_anEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId E_CTU::scm_anEventOutputNames[] = {g_nStringIdCUO, g_nStringIdRO};

void E_CTU::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventCUID:
      if(CV() < 65535){
        CV() = static_cast<TForteUInt16>(CV() + 1);
        Q() = (CV() >= PV());
        sendOutputEvent( scm_nEventCUOID);
      }
      break;
    case scm_nEventRID:
      CV() = 0;
      Q() = false;
      sendOutputEvent( scm_nEventROID);
      break;
    default:
      break;
  }
}

const SFBInterfaceSpec E_CTU::scm_stFBInterfaceSpec = {
  2,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  2,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  2,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};
