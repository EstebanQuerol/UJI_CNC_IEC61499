/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: BOOL2BOOL
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _BOOL2BOOL_H_
#define _BOOL2BOOL_H_

#include <funcbloc.h>
#include <forte_bool.h>


class BOOL2BOOL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(BOOL2BOOL)

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

CIEC_BOOL& IN() {
	return *static_cast<CIEC_BOOL*>(getDI(0));
}

CIEC_BOOL& OUT() {
	return *static_cast<CIEC_BOOL*>(getDO(0));
}

public:
  FUNCTION_BLOCK_CTOR(BOOL2BOOL){};
  virtual ~BOOL2BOOL();


};

#endif //close the ifdef sequence from the beginning of the file

