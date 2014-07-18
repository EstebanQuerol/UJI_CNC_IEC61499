/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "fbtestdiconn.h"
#include "funcbloc.h"

CFBTestDIConn::CFBTestDIConn(CFunctionBlock& pa_roDstFB, CStringDictionary::TStringId pa_nDINameID, CIEC_ANY *pa_poValue):
               CDataConnection(CStringDictionary::scm_nInvalidStringId, CStringDictionary::scm_nInvalidStringId){
  m_poValue = pa_poValue;

  pa_roDstFB.connectDI(pa_nDINameID, this);
}

CFBTestDIConn::~CFBTestDIConn(){
  m_poValue = 0;
}

