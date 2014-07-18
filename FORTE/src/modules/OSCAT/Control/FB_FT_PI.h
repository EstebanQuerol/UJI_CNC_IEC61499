/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PI
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2011-07-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _FB_FT_PI_H_
#define _FB_FT_PI_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_real.h>
#include <forte_bool.h>

class FORTE_FB_FT_PI: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_FB_FT_PI)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &In() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &KP() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &KI() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &Ilim_L() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &Ilim_H() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_BOOL &rst() {
    return *static_cast<CIEC_BOOL*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Y() {
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

   FORTE_FB_DATA_ARRAY(2, 6, 2, 0);

virtual void setInitialValues();

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_FB_FT_PI){
  };

  virtual ~FORTE_FB_FT_PI(){};

};

#endif //close the ifdef sequence from the beginning of the file

