/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ReceivePart
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_RECEIVEPART_H_
#define _L3_RECEIVEPART_H_

#include <basicfb.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_L3_ReceivePart: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_ReceivePart)

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

  CIEC_DATE_AND_TIME &Deadline() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_UINT &FamilyOut() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &TypeOut() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &FamilyS() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_UINT &TypeS() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  CIEC_DATE_AND_TIME &DeadlineS() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(5));
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

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT &CurrentID() {
    return *static_cast<CIEC_UINT*>(getVarInternal(0));
  };

  CIEC_UINT &CurrentFamily() {
    return *static_cast<CIEC_UINT*>(getVarInternal(1));
  };

  CIEC_UINT &CurrentType() {
    return *static_cast<CIEC_UINT*>(getVarInternal(2));
  };

  CIEC_BOOL &LostIND() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(3));
  };

  CIEC_UINT *CompletedIDS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &CompletedIDS_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(4));
  };

  CIEC_UINT *CompletedFamilies() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(5)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &CompletedFamilies_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(5));
  };

  CIEC_UINT *CompletedTypes() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(6)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &CompletedTypes_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(6));
  };

  CIEC_DATE_AND_TIME *CompletedDeadlines() {
    return (CIEC_DATE_AND_TIME*)(*static_cast<CIEC_ARRAY *>(getVarInternal(7)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &CompletedDeadlines_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(7));
  };

  CIEC_UINT &Index() {
    return *static_cast<CIEC_UINT*>(getVarInternal(8));
  };

  CIEC_UINT &i() {
    return *static_cast<CIEC_UINT*>(getVarInternal(9));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 6, 10, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_HDL(void);
  void alg_RSP(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateREQUESTING = 2;
  static const TForteInt16 scm_nStateREQHANDLER = 3;
  static const TForteInt16 scm_nStateLOSTIND = 4;
  static const TForteInt16 scm_nStateRSP = 5;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateREQUESTING(void);
  void enterStateREQHANDLER(void);
  void enterStateLOSTIND(void);
  void enterStateRSP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_ReceivePart(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_ReceivePart(){};

};

#endif //close the ifdef sequence from the beginning of the file

