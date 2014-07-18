/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PT1
 *** Description: low pass filter with a programmable time T and faktor K
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_FT_PT1_H_
#define _FB_FT_PT1_H_

#include <basicfb.h>
#include <forte_time.h>
#include <forte_real.h>
#include <forte_dword.h>

class FORTE_FB_FT_PT1: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_FT_PT1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_TIME &T() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_REAL &K() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &OUT() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_DWORD &tx() {
    return *static_cast<CIEC_DWORD*>(getVarInternal(0));
  };

  CIEC_DWORD &last() {
    return *static_cast<CIEC_DWORD*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 3, 1, 2, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_INIT(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStateREQt0 = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateREQt0(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_FT_PT1(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_FT_PT1(){};

};

#endif //close the ifdef sequence from the beginning of the file

