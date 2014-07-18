/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "GEN_SUBSCRIBE.h"

DEFINE_GENERIC_FIRMWARE_FB(GEN_SUBSCRIBE, g_nStringIdGEN_SUBSCRIBE)

GEN_SUBSCRIBE::GEN_SUBSCRIBE(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes):
forte::com_infra::CCommFB( pa_nInstanceNameId, pa_poSrcRes, forte::com_infra::e_Subscriber){
//CNetCommFB( pa_nInstanceNameId, pa_poSrcRes, false, 0, scm_nRecvBufferSize, CCommFB::e_Subscriber){
}

