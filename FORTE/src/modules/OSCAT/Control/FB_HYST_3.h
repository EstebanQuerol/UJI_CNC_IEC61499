/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_HYST_3
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-31/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_HYST_3_H_
#define _FB_HYST_3_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_bool.h>

class FORTE_FB_HYST_3: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_HYST_3)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &HYS() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &VAL1() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &VAL2() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &Q1() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &Q2() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &WIN() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
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

   FORTE_BASIC_FB_DATA_ARRAY(1, 4, 3, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_HYST_3(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_HYST_3(){};

};

#endif //close the ifdef sequence from the beginning of the file

