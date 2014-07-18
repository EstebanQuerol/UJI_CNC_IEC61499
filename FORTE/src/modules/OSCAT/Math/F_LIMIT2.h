/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_LIMITx
 *** Description: limiter
 *** Version: 
 ***     0.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_LIMIT2_H_
#define _F_LIMIT2_H_

#include <funcbloc.h>
#include <forte_any_elementary.h>
#include <forte_bool.h>

class FORTE_F_LIMIT2: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_LIMIT2)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_ELEMENTARY &MN() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(0));
  };

  CIEC_ANY_ELEMENTARY &IN() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(1));
  };

  CIEC_ANY_ELEMENTARY &MX() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &LIM() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_ANY_ELEMENTARY &OUT() {
    return *static_cast<CIEC_ANY_ELEMENTARY*>(getDO(1));
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

   FORTE_FB_DATA_ARRAY(1, 3, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_LIMIT2){
  };

  template<typename T> void calculateValue(){
    T oMin;
    T oMax;
    T& roIn(static_cast<T &> (IN()));

    oMin.saveAssign(MN());
    oMax.saveAssign(MX());

    if(roIn >= oMax){
      OUT().saveAssign(oMax);
      LIM() = true;
    }
    else{
      if(roIn <= oMin){
         OUT().saveAssign(oMin);
         LIM() = true;
      }else{
        OUT().saveAssign(roIn);
        LIM() = false;
      }
    }
  }

  template<typename T> void calculateValueString(){
    //TODO fill this function
  }

  virtual ~FORTE_F_LIMIT2(){};
};

#endif //close the ifdef sequence from the beginning of the file

