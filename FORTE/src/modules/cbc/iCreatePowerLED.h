/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreatePowerLED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEPOWERLED_H_
#define _ICREATEPOWERLED_H_

#include <funcbloc.h>
#include <forte_int.h>

class FORTE_iCreatePowerLED : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreatePowerLED)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_INT &COLOR(){
      return *static_cast<CIEC_INT*>(getDI(0));
    }
    ;

    CIEC_INT &BRITE(){
      return *static_cast<CIEC_INT*>(getDI(1));
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

    FORTE_FB_DATA_ARRAY(1, 2, 0, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreatePowerLED){
  };

  virtual ~FORTE_iCreatePowerLED(){};

};

#endif //close the ifdef sequence from the beginning of the file
