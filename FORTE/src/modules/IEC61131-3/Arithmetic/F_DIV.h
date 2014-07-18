/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_DIV
 *** Description: Divides two values
 *** Version: 
 ***     1.0: 2011-09-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_DIV_H_
#define _F_DIV_H_

#include <funcbloc.h>
#include <forte_any_num.h>

class FORTE_F_DIV: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_DIV)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_NUM &IN1() {
    return *static_cast<CIEC_ANY_NUM*>(getDI(0));
  };

  CIEC_ANY_NUM &IN2() {
    return *static_cast<CIEC_ANY_NUM*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_NUM &OUT() {
    return *static_cast<CIEC_ANY_NUM*>(getDO(0));
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
  FUNCTION_BLOCK_CTOR(FORTE_F_DIV){
  };

  template<typename T> void calculateValue(){
    T oIn1;
    T oIn2;
    oIn1.saveAssign(IN1());
    oIn2.saveAssign(IN2());

    OUT().saveAssign(DIV(oIn1,oIn2));

//    char strbuf1[100];
//    char strbuf2[100];
//    char strbuf3[100];
//    IN1().toString(strbuf1, sizeof(strbuf1));
//    IN2().toString(strbuf2, sizeof(strbuf2));
//    OUT().toString(strbuf3, sizeof(strbuf3));
//    DEVLOG_INFO_4(cg_nID_CDeviceLog, 0x10, " %s / %s = %s", strbuf1, strbuf2, strbuf3);
  }

  virtual ~FORTE_F_DIV(){};
};

#endif //close the ifdef sequence from the beginning of the file

