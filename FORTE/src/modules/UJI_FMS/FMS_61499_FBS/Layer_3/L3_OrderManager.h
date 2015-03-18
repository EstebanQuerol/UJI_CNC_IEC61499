/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_OrderManager
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_ORDERMANAGER_H_
#define _L3_ORDERMANAGER_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include "L3_APart.h"

class FORTE_L3_OrderManager: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_OrderManager)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_UINT &Family() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &Type() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &Lotsize() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_DATE_AND_TIME &Deadline() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_APart& L3_APart() {
    return (*static_cast<FORTE_L3_APart*>(m_apoAdapters[0]));
  };
  static const int scm_nL3_APartAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 5, 1, 1);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L3_OrderManager){
  };

  virtual ~FORTE_L3_OrderManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

