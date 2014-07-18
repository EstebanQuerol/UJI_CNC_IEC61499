/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "dataconn.h"
#include "funcbloc.h"

CDataConnection::CDataConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB) :
  CConnection(pa_nSrcId, pa_nDstId),
  m_poValue(0),
  m_bSpecialCastConnection(false){

  CStringDictionary::TStringId nDstDataPointNameId = extractPortNameId(pa_nDstId);
  CStringDictionary::TStringId nSrcOutputNameId = getOutputNameId();

  CIEC_ANY *poDstDataPoint = getDstDataPoint(pa_nDstId, pa_roDstFB);
  CIEC_ANY *poSrcOutput = pa_roSrcFB.getDataOutput(nSrcOutputNameId);

  if(0 != poDstDataPoint){
    if(canBeConnected(poSrcOutput, poDstDataPoint, m_bSpecialCastConnection)){
      if(CIEC_ANY::e_ANY != poSrcOutput->getDataTypeID()){
        m_poValue = poSrcOutput->clone(m_acDataBuf);
      }
      else{
        if(CIEC_ANY::e_ANY != poDstDataPoint->getDataTypeID()){
          m_poValue = poDstDataPoint->clone(m_acDataBuf);
        }
      }
      pa_roSrcFB.connectDO(nSrcOutputNameId, this);
      pa_roDstFB.connectDI(nDstDataPointNameId, this);
    }
    else{
      m_lstDestinationIds.pop_front(); //empty the list so that the caller can identify that something went wrong
    }
  }
  else{
    m_lstDestinationIds.pop_front(); //empty the list so that the caller can identify that something went wrong
  }
}

EMGMResponse CDataConnection::connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB){
  EMGMResponse retval = e_NO_SUCH_OBJECT;

  CStringDictionary::TStringId nDstDataPointNameId = extractPortNameId(pa_nDstId);
  CIEC_ANY *poDstDataPoint = getDstDataPoint(pa_nDstId, pa_roDstFB);

  if(0 != poDstDataPoint){
    CIEC_ANY::EDataTypeID dstFBDTID = poDstDataPoint->getDataTypeID();

    if(0 == m_poValue){
      // we have an existing any to any connection
      if(CIEC_ANY::e_ANY != dstFBDTID){
        m_poValue = poDstDataPoint->clone(m_acDataBuf);
        pa_roSrcFB.connectDO(getOutputNameId(), this);
        //TODO we should also reconnect all destinations however we don't have the destination FBs
      }
    }
    else{
      if((dstFBDTID != CIEC_ANY::e_ANY) && (dstFBDTID
          != m_poValue->getDataTypeID())){
        if(!CIEC_ANY::isCastable(m_poValue->getDataTypeID(), dstFBDTID)){
          return e_INVALID_OBJECT;
        }
        else{
          //we want to cast from floating point data to an integer data type
          m_bSpecialCastConnection = needsSpecialCast(m_poValue->getDataTypeID());
        }
      }
    }
    if(e_RDY == (retval
        = CConnection::connectFannedOut(pa_nDstId, pa_roSrcFB, pa_roDstFB))){
      pa_roDstFB.connectDI(nDstDataPointNameId, this);
    }
  }
  return retval;
}

#ifndef FORTE_CLASS_0
EMGMResponse CDataConnection::disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB){

  EMGMResponse retval =
      CConnection::disconnect(pa_nDstId, pa_roSrcFB, pa_roDstFB);
  if(e_RDY == retval){ // the CConnection class didn't respond an error
    pa_roDstFB.connectDI(extractPortNameId(pa_nDstId), 0);
    if(m_lstDestinationIds.isEmpty()){
      if(CStringDictionary::scm_nInvalidStringId != extractFBNameId(m_nSourceId)){
        pa_roSrcFB.connectDO(getOutputNameId(), 0); //disconnect output
      }
    }
  }
  return retval;
}
#endif

void CDataConnection::readData(CIEC_ANY *pa_poValue) const {
  if(m_poValue) {
    if(!m_bSpecialCastConnection){
      pa_poValue->setValue(*m_poValue);
    }
    else{
      CIEC_ANY::specialCast(*m_poValue, *pa_poValue);
    }
  }
}

bool CDataConnection::canBeConnected(const CIEC_ANY *pa_poSrcDataPoint, const CIEC_ANY *pa_poDstDataPoint, bool &pa_rbSpecialCast) {
  CIEC_ANY::EDataTypeID eSrcId = pa_poSrcDataPoint->getDataTypeID();
  CIEC_ANY::EDataTypeID eDstId = pa_poDstDataPoint->getDataTypeID();
  bool bCanConnect = false;

  if(eSrcId == eDstId){
    bCanConnect = true;
  }
  else{
    if(((eSrcId == CIEC_ANY::e_ANY) && (eDstId != CIEC_ANY::e_ANY))
        || ((eSrcId != CIEC_ANY::e_ANY) && (eDstId == CIEC_ANY::e_ANY))){
      bCanConnect = true;
    }
    else{
      bCanConnect = CIEC_ANY::isCastable(eSrcId, eDstId);
      pa_rbSpecialCast = ((bCanConnect) && needsSpecialCast(eSrcId));
    }
  }
  return bCanConnect;
}

bool CDataConnection::needsSpecialCast(CIEC_ANY::EDataTypeID pa_eSrcDTId){
  //we want to cast from floating point data to an integer data type
  return ((CIEC_ANY::e_LREAL == pa_eSrcDTId) || (CIEC_ANY::e_REAL == pa_eSrcDTId));
}


CIEC_ANY *CDataConnection::getDstDataPoint(TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB){
  CIEC_ANY *poRetVal = 0;
  CStringDictionary::TStringId nDstDataPointNameId = extractPortNameId(pa_nDstId);

  if(CStringDictionary::scm_nInvalidStringId == extractFBNameId(pa_nDstId)){
    poRetVal = pa_roDstFB.getDataOutput(nDstDataPointNameId);
  }
  else{
    poRetVal = pa_roDstFB.getDataInput(nDstDataPointNameId);
  }
  return poRetVal;
}
