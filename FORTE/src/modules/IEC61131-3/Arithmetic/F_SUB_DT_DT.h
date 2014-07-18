/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_SUB_DT_DT
 *** Description: Subtracts two time data types
 *** Version: 
 ***     1.0: 2013-09-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_SUB_DT_DT_H_
#define _F_SUB_DT_DT_H_

#include <funcbloc.h>
#include <forte_date_and_time.h>
#include <forte_time.h>

class FORTE_F_SUB_DT_DT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_SUB_DT_DT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_DATE_AND_TIME &IN1() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(0));
  };

  CIEC_DATE_AND_TIME &IN2() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_TIME &OUT() {
    return *static_cast<CIEC_TIME*>(getDO(0));
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

   FORTE_FB_DATA_ARRAY(1, 2, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_SUB_DT_DT){
  };

  virtual ~FORTE_F_SUB_DT_DT(){};

};

#endif //close the ifdef sequence from the beginning of the file

