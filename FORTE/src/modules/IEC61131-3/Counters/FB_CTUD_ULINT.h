/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTUD_ULINT
 *** Description: counters (up-down-counter)
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _FB_CTUD_ULINT_H_
#define _FB_CTUD_ULINT_H_

#include <funcbloc.h>
#include <forte_ulint.h>
#include <forte_bool.h>
#include <forte_array.h>

#ifdef FORTE_USE_64BIT_DATATYPES

class FB_CTUD_ULINT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FB_CTUD_ULINT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anDataOutputNames[], scm_aunDODataTypeIds[];
  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,5,3, 0);

  void executeEvent(int pa_nEIID);

  CIEC_BOOL& CU() {
   	return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  CIEC_BOOL& CD() {
   	return *static_cast<CIEC_BOOL*>(getDI(1));
  }
  CIEC_BOOL& R() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  }
  CIEC_BOOL& LD() {
   	return *static_cast<CIEC_BOOL*>(getDI(3));
  }
  CIEC_ULINT& PV() {
   	return *static_cast<CIEC_ULINT*>(getDI(4));
  }

  CIEC_BOOL& QU() {
   	return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  CIEC_BOOL& QD() {
   	return *static_cast<CIEC_BOOL*>(getDO(1));
  }
  CIEC_ULINT& CV() {
   	return *static_cast<CIEC_ULINT*>(getDO(2));
  }

public:
  FUNCTION_BLOCK_CTOR(FB_CTUD_ULINT){};
  virtual ~FB_CTUD_ULINT(){};

};

#endif

#endif //close the ifdef sequence from the beginning of the file
