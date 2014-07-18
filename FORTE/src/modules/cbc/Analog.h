/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Analog
 *** Description: Analog sensor that return a 10 bit 0-255
 *** Version: 
 ***     0.0: 2012-06-16/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ANALOG_H_
#define _ANALOG_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_Analog : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_Analog)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_UINT &PORT(){
      return *static_cast<CIEC_UINT*>(getDI(1));
    }
    ;

    CIEC_INT &OUT_BITS(){
      return *static_cast<CIEC_INT*>(getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_INT &STATUS(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &OUT(){
      return *static_cast<CIEC_INT*>(getDO(2));
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

    FORTE_FB_DATA_ARRAY(2, 3, 3, 0)
    ;
    int m_nPort;
    int m_nOUT_BITS;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_Analog){
  };

  virtual ~FORTE_Analog(){};

};

#endif //close the ifdef sequence from the beginning of the file
