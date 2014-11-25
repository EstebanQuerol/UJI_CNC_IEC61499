/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_CompletedPartHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-04/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_COMPLETEDPARTHDLR_H_
#define _L3_COMPLETEDPARTHDLR_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_time.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_L3_CompletedPartHDLR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_CompletedPartHDLR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_UINT &FamilyIn() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &TypeIn() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &PartIDIn() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_DATE_AND_TIME &DeadlineIn() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &FamilyOut() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &TypeOut() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(4));
  };

  CIEC_DATE_AND_TIME &DeadlineOut() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(5));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRSPID = 2;
  static const TEventID scm_nEventTimeoutID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TEventID scm_nEventStartID = 3;
  static const TEventID scm_nEventStopID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(5, 5, 6, 0, 0);
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_RSP(void);
  void alg_TO(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStateRSP = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateRSP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_CompletedPartHDLR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_CompletedPartHDLR(){};

};

#endif //close the ifdef sequence from the beginning of the file

