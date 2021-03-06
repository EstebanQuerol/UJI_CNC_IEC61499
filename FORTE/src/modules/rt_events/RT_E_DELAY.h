/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: RT_E_DELAY
 *** Description: Delayed propagation of an event-Cancellable
 *** Version: 
 ***     0.0: 2008-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _RT_E_DELAY_H_
#define _RT_E_DELAY_H_

#include <esfb.h>
#include <ecet.h>
#include <forte_time.h>
#include <forte_bool.h>
#include "../arch/timerha.h"

class FORTE_RT_E_DELAY: public CEventSourceFB{
  DECLARE_FIRMWARE_FB(FORTE_RT_E_DELAY)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &DT() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_TIME &Tmin() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  };

  CIEC_TIME &Deadline() {
    return *static_cast<CIEC_TIME*>(getDI(3));
  };

  CIEC_TIME &WCET() {
    return *static_cast<CIEC_TIME*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventSTARTID = 1;
  static const TEventID scm_nEventSTOPID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEOID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 5, 1, 0);

  bool m_bActive; //!> flag to indicate that the timed fb is currently active
  bool m_bInitialized;
  STimedFBListEntry m_stTimeListEntry;
  CEventChainExecutionThread m_oECEO;

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_RT_E_DELAY(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
  virtual ~FORTE_RT_E_DELAY(){};

};

#endif //close the ifdef sequence from the beginning of the file

