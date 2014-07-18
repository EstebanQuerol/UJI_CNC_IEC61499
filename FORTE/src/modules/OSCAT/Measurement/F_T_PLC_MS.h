/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_T_PLC_MS
 *** Description: reads the internal PLC timer and returns the time
 *** Version: 
 ***     0.0: 2011-08-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_T_PLC_MS_H_
#define _F_T_PLC_MS_H_

#include <funcbloc.h>
#include <forte_dword.h>

class FORTE_F_T_PLC_MS: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_T_PLC_MS)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_DWORD &OUT() {
    return *static_cast<CIEC_DWORD*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 0, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_T_PLC_MS){
  };

  virtual ~FORTE_F_T_PLC_MS(){};

};


inline const CIEC_DWORD T_PLC_MS(){
  return CIEC_DWORD( TIME().getInMiliSeconds());
}

#endif //close the ifdef sequence from the beginning of the file

