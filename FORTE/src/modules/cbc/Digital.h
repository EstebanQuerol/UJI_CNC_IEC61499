/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Digital
 *** Description: Analog sensor that return a 10 bit 0-255
 *** Version: 
 ***     0.0: 2012-06-16/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _DIGITAL_H_
#define _DIGITAL_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_Digital : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_Digital)

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

    CIEC_BOOL &Q(){
      return *static_cast<CIEC_BOOL*>(getDO(2));
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

    FORTE_FB_DATA_ARRAY(2, 2, 3, 0)
    ;
    int m_nPort;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_Digital){
  };

  virtual ~FORTE_Digital(){};

};

#endif //close the ifdef sequence from the beginning of the file
