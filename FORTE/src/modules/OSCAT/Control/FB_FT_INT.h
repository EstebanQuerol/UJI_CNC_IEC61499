/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_INT
 *** Description: Integrator
 *** Version: 
 ***     0.0: 2011-07-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_FT_INT_H_
#define _FB_FT_INT_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_real.h>
#include <forte_bool.h>

class FORTE_FB_FT_INT: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_FT_INT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &Input() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &K() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_BOOL &rst() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_REAL &Out_max() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &Out_min() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Output() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_BOOL &lim() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
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

   FORTE_FB_DATA_ARRAY(2, 5, 2, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_FB_FT_INT){
  };

  virtual ~FORTE_FB_FT_INT(){};

};

#endif //close the ifdef sequence from the beginning of the file

