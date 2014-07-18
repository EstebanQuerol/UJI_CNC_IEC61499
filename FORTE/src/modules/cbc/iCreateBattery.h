/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateBattery
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEBATTERY_H_
#define _ICREATEBATTERY_H_

#include <funcbloc.h>
#include <forte_int.h>

class FORTE_iCreateBattery : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateBattery)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_INT &Charging(){
      return *static_cast<CIEC_INT*>(getDO(0));
    }
    ;

    CIEC_INT &Voltage(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &Current(){
      return *static_cast<CIEC_INT*>(getDO(2));
    }
    ;

    CIEC_INT &Temperature(){
      return *static_cast<CIEC_INT*>(getDO(3));
    }
    ;

    CIEC_INT &Charge(){
      return *static_cast<CIEC_INT*>(getDO(4));
    }
    ;

    CIEC_INT &Capacity(){
      return *static_cast<CIEC_INT*>(getDO(5));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(1, 0, 6, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreateBattery){
  };

  virtual ~FORTE_iCreateBattery(){};

};

#endif //close the ifdef sequence from the beginning of the file
