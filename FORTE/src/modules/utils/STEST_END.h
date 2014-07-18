/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: STEST_END
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-02-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _STEST_END_H_
#define _STEST_END_H_

#include <funcbloc.h>
#include "../../core/resource.h"
#include <mgmcmdstruct.h>

class FORTE_STEST_END: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_STEST_END)

private:
  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 0, 0, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_STEST_END){
  };

  virtual ~FORTE_STEST_END(){};

};

#endif //close the ifdef sequence from the beginning of the file

