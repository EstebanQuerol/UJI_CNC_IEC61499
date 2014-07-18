/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_ROUND
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_ROUND_H_
#define _F_ROUND_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <stdio.h>

class FORTE_F_ROUND: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_ROUND)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &in() {
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
  FUNCTION_BLOCK_CTOR(FORTE_F_ROUND){
  };

  virtual ~FORTE_F_ROUND(){};

};

inline const CIEC_REAL ROUND(CIEC_REAL &in,CIEC_INT &n){
  CIEC_REAL DECADES[9] = {1,10,100,1000,10000,10000,100000,1000000,10000000};
  CIEC_REAL x = DECADES[LIMIT(CIEC_INT(0),n,CIEC_INT(8))];
  CIEC_REAL temp = DINT_TO_REAL(REAL_TO_DINT(in * x)) / x;
  fprintf(stderr,"****** round = %f",temp.operator float());
  return temp;
};

#endif //close the ifdef sequence from the beginning of the file

