/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_DELAY_H_
#define _E_DELAY_H_

#include "../timedfb.h"

/*! \brief Implementation of the E_DELAY FB.
 *
 * The E_DELAY block will delay the event propagation of the ec. In the current implementation it is not
 * a busy wait. Instead it is implemented like an event source. The main difference to an event source
 * is that it will not start in an own new ecexectuionthread (or background trhead of the resource). It
 * will use the EC-Thread of the EC that sent the start command.
 *
 * @author AZ
 * @version 20061106/AZ - E_DELAY now stores the starting event chain and will send the eo in the same event chain
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051203/AZ - Inserted base class for all timed FBs, adapted to new timerhandler
 * @version 20051022/AZ - Initial version as basis for the interface documentation
 */
class E_DELAY : public CTimedFB{
  DECLARE_FIRMWARE_FB(E_DELAY)
private:

  void executeEvent(int pa_nEIID);
public:
  E_DELAY(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
	virtual ~E_DELAY(){};

};

#endif /*E_DELAY_H_*/
