/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: RT_E_EC_COUPLER
 *** Description: Coupling two succeeding event chains
 *** Version: 
 ***     0.0: 2008-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _RT_E_EC_COUPLER_H_
#define _RT_E_EC_COUPLER_H_

#include "rtesingle.h"
#include <forte_time.h>
#include <forte_bool.h>

class FORTE_RT_E_EC_COUPLER: public CRTEventSingle{
  DECLARE_FIRMWARE_FB(FORTE_RT_E_EC_COUPLER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &Tmin() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_TIME &Deadline() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventEIID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEOID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 3, 1, 0);

   virtual bool checkActivation(int ) {return true;};

public:
  FORTE_RT_E_EC_COUPLER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);

  virtual ~FORTE_RT_E_EC_COUPLER(){};

};

#endif //close the ifdef sequence from the beginning of the file

