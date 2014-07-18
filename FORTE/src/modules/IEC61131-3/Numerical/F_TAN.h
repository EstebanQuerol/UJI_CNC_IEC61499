/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_TAN
 *** Description: tangent in radians
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_TAN_H_
#define _F_TAN_H_

#include <funcbloc.h>
#include <forte_any_real.h>

class FORTE_F_TAN: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_TAN)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_REAL &IN() {
    return *static_cast<CIEC_ANY_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_REAL &OUT() {
    return *static_cast<CIEC_ANY_REAL*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_TAN){
  };

  template<typename T> void calculateValue(){
    T oIn;
    oIn.saveAssign(IN());
    OUT().saveAssign(TAN(oIn));
  }

  virtual ~FORTE_F_TAN(){};

};

#endif //close the ifdef sequence from the beginning of the file

