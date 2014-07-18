/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef FBTESTDICONN_H_
#define FBTESTDICONN_H_

#include "dataconn.h"

class CFBTestDIConn : public CDataConnection{
  public:
    CFBTestDIConn(CFunctionBlock& pa_roDstFB, CStringDictionary::TStringId pa_nDINameID, CIEC_ANY *pa_poValue);
    virtual ~CFBTestDIConn();

    static bool canBeConnected(const CIEC_ANY *pa_poSrcDataPoint, const CIEC_ANY *pa_poDstDataPoint){
    	bool bSpecialCast;
    	return CDataConnection::canBeConnected(pa_poSrcDataPoint, pa_poDstDataPoint, bSpecialCast);
    }
};

#endif /* FBTESTDOCONN_H_ */
