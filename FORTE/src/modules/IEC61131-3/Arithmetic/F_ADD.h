/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_ADD
 *** Description: Adds two number values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_ADD_H_
#define _F_ADD_H_

#include <funcbloc.h>
#include <forte_any_magnitude.h>

class FORTE_F_ADD: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_ADD)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_MAGNITUDE &IN1() {
    return *static_cast<CIEC_ANY_MAGNITUDE*>(getDI(0));
  };

  CIEC_ANY_MAGNITUDE &IN2() {
    return *static_cast<CIEC_ANY_MAGNITUDE*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_MAGNITUDE &OUT() {
    return *static_cast<CIEC_ANY_MAGNITUDE*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_ADD){
  };

  template<typename T> void calculateValue(){
    T &roIn1(static_cast<T&>(IN1()));
    T oIn2;
    oIn2.saveAssign(IN2());
    OUT().saveAssign(ADD(roIn1,oIn2));
  }

  virtual ~FORTE_F_ADD(){};
};

#endif //close the ifdef sequence from the beginning of the file

