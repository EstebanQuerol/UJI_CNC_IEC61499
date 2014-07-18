/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _THREAD_H_
#define _THREAD_H_

#include <cyg/kernel/kapi.h>
#include "../datatype.h"
#include "sync.h"
#include "../devlog.h"
#include "../../core/datatypes/forte_time.h"

#define CThread CECOSThread  //allows that doxygen can generate better documentation
class CECOSThread;

typedef CECOSThread *TCECOSThreadPtr;

/**  \defgroup ECOS-HAL eCos FORTE Hardware Abstraction Layer
 *\ingroup FORTE-HAL
 * \brief The FORTE-HAL implementation for the eCos operating system.
 *
 * 
 */
/*! \ingroup ECOS-HAL
 * \brief This class is a wrapper class the eCos multitasking support 
 *     
 * @author AZ
 * @version 20051009/AZ - Initial implementation
 */
class CECOSThread {
  public:
    /*! \brief Constructor of the Thread class
     *
     *  Does all the necessary steps in order to get the thread running with the start()-method
     *  @param pa_nStackSize the Size of the stack the thread is allowed to use. this class will
     *         allocate the stack size in bytes from the heap
     */
    CECOSThread(long pa_nStackSize = CYGNUM_HAL_STACK_SIZE_TYPICAL);  // may need adjustment for small platforms

    /*! \brief Stops and destroys thread.
     *
     *  Will stop the execution if running and destroy the thread including all system specific data.
     */
    virtual ~CECOSThread();

    /*! \brief Indicates if the thread is allowed to execute.
     *
     *  This functions checks if the Thread is still executing user code in its run()-method.
     *  \return true if there the run method is active.
     */
    bool isAlive(void) const {
      return m_bAlive;
    }

    //!Set the deadline of the thread.
    void setDeadline(const CIEC_TIME &pa_roVal);

    //!Get the current deadline of the thread.
    const CIEC_TIME &getDeadline(void) const {
      return m_oDeadLine;
    }


    /*! \brief starts the Thread
     *
     *  By calling this method the execution in the run()-Method will be started. If necessary additional data
     *  can be created here. Because of inheritance reasons the best place for executing create is in this method.
     */
    void start(void){
      create();
      cyg_thread_resume(m_stHandle);
    }

    /*! \brief Resumes a suspended Thread
     *
     *
     */
    void resumeSelfSuspend(void){
      cyg_semaphore_post(&m_stSuspendSem);
    }

    /*! \brief Stops the execution of the thread
     *
     *  This function imidiatly stops the execution of the thread (seting m_bAlive to false) and waits till
     *  this is finished.
     */
    void end(void){
      m_bAlive = false;
      resumeSelfSuspend();
      join();
    }

    /*! \brief Waits for the Thread to finish its execution.
     *
     *  This function waits till the execution in the thread decides to end the execution. Blocks the caller!!!
     */
    void join(void);
  protected:
    /*! \brief Suspends the thread.
     *
     *  Suspends the execution of the thread until resumeSelfSuspend(), end(), or join() is called.
     */

    void selfSuspend(void){
      cyg_semaphore_wait(&m_stSuspendSem);
    }

    void setPriority(cyg_priority_t pa_nPriority) {
      DEVLOG_DEBUG(">>>>Thread: Set Priority: %d\n", pa_nPriority);
      cyg_thread_set_priority(m_stHandle, pa_nPriority);
    }

  private:
    /*!\brief Function that is given to the system thread support that should be called for the thread.
     *
     * this function will call the run method of the thread instance.
     */
    static void threadFunction(cyg_addrword_t data);

    /*! \brief Abstract method for the code to execute in the thread.
     *
     *  This thread class has to provide means that the code a inheriting class will add to the run()-method will
     *  be executed in a separated thread regarding the creator of the CThread class.
     *
     *  The inheriting class has to fulfill the following rules when using the run method:
     *    - To end the thread execution simple leave the run()-method
     *    - In order to allow the deletion and stopping of the thread add frequent checks to isAlive and end the
     *      execution if isAlive() returns false.
     */
    virtual void run() = 0;

    /*! \brief Creates a new thread.
     *
     *  With this function all the setup things for a new thread are done. The Thread created is initial
     *  suspended and with the start() method the execution of the code in the run() method is started.
     */
    bool create(void);

    /*! \brief Destroys the thread
     *
     *  This function destroys all the data structures created in the creation phase. All used memory is freed.
     */
    bool destroy(void);


    static const int scm_nThreadListSize = 27;
    static TCECOSThreadPtr sm_aoThreadList[scm_nThreadListSize];
    static CSyncObject sm_oThreadListLock;

    /*! \brief data needed for ecos to identify the thread.
     */
    cyg_handle_t m_stHandle;
    cyg_thread m_stThread;
    //! used for providing the join function
    CSyncObject m_stResLock;

    /*! \brief Size of the stack used by this thread.
     */
    long m_nStackSize;
    unsigned char *m_cStack;
    CIEC_TIME m_oDeadLine;
    cyg_sem_t m_stSuspendSem; //! Semaphore for implementing the self suspend


    /*! \brief Flag that indicates if the Thread is alive.
     *
     *  This flag has two main purposes:
     *    -# indicate for other classes if the thread is still executing
     *    -# use in the run()-method to check if the thread is still allowed to execute (e.g. while(isAlive()) ).
     *       This is important for stopping and destroying threads.
     */
    bool m_bAlive;

};

#endif /*THREAD_H_*/
