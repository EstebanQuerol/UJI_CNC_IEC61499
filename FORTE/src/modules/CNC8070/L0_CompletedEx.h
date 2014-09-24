/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CompletedEx
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _L0_COMPLETEDEX_H_
#define _L0_COMPLETEDEX_H_

#include <basicfb.h>
#include <forte_usint.h>

class FORTE_L0_CompletedEx: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L0_CompletedEx)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT &RID() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  };

  static const TEventID scm_nEventOnReadyID = 0;
  static const TEventID scm_nEventOnExecutingID = 1;
  static const TEventID scm_nEventOnNotReadyID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSuccessID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 0, 1, 0, 0);
  void alg_Ready(void);
  static const TForteInt16 scm_nStateNotReady = 0;
  static const TForteInt16 scm_nStateReady = 1;
  static const TForteInt16 scm_nStateExecuting = 2;

  void enterStateNotReady(void);
  void enterStateReady(void);
  void enterStateExecuting(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L0_CompletedEx(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L0_CompletedEx(){};

};

#endif //close the ifdef sequence from the beginning of the file

