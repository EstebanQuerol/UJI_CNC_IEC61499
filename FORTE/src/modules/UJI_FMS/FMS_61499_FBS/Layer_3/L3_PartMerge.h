/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PartMerge
 *** Description: Part adapter encapculation
 *** Version: 
 ***     0.0: 2014-09-24/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_PARTMERGE_H_
#define _L3_PARTMERGE_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>

class FORTE_L3_PartMerge: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_PartMerge)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &PartIDP1() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &FamilyP1() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &TypeP1() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &Lotsize1() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_DATE_AND_TIME &Deadline1() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(4));
  };

  CIEC_UINT &FamilyP2() {
    return *static_cast<CIEC_UINT*>(getDI(5));
  };

  CIEC_UINT &TypeP2() {
    return *static_cast<CIEC_UINT*>(getDI(6));
  };

  CIEC_DATE_AND_TIME &Deadline2() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(7));
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

  static const TEventID scm_nEventREQINID = 0;
  static const TEventID scm_nEventRSPINID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQOUTID = 0;
  static const TEventID scm_nEventRSPOUTID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 8, 5, 0, 0);
  void alg_REQ(void);
  void alg_RSP(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateRSP = 2;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateRSP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_PartMerge(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_PartMerge(){};

};

#endif //close the ifdef sequence from the beginning of the file

