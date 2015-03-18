/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PartDesEncap
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-09-24/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_PARTDESENCAP_H_
#define _L3_PARTDESENCAP_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>
#include "L3_APart.h"

class FORTE_L3_PartDesEncap: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_PartDesEncap)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &PartIDS() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &FamilyS() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &TypeS() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &PartIDP() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_UINT &FamilyP() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &TypeP() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &Lotsize() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_DATE_AND_TIME &Deadline() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(4));
  };

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  FORTE_L3_APart& L3_APart() {
    return (*static_cast<FORTE_L3_APart*>(m_apoAdapters[0]));
  };
  static const int scm_nL3_APartAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 3, 5, 0, 1);
  void alg_REQ(void);
  void alg_RSP(void);
  void alg_IND(void);
  void alg_CNF(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateRSP = 2;
  static const TForteInt16 scm_nStateCNF = 3;
  static const TForteInt16 scm_nStateIND = 4;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateRSP(void);
  void enterStateCNF(void);
  void enterStateIND(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_PartDesEncap(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_PartDesEncap(){};

};

#endif //close the ifdef sequence from the beginning of the file

