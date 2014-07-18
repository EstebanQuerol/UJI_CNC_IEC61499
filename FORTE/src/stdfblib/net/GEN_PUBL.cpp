/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     <date>: <author>, <author email> - changes
 *   20090406: AZ, alil@users.sourceforge.net - improved the implementation of all network communication FBs
 *******************************************************************************/
#include "GEN_PUBL.h"

DEFINE_GENERIC_FIRMWARE_FB(GEN_PUBL, g_nStringIdGEN_PUBL)

GEN_PUBL::GEN_PUBL(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes):
          GEN_PUBLISH( pa_nInstanceNameId, pa_poSrcRes) {
}

bool GEN_PUBL::configureFB(const char *pa_acConfigString){
  bool bRetVal = GEN_PUBLISH::configureFB(pa_acConfigString);
  //publs normally don't show the QI in the tool
  QI() = true;
  return bRetVal;
}


