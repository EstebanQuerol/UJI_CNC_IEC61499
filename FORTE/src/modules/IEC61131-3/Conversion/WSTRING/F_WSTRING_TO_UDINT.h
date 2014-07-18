/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_WSTRING_TO_UDINT
 *** Description: convert WSTRING to UDINT
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_WSTRING_TO_UDINT_H_
#define _F_WSTRING_TO_UDINT_H_

#include <funcbloc.h>
#include <forte_wstring.h>
#include <forte_udint.h>

class FORTE_F_WSTRING_TO_UDINT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_WSTRING_TO_UDINT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_WSTRING &IN() {
    return *static_cast<CIEC_WSTRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UDINT &OUT() {
    return *static_cast<CIEC_UDINT*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_WSTRING_TO_UDINT){
  };

  virtual ~FORTE_F_WSTRING_TO_UDINT(){};

};

#endif //close the ifdef sequence from the beginning of the file

