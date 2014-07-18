/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateDemo
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-08/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEDEMO_H_
#define _ICREATEDEMO_H_

#include <funcbloc.h>
#include <forte_wstring.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_iCreateDemo : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateDemo)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_WSTRING &SCRIPT(){
      return *static_cast<CIEC_WSTRING*>(getDI(1));
    }
    ;

    CIEC_UINT &D(){
      return *static_cast<CIEC_UINT*>(getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventSpotID = 1;
    static const TEventID scm_nEventCoverID = 2;
    static const TEventID scm_nEventDemoID = 3;
    static const TEventID scm_nEventCoverDockID = 4;
    static const TEventID scm_nEventSendScriptID = 5;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventSpotOID = 1;
    static const TEventID scm_nEventCoverOID = 2;
    static const TEventID scm_nEventDemoOID = 3;
    static const TEventID scm_nEventCoverDockOID = 4;
    static const TEventID scm_nEventSendScriptOID = 5;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(6, 3, 1, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreateDemo){
  };

  virtual ~FORTE_iCreateDemo(){};

};

#endif //close the ifdef sequence from the beginning of the file
