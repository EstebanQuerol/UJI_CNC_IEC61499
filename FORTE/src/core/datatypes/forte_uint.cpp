/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_uint.h"

DEFINE_FIRMWARE_DATATYPE(UINT, g_nStringIdUINT)

const TForteUInt16 CIEC_UINT::scm_unMaxStringBufSize = 100;

const CIEC_UINT::TValueType CIEC_UINT::scm_nMaxVal = std::numeric_limits<CIEC_UINT::TValueType>::max();
