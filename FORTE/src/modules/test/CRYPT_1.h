/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: CRYPT_1
 *** Description: Basic Function Block Type
 *** Version: 
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH - 
 *************************************************************************/

#ifndef _CRYPT_1_H_
#define _CRYPT_1_H_

#include <basicfb.h>
#include <forte_wstring.h>

class CRYPT_1: public CBasicFB{
  DECLARE_FIRMWARE_FB(CRYPT_1)

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

  FORTE_BASIC_FB_DATA_ARRAY(1,1,1,0, 0);

  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART();
  void enterStateREQ();


  virtual void executeEvent(int pa_nEIID);

  CIEC_WSTRING& INPUT() {
   	return *static_cast<CIEC_WSTRING*>(getDI(0));
  }

  CIEC_WSTRING& OUTPUT() {
   	return *static_cast<CIEC_WSTRING*>(getDO(0));
  }
public:
  CRYPT_1(CStringDictionary::TStringId pa_nFBInstanceNameId, CResource *pa_poSrcRes);
  virtual ~CRYPT_1();

};

#endif //close the ifdef sequence from the beginning of the file

