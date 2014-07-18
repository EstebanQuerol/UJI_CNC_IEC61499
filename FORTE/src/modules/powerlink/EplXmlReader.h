/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _EPLXMLREADER_H_
#define _EPLXMLREADER_H_

#include "ProcessImageMatrix.h"
#include "ModuleList.h"

class TiXmlNode;

class CEplXmlReader{
  public:
    CEplXmlReader(CProcessImageMatrix* pa_pIn, CProcessImageMatrix* pa_pOut);
    ~CEplXmlReader();

    void setProcessImageIn(CProcessImageMatrix* pa_pIn);
    void setProcessImageOut(CProcessImageMatrix* pa_pOut);

    void readXmlFile(const char* pa_pchFileName);

    int getProcessImageIn();

  private:
    CModuleList m_oModuleListOut;
    CModuleList m_oModuleListIn;
    CProcessImageMatrix* m_pProcImageOut;
    CProcessImageMatrix* m_pProcImageIn;

    void createProcImageOut(TiXmlNode* pa_pProcessImage);
    void createProcImageIn(TiXmlNode* pa_pProcessImage);

    int getModuleNr(const char* pa_pchIoId);

};

#endif
