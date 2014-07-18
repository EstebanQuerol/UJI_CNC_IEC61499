/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _PCTIMEHA_H_
#define _PCTIMEHA_H_

#include <cyg/kernel/kapi.h>
#include "../timerha.h"
#include "thread.h"

/*! \brief External event handler for the eCos Timer.
 * \ingroup ECOS-HAL
 *  
 */
class CECOSTimerHandler : public CTimerHandler, private CThread{
  public:
    virtual ~CECOSTimerHandler();

    /*!\brief Enables this event source
     *
     */
    virtual void enableHandler(void);
    /*!\brief Disable this event source
     */
    virtual void disableHandler(void);
    /*!\brief Sets the priority of the event source
     *
     * \param pa_nPriority new priority of the event source
     */
    virtual void setPriority(int pa_nPriority);
    /*!\brief Get the current priority of the event source
     *
     * \return current priority
     */
    virtual int getPriority(void) const;

  private:

    static cyg_sem_t m_stSemaphore;

    /*!\brief callback function for the system timer
     */
    static void timerHandlerFunc(cyg_handle_t , cyg_addrword_t ){
      cyg_semaphore_post(&m_stSemaphore);
    }

    CECOSTimerHandler();
    virtual void run(void);

    cyg_handle_t m_stAlarmHandle;
    cyg_handle_t m_stCounterHandle, m_stSystemclockHandle;
    cyg_alarm m_stAlarm;

    friend class CTimerHandler;
};

#endif /*PCTIMEHA_H_*/
