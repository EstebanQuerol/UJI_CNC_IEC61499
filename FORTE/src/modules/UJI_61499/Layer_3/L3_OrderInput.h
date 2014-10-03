/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_OrderInput
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_ORDERINPUT_H_
#define _L3_ORDERINPUT_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>

class FORTE_L3_OrderInput: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_OrderInput)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &FamilyIn() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &TypeIn() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &LotsizeIn() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_DATE_AND_TIME &DeadlineIn() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &FamilyOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_UINT &TypeOut() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &LotsizeOut() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_DATE_AND_TIME &DeadlineOut() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(3));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 4, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStatePROCESSING = 2;
  static const TForteInt16 scm_nStateRSP = 3;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStatePROCESSING(void);
  void enterStateRSP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_OrderInput(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_OrderInput(){};

};

#endif //close the ifdef sequence from the beginning of the file

