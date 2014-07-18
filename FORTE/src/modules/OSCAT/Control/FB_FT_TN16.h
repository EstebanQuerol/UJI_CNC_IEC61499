/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_TN16
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-28/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_FT_TN16_H_
#define _FB_FT_TN16_H_

#include <basicfb.h>
#include <forte_time.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_FB_FT_TN16: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_FT_TN16)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &T() {
    return *static_cast<CIEC_REAL*>(getDI(1));
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
  CIEC_INT &length() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_REAL *X() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getVarInternal(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &X_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(1));
  };

  CIEC_INT &cnt() {
    return *static_cast<CIEC_INT*>(getVarInternal(2));
  };

  CIEC_TIME &last() {
    return *static_cast<CIEC_TIME*>(getVarInternal(3));
  };

  CIEC_TIME &tx() {
    return *static_cast<CIEC_TIME*>(getVarInternal(4));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 1, 5, 0);

   virtual void setInitialValues();

  void alg_INIT(void);
  void alg_REQ(void);
  void alg_checkTime(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStatecheckTime = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStatecheckTime(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_FT_TN16(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_FT_TN16(){};

};

#endif //close the ifdef sequence from the beginning of the file

