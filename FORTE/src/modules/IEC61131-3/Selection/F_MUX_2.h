/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MUX_2
 *** Description: multiplexer
 *** Version: 
 ***     1.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_MUX_2_H_
#define _F_MUX_2_H_

#include <funcbloc.h>
#include <forte_any.h>
#include <forte_any_int.h>

class FORTE_F_MUX_2: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_MUX_2)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_INT &K() {
    return *static_cast<CIEC_ANY_INT*>(getDI(0));
  };

  CIEC_ANY &IN1() {
    return *static_cast<CIEC_ANY*>(getDI(1));
  };

  CIEC_ANY &IN2() {
    return *static_cast<CIEC_ANY*>(getDI(2));
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

   FORTE_FB_DATA_ARRAY(1, 3, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_MUX_2){
  };

  virtual ~FORTE_F_MUX_2(){};

};

#endif //close the ifdef sequence from the beginning of the file

