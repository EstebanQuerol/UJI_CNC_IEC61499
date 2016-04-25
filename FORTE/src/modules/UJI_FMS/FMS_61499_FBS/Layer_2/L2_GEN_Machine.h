/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_GEN_Machine
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2015-03-17/EQUEROL - UJI - 
 ***     1.0: 2016-01-19/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_GEN_MACHINE_H_
#define _L2_GEN_MACHINE_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L2_GEN_Machine: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_GEN_Machine)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_BOOL &COM_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_UINT *PartInfoIn1() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoIn1_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(3));
  };

  CIEC_STRING &SetupIn() {
    return *static_cast<CIEC_STRING*>(getDI(4));
  };

  CIEC_UINT *PartInfoIn2() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(5)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoIn2_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(5));
  };

  CIEC_BOOL &QI2() {
    return *static_cast<CIEC_BOOL*>(getDI(6));
  };

  CIEC_USINT &ServiceStateIn() {
    return *static_cast<CIEC_USINT*>(getDI(7));
  };

  CIEC_USINT &ENDOPIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(8));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &MUI_STATE() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &MUI_MSG() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_UINT &MUI_PART_ID() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &MUI_PART_FAMILY() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_UINT &MUI_PART_TYPE() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  CIEC_BOOL &COM_INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(5));
  };

  CIEC_STRING &OperationOut() {
    return *static_cast<CIEC_STRING*>(getDO(6));
  };

  CIEC_USINT &L1MIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(7));
  };

  CIEC_UINT *PartInfoOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(8)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(8));
  };

  CIEC_USINT &ENDID() {
    return *static_cast<CIEC_USINT*>(getDO(9));
  };

  CIEC_BOOL &MachineState() {
    return *static_cast<CIEC_BOOL*>(getDO(10));
  };

  CIEC_BOOL &QO2() {
    return *static_cast<CIEC_BOOL*>(getDO(11));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventCOM_INIT_RSPID = 1;
  static const TEventID scm_nEventL3REQID = 2;
  static const TEventID scm_nEventL3RSPID = 3;
  static const TEventID scm_nEventL0RSP1ID = 4;
  static const TEventID scm_nEventL0RSP2ID = 5;
  static const TEventID scm_nEventL1RSPID = 6;
  static const TEventID scm_nEventL1INDID = 7;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventMUI_INDID = 0;
  static const TEventID scm_nEventCOM_INITID = 1;
  static const TEventID scm_nEventSendID = 2;
  static const TEventID scm_nEventCNFID = 3;
  static const TEventID scm_nEventINDID = 4;
  static const TEventID scm_nEventFREEID = 5;
  static const TEventID scm_nEventERRORID = 6;
  static const TEventID scm_nEventL0INITOID = 7;
  static const TEventID scm_nEventL0IND1ID = 8;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(9, 9, 12, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L2_GEN_Machine){
  };

  virtual ~FORTE_L2_GEN_Machine(){};

};

#endif //close the ifdef sequence from the beginning of the file

