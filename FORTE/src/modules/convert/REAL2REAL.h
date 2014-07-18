/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: REAL2REAL
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _REAL2REAL_H_
#define _REAL2REAL_H_

#include <funcbloc.h>
#include <forte_real.h>

#ifdef FORTE_USE_REAL_DATATYPE

class REAL2REAL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(REAL2REAL)

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

  FORTE_FB_DATA_ARRAY(1,1,1, 0);

   virtual void executeEvent(int pa_nEIID);

   CIEC_REAL& IN() {
   	return *static_cast<CIEC_REAL*>(getDI(0));
   }

   CIEC_REAL& OUT() {
   	return *static_cast<CIEC_REAL*>(getDO(0));
   }


public:
  FUNCTION_BLOCK_CTOR(REAL2REAL) {};
  virtual ~REAL2REAL();

};

#endif

#endif //close the ifdef sequence from the beginning of the file

