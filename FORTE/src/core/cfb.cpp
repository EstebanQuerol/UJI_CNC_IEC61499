/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "cfb.h"
#include "adapter.h"
#include "resource.h"

CCompositeFB::CCompositeFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId, const SCFB_FBNData * const pa_cpoFBNData, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
  CFunctionBlock(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData), cm_cpoFBNData(pa_cpoFBNData) {

  createInternalFBs();

  createEventConnections();
  createDataConnections();
  setParams();

  //remove adapter-references for CFB
  for (TForteUInt8 i=0; i<pa_pstInterfaceSpec->m_nNumAdapters;i++) {
    if (0!=m_apoAdapters) {
      ((CAdapter*)m_apoAdapters[i])->setParentFB(0,0);
    }
  }

}

CCompositeFB::~CCompositeFB() {
  //CTypeLib &roTypeLib(CTypeLib::getInstance());
  if (cm_cpoFBNData->m_nNumFBs) {
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i) {
      delete m_apoInternalFBs[i];
    }
    delete[] m_apoInternalFBs;
  }
  if (cm_cpoFBNData->m_nNumEventConnections) {
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumEventConnections; ++i) {
      delete m_apoEventConnections[i];
    }
    delete[] m_apoEventConnections;
    delete[] m_apstInterface2InternalEventCons;
  }
  if (cm_cpoFBNData->m_nNumDataConnections) {
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumDataConnections; ++i) {
      delete m_apoDataConnections[i];
    }
    delete[] m_apoDataConnections;
    delete[] m_apoIf2InDConns;
    delete[] m_apoIn2IfDConns;
  }
}

bool CCompositeFB::connectDI(CStringDictionary::TStringId pa_unDINameId, CDataConnection *pa_poDataCon) {
  bool bRetVal = false;
  unsigned int unDIOD = getDIID(pa_unDINameId);
  if (cg_unInvalidPortId != unDIOD) {
    bool bNeedsCloning = (getDI(unDIOD)->getDataTypeID() == CIEC_ANY::e_ANY);
    bRetVal = CFunctionBlock::connectDI(pa_unDINameId, pa_poDataCon);
    if ((true == bNeedsCloning) && (0 != pa_poDataCon->getValue())) {
      if (0 != m_apoIf2InDConns[unDIOD]) {
        //check if internal connected
        m_apoIf2InDConns[unDIOD]->setValue(getDI(unDIOD));
        m_apoIf2InDConns[unDIOD]->cloneInputInterfaceValue();
      }
    }
  }
  return bRetVal;
}

bool CCompositeFB::connectDO(CStringDictionary::TStringId pa_unDONameId, CDataConnection *pa_poDataCon) {
  bool bRetVal = false;
  unsigned int unDOID = getDOID(pa_unDONameId);
  if (cg_unInvalidPortId != unDOID) {
    bool bNeedsCloning = (getDO(unDOID)->getDataTypeID() == CIEC_ANY::e_ANY);
    bRetVal = CFunctionBlock::connectDO(pa_unDONameId, pa_poDataCon);
    if ((true == bNeedsCloning) && (0 != pa_poDataCon->getValue())) {
      if (0 != m_apoIn2IfDConns[unDOID]) {
        //check if internal connected
        m_apoIn2IfDConns[unDOID]->setValue(getDO(unDOID));
        //FIXME ANY backward resolveing
        //m_apoIn2IfDConns[unDOID]->cloneOutputInterfaceValue();
      }
    }
  }
  return bRetVal;
}

EMGMResponse CCompositeFB::changeFBExecutionState(EMGMCommandType pa_unCommand) {
  EMGMResponse nRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  for (unsigned int i = 0; ((i < cm_cpoFBNData->m_nNumFBs) && (e_RDY == nRetVal)); ++i) {
    if (m_apoInternalFBs[i]) {
      nRetVal = m_apoInternalFBs[i]->changeFBExecutionState(pa_unCommand);
    }
  }
  //Update FB parameters that maybe got overwritten by default values of the FB
  if((cg_nMGM_CMD_Reset == pa_unCommand) && (e_IDLE == getState())){
    setParams();
  }
  return nRetVal;
}

// TODO make this const char * and working with const char *
CIEC_ANY *CCompositeFB::getVar(const char *pa_acVarName) {
  CIEC_ANY *poRetVal = CFunctionBlock::getVar(pa_acVarName);
  if (0 == poRetVal) { //The named element is no in- or output var
    const char *acBuf = strchr(pa_acVarName, '.'); //find the first dot in the list
    if ('\0' != acBuf) { //we found a dot
      TIdentifier acFBName;
      memcpy(acFBName, pa_acVarName, ((acBuf - pa_acVarName) > cg_nIdentifierLength) ? cg_nIdentifierLength : (acBuf - pa_acVarName));
      acFBName[cg_nIdentifierLength] = '\0';
      acBuf++;
      CStringDictionary::TStringId nFBId = CStringDictionary::getInstance().getId(acFBName);
      for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i) {
        if (nFBId == m_apoInternalFBs[i]->getInstanceNameId()) {
          poRetVal = m_apoInternalFBs[i]->getVar(acBuf);
          break;
        }
      }
    }
  }
  return poRetVal;
}

void CCompositeFB::executeEvent(int pa_nEIID) {
  if (0x100 & pa_nEIID) {
    sendInternal2InterfaceOutputEvent(static_cast<TEventID>(pa_nEIID & 0xFF));
  }
  else {
    if (pa_nEIID < m_pstInterfaceSpec->m_nNumEIs) {
      if (0 != m_apstInterface2InternalEventCons[pa_nEIID]) {
        m_apstInterface2InternalEventCons[pa_nEIID]->triggerEvent(*m_poInvokingExecEnv);
      }
    }
  }
}

void CCompositeFB::sendInternal2InterfaceOutputEvent(int pa_nEOID){
  //handle sampling of internal 2 interface data connections
  if((pa_nEOID < m_pstInterfaceSpec->m_nNumEOs) && (0 != m_pstInterfaceSpec->m_anEOWithIndexes)){
    if(-1 != m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEOID]){
      const TDataIOID *poEOWithStart = &(m_pstInterfaceSpec->m_anEOWith[m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEOID]]);

      // TODO think on this lock
      getResource().m_oResDataConSync.lock();
      for(int i = 0; poEOWithStart[i] != 255; ++i){
        if(0 != m_apoIn2IfDConns[poEOWithStart[i]]){
          m_apoIn2IfDConns[poEOWithStart[i]]->readData(getDO(poEOWithStart[i]));
        }
      }
      // TODO think on this lock
      getResource().m_oResDataConSync.unlock();
    }
  }

  sendOutputEvent(pa_nEOID);
}

void CCompositeFB::createInternalFBs() {
  if (cm_cpoFBNData->m_nNumFBs) {
    m_apoInternalFBs = new TFunctionBlockPtr[cm_cpoFBNData->m_nNumFBs];
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i) {
      m_apoInternalFBs[i] = CTypeLib::createFB(cm_cpoFBNData->m_pstFBInstances[i].m_nFBInstanceNameId, cm_cpoFBNData->m_pstFBInstances[i].m_nFBTypeNameId, getResourcePtr());
    }
  }
}

void CCompositeFB::createEventConnections() {
  if(0 != cm_cpoFBNData->m_nNumEventConnections) {
    if(0 != m_pstInterfaceSpec->m_nNumEIs) {
      m_apstInterface2InternalEventCons = new TEventConnectionPtr[m_pstInterfaceSpec->m_nNumEIs];
      memset(m_apstInterface2InternalEventCons, 0, sizeof(TEventConnectionPtr) * m_pstInterfaceSpec->m_nNumEIs);
    }
    m_apoEventConnections = new CEventConnection *[cm_cpoFBNData->m_nNumEventConnections];
    const SCFB_FBConnectionData *cpstCurrentConn;
    CFunctionBlock *poSrcFB;
    CFunctionBlock *poDstFB;
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumEventConnections; ++i) {
      cpstCurrentConn = &(cm_cpoFBNData->m_pstEventConnections[i]);
      //FIXME check if we could get the FB
      //FIXME implement way to inform FB creator that creation failed
      poSrcFB = getFunctionBlock(cpstCurrentConn->m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentConn->m_nDstFBNum);

      m_apoEventConnections[i] = new CEventConnection(cpstCurrentConn->m_nSrcId, *poSrcFB, cpstCurrentConn->m_nDstId, *poDstFB);
      if (this == poSrcFB) {
        m_apstInterface2InternalEventCons[getEIID(CConnection::extractPortNameId(cpstCurrentConn->m_nSrcId))] = m_apoEventConnections[i];
      }
    }
    //now handle the fanned out connections
    const SCFB_FBFannedOutConnectionData *cpstCurrentFannedConn;
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumFannedOutEventConnections; ++i) {
      cpstCurrentFannedConn = &(cm_cpoFBNData->m_pstFannedOutEventConnections[i]);
      poSrcFB = getFunctionBlock(cm_cpoFBNData->m_pstEventConnections[cpstCurrentFannedConn->m_nConnectionNum].m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentFannedConn->m_nDstFBNum);
      m_apoEventConnections[cpstCurrentFannedConn->m_nConnectionNum]->connectFannedOut(cpstCurrentFannedConn->m_nDstId, *poSrcFB, *poDstFB);
    }
  }
}

void CCompositeFB::createDataConnections() {
  if (cm_cpoFBNData->m_nNumDataConnections) {
    if (m_pstInterfaceSpec->m_nNumDIs) {
      m_apoIf2InDConns = new TCInterface2InternalDataConnectionPtr[m_pstInterfaceSpec->m_nNumDIs];
    }
    if (m_pstInterfaceSpec->m_nNumDOs) {
      m_apoIn2IfDConns = new CDataConnection *[m_pstInterfaceSpec->m_nNumDOs];
    }

    m_apoDataConnections = new CDataConnection *[cm_cpoFBNData->m_nNumDataConnections];
    const SCFB_FBConnectionData *cpstCurrentConn;
    CFunctionBlock *poSrcFB;
    CFunctionBlock *poDstFB;
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumDataConnections; ++i) {
      cpstCurrentConn = &(cm_cpoFBNData->m_pstDataConnections[i]);
      //FIXME check if we could get the FB
      //FIXME implement way to inform FB creator that creation failed
      poSrcFB = getFunctionBlock(cpstCurrentConn->m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentConn->m_nDstFBNum);

      if (this == poSrcFB) {
        m_apoIf2InDConns[getDIID(CConnection::extractPortNameId(cpstCurrentConn->m_nSrcId))] = new CInterface2InternalDataConnection(cpstCurrentConn->m_nSrcId, *poSrcFB, cpstCurrentConn->m_nDstId, *poDstFB);
        m_apoDataConnections[i] = m_apoIf2InDConns[getDIID(CConnection::extractPortNameId(cpstCurrentConn->m_nSrcId))];
      }
      else {
        m_apoDataConnections[i] = new CDataConnection(cpstCurrentConn->m_nSrcId, *poSrcFB, cpstCurrentConn->m_nDstId, *poDstFB);
      }
      if(this == poDstFB){
        m_apoIn2IfDConns[getDOID(CConnection::extractPortNameId(cpstCurrentConn->m_nDstId))] = m_apoDataConnections[i];
      }
    }
    //now handle the fanned out connections
    const SCFB_FBFannedOutConnectionData *cpstCurrentFannedConn;
    for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumFannedOutDataConnections; ++i) {
      cpstCurrentFannedConn = &(cm_cpoFBNData->m_pstFannedOutDataConnections[i]);
      poSrcFB = getFunctionBlock(cm_cpoFBNData->m_pstDataConnections[cpstCurrentFannedConn->m_nConnectionNum].m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentFannedConn->m_nDstFBNum);
      if(this == poDstFB){
        //TODO check if we need to also handle connected Fanned out here
        m_apoIn2IfDConns[getDOID(CConnection::extractPortNameId(cpstCurrentFannedConn->m_nDstId))] = m_apoDataConnections[cpstCurrentFannedConn->m_nConnectionNum];
      }
      else{
        m_apoDataConnections[cpstCurrentFannedConn->m_nConnectionNum]->connectFannedOut(cpstCurrentFannedConn->m_nDstId, *poSrcFB, *poDstFB);
      }
    }
  }
}

void CCompositeFB::setParams() {
  const SCFB_FBParameter *pstCurrentParam;
  for (unsigned int i = 0; i < cm_cpoFBNData->m_nNumParams; ++i) {
    pstCurrentParam = &(cm_cpoFBNData->m_pstParams[i]);
    CIEC_ANY *poDI = m_apoInternalFBs[pstCurrentParam->m_nFBNum]->getDataInput(pstCurrentParam->m_nDINameID);
    if (0 != poDI) {
      poDI->fromString(pstCurrentParam->m_acParamValue);
    }
    else {
      DEVLOG_ERROR("Could not get date input for setting a parameter");
    }
  }
}

CFunctionBlock *CCompositeFB::getFunctionBlock(int pa_nFBNum) {
  CFunctionBlock *poRetVal = 0;
  if (-1 == pa_nFBNum) {
    poRetVal = this;
  }
  else if (0 <= pa_nFBNum){
    //FIXME check range

    if ( scm_nAdapterMarker == ( scm_nAdapterMarker & pa_nFBNum ) ) {
      pa_nFBNum &= scm_nAdapterFBRange;
      if( pa_nFBNum < m_pstInterfaceSpec->m_nNumAdapters){
        poRetVal = m_apoAdapters[pa_nFBNum];
      }
    }
    else {
      if(static_cast<unsigned int>(pa_nFBNum) < cm_cpoFBNData->m_nNumFBs){
        poRetVal = m_apoInternalFBs[pa_nFBNum];
      }
    }
    //poRetVal = (0x10000  & pa_nFBNum) ? m_apoAdapters[pa_nFBNum & 0xFFFF] : m_apoInternalFBs[pa_nFBNum];
  }
  return poRetVal;
}
