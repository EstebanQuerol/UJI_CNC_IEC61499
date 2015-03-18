/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_L1CFB
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2015-03-18/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L1_L1CFB_H_
#define _L1_L1CFB_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_usint.h>
#include <forte_string.h>

class FORTE_L1_L1CFB: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L1_L1CFB)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &OperationIn() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_USINT &L1MIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &CmdOut() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_USINT &ENDOPID() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventL2REQID = 0;
  static const TEventID scm_nEventL0RSPID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventL0SendID = 0;
  static const TEventID scm_nEventL2INDID = 1;
  static const TEventID scm_nEventL2CNFID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 2, 2, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L1_L1CFB){
  };

  virtual ~FORTE_L1_L1CFB(){};

};

#endif //close the ifdef sequence from the beginning of the file

