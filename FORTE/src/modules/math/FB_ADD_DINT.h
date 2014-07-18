/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: FB_ADD_DINT
 *** Description: Adds two DINT values
 *** Version:
 ***     1.0: 2007-06-26/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _FB_ADD_DINT_H_
#define _FB_ADD_DINT_H_

#include <basicfb.h>
#include <forte_dint.h>


class FB_ADD_DINT: public CBasicFB{
  DECLARE_FIRMWARE_FB(FB_ADD_DINT)

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

  FORTE_BASIC_FB_DATA_ARRAY(1,2,1,0, 0);

  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

  CIEC_DINT& IN1() {
  	return *static_cast<CIEC_DINT*>(getDI(0));
  }
  CIEC_DINT& IN2() {
  	return *static_cast<CIEC_DINT*>(getDI(1));
  }

  CIEC_DINT& OUT() {
  	return *static_cast<CIEC_DINT*>(getDO(0));
  }

public:
  FB_ADD_DINT(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
  virtual ~FB_ADD_DINT();

};

#endif //close the ifdef sequence from the beginning of the file

