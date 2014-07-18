/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MotorDC
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _MOTORDC_H_
#define _MOTORDC_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_MotorDC : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_MotorDC)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_INT &PORT(){
      return *static_cast<CIEC_INT*>(getDI(1));
    }
    ;

    CIEC_BOOL &FREEZE(){
      return *static_cast<CIEC_BOOL*>(getDI(2));
    }
    ;

    CIEC_INT &PWR(){
      return *static_cast<CIEC_INT*>(getDI(3));
    }
    ;

    CIEC_INT &VEL(){
      return *static_cast<CIEC_INT*>(getDI(4));
    }
    ;

    CIEC_INT &POS(){
      return *static_cast<CIEC_INT*>(getDI(5));
    }
    ;

    CIEC_BOOL &RELPOS(){
      return *static_cast<CIEC_BOOL*>(getDI(6));
    }
    ;

    CIEC_INT *PID(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDI(7)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &PID_Array(){
      return *static_cast<CIEC_ARRAY*>(getDI(7));
    }
    ;

    CIEC_BOOL &PWM(){
      return *static_cast<CIEC_BOOL*>(getDI(8));
    }
    ;

    CIEC_BOOL &DUTY_CYCLE(){
      return *static_cast<CIEC_BOOL*>(getDI(9));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_INT &ERRNUM(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &POS_OUT(){
      return *static_cast<CIEC_INT*>(getDO(2));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventREQPWRID = 1;
    static const TEventID scm_nEventREQVELID = 2;
    static const TEventID scm_nEventREQPOSID = 3;
    static const TEventID scm_nEventSTOPID = 4;
    static const TEventID scm_nEventRSPID = 5;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventCNFPWRID = 1;
    static const TEventID scm_nEventCNFVELID = 2;
    static const TEventID scm_nEventCNFPOSID = 3;
    static const TEventID scm_nEventSTOPOID = 4;
    static const TEventID scm_nEventINDID = 5;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(6, 10, 3, 0)
    ;
    int m_nPort;
    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_MotorDC){
  };

  virtual ~FORTE_MotorDC(){};

};

#endif //close the ifdef sequence from the beginning of the file
