/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef COMCALLBACK_H_
#define COMCALLBACK_H_

#include "comtypes.h"

class CEventSourceFB;

namespace forte {
  namespace com_infra {


/*! \brief Interface for classes that like to be called on external communication events.
 *
 * This can be for example the CIpComLayer.
 *
 */
class IComCallback{
  public:
    /*!\brief Inform requesting entity that data has been received
     *
     * This function is called from the context the external event is generated
     * in (e.g., communication interrupt). All executions done in this function
     * should be kept be short.
     *
     * \return not 0 if an event chain needs to be started.
     */
    virtual CEventSourceFB *onComEvent() = 0;

    /*!\brief Process the data received in the onComEvent function in a context outside the communication interrupt.
     *
     * This function shall be used for finishing the data reception.
     */
    virtual EComResponse processComEvent() = 0;
  protected:
    /*! This destructor is protected because currently we don't want to delete IComCallbacks polymorphically
     * (therefore it is also not virtual).
     * That means that call back handlers are not the objects in charge for managing the lifetime of these objects.
     */
    virtual ~IComCallback(){}
};

  }
}
#endif /* COMCALLBACK_H_ */
