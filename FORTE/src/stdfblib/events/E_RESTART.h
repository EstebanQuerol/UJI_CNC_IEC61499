/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_RESTART_H_
#define _E_RESTART_H_

#include "../core/esfb.h"
#include "../core/resource.h"

/*! \brief Implementation of the E_RESTART FB.
 *
 * @author AZ
 * @version 20060619/AZ+SMR - New FB-interface introduced
 * @version 20060207/AZ - Removed number of EOs in CFunctionBlock-Constructor
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051208/AZ - changed sate machine to send cold events after reset
 * @version 20051022/AZ - Initial version as basis for the interface documentation
 */

class E_RESTART : public CEventSourceFB{
  DECLARE_FIRMWARE_FB(E_RESTART)
private:
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(3,0,0, 0);

  static const TEventID csm_nCOLDID = 0;
  static const TEventID csm_nWARMID = 1;
  static const TEventID csm_nSTOPID = 2;

  static const CStringDictionary::TStringId scm_aunEONameIds[];

  bool m_bStartedOnce;

  virtual void executeEvent(int pa_nEIID);

public:
  EVENT_SOURCE_FUNCTION_BLOCK_CTOR(E_RESTART), m_bStartedOnce(false) {
    setEventChainExecutor(pa_poSrcRes->getResourceEventExecution());
    m_stEventSourceEventEntry.m_poFB = this;
  }
	virtual ~E_RESTART() {};

	virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);
};

#endif /*E_RESTART_H_*/
