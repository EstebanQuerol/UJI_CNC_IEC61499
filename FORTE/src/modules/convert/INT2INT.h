/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: INT2INT
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _INT2INT_H_
#define _INT2INT_H_

#include <funcbloc.h>
#include <forte_int.h>


class INT2INT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(INT2INT)

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

  CIEC_INT& IN() {
  	return *static_cast<CIEC_INT*>(getDI(0));
  }

  CIEC_INT& OUT() {
  	return *static_cast<CIEC_INT*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(INT2INT){};
  virtual ~INT2INT();

};

#endif //close the ifdef sequence from the beginning of the file

