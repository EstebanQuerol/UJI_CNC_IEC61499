/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineManager
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_MACHINEMANAGER_H_
#define _L3_MACHINEMANAGER_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_time.h>
#include <forte_usint.h>
#include <forte_bool.h>
#include <forte_array.h>
#include "L3_AAssignMachine.h"

class FORTE_L3_MachineManager: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_MachineManager)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &Period() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_USINT *MType() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MType_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(2));
  };

  CIEC_USINT &MID1() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  CIEC_USINT &MID2() {
    return *static_cast<CIEC_USINT*>(getDI(4));
  };

  CIEC_BOOL &State() {
    return *static_cast<CIEC_BOOL*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQ1ID = 1;
  static const TEventID scm_nEventREQ2ID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_AAssignMachine& L3_AAssignMachine() {
    return (*static_cast<FORTE_L3_AAssignMachine*>(m_apoAdapters[0]));
  };
  static const int scm_nL3_AAssignMachineAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 6, 1, 1);

virtual void setInitialValues();

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L3_MachineManager){
  };

  virtual ~FORTE_L3_MachineManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

