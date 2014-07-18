/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "ModuleList.h"
#include <cstring>

CModuleList::IoModule::IoModule(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset, unsigned int pa_nModuleNr) :
    m_nPiOffset(pa_nPiOffset), m_nBitOffset(pa_nBitOffset), m_nModuleNr(pa_nModuleNr){

  m_pchName = new char[strlen(pa_pchName) + 1];
  strcpy(m_pchName, pa_pchName);
}

CModuleList::IoModule::~IoModule(){
  delete[] m_pchName;
}

CModuleList::CModuleList() :
    m_nNumberOfModules(0){

}

CModuleList::~CModuleList(){
  // Delete modules in list
  m_lModules.clearAll();

}

void CModuleList::addEntry(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset, unsigned int pa_nModuleNr){
  m_lModules.push_back(new IoModule(pa_pchName, pa_nPiOffset, pa_nBitOffset, pa_nModuleNr));

  m_nNumberOfModules++;
}

int CModuleList::getModuleNr(const char* pa_pchName, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset){

  TModuleList::Iterator itEnd(m_lModules.end());
  for(TModuleList::Iterator it(m_lModules.begin()); it != itEnd; ++it){
    if(strcmp(it->m_pchName, pa_pchName) == 0 && it->m_nPiOffset == pa_nPiOffset && it->m_nBitOffset == pa_nBitOffset){
      return it->m_nModuleNr;
    }
  }

  return -1;
}

int CModuleList::getModuleNr(const char* pa_pchName, unsigned int pa_nOccurence){
  unsigned int nrOcc = 0;

  TModuleList::Iterator itEnd(m_lModules.end());
  for(TModuleList::Iterator it(m_lModules.begin()); it != itEnd; ++it){
    char* pch = strstr(it->m_pchName, pa_pchName);
    if(pch != NULL){
      nrOcc++;
      if(nrOcc == pa_nOccurence){
        return it->m_nModuleNr;
      }
    }
  }

  return -1;
}

int CModuleList::getNrOfModules(const char* pa_pchName){
  int nrMods = 0;

  TModuleList::Iterator itEnd(m_lModules.end());
  for(TModuleList::Iterator it(m_lModules.begin()); it != itEnd; ++it){
    char* pch = strstr(it->m_pchName, pa_pchName);
    if(pch != NULL){
      nrMods++;
    }
  }

  return nrMods;
}

bool CModuleList::moduleNameExist(const char* pa_pchName){

  TModuleList::Iterator itEnd(m_lModules.end());
  for(TModuleList::Iterator it(m_lModules.begin()); it != itEnd; ++it){
    if(strcmp(it->m_pchName, pa_pchName) == 0){
      return true;
    }
  }

  return false;
}
