/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_sint.h"

DEFINE_FIRMWARE_DATATYPE(SINT, g_nStringIdSINT)

const TForteUInt16 CIEC_SINT::scm_unMaxStringBufSize = 100;

const CIEC_SINT::TValueType CIEC_SINT::scm_nMinVal = std::numeric_limits<CIEC_SINT::TValueType>::min();
const CIEC_SINT::TValueType CIEC_SINT::scm_nMaxVal = std::numeric_limits<CIEC_SINT::TValueType>::max();
