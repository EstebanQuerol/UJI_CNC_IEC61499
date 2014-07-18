/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: UDINT2UDINT
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _UDINT2UDINT_H_
#define _UDINT2UDINT_H_

#include <funcbloc.h>
#include <forte_udint.h>


class UDINT2UDINT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(UDINT2UDINT)

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

  CIEC_UDINT& IN() {
  	return *static_cast<CIEC_UDINT*>(getDI(0));
  }

  CIEC_UDINT& OUT() {
  	return *static_cast<CIEC_UDINT*>(getDO(0));
  }


public:
  FUNCTION_BLOCK_CTOR(UDINT2UDINT) {};
  virtual ~UDINT2UDINT();

};

#endif //close the ifdef sequence from the beginning of the file

