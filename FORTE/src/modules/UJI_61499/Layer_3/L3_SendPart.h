/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SendPart
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_SENDPART_H_
#define _L3_SENDPART_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_time.h>
#include <forte_uint.h>

class FORTE_L3_SendPart: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_SendPart)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &PartIDIn() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &FamilyIn() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &TypeIn() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &LotsizeIn() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_DATE_AND_TIME &DeadlineIn() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_TIME &TimeoutDT() {
    return *static_cast<CIEC_TIME*>(getDO(0));
  };

  CIEC_UINT &PartIDP() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &FamilyP() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &TypeP() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_UINT &LotsizeP() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  CIEC_DATE_AND_TIME &DeadlineP() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(5));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventRSPID = 1;
  static const TEventID scm_nEventTimeoutID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TEventID scm_nEventStartID = 2;
  static const TEventID scm_nEventStopID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 5, 6, 0, 0);
  void alg_REQ(void);
  void alg_TO(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateSENDING = 2;
  static const TForteInt16 scm_nStateTimeOut = 3;
  static const TForteInt16 scm_nStateSTOPTIMER = 4;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateSENDING(void);
  void enterStateTimeOut(void);
  void enterStateSTOPTIMER(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_SendPart(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_SendPart(){};

};

#endif //close the ifdef sequence from the beginning of the file

