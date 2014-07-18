/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_STRING_TO_INT
 *** Description: convert STRING to INT
 *** Version: 
 ***     0.0: 2012-02-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_STRING_TO_INT_H_
#define _F_STRING_TO_INT_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_string.h>

class FORTE_F_STRING_TO_INT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_STRING_TO_INT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &IN() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &OUT() {
    return *static_cast<CIEC_INT*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_STRING_TO_INT){
  };

  virtual ~FORTE_F_STRING_TO_INT(){};

};

#endif //close the ifdef sequence from the beginning of the file

