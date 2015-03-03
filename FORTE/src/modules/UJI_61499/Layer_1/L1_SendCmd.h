/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_SendCmd
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L1_SENDCMD_H_
#define _L1_SENDCMD_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_time.h>

class FORTE_L1_SendCmd: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L1_SendCmd)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &CmdIn() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_USINT &L1MID() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &CmdOut() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(1));
  };

  CIEC_USINT &ENDOPID() {
    return *static_cast<CIEC_USINT*>(getDO(2));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TEventID scm_nEventTimeoutID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TEventID scm_nEventStartID = 2;
  static const TEventID scm_nEventStopID = 3;
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

   FORTE_BASIC_FB_DATA_ARRAY(4, 2, 3, 1, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_START(void);
  void alg_TO(void);
  void alg_RSP(void);
  void alg_FAIL(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateWAIT = 2;
  static const TForteInt16 scm_nStateRSP = 3;
  static const TForteInt16 scm_nStateTIMEOUT = 4;
  static const TForteInt16 scm_nStateRETRY = 5;
  static const TForteInt16 scm_nStateFAIL = 6;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateWAIT(void);
  void enterStateRSP(void);
  void enterStateTIMEOUT(void);
  void enterStateRETRY(void);
  void enterStateFAIL(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L1_SendCmd(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L1_SendCmd(){};

};

#endif //close the ifdef sequence from the beginning of the file

