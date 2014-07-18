/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _MODULELIST_H_
#define _MODULELIST_H_

#include <fortelist.h>

class CModuleList{
  public:
    CModuleList();
    ~CModuleList();

    void addEntry(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset, unsigned int pa_nModuleNr);

    int getModuleNr(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset);

    int getModuleNr(const char* pa_pchName, unsigned int pa_nOccurence);

    int getNrOfModules(const char* pa_pchName);

    bool moduleNameExist(const char* pa_pchName);

  private:
    class IoModule{
      public:
        IoModule(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset, unsigned int pa_nModuleNr);
        ~IoModule();

        char* m_pchName;
        unsigned int m_nPiOffset;
        unsigned int m_nBitOffset;

        unsigned int m_nModuleNr;
    };

    //std::vector<IoModule*> m_lModules;

    typedef CSinglyLinkedList<IoModule*> TModuleList;
    TModuleList m_lModules;

    unsigned int m_nNumberOfModules;
};

#endif
