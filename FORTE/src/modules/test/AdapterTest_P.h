/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: AdapterTest_P
 *** Description: Composite Function Block Type
 *** Version:
 ***     0.0: 2008-04-22/IH - ACIN -
 *************************************************************************/

#ifndef _AdapterTest_P_H_
#define _AdapterTest_P_H_

#include <cfb.h>
#include <forte_wstring.h>
#include <forte_bool.h>
#include <forte_array.h>
#include "TestAdapter.h"

class AdapterTest_P: public CCompositeFB{
  DECLARE_FIRMWARE_FB(AdapterTest_P);

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anAdapterNames[];


  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,5,0,1);

  static const SCFB_FBInstanceData scm_astInternalFBs[];
  static const SCFB_FBConnectionData scm_astEventConnections[];
  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

  static const TForteUInt8 m_nNumAdapters = 1;

  static const SAdapterInstanceDef scm_astAdapterInstances[];

//  TESTADAPTER myPlug;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(AdapterTest_P) {   // myPlug
  };
  virtual ~AdapterTest_P();

};

#endif //close the ifdef sequence from the beginning of the file

