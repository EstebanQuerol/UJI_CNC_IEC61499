/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: WSTRING2WSTRING
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _WSTRING2WSTRING_H_
#define _WSTRING2WSTRING_H_

#include <funcbloc.h>
#include <forte_wstring.h>

class WSTRING2WSTRING: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(WSTRING2WSTRING)

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

  CIEC_WSTRING& IN() {
  	return *static_cast<CIEC_WSTRING*>(getDI(0));
  }

  CIEC_WSTRING& OUT() {
  	return *static_cast<CIEC_WSTRING*>(getDO(0));
  }


public:
  FUNCTION_BLOCK_CTOR(WSTRING2WSTRING){};
  virtual ~WSTRING2WSTRING();

};

#endif //close the ifdef sequence from the beginning of the file

