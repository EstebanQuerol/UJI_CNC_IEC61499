/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_L1Comm
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-02-25/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_L1COMM_H_
#define _L2_L1COMM_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_time.h>

class FORTE_L2_L1Comm: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_L1Comm)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &OperationIn() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_USINT &L1MIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_USINT &ENDOPIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &OperationOut() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_USINT &L1MIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(2));
  };

  CIEC_USINT &ENDOPIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(3));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TEventID scm_nEventTimeoutID = 2;
  static const TEventID scm_nEventINDID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSendID = 0;
  static const TEventID scm_nEventStartID = 1;
  static const TEventID scm_nEventStopID = 2;
  static const TEventID scm_nEventCompletedOPID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT &TOCounter() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(4, 3, 4, 1, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_SEND(void);
  void alg_DT(void);
  void alg_RESET(void);
  void alg_TO(void);
  void alg_FAIL(void);
  void alg_IND(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateWait = 2;
  static const TForteInt16 scm_nStateSEND_OK = 3;
  static const TForteInt16 scm_nStateTimeout = 4;
  static const TForteInt16 scm_nStateRETRY = 5;
  static const TForteInt16 scm_nStateFAIL = 6;
  static const TForteInt16 scm_nStateIND = 7;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateWait(void);
  void enterStateSEND_OK(void);
  void enterStateTimeout(void);
  void enterStateRETRY(void);
  void enterStateFAIL(void);
  void enterStateIND(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_L1Comm(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_L1Comm(){};

};

#endif //close the ifdef sequence from the beginning of the file

