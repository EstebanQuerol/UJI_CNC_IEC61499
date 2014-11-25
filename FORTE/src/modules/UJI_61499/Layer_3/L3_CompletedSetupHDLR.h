/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_CompletedSetupHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-03/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_COMPLETEDSETUPHDLR_H_
#define _L3_COMPLETEDSETUPHDLR_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L3_CompletedSetupHDLR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_CompletedSetupHDLR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &PartIDIn() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  static const TEventID scm_nEventREQ1ID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNF1ID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT *PartBuffer() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartBuffer_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(0));
  };

  CIEC_USINT &TailIndex() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  CIEC_USINT &HeadIndex() {
    return *static_cast<CIEC_USINT*>(getVarInternal(2));
  };

  CIEC_USINT &BufferSize() {
    return *static_cast<CIEC_USINT*>(getVarInternal(3));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 4, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_REQ1(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateREQ1 = 2;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateREQ1(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_CompletedSetupHDLR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_CompletedSetupHDLR(){};

};

#endif //close the ifdef sequence from the beginning of the file

