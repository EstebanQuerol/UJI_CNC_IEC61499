/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DownButton
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _DOWNBUTTON_H_
#define _DOWNBUTTON_H_

#include <funcbloc.h>
#include <forte_bool.h>

class FORTE_DownButton : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_DownButton)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &Q(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
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

    FORTE_FB_DATA_ARRAY(1, 0, 1, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_DownButton){
  };

  virtual ~FORTE_DownButton(){};

};

#endif //close the ifdef sequence from the beginning of the file
