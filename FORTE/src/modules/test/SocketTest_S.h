/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: SocketTest_S
 *** Description: Composite Function Block Type
 *** Version:
 ***     0.0: 2008-04-22/IH - ACIN -
 *************************************************************************/

#ifndef _SocketTest_S_H_
#define _SocketTest_S_H_

#include <cfb.h>
#include <forte_wstring.h>
#include <forte_bool.h>
#include <forte_array.h>
#include "TestAdapter.h"

class SocketTest_S: public CCompositeFB{
  DECLARE_FIRMWARE_FB(SocketTest_S);

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,5,0,1);

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  static const SCFB_FBInstanceData scm_astInternalFBs[];
  static const SCFB_FBConnectionData scm_astEventConnections[];
  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;


public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(SocketTest_S){
  };
  virtual ~SocketTest_S();

};

#endif //close the ifdef sequence from the beginning of the file

