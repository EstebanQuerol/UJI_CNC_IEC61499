/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_DWORD_TO_BOOL
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-04-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_DWORD_TO_BOOL_H_
#define _F_DWORD_TO_BOOL_H_

#include <funcbloc.h>
#include <forte_dword.h>
#include <forte_bool.h>

class FORTE_F_DWORD_TO_BOOL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_DWORD_TO_BOOL)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_DWORD &IN() {
    return *static_cast<CIEC_DWORD*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &OUT() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_DWORD_TO_BOOL){
  };

  virtual ~FORTE_F_DWORD_TO_BOOL(){};

};

#endif //close the ifdef sequence from the beginning of the file

