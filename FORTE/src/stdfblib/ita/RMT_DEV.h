/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _RMT_DEV_H_
#define _RMT_DEV_H_

#include <device.h>
#include <if2indco.h>
#include <forte_wstring.h>
#include "RMT_RES.h"
#include <class1objhand.h>

/*! \brief Implementation of the RMT_DEV.
 *
 * @author unknown
 * @version 20081121/mmm - removed getDataInput because it is dead code
 */


class RMT_DEV : public CDevice{


public:
  RMT_RES MGR;

	RMT_DEV();
	virtual ~RMT_DEV();

/*! \brief Adds additional functionality to the originals execute func of the device.
 *
 * This is that it waits till the thread of the MGR resource has anded
 */
	virtual int startDevice(void);

	virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

  void setMGR_ID(const char * const pa_acConn);

private:
  CInterface2InternalDataConnection m_oDConnMGR_ID;

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(0,1,0, 0);

  static const CStringDictionary::TStringId scm_aunDINameIds[];
  static const CStringDictionary::TStringId scm_aunDIDataTypeIds[];

  CIEC_WSTRING& MGR_ID() {
   	return *static_cast<CIEC_WSTRING*>(getDI(0));
  }
};

#endif /*RMT_DEV_H_*/
