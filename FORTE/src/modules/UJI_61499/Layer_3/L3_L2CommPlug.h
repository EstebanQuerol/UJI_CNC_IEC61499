/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_L2CommPlug
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-11-25/EQUEROL - UJI - 
 ***     1.0: 2015-01-08/EQUEROL - UJI - modified adapter definition
 *************************************************************************/

#ifndef _L3_L2COMMPLUG_H_
#define _L3_L2COMMPLUG_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <forte_array.h>
#include "L3_ASetup.h"

class FORTE_L3_L2CommPlug: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_L2CommPlug)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT *PartInfoS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoS_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_USINT &ENDID() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT *PartInfoP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoP_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(0));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_STRING &Setup() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_ASetup& L3_ASetup() {
    return (*static_cast<FORTE_L3_ASetup*>(m_apoAdapters[0]));
  };
  static const int scm_nL3_ASetupAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 2, 3, 1);

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_L3_L2CommPlug){
  };

  virtual ~FORTE_L3_L2CommPlug(){};

};

#endif //close the ifdef sequence from the beginning of the file

