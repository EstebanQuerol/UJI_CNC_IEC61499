/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: TIME2TIME
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _TIME2TIME_H_
#define _TIME2TIME_H_

#include <funcbloc.h>
#include <forte_time.h>


class TIME2TIME: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(TIME2TIME)

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

  CIEC_TIME& IN() {
  	return *static_cast<CIEC_TIME*>(getDI(0));
  }

  CIEC_TIME& OUT() {
  	return *static_cast<CIEC_TIME*>(getDO(0));
  }


public:
  FUNCTION_BLOCK_CTOR(TIME2TIME){};
  virtual ~TIME2TIME();

};

#endif //close the ifdef sequence from the beginning of the file

