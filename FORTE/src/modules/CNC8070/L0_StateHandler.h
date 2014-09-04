/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_StateHandler
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _L0_STATEHANDLER_H_
#define _L0_STATEHANDLER_H_

#include <basicfb.h>
#include <forte_usint.h>

class FORTE_L0_StateHandler: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L0_StateHandler)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &CNCState() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventOnReadyID = 0;
  static const TEventID scm_nEventOnNotReadyID = 1;
  static const TEventID scm_nEventOnInterruptedID = 2;
  static const TEventID scm_nEventOnIntErrorID = 3;
  static const TEventID scm_nEventOnExecutionID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(5, 1, 0, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateReady = 1;
  static const TForteInt16 scm_nStateNotReady = 2;
  static const TForteInt16 scm_nStateInterrupted = 3;
  static const TForteInt16 scm_nStateError = 4;
  static const TForteInt16 scm_nStateExecution = 5;

  void enterStateSTART(void);
  void enterStateReady(void);
  void enterStateNotReady(void);
  void enterStateInterrupted(void);
  void enterStateError(void);
  void enterStateExecution(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L0_StateHandler(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L0_StateHandler(){};

};

#endif //close the ifdef sequence from the beginning of the file

