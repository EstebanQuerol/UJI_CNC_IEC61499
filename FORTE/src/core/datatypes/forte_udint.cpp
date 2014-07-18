/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_udint.h"

DEFINE_FIRMWARE_DATATYPE(UDINT, g_nStringIdUDINT)

const TForteUInt16 CIEC_UDINT::scm_unMaxStringBufSize = 100;

const CIEC_UDINT::TValueType CIEC_UDINT::scm_nMaxVal = std::numeric_limits<CIEC_UDINT::TValueType>::max();
