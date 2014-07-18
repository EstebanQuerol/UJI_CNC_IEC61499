/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef BE_SVIFB_H_
#define BE_SVIFB_H_

#include <arch/be_m1/fortemodule.h>
#include "funcbloc.h"

class BE_SVIFB : public CFunctionBlock{
  public:
    BE_SVIFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
        CFunctionBlock(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData){
    }

  protected:
    bool registerSVIvar(const CIEC_STRING& pa_roID, CIEC_ANY& pa_roValue, const TForteUInt32 pa_nMode);

  private:
    static const TForteUInt32 scm_anBE_SVI_Types[];
    static const TForteUInt32 scm_anBE_SVI_VarSizes[];

};

#endif /* BE_SVIFB_H_ */
