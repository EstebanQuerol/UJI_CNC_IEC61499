/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MMCore
 *** Description: Machine manager core
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_MMCORE_H_
#define _L3_MMCORE_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_L3_MMCore: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_MMCore)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT *MReleased() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MReleased_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  CIEC_USINT *MFaulty() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFaulty_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(2));
  };

  CIEC_UINT *MAssignS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignS_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(3));
  };

  CIEC_UINT *MFinalAssignS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignS_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT *MStateP() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MStateP_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_INT *MPriority() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MPriority_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(2));
  };

  CIEC_UINT *MAssignP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignP_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(3));
  };

  CIEC_UINT *MFinalAssignP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignP_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(4));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventRSP1ID = 1;
  static const TEventID scm_nEventRSP2ID = 2;
  static const TEventID scm_nEventRSP3ID = 3;
  static const TEventID scm_nEventRSP4ID = 4;
  static const TEventID scm_nEventTimeOutID = 5;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventIND1ID = 1;
  static const TEventID scm_nEventIND2ID = 2;
  static const TEventID scm_nEventIND3ID = 3;
  static const TEventID scm_nEventIND4ID = 4;
  static const TEventID scm_nEventStartID = 5;
  static const TEventID scm_nEventStopID = 6;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT *MState() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MState_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(0));
  };

  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  CIEC_USINT &MachineCounter() {
    return *static_cast<CIEC_USINT*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(7, 5, 5, 3, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_RSP1(void);
  void alg_RSP2(void);
  void alg_RSP3(void);
  void alg_RSP4(void);
  void alg_UINIT(void);
  void alg_IND3(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateSTEP1 = 2;
  static const TForteInt16 scm_nStateRSP1 = 3;
  static const TForteInt16 scm_nStateNOFREEMACHINE = 4;
  static const TForteInt16 scm_nStateRSP2 = 5;
  static const TForteInt16 scm_nStateFREEMACHINE = 6;
  static const TForteInt16 scm_nStateRSP3 = 7;
  static const TForteInt16 scm_nStateRSP4 = 8;
  static const TForteInt16 scm_nStateSTARTTIMER = 9;
  static const TForteInt16 scm_nStateSTOPTIMER = 10;
  static const TForteInt16 scm_nStateMACHINESTOBEASSIGNED = 11;
  static const TForteInt16 scm_nStateNONEEDEDMACHINE = 12;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateSTEP1(void);
  void enterStateRSP1(void);
  void enterStateNOFREEMACHINE(void);
  void enterStateRSP2(void);
  void enterStateFREEMACHINE(void);
  void enterStateRSP3(void);
  void enterStateRSP4(void);
  void enterStateSTARTTIMER(void);
  void enterStateSTOPTIMER(void);
  void enterStateMACHINESTOBEASSIGNED(void);
  void enterStateNONEEDEDMACHINE(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_MMCore(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_MMCore(){};

};

#endif //close the ifdef sequence from the beginning of the file

