/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: X20AT4222
 *** Description: X20 Temperature Input Module
 *** Version: 
 ***     0.0: 2012-03-06/4DIAC-IDE - 4DIAC-Consortium - null
 ***     1.0: 2012-11-05/FA - AIT - null
 *************************************************************************/

#ifndef _X20AT4222_H_
#define _X20AT4222_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_bool.h>

#include "EplCNCallback.h"
#include "EplWrapper.h"

class FORTE_X20AT4222 : public CFunctionBlock, public IEplCNCallback{
  DECLARE_FIRMWARE_FB(FORTE_X20AT4222)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_USINT &CNID(){
      return *static_cast<CIEC_USINT*>(getDI(1));
    }
    ;

    CIEC_UINT &MODID(){
      return *static_cast<CIEC_UINT*>(getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_USINT &CNIDO(){
      return *static_cast<CIEC_USINT*>(getDO(1));
    }
    ;

    CIEC_STRING &STATUS(){
      return *static_cast<CIEC_STRING*>(getDO(2));
    }
    ;

    CIEC_REAL &T01(){
      return *static_cast<CIEC_REAL*>(getDO(3));
    }
    ;

    CIEC_REAL &T02(){
      return *static_cast<CIEC_REAL*>(getDO(4));
    }
    ;

    CIEC_REAL &T03(){
      return *static_cast<CIEC_REAL*>(getDO(5));
    }
    ;

    CIEC_REAL &T04(){
      return *static_cast<CIEC_REAL*>(getDO(6));
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

    FORTE_FB_DATA_ARRAY(2, 3, 7, 0)
    ;

    void executeEvent(int pa_nEIID);

    // Variables for mapping between inputs and POWERLINK stack
    SEplMapping m_oEplMapping;CSyncObject m_oSync;
    bool m_bInitOk;
    // ...

  public:
    FUNCTION_BLOCK_CTOR(FORTE_X20AT4222){
  };

  virtual ~FORTE_X20AT4222(){};

  void cnSynchCallback();

};

#endif //close the ifdef sequence from the beginning of the file
