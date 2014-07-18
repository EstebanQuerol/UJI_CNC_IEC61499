/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "GEN_SUBL.h"

DEFINE_GENERIC_FIRMWARE_FB(GEN_SUBL, g_nStringIdGEN_SUBL)


GEN_SUBL::GEN_SUBL(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes):
          GEN_SUBSCRIBE( pa_nInstanceNameId, pa_poSrcRes){
}

bool GEN_SUBL::configureFB(const char *pa_acConfigString){
  bool bRetVal = GEN_SUBSCRIBE::configureFB(pa_acConfigString);
  //subls normally don't show the QI in the tool
  QI() = true;
  return bRetVal;
}

