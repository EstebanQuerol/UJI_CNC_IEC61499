/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_8070Service
 *** Description: FAGOR 8070 CNC service FB
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - 
 ***     1.0: 2015-03-03/EQUEROL - UJI - Service rework
 *************************************************************************/

#ifndef _L0_8070SERVICE_H_
#define _L0_8070SERVICE_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>

class FORTE_L0_8070Service: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L0_8070Service)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &Cmd() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &ENDOPID() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_STRING &RD() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  CIEC_USINT &ServiceState() {
    return *static_cast<CIEC_USINT*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventREQSID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TEventID scm_nEventCompletedOPID = 2;
  static const TEventID scm_nEventCNFSID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(4, 2, 4, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBParameter scm_astParamters[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L0_8070Service){
  };

  virtual ~FORTE_L0_8070Service(){};

};

#endif //close the ifdef sequence from the beginning of the file

