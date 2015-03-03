/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FClosedPocket
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _L1_FCLOSEDPOCKET_H_
#define _L1_FCLOSEDPOCKET_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_any.h>

#ERROR type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!

#include <forte_wstring.h>

class FORTE_L1_FClosedPocket: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L1_FClosedPocket)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_WSTRING &PARAMS() {
    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_ANY &SD() {
    return *static_cast<CIEC_ANY*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_WSTRING &STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  };

  CIEC_ANY &RD() {
    return *static_cast<CIEC_ANY*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRSPID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 3, 3, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_L1_FClosedPocket){
  };

  virtual ~FORTE_L1_FClosedPocket(){};

};

#endif //close the ifdef sequence from the beginning of the file

