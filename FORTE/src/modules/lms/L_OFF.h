/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_OFF
 *** Description: SIFB to Turn off power to LMS
 *** Version: 
 ***     0.0: 2011-10-05/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_OFF_H_
#define _L_OFF_H_

#include <funcbloc.h>
#include <forte_bool.h>

class FORTE_L_OFF : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_OFF)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*> (getDI(0));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TForteInt16 scm_anEOWithIndexes[];
    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(0, 1, 0, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_L_OFF){
  };

  virtual ~FORTE_L_OFF(){};

};

#endif //close the ifdef sequence from the beginning of the file
