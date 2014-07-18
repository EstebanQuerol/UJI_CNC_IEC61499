/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _GEN_SERVER_H_
#define _GEN_SERVER_H_

#include "../../core/cominfra/commfb.h"

/*! \brief Implementation of the SERVER_* SIFB.
 *
 */

class GEN_SERVER: public forte::com_infra::CCommFB {
    DECLARE_GENERIC_FIRMWARE_FB(GEN_SERVER)
  public:
    GEN_SERVER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_SERVER(){};

};

#endif //_GEN_SERVER_H_
