/* Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "if2indco.h"

CInterface2InternalDataConnection::CInterface2InternalDataConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB) :
                                   CDataConnection(pa_nSrcId, pa_nDstId) {
  m_poValue = pa_roSrcFB.getDataInput(extractPortNameId(pa_nSrcId));

  CStringDictionary::TStringId nDstInputNameId = extractPortNameId(pa_nDstId);
  CIEC_ANY *poDstInput = pa_roDstFB.getDataInput(nDstInputNameId);

  if(0 != poDstInput) {
    if(canBeConnected(m_poValue, poDstInput, m_bSpecialCastConnection)){
      pa_roDstFB.connectDI(nDstInputNameId, this);
      m_lstDstFBPtr.push_back(&pa_roDstFB);
    }
    else{
      m_lstDestinationIds.pop_front(); //empty the list so that the caller can identify that something went wrong
    }
  }
  else{
    m_lstDestinationIds.pop_front(); //empty the list so that the caller can identify that something went wrong
  }
}

EMGMResponse CInterface2InternalDataConnection::connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB) {
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  CStringDictionary::TStringId nDstInputNameId = extractPortNameId(pa_nDstId);
  CIEC_ANY *poDstInput = pa_roDstFB.getDataInput(nDstInputNameId);

  if(0 != poDstInput) {
    if(canBeConnected(m_poValue, poDstInput, m_bSpecialCastConnection)){
      if(e_RDY == (eRetVal = CConnection::connectFannedOut(pa_nDstId, pa_roSrcFB, pa_roDstFB))){
        pa_roDstFB.connectDI(nDstInputNameId, this);
        m_lstDstFBPtr.push_back(&pa_roDstFB);
      }
    }
    else{
      eRetVal = e_INVALID_OBJECT;
    }
  }
  return eRetVal;
}

void CInterface2InternalDataConnection::cloneInputInterfaceValue(void){
  TDestinationIdList::Iterator runnerDst = m_lstDestinationIds.begin();
  for(TFunctionBlockList::Iterator runnerFB= m_lstDstFBPtr.begin();
      runnerFB != m_lstDstFBPtr.end(); ++runnerFB,++runnerDst){   //run through inner destination FB array
	(*runnerFB)->connectDI(extractPortNameId(*runnerDst), this);
  }
}

