/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_NewPartHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-04/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_NEWPARTHDLR_H_
#define _L3_NEWPARTHDLR_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L3_NewPartHDLR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_NewPartHDLR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &PartIDIn() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &LotsizeIn() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_DATE_AND_TIME &DeadlineIn() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_UINT &LotsizeOut() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_DATE_AND_TIME &DeadlineOut() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(2));
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

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT *PartBuffer() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartBuffer_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(0));
  };

  CIEC_UINT *SizesBuffer() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &SizesBuffer_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(1));
  };

  CIEC_DATE_AND_TIME *DeadlinesBuffer() {
    return (CIEC_DATE_AND_TIME*)(*static_cast<CIEC_ARRAY *>(getVarInternal(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &DeadlinesBuffer_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(2));
  };

  CIEC_USINT &HeadIndex() {
    return *static_cast<CIEC_USINT*>(getVarInternal(3));
  };

  CIEC_USINT &TailIndex() {
    return *static_cast<CIEC_USINT*>(getVarInternal(4));
  };

  CIEC_USINT &BufferSize() {
    return *static_cast<CIEC_USINT*>(getVarInternal(5));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 3, 3, 6, 0);

virtual void setInitialValues();
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
  FORTE_L3_NewPartHDLR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_NewPartHDLR(){};

};

#endif //close the ifdef sequence from the beginning of the file

