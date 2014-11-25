/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ProcessPlan
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-13/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_PROCESSPLAN_H_
#define _L3_PROCESSPLAN_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include "L3_ASetup.h"
#include "L3_APart.h"
#include "L3_AAssignMachine.h"

class FORTE_L3_ProcessPlan: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_ProcessPlan)

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

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_AAssignMachine& L3_AAssignMachine_P() {
    return (*static_cast<FORTE_L3_AAssignMachine*>(m_apoAdapters[0]));
  };
  static const int scm_nL3_AAssignMachine_PAdpNum = 0;
  FORTE_L3_ASetup& L3_ASetup() {
    return (*static_cast<FORTE_L3_ASetup*>(m_apoAdapters[1]));
  };
  static const int scm_nL3_ASetupAdpNum = 1;
  FORTE_L3_APart& L3_APart() {
    return (*static_cast<FORTE_L3_APart*>(m_apoAdapters[2]));
  };
  static const int scm_nL3_APartAdpNum = 2;
  FORTE_L3_AAssignMachine& L3_AAssignMachine_S() {
    return (*static_cast<FORTE_L3_AAssignMachine*>(m_apoAdapters[3]));
  };
  static const int scm_nL3_AAssignMachine_SAdpNum = 3;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 3, 1, 4);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L3_ProcessPlan){
  };

  virtual ~FORTE_L3_ProcessPlan(){};

};

#endif //close the ifdef sequence from the beginning of the file

