/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_BAND_B
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_BAND_B_H_
#define _F_BAND_B_H_

#include <basicfb.h>
#include <forte_byte.h>

class FORTE_F_BAND_B: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_F_BAND_B)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BYTE &X() {
    return *static_cast<CIEC_BYTE*>(getDI(0));
  };

  CIEC_BYTE &B() {
    return *static_cast<CIEC_BYTE*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BYTE &OUT() {
    return *static_cast<CIEC_BYTE*>(getDO(0));
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

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 0, 0);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_F_BAND_B(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_F_BAND_B(){};

};

inline const CIEC_BYTE BAND_B(const CIEC_BYTE &X, const CIEC_BYTE &B){
  CIEC_BYTE RetVal;
  if((X < B)){
    RetVal = 0;
  }
  else{
    if((X > 255-B)){
      RetVal = 255;
    }
    else{
      RetVal = X;
    }
  }
  return RetVal;
}

#endif //close the ifdef sequence from the beginning of the file

