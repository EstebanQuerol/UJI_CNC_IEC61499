/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: X20DI4653
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-05-31/4DIAC-IDE - 4DIAC-Consortium - null
 ***     1.0: 2013-02-11/FA,TS - AIT - null
 *************************************************************************/

#ifndef _X20DI4653_H_
#define _X20DI4653_H_

#include <funcbloc.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_bool.h>

#include "EplCNCallback.h"
#include "EplWrapper.h"

class FORTE_X20DI4653: public CFunctionBlock, public IEplCNCallback{
  DECLARE_FIRMWARE_FB(FORTE_X20DI4653)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &CNID() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_UINT &MODID() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &CNIDO() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  CIEC_BOOL &DI01() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_BOOL &DI02() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  };

  CIEC_BOOL &DI03() {
    return *static_cast<CIEC_BOOL*>(getDO(5));
  };

  CIEC_BOOL &DI04() {
    return *static_cast<CIEC_BOOL*>(getDO(6));
  };

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

   FORTE_FB_DATA_ARRAY(2, 3, 7, 0);

  void executeEvent(int pa_nEIID);

  // Variables for mapping between inputs and POWERLINK stack

  SEplMapping m_oEplMapping;
  CSyncObject m_oSync;
  bool m_bInitOk;
  // ...

public:
  FUNCTION_BLOCK_CTOR(FORTE_X20DI4653){
  };

  virtual ~FORTE_X20DI4653(){};

  void cnSynchCallback();

};

#endif //close the ifdef sequence from the beginning of the file

