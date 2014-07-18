/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_EXPN
 *** Description: calculates X to the power of N (Y = X^N)
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_EXPN_H_
#define _F_EXPN_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_int.h>
#include <stdio.h>

class FORTE_F_EXPN: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_EXPN)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &X() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_INT &N() {
    return *static_cast<CIEC_INT*>(getDI(1));
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

   FORTE_FB_DATA_ARRAY(1, 2, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_EXPN){
  };

  virtual ~FORTE_F_EXPN(){};

};

inline const CIEC_REAL EXPN(CIEC_REAL pa_oVal1, const CIEC_INT &pa_roVal2){
  CIEC_REAL tempReal = 0;
  TForteUInt32 tempInt = 0;
  tempInt = ABS(pa_roVal2);
  if(tempInt & 0x1){
      tempReal = pa_oVal1;
  }else{
      tempReal = 1.0f;
  }
  tempInt = tempInt >> 1;
  while(tempInt > 0){
      pa_oVal1 = pa_oVal1 * pa_oVal1;

     if(tempInt & 0x1){
           tempReal = tempReal * pa_oVal1;
     }
     tempInt = tempInt >> 1;
  };
  if(pa_roVal2 < 0){
      tempReal = 1.0f / tempReal;
  }
  fprintf(stderr,"****** expn = %f",tempReal.operator float());
  return tempReal;
};

#endif //close the ifdef sequence from the beginning of the file

