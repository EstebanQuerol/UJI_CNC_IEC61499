/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SetupRouterT
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-19/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _L3_SETUPROUTERT_H_
#define _L3_SETUPROUTERT_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include "L3_ASetup.h"

class FORTE_L3_SetupRouterT: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_SetupRouterT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &SelType() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  CIEC_BOOL &Select() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(1));
  };

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_ASetup& ASetupC() {
    return (*static_cast<FORTE_L3_ASetup*>(m_apoAdapters[0]));
  };
  static const int scm_nASetupCAdpNum = 0;
  FORTE_L3_ASetup& ASetup1() {
    return (*static_cast<FORTE_L3_ASetup*>(m_apoAdapters[1]));
  };
  static const int scm_nASetup1AdpNum = 1;
  FORTE_L3_ASetup& ASetup2() {
    return (*static_cast<FORTE_L3_ASetup*>(m_apoAdapters[2]));
  };
  static const int scm_nASetup2AdpNum = 2;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 0, 2, 3);
  void alg_REQ1(void);
  void alg_REQ2(void);
  void alg_RSP1(void);
  void alg_RSP2(void);
  void alg_CNF(void);
  void alg_IND(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ1 = 2;
  static const TForteInt16 scm_nStateREQ2 = 3;
  static const TForteInt16 scm_nStateRSP1 = 4;
  static const TForteInt16 scm_nStateRSP2 = 5;
  static const TForteInt16 scm_nStateCNF = 6;
  static const TForteInt16 scm_nStateCNF1 = 7;
  static const TForteInt16 scm_nStateCNF2 = 8;
  static const TForteInt16 scm_nStateIND = 9;
  static const TForteInt16 scm_nStateIND1 = 10;
  static const TForteInt16 scm_nStateIND2 = 11;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ1(void);
  void enterStateREQ2(void);
  void enterStateRSP1(void);
  void enterStateRSP2(void);
  void enterStateCNF(void);
  void enterStateCNF1(void);
  void enterStateCNF2(void);
  void enterStateIND(void);
  void enterStateIND1(void);
  void enterStateIND2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_SetupRouterT(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_SetupRouterT(){};

};

#endif //close the ifdef sequence from the beginning of the file

