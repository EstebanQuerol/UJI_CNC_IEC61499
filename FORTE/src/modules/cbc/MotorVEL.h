/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MotorVEL
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-03/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _MOTORVEL_H_
#define _MOTORVEL_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_MotorVEL : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_MotorVEL)

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

    CIEC_INT &VEL(){
      return *static_cast<CIEC_INT*>(getDI(3));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventREQID = 1;
    static const TEventID scm_nEventSTOPID = 2;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventCNFID = 1;
    static const TEventID scm_nEventSTOPOID = 2;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(3, 4, 1, 0)
    ;
    int m_nPort;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_MotorVEL){
  };

  virtual ~FORTE_MotorVEL(){};

};

#endif //close the ifdef sequence from the beginning of the file
