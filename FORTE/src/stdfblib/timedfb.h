/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _TIMEDFB_H_
#define _TIMEDFB_H_

#include "../core/esfb.h"
#include "../core/datatypes/forte_time.h"
#include "../arch/timerha.h"
#include "../core/resource.h"

/*!\brief Base class for timed function block like E_CYCLE or E_DELAY providing this interface
 *
 *
 * @author AZ
 * @version 20090801/mmm - added parameter const CStringDictionary::TStringId pa_nInstanceNameId to constructor
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051203/AZ - First version as basis
 */
class CTimedFB : public CEventSourceFB{
private:
protected:
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  static const CStringDictionary::TStringId scm_aunEINameIds[];
  static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_aunEONameIds[];
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_aunDINameIds[];
  static const CStringDictionary::TStringId scm_aunDIDataTypeNameIds[];

  static const TEventID csm_nEventSTARTID = 0;
  static const TEventID csm_nEventSTOPID = 1;

  static const TEventID csm_nEOID = 0;

  FORTE_FB_DATA_ARRAY(1,1,0, 0);

  bool m_bActive; //!> flag to indicate that the timed fb is currently active
  STimedFBListEntry m_stTimeListEntry; //!> The Timer list entry of this timed FB
/*!\brief execute the input events of timed FBs as far it is possible
 *
 * Derived Timed FBs only normaly need only the start event es this is different for each timed FB type (e.g. periodic vs. onetimeshot)
 */
  virtual void executeEvent(int pa_nEIID);

  CIEC_TIME& DT() {
   	return *static_cast<CIEC_TIME*>(getDI(0));
  }
public:
  EVENT_SOURCE_FUNCTION_BLOCK_CTOR(CTimedFB){
    setEventChainExecutor(pa_poSrcRes->getResourceEventExecution());
    m_bActive = false;
    m_stTimeListEntry.m_stTimeOut.m_nLowerValue = 0;
    m_stTimeListEntry.m_stTimeOut.m_nUpperValue = 0;
    m_stTimeListEntry.m_nInterval = 0;
    m_stTimeListEntry.m_pstNext = 0;
    m_stEventSourceEventEntry.m_poFB = this;
  };
  virtual ~CTimedFB() {};

  virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

};

#endif /*TIMEDFB_H_*/
