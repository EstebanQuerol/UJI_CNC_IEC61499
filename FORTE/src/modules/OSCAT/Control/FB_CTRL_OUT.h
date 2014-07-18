/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTRL_OUT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_CTRL_OUT_H_
#define _FB_CTRL_OUT_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_bool.h>

#ifdef OFFSET
#undef OFFSET
#endif

class FORTE_FB_CTRL_OUT: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_CTRL_OUT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &CI() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &OFFSET() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &MAN_IN() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &LIM_L() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &LIM_H() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_BOOL &MANUAL() {
    return *static_cast<CIEC_BOOL*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Y() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_BOOL &LIM() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 6, 2, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_CTRL_OUT(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_CTRL_OUT(){};

};

#endif //close the ifdef sequence from the beginning of the file

