/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateWall
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEWALL_H_
#define _ICREATEWALL_H_

#include <funcbloc.h>
#include <forte_int.h>

class FORTE_iCreateWall : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateWall)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_INT &WALL(){
      return *static_cast<CIEC_INT*>(getDO(0));
    }
    ;

    CIEC_INT &AMT(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &VWALL(){
      return *static_cast<CIEC_INT*>(getDO(2));
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

    FORTE_FB_DATA_ARRAY(1, 0, 3, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreateWall){
  };

  virtual ~FORTE_iCreateWall(){};

};

#endif //close the ifdef sequence from the beginning of the file
