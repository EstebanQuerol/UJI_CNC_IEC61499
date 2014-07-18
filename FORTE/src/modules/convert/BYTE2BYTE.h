/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: BYTE2BYTE
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _BYTE2BYTE_H_
#define _BYTE2BYTE_H_

#include <funcbloc.h>
#include <forte_byte.h>


class BYTE2BYTE: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(BYTE2BYTE)

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

  CIEC_BYTE& IN() {
  	return *static_cast<CIEC_BYTE*>(getDI(0));
  }

  CIEC_BYTE& OUT() {
  	return *static_cast<CIEC_BYTE*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(BYTE2BYTE){};
  virtual ~BYTE2BYTE();

};

#endif //close the ifdef sequence from the beginning of the file

