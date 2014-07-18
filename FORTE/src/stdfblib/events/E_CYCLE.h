/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_CYCLE_H_
#define _E_CYCLE_H_

#include "../timedfb.h"

/*! \brief Implementation of the E_CYCLE FB.
 *
 * @author AZ
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051203/AZ - Inserted base class for all timed FBs, adapted to new timerhandler
 * @version 20051022/AZ - Initial version as basis for the interface documentation
 */
class E_CYCLE : public CTimedFB{
  DECLARE_FIRMWARE_FB(E_CYCLE)
private:
public:
	E_CYCLE(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : CTimedFB( pa_nInstanceNameId, pa_poSrcRes){
    m_stTimeListEntry.m_poTimedFB = this;
    m_stTimeListEntry.m_eType = e_Periodic;
  };
	virtual ~E_CYCLE() {};
};

#endif /*E_CYCLE_H_*/
