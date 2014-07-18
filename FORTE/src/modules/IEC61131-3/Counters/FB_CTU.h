/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTU
 *** Description: counters (up-counter)
 *** Version: 
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _FB_CTU_H_
#define _FB_CTU_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FB_CTU: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FB_CTU)

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

  FORTE_FB_DATA_ARRAY(1,3,2, 0);

  void executeEvent(int pa_nEIID);

  CIEC_BOOL& CU() {
   	return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  CIEC_BOOL& R() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  }
  CIEC_INT& PV() {
   	return *static_cast<CIEC_INT*>(getDI(2));
  }

  CIEC_BOOL& Q() {
   	return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  CIEC_INT& CV() {
   	return *static_cast<CIEC_INT*>(getDO(1));
  }

public:
  FUNCTION_BLOCK_CTOR(FB_CTU){};
  virtual ~FB_CTU(){};

};

#endif //close the ifdef sequence from the beginning of the file

