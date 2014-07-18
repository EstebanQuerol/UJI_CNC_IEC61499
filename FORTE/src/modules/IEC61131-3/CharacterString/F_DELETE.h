/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_DELETE
 *** Description: delete L characters of IN beginning at the P-th character position
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_DELETE_H_
#define _F_DELETE_H_

#include <funcbloc.h>
#include <forte_any_int.h>
#include <forte_any_string.h>

class FORTE_F_DELETE: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_DELETE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_STRING &IN() {
    return *static_cast<CIEC_ANY_STRING*>(getDI(0));
  };

  CIEC_ANY_INT &L() {
    return *static_cast<CIEC_ANY_INT*>(getDI(1));
  };

  CIEC_ANY_INT &P() {
    return *static_cast<CIEC_ANY_INT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_STRING &OUT() {
    return *static_cast<CIEC_ANY_STRING*>(getDO(0));
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

   FORTE_FB_DATA_ARRAY(1, 3, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_DELETE){
  };

  template<typename T> void calculateValueString(){
     T oIn1;
     oIn1.saveAssign(IN());
     OUT().saveAssign(DELETE(oIn1,L(),P()));
   }

  virtual ~FORTE_F_DELETE(){};

};

#endif //close the ifdef sequence from the beginning of the file

