/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: FB_DIV_LREAL
 *** Description: Divides two LREAL values
 *** Version:
 ***     1.0: 2007-06-26/TS - PROFACTOR GmbH -
 *************************************************************************/

#ifndef _FB_DIV_LREAL_H_
#define _FB_DIV_LREAL_H_

#include <basicfb.h>
#include <forte_lreal.h>


class FB_DIV_LREAL: public CBasicFB{
  DECLARE_FIRMWARE_FB(FB_DIV_LREAL)

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

  CIEC_LREAL& IN1() {
  	return *static_cast<CIEC_LREAL*>(getDI(0));
  }
  CIEC_LREAL& IN2() {
  	return *static_cast<CIEC_LREAL*>(getDI(1));
  }

  CIEC_LREAL& OUT() {
  	return *static_cast<CIEC_LREAL*>(getDO(0));
  }

public:
  FB_DIV_LREAL(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
  virtual ~FB_DIV_LREAL();

};

#endif //close the ifdef sequence from the beginning of the file

