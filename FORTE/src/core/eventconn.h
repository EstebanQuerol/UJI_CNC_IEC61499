/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _EVENCONN_H_
#define _EVENCONN_H_

#include "conn.h"
#include "event.h"
#include "fortelist.h"

class CEventChainExecutionThread;

/*!\ingroup CORE \brief Class for handling an event connection.
 *
 */
class CEventConnection : public CConnection{
  public:
    CEventConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB);
    virtual ~CEventConnection();
    /*! \brief Establishes the connection.
     *
     * With this command the connection is created and the FBs are set to appropriate states.
     * This mainly effects the destination of the connection (because of the fan-out)
     * If the referenced connection through the pa_sDst parameter is the first destination
     * also the src reference is created as necessary.
     * \param pa_nDstId     string of the destination of the connection
     * \param pa_roSrcFB  reference to the source FB of this connection
     * \param pa_roDstFB  reference to the destination Fb of this connection
     * \return can be the following response:
     *     - e_RDY... creation went well.
     *     - e_NO_SUCH_OBJECT... The destination is not a valid input.
     *     - e_INVALID_STATE... The specified connection already exists.
     */
    virtual EMGMResponse connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);

#ifndef FORTE_CLASS_0
    /*! \brief Disconnects the connection.
     *
     * With this command the connection is removed and the FBs are set to appropriate states.
     * This mainly effects the destination of the connection (because of the fan-out)
     * If the referenced connection through the pa_sDst parameter is the last destination
     * also the src reference is removed.
     * \param pa_nDstId     string of the destination of the connection
     * \param pa_roSrcFB  reference to the source FB of this connection
     * \param pa_roDstFB  reference to the destination Fb of this connection
     * \return can be the following response:
     *     - e_RDY... creation went well.
     *     - e_NO_SUCH_OBJECT... The destination is not a valid input.
     */
    virtual EMGMResponse disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);
#endif
    /*! \brief Triggers the event connection and all destinations are notified.
     *
     *
     *  \param pa_poExecEnv Pointer to the execution environment the event is sent in.
     */
    void triggerEvent(CEventChainExecutionThread &pa_poExecEnv);
  protected:
    /*!\brief Structure to hold the information needed for storing event entry list in the event
     * connection
     */
    typedef CSinglyLinkedList<SEventEntry> TEventEntryList;

    TEventEntryList m_lstEventEntryList;
  private:
    static int createDstEventId(TConnectionID pa_nDstId, CFunctionBlock & pa_roDstFB);
};

typedef CEventConnection *TEventConnectionPtr;

#endif /*_EVENCONN_H_*/
