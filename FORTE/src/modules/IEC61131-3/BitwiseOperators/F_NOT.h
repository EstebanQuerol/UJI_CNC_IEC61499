/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_NOT
 *** Description: standard bitwise boolean function (not)
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_NOT_H_
#define _F_NOT_H_

#include <funcbloc.h>
#include <forte_any_bit.h>

class FORTE_F_NOT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_NOT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_BIT &IN() {
    return *static_cast<CIEC_ANY_BIT*>(getDI(0));
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

   FORTE_FB_DATA_ARRAY(1, 1, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_NOT){
  };

  template<typename T> void calculateValue(){
    T oIn;
    oIn.saveAssign(IN());
    OUT().saveAssign(NOT(oIn));
  }

  virtual ~FORTE_F_NOT(){};

};

#endif //close the ifdef sequence from the beginning of the file

