/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_ROR
 *** Description: rotate right
 *** Version: 
 ***     0.0: 2013-04-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_ROR_H_
#define _F_ROR_H_

#include <funcbloc.h>
#include <forte_any_int.h>
#include <forte_any_bit.h>

class FORTE_F_ROR: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_ROR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_BIT &IN() {
    return *static_cast<CIEC_ANY_BIT*>(getDI(0));
  };

  CIEC_ANY_INT &N() {
    return *static_cast<CIEC_ANY_INT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_BIT &OUT() {
    return *static_cast<CIEC_ANY_BIT*>(getDO(0));
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

   FORTE_FB_DATA_ARRAY(1, 2, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_ROR){
  };

  template<typename T> void calculateValue(){
    T oIn;
	#ifdef FORTE_USE_64BIT_DATATYPES
	  CIEC_ULINT oN;
    #else
	  CIEC_UDINT oN;
	#endif //#ifdef FORTE_USE_64BIT_DATATYPES
    oIn.saveAssign(IN());
    oN.saveAssign(N());
    OUT().saveAssign(ROR(oIn, oN));
  }

  virtual ~FORTE_F_ROR(){};

};

#endif //close the ifdef sequence from the beginning of the file

