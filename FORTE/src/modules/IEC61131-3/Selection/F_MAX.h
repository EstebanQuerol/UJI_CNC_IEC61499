/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MAX
 *** Description: maximum
 *** Version: 
 ***     1.0: 2011-09-28/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_MAX_H_
#define _F_MAX_H_

#include <funcbloc.h>
#include <forte_any_elementary.h>

class FORTE_F_MAX: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_MAX)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_ELEMENTARY &IN1() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(0));
  };

  CIEC_ANY_ELEMENTARY &IN2() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_ELEMENTARY &OUT() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_MAX){
  };

  template<typename T> void calculateValue(){
      T oMin;
      T oMax;

      oMin.saveAssign(IN1());
      oMax.saveAssign(IN2());

      OUT().saveAssign(MAX<T> (oMin, oMax));
  }

  template<typename T> void calculateValueString(){
    //TODO fill this function
  }
  virtual ~FORTE_F_MAX(){};

};

#endif //close the ifdef sequence from the beginning of the file

