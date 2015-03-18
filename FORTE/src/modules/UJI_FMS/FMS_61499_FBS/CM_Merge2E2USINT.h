/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_Merge2E2USINT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _CM_MERGE2E2USINT_H_
#define _CM_MERGE2E2USINT_H_

#include <basicfb.h>
#include <forte_usint.h>

class FORTE_CM_Merge2E2USINT: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CM_Merge2E2USINT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &E1In() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  CIEC_USINT &E2In() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT &Out() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  };

  static const TEventID scm_nEventE1ID = 0;
  static const TEventID scm_nEventE2ID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 0, 0);
  void alg_E1(void);
  void alg_E2(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateIN1 = 1;
  static const TForteInt16 scm_nStateIN2 = 2;

  void enterStateSTART(void);
  void enterStateIN1(void);
  void enterStateIN2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CM_Merge2E2USINT(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CM_Merge2E2USINT(){};

};

#endif //close the ifdef sequence from the beginning of the file

