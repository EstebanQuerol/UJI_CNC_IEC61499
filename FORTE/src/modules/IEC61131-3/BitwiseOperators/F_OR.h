/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_OR
 *** Description: bitwise or
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_OR_H_
#define _F_OR_H_

#include <funcbloc.h>
#include <forte_any_bit.h>

class FORTE_F_OR: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_OR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_BIT &IN1() {
    return *static_cast<CIEC_ANY_BIT*>(getDI(0));
  };

  CIEC_ANY_BIT &IN2() {
    return *static_cast<CIEC_ANY_BIT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_BIT &OUT() {
    return *static_cast<CIEC_ANY_BIT*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_OR){
  };

  template<typename T> void calculateValue(){
    T oIn1;
    T oIn2;
    oIn1.saveAssign(IN1());
    oIn2.saveAssign(IN2());
    OUT().saveAssign(OR(oIn1, oIn2));
  }

  virtual ~FORTE_F_OR(){};

};

#endif //close the ifdef sequence from the beginning of the file

