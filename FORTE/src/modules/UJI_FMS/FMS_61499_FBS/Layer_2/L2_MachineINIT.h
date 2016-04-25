/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineINIT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-01-15/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_MACHINEINIT_H_
#define _L2_MACHINEINIT_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_time.h>

class FORTE_L2_MachineINIT: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_MachineINIT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &COM_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_BOOL &L0_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_BOOL &L2_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &INIT_STATE() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_BOOL &INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &COM_INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  CIEC_BOOL &L0_INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_BOOL &L2_INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  };

  CIEC_TIME &TODelay() {
    return *static_cast<CIEC_TIME*>(getDO(5));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventCOM_INIT_RSPID = 1;
  static const TEventID scm_nEventL0_INIT_RSPID = 2;
  static const TEventID scm_nEventL2_INIT_RSPID = 3;
  static const TEventID scm_nEventTimeOutID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINDID = 0;
  static const TEventID scm_nEventCOM_INITID = 1;
  static const TEventID scm_nEventL0_INITID = 2;
  static const TEventID scm_nEventL2_INITID = 3;
  static const TEventID scm_nEventStartID = 4;
  static const TEventID scm_nEventStopID = 5;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(6, 4, 6, 0, 0);
  void alg_COM_INIT_P(void);
  void alg_COM_INIT_FAIL(void);
  void alg_L0_INIT_P(void);
  void alg_L0_INIT_FAIL(void);
  void alg_L2_INIT_P(void);
  void alg_L2_INIT_FAIL(void);
  void alg_INIT_OK(void);
  void alg_Delay(void);
  void alg_INIT_P_TO(void);
  void alg_L2_INIT_M(void);
  void alg_L2_DINT_FAIL(void);
  void alg_L0_INIT_M(void);
  void alg_L0_DINT_FAIL(void);
  void alg_COM_INIT_M(void);
  void alg_COM_DINT_FAIL(void);
  void alg_DINT_OK(void);
  void alg_INIT_M_TO(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINITIALIZING_COM = 1;
  static const TForteInt16 scm_nStateDESINITIALIZING_L0 = 2;
  static const TForteInt16 scm_nStateINIT_COMPLETE = 3;
  static const TForteInt16 scm_nStateINIT_SINK = 4;
  static const TForteInt16 scm_nStateINITIALIZING_L0 = 5;
  static const TForteInt16 scm_nStateCOM_INIT_FAIL = 6;
  static const TForteInt16 scm_nStateL0_INIT_FAIL = 7;
  static const TForteInt16 scm_nStateINITIALIZING_L2 = 8;
  static const TForteInt16 scm_nStateL2_INIT_FAIL = 9;
  static const TForteInt16 scm_nStateDESINITIALIZING_COM = 10;
  static const TForteInt16 scm_nStateDESINITIALIZING_L2 = 11;
  static const TForteInt16 scm_nStateStartTimer = 12;
  static const TForteInt16 scm_nStateINIT_TIMEOUT = 13;
  static const TForteInt16 scm_nStateDINIT_COMPLETE = 14;
  static const TForteInt16 scm_nStateState = 15;
  static const TForteInt16 scm_nStateDINIT_L2_FAIL = 16;
  static const TForteInt16 scm_nStateDINT_L0_FAIL = 17;
  static const TForteInt16 scm_nStateDINT_COM_FAIL = 18;
  static const TForteInt16 scm_nStateDINT_TIMEOUT = 19;

  void enterStateSTART(void);
  void enterStateINITIALIZING_COM(void);
  void enterStateDESINITIALIZING_L0(void);
  void enterStateINIT_COMPLETE(void);
  void enterStateINIT_SINK(void);
  void enterStateINITIALIZING_L0(void);
  void enterStateCOM_INIT_FAIL(void);
  void enterStateL0_INIT_FAIL(void);
  void enterStateINITIALIZING_L2(void);
  void enterStateL2_INIT_FAIL(void);
  void enterStateDESINITIALIZING_COM(void);
  void enterStateDESINITIALIZING_L2(void);
  void enterStateStartTimer(void);
  void enterStateINIT_TIMEOUT(void);
  void enterStateDINIT_COMPLETE(void);
  void enterStateState(void);
  void enterStateDINIT_L2_FAIL(void);
  void enterStateDINT_L0_FAIL(void);
  void enterStateDINT_COM_FAIL(void);
  void enterStateDINT_TIMEOUT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_MachineINIT(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_MachineINIT(){};

};

#endif //close the ifdef sequence from the beginning of the file

