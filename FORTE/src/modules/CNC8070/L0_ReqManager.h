/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_ReqManager
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - 
 ***     1.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L0_REQMANAGER_H_
#define _L0_REQMANAGER_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_usint.h>

class FORTE_L0_ReqManager: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L0_ReqManager)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &RIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_USINT &ServiceState() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &ENDOPID() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventUPDTID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TEventID scm_nEventCompletedID = 2;
  static const TEventID scm_nEventCNFID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &ExecutionRequested() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(4, 3, 2, 1, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_UPDT(void);
  static const TForteInt16 scm_nStateIDLE = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStateExecutionRequested = 3;
  static const TForteInt16 scm_nStateExecutionDone = 4;
  static const TForteInt16 scm_nStateServiceDown = 5;
  static const TForteInt16 scm_nStateStartExecution = 6;
  static const TForteInt16 scm_nStateLostIND = 7;

  void enterStateIDLE(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateExecutionRequested(void);
  void enterStateExecutionDone(void);
  void enterStateServiceDown(void);
  void enterStateStartExecution(void);
  void enterStateLostIND(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L0_ReqManager(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L0_ReqManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

