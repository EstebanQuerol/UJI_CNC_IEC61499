/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CM_Merge2PartInfo
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _CM_MERGE2PARTINFO_H_
#define _CM_MERGE2PARTINFO_H_

#include <basicfb.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_CM_Merge2PartInfo: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CM_Merge2PartInfo)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT *PartInfo1() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfo1_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_UINT *PartInfo2() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfo2_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT *PartInfoOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(0));
  };

  static const TEventID scm_nEventREQ1ID = 0;
  static const TEventID scm_nEventREQ2ID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNF1ID = 0;
  static const TEventID scm_nEventCNF2ID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 1, 0, 0);
  void alg_REQ1(void);
  void alg_REQ2(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ1 = 1;
  static const TForteInt16 scm_nStateREQ2 = 2;

  void enterStateSTART(void);
  void enterStateREQ1(void);
  void enterStateREQ2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CM_Merge2PartInfo(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CM_Merge2PartInfo(){};

};

#endif //close the ifdef sequence from the beginning of the file

