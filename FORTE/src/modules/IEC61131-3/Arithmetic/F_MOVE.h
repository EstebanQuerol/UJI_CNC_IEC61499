/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MOVE
 *** Description: Adds two number values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_MOVE_H_
#define _F_MOVE_H_

#include <funcbloc.h>
#include <forte_any.h>

class FORTE_F_MOVE: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_MOVE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY &IN() {
    return *static_cast<CIEC_ANY*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY &OUT() {
    return *static_cast<CIEC_ANY*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_MOVE){
  };

  template<typename T> void calculateValue(){
    T &roIn(static_cast<T&>(IN()));
    OUT().saveAssign(MOVE(roIn));
  }

  virtual ~FORTE_F_MOVE(){};

};

#endif //close the ifdef sequence from the beginning of the file

