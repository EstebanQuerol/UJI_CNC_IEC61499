/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_CTRL_IN
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_CTRL_IN_H_
#define _F_CTRL_IN_H_

#include <basicfb.h>
#include <forte_real.h>
#include "F_DEAD_ZONE.h"

class FORTE_F_CTRL_IN: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_F_CTRL_IN)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &SET_POINT() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &ACTUAL() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &NOISE() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &OUT() {
    return *static_cast<CIEC_REAL*>(getDO(0));
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

   FORTE_BASIC_FB_DATA_ARRAY(1, 3, 1, 0, 0);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_F_CTRL_IN(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_F_CTRL_IN(){};

};

inline const CIEC_REAL CTRL_IN(const CIEC_REAL &SET_POINT, const CIEC_REAL &ACTUAL, const CIEC_REAL &NOISE){
 return DEAD_ZONE(SET_POINT - ACTUAL, NOISE);
}

#endif //close the ifdef sequence from the beginning of the file

