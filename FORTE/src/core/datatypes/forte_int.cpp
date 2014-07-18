/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_int.h"

DEFINE_FIRMWARE_DATATYPE(INT, g_nStringIdINT)

const TForteUInt16 CIEC_INT::scm_unMaxStringBufSize = 100;

const CIEC_INT::TValueType CIEC_INT::scm_nMinVal = std::numeric_limits<CIEC_INT::TValueType>::min();
const CIEC_INT::TValueType CIEC_INT::scm_nMaxVal = std::numeric_limits<CIEC_INT::TValueType>::max();
