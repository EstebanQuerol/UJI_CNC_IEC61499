/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: GET_CHAN_INFO
 *** Description: Loads channel with the specified symbolic name
 *** Version:
 ***     0.0: 2011-10-04/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _GET_CHAN_INFO_H_
#define _GET_CHAN_INFO_H_

#include <mtypes.h>
#include <funcbloc.h>
#include <forte_int.h>
#include <forte_string.h>

class FORTE_GET_CHAN_INFO: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_GET_CHAN_INFO)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &SYMB_NAME() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &RET_CODE() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  CIEC_INT &MOD_NB() {
    return *static_cast<CIEC_INT*>(getDO(1));
  };

  CIEC_INT &CHAN_NB() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 1, 3, 0);

  void executeEvent(int pa_nEIID);

  bool init();
  SINT32 getChannelInfo();

public:
  FUNCTION_BLOCK_CTOR(FORTE_GET_CHAN_INFO){
  };

  virtual ~FORTE_GET_CHAN_INFO(){};
};

#endif //close the ifdef sequence from the beginning of the file

