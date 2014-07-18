/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _EVENT_H_
#define _EVENT_H_

#include "../arch/datatype.h"


//forward declaration of a few classes to reduce includefile dependencies
class CFunctionBlock;

/*! \ingroup CORE\brief Datatype for holding the IDs of event inputs.
 *
 *  With the current implementation at max 255 event inputs per FB are possible.
 *  That should be enough.
 */
typedef TForteUInt8 TEventID;

//!\ingroup CORE Constant for the invalid event input id
const TEventID cg_nInvalidEventID = cg_unInvalidPortId;
//!\ingroup CORE Constant for the invalid event input id
const TEventID cg_nExternalEventID = 254;


/*!\ingroup CORE \brief Structure to hold the information needed for delivering input events to FBs.
 */
struct SEventEntry{
  CFunctionBlock* m_poFB; //!< Pointer to the FB the event should be sent to.
  int m_nEIID;   //!< Identifier of the input event to send.

  SEventEntry(CFunctionBlock* pa_poFB, int pa_nEIID):m_poFB(pa_poFB), m_nEIID(pa_nEIID) {

  }

  SEventEntry():m_poFB(0), m_nEIID(0) {

  }
};

typedef SEventEntry* TEventEntryPtr;

#endif /*_EVENT_H_*/
