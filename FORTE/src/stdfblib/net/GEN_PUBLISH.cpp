/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "GEN_PUBLISH.h"

DEFINE_GENERIC_FIRMWARE_FB(GEN_PUBLISH, g_nStringIdGEN_PUBLISH)

GEN_PUBLISH::GEN_PUBLISH(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes):
forte::com_infra::CCommFB( pa_nInstanceNameId, pa_poSrcRes, forte::com_infra::e_Publisher){
             //CNetCommFB( pa_nInstanceNameId, pa_poSrcRes, true, scm_nSendBufferSize, 0, CCommFB::e_Publisher){
}
