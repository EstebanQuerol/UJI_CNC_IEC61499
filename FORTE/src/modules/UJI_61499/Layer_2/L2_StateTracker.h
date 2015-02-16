/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_StateTracker
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-12-04/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_STATETRACKER_H_
#define _L2_STATETRACKER_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_time.h>

class FORTE_L2_StateTracker: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_StateTracker)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &QI2() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_USINT &ServiceStateIn() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT &ServiceStateOut() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  };

  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventRSP1ID = 1;
  static const TEventID scm_nEventRSP2ID = 2;
  static const TEventID scm_nEventTimeoutID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventUPDTID = 0;
  static const TEventID scm_nEventINITOID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TEventID scm_nEventStartID = 3;
  static const TEventID scm_nEventStopID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT &TOCounter() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  CIEC_USINT &MaxTO() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  CIEC_BOOL &ServiceWorking() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(5, 3, 3, 3, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_UPDT(void);
  void alg_INITO(void);
  void alg_DT1(void);
  void alg_DT2(void);
  void alg_TO2(void);
  void alg_LOST(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateUPDT = 2;
  static const TForteInt16 scm_nStateInitCompleted = 3;
  static const TForteInt16 scm_nStateUPD = 4;
  static const TForteInt16 scm_nStateRequestState = 5;
  static const TForteInt16 scm_nStateKeepAlive = 6;
  static const TForteInt16 scm_nStateRequesting = 7;
  static const TForteInt16 scm_nStateTO2 = 8;
  static const TForteInt16 scm_nStateLostCommunication = 9;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateUPDT(void);
  void enterStateInitCompleted(void);
  void enterStateUPD(void);
  void enterStateRequestState(void);
  void enterStateKeepAlive(void);
  void enterStateRequesting(void);
  void enterStateTO2(void);
  void enterStateLostCommunication(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_StateTracker(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_StateTracker(){};

};

#endif //close the ifdef sequence from the beginning of the file

