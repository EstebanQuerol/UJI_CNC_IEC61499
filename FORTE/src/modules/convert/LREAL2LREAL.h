/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: LREAL2LREAL
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _LREAL2LREAL_H_
#define _LREAL2LREAL_H_

#include <funcbloc.h>
#include <forte_lreal.h>

#ifdef FORTE_USE_REAL_DATATYPE

#ifdef FORTE_USE_64BIT_DATATYPES

class LREAL2LREAL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(LREAL2LREAL)

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

  CIEC_LREAL& IN() {
  	return *static_cast<CIEC_LREAL*>(getDI(0));
  }

  CIEC_LREAL& OUT() {
  	return *static_cast<CIEC_LREAL*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(LREAL2LREAL){};
  virtual ~LREAL2LREAL();

};

#endif
#endif

#endif //close the ifdef sequence from the beginning of the file

