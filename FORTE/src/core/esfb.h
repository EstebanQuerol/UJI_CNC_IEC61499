/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ESFB_H_
#define _ESFB_H_

#include "funcbloc.h"

/*!\ingroup CORE\brief Base-Class for all event sources.
 *
 * @author AZ
 * @version 20090801/mmm - added parameter const CStringDictionary::TStringId pa_nInstanceNameId to constructor
 * @version 20060207/AZ - Removed number of EOs in CFunctionBlock-Constructor
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051022/AZ - First version as basis for interface description
 */
class CEventSourceFB : public CFunctionBlock{
private:

/* \brief the event chain executor used by this ES.
 */
  CEventChainExecutionThread *m_poEventChainExecutor;
protected:
   SEventEntry m_stEventSourceEventEntry; //! the event entry to start the event chain
public:
  CEventSourceFB(CResource *pa_poSrcRes,
           const SFBInterfaceSpec *pa_pstInterfaceSpec,
           const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
    CFunctionBlock(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData),
    m_poEventChainExecutor(0),
    m_stEventSourceEventEntry(0, cg_nExternalEventID){
  }
  virtual ~CEventSourceFB() {};
  void setEventChainExecutor(CEventChainExecutionThread *pa_poEventChainExecutor) { m_poEventChainExecutor = pa_poEventChainExecutor; };
  CEventChainExecutionThread * getEventChainExecutor(void) { return m_poEventChainExecutor; };

  SEventEntry *getEventSourceEventEntry(void) { return &m_stEventSourceEventEntry; };
};

#define EVENT_SOURCE_FUNCTION_BLOCK_CTOR(fbclass) \
 fbclass(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : \
 CEventSourceFB( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData)

#endif /*_ESFB_H_*/
