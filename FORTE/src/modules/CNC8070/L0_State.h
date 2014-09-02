/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_State
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-08-25/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _L0_STATE_H_
#define _L0_STATE_H_

#include <basicfb.h>
#include <forte_usint.h>

class FORTE_L0_State: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L0_State)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &StateIn() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT &StateOut() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  };

  CIEC_USINT &ServiceState() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventUPDTID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventUPDTOID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT &CNCState() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  CIEC_USINT &CurrentServiceState() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 1, 2, 2, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_UPDT(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStateUPDT = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateUPDT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L0_State(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L0_State(){};

};

#endif //close the ifdef sequence from the beginning of the file

