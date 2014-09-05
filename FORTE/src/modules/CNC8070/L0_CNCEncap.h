/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CNCEncap
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L0_CNCENCAP_H_
#define _L0_CNCENCAP_H_

#include <funcbloc.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_L0_CNCEncap: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L0_CNCEncap)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_UINT &CmdID() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_STRING &SD() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_USINT &PN() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &sBlock() {
    return *static_cast<CIEC_STRING*>(getDO(1));
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

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 4, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_L0_CNCEncap){
  };

  virtual ~FORTE_L0_CNCEncap(){};

};

#endif //close the ifdef sequence from the beginning of the file

