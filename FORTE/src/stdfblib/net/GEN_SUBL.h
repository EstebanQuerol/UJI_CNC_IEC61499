/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef GEN_SUBL_H_
#define GEN_SUBL_H_

#include "GEN_SUBSCRIBE.h"
#include <localcomlayer.h>

/*! \brief Implementation of the SUBL SIFB.
 *
 */

class GEN_SUBL : public GEN_SUBSCRIBE{
    DECLARE_GENERIC_FIRMWARE_FB(GEN_SUBL)
  public:
    GEN_SUBL(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);

    virtual bool configureFB(const char *pa_acConfigString);

  private:
    virtual char * getDefaultIDString(){
      return forte::com_infra::CLocalComLayer::getDefaultLocalCommIdString(ID().getValue());
    }
    ;
};

#endif /*GEN_SUBL_H_*/
