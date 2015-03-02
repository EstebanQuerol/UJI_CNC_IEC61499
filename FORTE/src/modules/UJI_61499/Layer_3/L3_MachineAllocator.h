/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineAllocator
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_MACHINEALLOCATOR_H_
#define _L3_MACHINEALLOCATOR_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_bool.h>
#include <forte_time.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L3_MachineAllocator: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_MachineAllocator)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT *MFinalAssignIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_UINT *PartIDIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartIDIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  CIEC_USINT *SetupIDIn() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &SetupIDIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_USINT &SetupID() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDO(2));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(3));
  };

  CIEC_UINT *MFinalAssignOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(4));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventREQ2ID = 1;
  static const TEventID scm_nEventRSP2ID = 2;
  static const TEventID scm_nEventRSP1ID = 3;
  static const TEventID scm_nEventTimeoutID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventIND2ID = 1;
  static const TEventID scm_nEventIND1ID = 2;
  static const TEventID scm_nEventStartID = 3;
  static const TEventID scm_nEventStopID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &AssignRemaining() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  CIEC_UINT *IFinalAssign() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &IFinalAssign_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(2));
  };

  CIEC_UINT &CurrentPartID() {
    return *static_cast<CIEC_UINT*>(getVarInternal(3));
  };

  CIEC_USINT &CurrentSetupID() {
    return *static_cast<CIEC_USINT*>(getVarInternal(4));
  };

  CIEC_USINT &TOCounter() {
    return *static_cast<CIEC_USINT*>(getVarInternal(5));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(5, 3, 5, 6, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_SETTO(void);
  void alg_PREREQ(void);
  void alg_NM(void);
  void alg_SEND(void);
  void alg_RSP1(void);
  void alg_TO(void);
  void alg_FAILED(void);
  void alg_RSP2(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateREQ2 = 2;
  static const TForteInt16 scm_nStateSEND = 3;
  static const TForteInt16 scm_nStatePREREQ = 4;
  static const TForteInt16 scm_nStateNOMACHINE = 5;
  static const TForteInt16 scm_nStateWAIT = 6;
  static const TForteInt16 scm_nStateRSP1 = 7;
  static const TForteInt16 scm_nStateTIMEOUT = 8;
  static const TForteInt16 scm_nStateFAILED = 9;
  static const TForteInt16 scm_nStateRSP2 = 10;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateREQ2(void);
  void enterStateSEND(void);
  void enterStatePREREQ(void);
  void enterStateNOMACHINE(void);
  void enterStateWAIT(void);
  void enterStateRSP1(void);
  void enterStateTIMEOUT(void);
  void enterStateFAILED(void);
  void enterStateRSP2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_MachineAllocator(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_MachineAllocator(){};

};

#endif //close the ifdef sequence from the beginning of the file

