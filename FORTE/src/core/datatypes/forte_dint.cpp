/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_dint.h"

DEFINE_FIRMWARE_DATATYPE(DINT, g_nStringIdDINT)

const TForteUInt16 CIEC_DINT::scm_unMaxStringBufSize = 100;

const CIEC_DINT::TValueType CIEC_DINT::scm_nMinVal = std::numeric_limits<CIEC_DINT::TValueType>::min();
const CIEC_DINT::TValueType CIEC_DINT::scm_nMaxVal = std::numeric_limits<CIEC_DINT::TValueType>::max();
