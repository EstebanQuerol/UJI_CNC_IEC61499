/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_TIME_TO_DWORD
 *** Description: convert TIME to DWORD
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_TIME_TO_DWORD_H_
#define _F_TIME_TO_DWORD_H_

#include <funcbloc.h>
#include <forte_time.h>
#include <forte_dword.h>

class FORTE_F_TIME_TO_DWORD: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_TIME_TO_DWORD)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_TIME &IN() {
    return *static_cast<CIEC_TIME*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_DWORD &OUT() {
    return *static_cast<CIEC_DWORD*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_TIME_TO_DWORD){
  };

  virtual ~FORTE_F_TIME_TO_DWORD(){};

};

#endif //close the ifdef sequence from the beginning of the file

