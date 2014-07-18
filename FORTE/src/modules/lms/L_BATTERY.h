/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L_BATTERY
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-12-26/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_BATTERY_H_
#define _L_BATTERY_H_

#include <funcbloc.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_L_BATTERY: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_BATTERY)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &RD() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_BOOL &RE() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 0, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_L_BATTERY){
  };

  virtual ~FORTE_L_BATTERY(){};

};

#endif //close the ifdef sequence from the beginning of the file

