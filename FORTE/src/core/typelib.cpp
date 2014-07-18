/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "./datatypes/forte_any.h"
#include "typelib.h"
#include "eventconn.h"
#include "dataconn.h"
#include "adapterconn.h"
#include "resource.h"
#include "if2indco.h"
#include <stddef.h>

#ifndef FORTE_CLASS_0
CTypeLib::CTypeEntry::CTypeEntry(CStringDictionary::TStringId pa_nTypeNameId) :
        m_nTypeNameId(pa_nTypeNameId),
        m_poNext(0){
      }

CTypeLib::CTypeEntry::~CTypeEntry(void){

}

CTypeLib::CFBTypeEntry::CFBTypeEntry(CStringDictionary::TStringId pa_nTypeNameId, TFunctionBlockCreateFunc pa_pfuncCreateFB):
          CTypeEntry(pa_nTypeNameId),
          m_pfuncFBCreationFunc(pa_pfuncCreateFB){
  CTypeLib::addFBType(this);

}


CTypeLib::CFBTypeEntry::~CFBTypeEntry(void){

}

CTypeLib::CAdapterTypeEntry::CAdapterTypeEntry(CStringDictionary::TStringId pa_nTypeNameId, TAdapterCreateFunc pa_pfuncCreateAdapter):
  CTypeEntry(pa_nTypeNameId),
  m_pfuncAdapterCreationFunc(pa_pfuncCreateAdapter){
CTypeLib::addAdapterType(this);

}

CTypeLib::CAdapterTypeEntry::~CAdapterTypeEntry(void){

}

CTypeLib::CDataTypeEntry::CDataTypeEntry(CStringDictionary::TStringId pa_nTypeNameId, TDataTypeCreateFunc pa_pfuncDTCreateFunc) :
          CTypeEntry(pa_nTypeNameId){
  m_pfuncDTCreateFunc = pa_pfuncDTCreateFunc;
  CTypeLib::addDataType(this);
}

CTypeLib::CDataTypeEntry::~CDataTypeEntry(void){

}


EMGMResponse CTypeLib::m_eLastErrorMSG = e_RDY;

CTypeLib::CFBTypeEntry *CTypeLib::m_poFBLibStart = 0;
CTypeLib::CFBTypeEntry *CTypeLib::m_poFBLibEnd = 0;

CTypeLib::CAdapterTypeEntry *CTypeLib::m_poAdapterLibStart = 0;
CTypeLib::CAdapterTypeEntry *CTypeLib::m_poAdapterLibEnd = 0;

CTypeLib::CDataTypeEntry *CTypeLib::m_poDTLibStart = 0;
CTypeLib::CDataTypeEntry *CTypeLib::m_poDTLibEnd = 0;

//CTypeLib::~CTypeLib() {
//  //TODO free memory of fblibrary (maybe not necessary as typelib is deleted at the end of the program)
//  //TODO free memory of RESlibrary (maybe not necessary as typelib is deleted at the end of the program)
//}

CTypeLib::CTypeEntry *CTypeLib::findType(CStringDictionary::TStringId pa_nTypeId, CTypeLib::CTypeEntry *pa_poListStart) {
  CTypeEntry *retval = 0;
  for (CTypeEntry *poRunner = pa_poListStart; poRunner != 0; poRunner
      = poRunner->m_poNext){
    if (pa_nTypeId == poRunner->getTypeNameId()) {
      retval = poRunner;
      break;
    }
  }
  return retval;
}

CAdapter *CTypeLib::createAdapter(CStringDictionary::TStringId pa_nInstanceNameId, CStringDictionary::TStringId pa_nAdapterTypeId, CResource *pa_poRes, bool pa_bIsPlug) {
  CAdapter *poNewAdapter = 0;
  CTypeEntry *poToCreate = findType(pa_nAdapterTypeId, m_poAdapterLibStart);
  if (0 != poToCreate) {
    poNewAdapter =
      ((CAdapterTypeEntry *)poToCreate)->createAdapterInstance(pa_nInstanceNameId,pa_poRes, pa_bIsPlug);
    if (0 == poNewAdapter)
      m_eLastErrorMSG = e_OVERFLOW;
  } //no generic adapters supported

    return poNewAdapter;

}

CFunctionBlock *CTypeLib::createFB(CStringDictionary::TStringId pa_nInstanceNameId, CStringDictionary::TStringId pa_nFBTypeId, CResource *pa_poRes) {
  CFunctionBlock *poNewFB = 0;
  CTypeEntry *poToCreate = findType(pa_nFBTypeId, m_poFBLibStart);
  //TODO: Avoid that the user can create generic blocks.
  if (0 != poToCreate) {
    poNewFB
        = ((CFBTypeEntry *)poToCreate)->createFBInstance(pa_nInstanceNameId, pa_poRes);
    if (0 == poNewFB) // we could not create the requested object
      m_eLastErrorMSG = e_OVERFLOW;
  } else { //check for parameterizable FBs (e.g. SERVER)
    TIdentifier acGenFBName = { "GEN_" };
    const char *acTypeBuf = CStringDictionary::getInstance().get(pa_nFBTypeId);
    const char *pcUnderScore = getFirstNonTypeNameUnderscorePos(acTypeBuf);

    if (0 != pcUnderScore) { // We found no underscore in the type name therefore it can not be a generic type
      ptrdiff_t nCopyLen = pcUnderScore - acTypeBuf;
      if (nCopyLen > cg_nIdentifierLength - 4)
        nCopyLen = cg_nIdentifierLength - 4;
      memcpy(&(acGenFBName[4]), acTypeBuf, nCopyLen);
      acGenFBName[cg_nIdentifierLength] = '\0';
      poToCreate = findType(CStringDictionary::getInstance().getId(acGenFBName), m_poFBLibStart);
      if (0 != poToCreate) {
        poNewFB = ((CFBTypeEntry *)poToCreate)->createFBInstance(pa_nInstanceNameId, pa_poRes);
        if (0 == poNewFB){ // we could not create the requested object
          m_eLastErrorMSG = e_OVERFLOW;
        }
        else { // we got a configurable block
          if (!poNewFB->configureFB(acTypeBuf)) {
            //TODO: Handle an error, if the FB was not configured correctly!!!!
          }
        }
      }
      else{
        m_eLastErrorMSG = e_UNSUPPORTED_TYPE;
      }
    }
    else{
      m_eLastErrorMSG = e_UNSUPPORTED_TYPE;
    }
  }

  if(0 != poNewFB){
    // perform reset to move it into idle state and set the initial values
    poNewFB->changeFBExecutionState(cg_nMGM_CMD_Reset);
  }

  return poNewFB;
}

bool CTypeLib::deleteFB(CFunctionBlock *pa_poFBToDelete) {
	delete pa_poFBToDelete;
  return true;
}

CIEC_ANY *CTypeLib::createDataTypeInstance(CStringDictionary::TStringId pa_nDTNameId, TForteByte *pa_acDataBuf) {
  CIEC_ANY *poNewDT = 0;
  CTypeEntry *poToCreate = findType(pa_nDTNameId, m_poDTLibStart);
  if (0 != poToCreate) {
    poNewDT = ((CDataTypeEntry *)poToCreate)->createDataTypeInstance(pa_acDataBuf);
    if (0 == poNewDT) // we could not create the requested object
      m_eLastErrorMSG = e_OVERFLOW;
  } else
    m_eLastErrorMSG = e_UNSUPPORTED_TYPE;

  return poNewDT;
}

void CTypeLib::deleteConnection(CConnection *pa_poToDelete) {
  delete pa_poToDelete;
}

void CTypeLib::addFBType(CFBTypeEntry *pa_poFBTypeEntry) {
  if (0 == findType(pa_poFBTypeEntry->getTypeNameId(), m_poFBLibStart)) {
    if (m_poFBLibStart == 0)
      m_poFBLibStart = pa_poFBTypeEntry;
    else
      m_poFBLibEnd->m_poNext = pa_poFBTypeEntry;
    m_poFBLibEnd = pa_poFBTypeEntry;
  }
}

void CTypeLib::addAdapterType(CAdapterTypeEntry *pa_poAdapterTypeEntry) {
  if (0 == findType(pa_poAdapterTypeEntry->getTypeNameId(), m_poAdapterLibStart)) {
    if (m_poAdapterLibStart == 0)
      m_poAdapterLibStart = pa_poAdapterTypeEntry;
    else
      m_poAdapterLibEnd->m_poNext = pa_poAdapterTypeEntry;
    m_poAdapterLibEnd = pa_poAdapterTypeEntry;
  }
}


void CTypeLib::addDataType(CDataTypeEntry *pa_poDTEntry) {
  if (0 == findType(pa_poDTEntry->getTypeNameId(), m_poDTLibStart)) {
    if (m_poDTLibStart == 0)
      m_poDTLibStart = pa_poDTEntry;
    else
      m_poDTLibEnd->m_poNext = pa_poDTEntry;
    m_poDTLibEnd = pa_poDTEntry;
  }
}


const char *CTypeLib::getFirstNonTypeNameUnderscorePos(const char *pa_acTypeName){
  const char* acRetVal = pa_acTypeName;

  do{
    acRetVal = strchr(acRetVal, '_');
    if(0 != acRetVal){
      if(forte::core::util::isDigit(*(acRetVal + 1))){
        //only when the element after the underscore is a digit it is a correct type name
        break;
      }
      acRetVal++;
    }
  } while(0 != acRetVal);

  return acRetVal;
}



#endif


