/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_RND
 *** Description: rounds a real down to n digits total, round(3.1415,2) = 3.1
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_RND_H_
#define _F_RND_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <math.h>
#include "F_EXPN.h"
#include "F_CEIL.h"

class FORTE_F_RND: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_RND)

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
  FUNCTION_BLOCK_CTOR(FORTE_F_RND){
  };

  virtual ~FORTE_F_RND(){};

};

inline const CIEC_REAL RND(CIEC_REAL &in, CIEC_INT &n){
  CIEC_REAL temp = 0.0f;
  if(in != 0){
      CIEC_REAL m = EXPN(10.0, n - CEIL(LOG(CIEC_REAL(ABS(in)))));
      temp = DINT_TO_REAL(REAL_TO_DINT(in * m)) / m;
  }
  return temp;
};

#endif //close the ifdef sequence from the beginning of the file

