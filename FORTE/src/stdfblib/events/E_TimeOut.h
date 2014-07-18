/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: E_TimeOut
 *** Description: Simple implementation of the timeout services
 *** Version: 
 ***     1.0: 2012-12-18/AZ - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _E_TIMEOUT_H_
#define _E_TIMEOUT_H_

#include <esfb.h>
#include <typelib.h>
#include "../arch/timerha.h"
#include "ATimeOut.h"

class FORTE_E_TimeOut : public CEventSourceFB{
  DECLARE_FIRMWARE_FB(FORTE_E_TimeOut)

  private:
    static const TForteInt16 scm_anEOWithIndexes[];
    static const SAdapterInstanceDef scm_astAdapterInstances[];

    FORTE_ATimeOut& TimeOutSocket(){
      return (*static_cast<FORTE_ATimeOut*>(m_apoAdapters[0]));
    }
    ;
    static const int scm_nTimeOutSocketAdpNum = 0;
    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(0, 0, 0, 1)
    ;

    bool m_bActive; //!> flag to indicate that the timed fb is currently active
    STimedFBListEntry m_stTimeListEntry; //!> The Timer list entry of this timed FB

    virtual void executeEvent(int pa_nEIID);

  public:
    EVENT_SOURCE_FUNCTION_BLOCK_CTOR(FORTE_E_TimeOut){
    m_bActive = false;
    m_stTimeListEntry.m_stTimeOut.m_nLowerValue = 0;
    m_stTimeListEntry.m_stTimeOut.m_nUpperValue = 0;
    m_stTimeListEntry.m_nInterval = 0;
    m_stTimeListEntry.m_pstNext = 0;
    m_stTimeListEntry.m_eType = e_SingleShot;
    m_stTimeListEntry.m_poTimedFB = this;
    m_stEventSourceEventEntry.m_poFB = this;
  };

  virtual ~FORTE_E_TimeOut(){};

  virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

};

#endif //close the ifdef sequence from the beginning of the file
