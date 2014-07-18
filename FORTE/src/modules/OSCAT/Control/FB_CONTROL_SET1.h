/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CONTROL_SET1
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_CONTROL_SET1_H_
#define _FB_CONTROL_SET1_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_FB_CONTROL_SET1: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_CONTROL_SET1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &KT() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &TT() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &P_K() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &PI_K() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &PI_TN() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &PID_K() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &PID_TN() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &PID_TV() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &KP() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_REAL &TN() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  CIEC_REAL &TV() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  CIEC_REAL &KI() {
    return *static_cast<CIEC_REAL*>(getDO(3));
  };

  CIEC_REAL &KD() {
    return *static_cast<CIEC_REAL*>(getDO(4));
  };

  static const TEventID scm_nEventREQ_PID = 0;
  static const TEventID scm_nEventREQ_PIID = 1;
  static const TEventID scm_nEventREQ_PIDID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNF_PID = 0;
  static const TEventID scm_nEventCNF_PIID = 1;
  static const TEventID scm_nEventCNF_PIDID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_REAL &TX() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 8, 5, 1, 0);

virtual void setInitialValues();
  void alg_REQ_P(void);
  void alg_REQ_PI(void);
  void alg_REQ_PID(void);
  void alg_CALC_KI(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateREQ_PI = 2;
  static const TForteInt16 scm_nStateREQ_PID = 3;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateREQ_PI(void);
  void enterStateREQ_PID(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_CONTROL_SET1(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_CONTROL_SET1(){};

};

#endif //close the ifdef sequence from the beginning of the file

