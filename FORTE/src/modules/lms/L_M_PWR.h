/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_M_PWR
 *** Description: LMS Motor control via power
 *** Version: 
 ***     0.0: 2011-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_M_PWR_H_
#define _L_M_PWR_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_L_M_PWR : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_M_PWR)

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

    CIEC_BOOL &DIR(){
      return *static_cast<CIEC_BOOL*> (getDI(2));
    }
    ;

    CIEC_INT &PWR(){
      return *static_cast<CIEC_INT*> (getDI(3));
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

    FORTE_FB_DATA_ARRAY(2, 4, 2, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_L_M_PWR){
  };

  virtual ~FORTE_L_M_PWR(){};

};

#endif //close the ifdef sequence from the beginning of the file
