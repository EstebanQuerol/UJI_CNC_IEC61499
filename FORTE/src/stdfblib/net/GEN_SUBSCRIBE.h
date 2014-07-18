/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _GEN_SUBSCRIBE_H_
#define _GEN_SUBSCRIBE_H_

#include "../../core/cominfra/commfb.h"

/*! \brief Implementation of the SUBSCRIBER SIFB.
 */


class GEN_SUBSCRIBE : public forte::com_infra::CCommFB {
    DECLARE_GENERIC_FIRMWARE_FB(GEN_SUBSCRIBE)

  public:
    GEN_SUBSCRIBE(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_SUBSCRIBE(){};

};

#endif //_GEN_SUBSCRIBE_H_

