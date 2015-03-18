/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ReleasedMHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_RELEASEDMHDLR_H_
#define _L3_RELEASEDMHDLR_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_array.h>

class FORTE_L3_ReleasedMHDLR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_ReleasedMHDLR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT *MReleased() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MReleased_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(0));
  };

  static const TEventID scm_nEventREQ1ID = 0;
  static const TEventID scm_nEventREQ2ID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT *ReleasedMachines() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &ReleasedMachines_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(0));
  };

  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 1, 2, 0);

virtual void setInitialValues();
  void alg_REQ2(void);
  void alg_REQ1(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ2 = 1;
  static const TForteInt16 scm_nStateREQ1 = 2;

  void enterStateSTART(void);
  void enterStateREQ2(void);
  void enterStateREQ1(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_ReleasedMHDLR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_ReleasedMHDLR(){};

};

#endif //close the ifdef sequence from the beginning of the file

