/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_any_int.h"

DEFINE_FIRMWARE_DATATYPE(ANY_INT, g_nStringIdANY_INT)

CIEC_ANY_INT::CIEC_ANY_INT(TLargestIntValueType paVal){
  setSignedValue(paVal);
}
