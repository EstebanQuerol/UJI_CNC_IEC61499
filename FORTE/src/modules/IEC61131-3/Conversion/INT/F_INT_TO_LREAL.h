/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_INT_TO_LREAL
 *** Description: convert INT to LREAL
 *** Version: 
 ***     0.0: 2011-06-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_INT_TO_LREAL_H_
#define _F_INT_TO_LREAL_H_

#ifdef FORTE_USE_REAL_DATATYPE

#ifdef FORTE_USE_64BIT_DATATYPES


#include <funcbloc.h>
#include <forte_int.h>
#include <forte_lreal.h>

class FORTE_F_INT_TO_LREAL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_INT_TO_LREAL)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &IN() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_LREAL &OUT() {
    return *static_cast<CIEC_LREAL*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 1, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_INT_TO_LREAL){
  };

  virtual ~FORTE_F_INT_TO_LREAL(){};

};

#endif
#endif

#endif //close the ifdef sequence from the beginning of the file

