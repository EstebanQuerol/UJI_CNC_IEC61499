/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SVIsend_1
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-09-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _SVISEND_1_H_
#define _SVISEND_1_H_

#include "BE_SVIFB.h"
#include <forte_any.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_SVIsend_1: public BE_SVIFB{
  DECLARE_FIRMWARE_FB(FORTE_SVIsend_1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &ID() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_ANY &SD_1() {
    return *static_cast<CIEC_ANY*>(getDI(2));
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

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 3, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FORTE_SVIsend_1(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
  		 BE_SVIFB( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_SVIsend_1(){};

};

#endif //close the ifdef sequence from the beginning of the file

