/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_SINT_TO_WSTRING
 *** Description: convert SINT to WSTRING
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_SINT_TO_WSTRING_H_
#define _F_SINT_TO_WSTRING_H_

#include <funcbloc.h>
#include <forte_sint.h>
#include <forte_wstring.h>

class FORTE_F_SINT_TO_WSTRING: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_SINT_TO_WSTRING)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_SINT &IN() {
    return *static_cast<CIEC_SINT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_WSTRING &OUT() {
    return *static_cast<CIEC_WSTRING*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_SINT_TO_WSTRING){
  };

  virtual ~FORTE_F_SINT_TO_WSTRING(){};

};

#endif //close the ifdef sequence from the beginning of the file

