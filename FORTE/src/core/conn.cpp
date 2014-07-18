/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "conn.h"
#include "stringdict.h"

EMGMResponse CConnection::connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &, CFunctionBlock &){
  EMGMResponse retval = e_INVALID_STATE;
  if(!dstExists(pa_nDstId)){ // check if there is up to now no such fan out with this destination
    m_lstDestinationIds.push_back(pa_nDstId);
    retval = e_RDY;
  }
  return retval;
}

#ifndef FORTE_CLASS_0
EMGMResponse CConnection::disconnect(TConnectionID pa_nDstId, CFunctionBlock &, CFunctionBlock &){
  EMGMResponse retval = e_NO_SUCH_OBJECT;

  TDestinationIdList::Iterator itRunner = m_lstDestinationIds.begin();
  TDestinationIdList::Iterator itRefNode = m_lstDestinationIds.end();

  while(itRunner != m_lstDestinationIds.end()){
    if((*itRunner) == pa_nDstId){
      retval = e_RDY;
      if(itRefNode == m_lstDestinationIds.end()){
        m_lstDestinationIds.pop_front();
      }else{
        m_lstDestinationIds.eraseAfter(itRefNode);
      }
      break;
    }
    itRefNode = itRunner;
    ++itRunner;
  }

  return retval;
}
#endif
