/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_AD
 *** Description: Read an Analog/Digital LMS  Sensor
 *** Version: 
 ***     0.0: 2011-08-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_AD_H_
#define _L_AD_H_

#include <funcbloc.h>
#include <forte_uint.h>
#include <forte_bool.h>

// TODO: rename to L_AI for analog input
class FORTE_L_AD : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_AD)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*> (getDI(0));
    }
    ;

    CIEC_UINT &PORT(){
      return *static_cast<CIEC_UINT*> (getDI(1));
    }
    ;

    CIEC_UINT &T(){
      return *static_cast<CIEC_UINT*> (getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*> (getDO(0));
    }
    ;

    CIEC_UINT &RD(){
      return *static_cast<CIEC_UINT*> (getDO(1));
    }
    ;

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

    FORTE_FB_DATA_ARRAY(2, 3, 2, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_L_AD){
  };

  virtual ~FORTE_L_AD(){};

};

#endif //close the ifdef sequence from the beginning of the file
