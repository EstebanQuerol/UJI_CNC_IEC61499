/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CBC_OFF
 *** Description: SIFB to Turn off power to LMS
 *** Version: 
 ***     0.0: 2012-06-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _CBC_OFF_H_
#define _CBC_OFF_H_

#include <funcbloc.h>
#include <forte_time.h>
#include <forte_bool.h>

class FORTE_CBC_OFF : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_CBC_OFF)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_TIME &DT(){
      return *static_cast<CIEC_TIME*>(getDI(1));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TForteInt16 scm_anEOWithIndexes[];
    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(0, 2, 0, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_CBC_OFF){
  };

  virtual ~FORTE_CBC_OFF(){};

};

#endif //close the ifdef sequence from the beginning of the file
