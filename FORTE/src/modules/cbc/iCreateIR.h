/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateIR
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEIR_H_
#define _ICREATEIR_H_

#include <funcbloc.h>
#include <forte_int.h>

class FORTE_iCreateIR : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateIR)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_INT &IRbyte(){
      return *static_cast<CIEC_INT*>(getDO(0));
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
    FUNCTION_BLOCK_CTOR(FORTE_iCreateIR){
  };

  virtual ~FORTE_iCreateIR(){};

};

#endif //close the ifdef sequence from the beginning of the file
