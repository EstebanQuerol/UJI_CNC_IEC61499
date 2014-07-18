/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PIWLx
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-07-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_FT_PIWL2_H_
#define _FB_FT_PIWL3_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_dword.h>
#include <forte_bool.h>

class FORTE_FB_FT_PIWL2: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_FT_PIWL2)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &KP() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &KI() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &LIM_L() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &LIM_H() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_BOOL &RST() {
    return *static_cast<CIEC_BOOL*>(getDI(5));
  };

  CIEC_BOOL &TRACK() {
    return *static_cast<CIEC_BOOL*>(getDI(6));
  };

  CIEC_REAL &TRACK_IN() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &LIM() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_REAL &Y() {
    return *static_cast<CIEC_REAL*>(getDO(1));
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

  CIEC_REAL &tc() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_DWORD &t_last() {
    return *static_cast<CIEC_DWORD*>(getVarInternal(2));
  };

  CIEC_REAL &in_last() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_REAL &i() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  CIEC_REAL &p() {
    return *static_cast<CIEC_REAL*>(getVarInternal(5));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 8, 2, 6, 0);

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
  FORTE_FB_FT_PIWL2(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_FB_FT_PIWL2(){};

};

#endif //close the ifdef sequence from the beginning of the file

