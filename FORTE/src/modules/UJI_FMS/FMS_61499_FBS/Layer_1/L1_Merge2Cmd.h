/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_Merge2Cmd
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-03-18/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L1_MERGE2CMD_H_
#define _L1_MERGE2CMD_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_string.h>

class FORTE_L1_Merge2Cmd: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L1_Merge2Cmd)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &Cmd1() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_USINT &L1MID1() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_STRING &Cmd2() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_USINT &L1MID2() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &CmdOut() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_USINT &L1MIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventE1ID = 0;
  static const TEventID scm_nEventE2ID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 4, 2, 0, 0);
  void alg_E1(void);
  void alg_E2(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateE1 = 1;
  static const TForteInt16 scm_nStateE2 = 2;

  void enterStateSTART(void);
  void enterStateE1(void);
  void enterStateE2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L1_Merge2Cmd(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L1_Merge2Cmd(){};

};

#endif //close the ifdef sequence from the beginning of the file

