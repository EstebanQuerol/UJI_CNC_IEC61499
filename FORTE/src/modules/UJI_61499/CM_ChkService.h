/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_ChkService
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-04/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _CM_CHKSERVICE_H_
#define _CM_CHKSERVICE_H_

#include <basicfb.h>
#include <forte_usint.h>

class FORTE_CM_ChkService: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CM_ChkService)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &ServiceState() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQSID = 0;
  static const TEventID scm_nEventUPID = 1;
  static const TEventID scm_nEventDOWNID = 2;
  static const TEventID scm_nEventBUSYID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 1, 0, 0, 0);
  void alg_INIT(void);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateUP = 2;
  static const TForteInt16 scm_nStateDOWN = 3;
  static const TForteInt16 scm_nStateBUSY = 4;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateUP(void);
  void enterStateDOWN(void);
  void enterStateBUSY(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CM_ChkService(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CM_ChkService(){};

};

#endif //close the ifdef sequence from the beginning of the file

