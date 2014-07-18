/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateMgt
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEMGT_H_
#define _ICREATEMGT_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_iCreateMgt : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateMgt)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_UINT &Mode(){
      return *static_cast<CIEC_UINT*>(getDI(1));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_INT &CurrentMode(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_BOOL &ERR(){
      return *static_cast<CIEC_BOOL*>(getDO(2));
    }
    ;

    CIEC_BOOL &Connected(){
      return *static_cast<CIEC_BOOL*>(getDO(3));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventstartID = 1;
    static const TEventID scm_nEventgetModeID = 2;
    static const TEventID scm_nEventsetModeID = 3;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventstartOID = 1;
    static const TEventID scm_nEventgetModeOID = 2;
    static const TEventID scm_nEventsetModeOID = 3;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(4, 2, 4, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreateMgt){
  };

  virtual ~FORTE_iCreateMgt(){};

};

#endif //close the ifdef sequence from the beginning of the file
