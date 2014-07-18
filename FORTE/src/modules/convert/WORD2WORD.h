/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: WORD2WORD
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _WORD2WORD_H_
#define _WORD2WORD_H_

#include <funcbloc.h>
#include <forte_word.h>

class WORD2WORD: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(WORD2WORD)

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

  CIEC_WORD& IN() {
  	return *static_cast<CIEC_WORD*>(getDI(0));
  }

  CIEC_WORD& OUT() {
  	return *static_cast<CIEC_WORD*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(WORD2WORD){};
  virtual ~WORD2WORD();

};

#endif //close the ifdef sequence from the beginning of the file

