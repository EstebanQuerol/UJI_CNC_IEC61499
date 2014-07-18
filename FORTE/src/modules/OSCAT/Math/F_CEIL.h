/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_CEIL
 *** Description: returns the smallest possible integer which is greater or equal to X
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_CEIL_H_
#define _F_CEIL_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_int.h>

class FORTE_F_CEIL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_CEIL)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &X() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &OUT() {
    return *static_cast<CIEC_INT*>(getDO(0));
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

   FORTE_FB_DATA_ARRAY(1, 1, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_CEIL){
  };

  virtual ~FORTE_F_CEIL(){};

};

inline const CIEC_INT CEIL(const CIEC_REAL &pa_roVal){
  CIEC_INT::TValueType temp = REAL_TO_INT(pa_roVal);
  if(temp < static_cast<TForteFloat>(pa_roVal)){
    temp = temp + 1;
  }
  return CIEC_INT( temp );
};

#endif //close the ifdef sequence from the beginning of the file

