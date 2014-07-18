/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "eventconn.h"
#include "ecet.h"
#include "funcbloc.h"

CEventConnection::CEventConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB) :
                  CConnection(pa_nSrcId, pa_nDstId){
  int nEIID = createDstEventId(pa_nDstId, pa_roDstFB);

  if(cg_nInvalidEventID != (nEIID & cg_nInvalidEventID)){
    m_lstEventEntryList.push_back(SEventEntry(&pa_roDstFB, nEIID));
    pa_roSrcFB.connectEO(getOutputNameId(), this);
  }
  else{
    m_lstDestinationIds.pop_front(); //empty the list so that the caller can identify that something went wrong
  }
}

CEventConnection::~CEventConnection(){

}

EMGMResponse CEventConnection::connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB){
  EMGMResponse retval = e_NO_SUCH_OBJECT;
  int nEIID = createDstEventId(pa_nDstId, pa_roDstFB);
  if(cg_nInvalidEventID != (nEIID & cg_nInvalidEventID)){
    if(e_RDY == (retval = CConnection::connectFannedOut(pa_nDstId, pa_roSrcFB, pa_roDstFB))){
      m_lstEventEntryList.push_back(SEventEntry(&pa_roDstFB, nEIID));
    }
  }
  return retval;
}

#ifndef FORTE_CLASS_0
EMGMResponse CEventConnection::disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB){
  EMGMResponse retval =
      CConnection::disconnect(pa_nDstId, pa_roSrcFB, pa_roDstFB);
  if(e_RDY == retval){
    // the CConnection class didn't respond an error

    if(!m_lstEventEntryList.isEmpty()){
      TEventID nEIID = pa_roDstFB.getEIID(extractPortNameId(pa_nDstId));
      TEventEntryList::Iterator itRunner = m_lstEventEntryList.begin();
      TEventEntryList::Iterator itRefNode = m_lstEventEntryList.end();

      while(itRunner != m_lstEventEntryList.end()){
        if(((*itRunner).m_nEIID == nEIID) && ((*itRunner).m_poFB == &pa_roDstFB)){
          if(itRefNode == m_lstEventEntryList.end()){
            m_lstEventEntryList.pop_front();
          }
          else{
            m_lstEventEntryList.eraseAfter(itRefNode);
          }
          break;
        }

        itRefNode = itRunner;
        ++itRunner;
      }

      if(m_lstEventEntryList.isEmpty()){ //this is the was the last entry in this connection -> detach from the source
        pa_roSrcFB.connectEO(getOutputNameId(), 0);
      }
    }
  }
  return retval;
}
#endif

void CEventConnection::triggerEvent(CEventChainExecutionThread &pa_poExecEnv){
  for(TEventEntryList::Iterator it = m_lstEventEntryList.begin(); it
      != m_lstEventEntryList.end(); ++it){
    pa_poExecEnv.addEventEntry(&(*it));
  }
}

int CEventConnection::createDstEventId(TConnectionID pa_nDstId, CFunctionBlock & pa_roDstFB){
  int nEIID;
  if(CStringDictionary::scm_nInvalidStringId == extractFBNameId(pa_nDstId)){
    //it is an internal to interface event connection of an composite function block here we need the output
    nEIID = pa_roDstFB.getEOID(extractPortNameId(pa_nDstId)) | 0x100;
  }else{
    nEIID = pa_roDstFB.getEIID(extractPortNameId(pa_nDstId));
  }
  return nEIID;
}

