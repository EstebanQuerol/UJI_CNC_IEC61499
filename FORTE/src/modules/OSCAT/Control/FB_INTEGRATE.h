/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_INTEGRATE
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-07-12/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_INTEGRATE_H_
#define _FB_INTEGRATE_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_dword.h>
#include <forte_bool.h>

class FORTE_FB_INTEGRATE: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_INTEGRATE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &X() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &K() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_BOOL &reset() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Y_OUT() {
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
  CIEC_REAL &X_last() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_DWORD &last() {
    return *static_cast<CIEC_DWORD*>(getVarInternal(1));
  };

  CIEC_DWORD &tx() {
    return *static_cast<CIEC_DWORD*>(getVarInternal(2));
  };

  CIEC_REAL &Y_intern() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 3, 1, 4, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_FB_INTEGRATE(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_INTEGRATE(){};

};

#endif //close the ifdef sequence from the beginning of the file

