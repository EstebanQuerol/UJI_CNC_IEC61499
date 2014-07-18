/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreatePlayLED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEPLAYLED_H_
#define _ICREATEPLAYLED_H_

#include <funcbloc.h>
#include <forte_bool.h>

class FORTE_iCreatePlayLED : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreatePlayLED)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &Q(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(1, 1, 0, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreatePlayLED){
  };

  virtual ~FORTE_iCreatePlayLED(){};

};

#endif //close the ifdef sequence from the beginning of the file
