/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef FBTESTDOCONN_H_
#define FBTESTDOCONN_H_

#include "dataconn.h"

class CFBTestDOConn : public CDataConnection{
  public:
    CFBTestDOConn(CFunctionBlock& pa_roSrcFB, CStringDictionary::TStringId pa_nDONameID, CIEC_ANY *pa_poValue);
    virtual ~CFBTestDOConn();
};

#endif /* FBTESTDOCONN_H_ */
