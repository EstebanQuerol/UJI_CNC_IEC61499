/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: STRING2DT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-11-24/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _STRING2DT_H_
#define _STRING2DT_H_

#include <funcbloc.h>
#include <forte_date_and_time.h>
#include <forte_string.h>

class FORTE_STRING2DT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_STRING2DT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &IN() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_DATE_AND_TIME &OUT() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_STRING2DT){
  };

  virtual ~FORTE_STRING2DT(){};

};

#endif //close the ifdef sequence from the beginning of the file

