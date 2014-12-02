/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineCore
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_MACHINECORE_H_
#define _L2_MACHINECORE_H_

#include <basicfb.h>
#include <forte_time.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_L2_MachineCore: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_MachineCore)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &ServiceState() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  CIEC_UINT *PartInfoIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  CIEC_USINT &ENDOPID() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT &NextOP() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  };

  CIEC_UINT *PartInfoOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_USINT &ENDID() {
    return *static_cast<CIEC_USINT*>(getDO(2));
  };

  CIEC_BOOL &MachineState() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_TIME &Delay() {
    return *static_cast<CIEC_TIME*>(getDO(4));
  };

  static const TEventID scm_nEventUPDTID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRSPID = 2;
  static const TEventID scm_nEventtimeoutID = 3;
  static const TEventID scm_nEventCompletedOPID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventRENEWID = 0;
  static const TEventID scm_nEventNEXTID = 1;
  static const TEventID scm_nEventCNFID = 2;
  static const TEventID scm_nEventINDID = 3;
  static const TEventID scm_nEventFREEID = 4;
  static const TEventID scm_nEventERRORID = 5;
  static const TEventID scm_nEventstartID = 6;
  static const TEventID scm_nEventstopID = 7;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_USINT &State() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  CIEC_UINT &CurrentPart() {
    return *static_cast<CIEC_UINT*>(getVarInternal(1));
  };

  CIEC_UINT &CurrentFamily() {
    return *static_cast<CIEC_UINT*>(getVarInternal(2));
  };

  CIEC_UINT &CurrentType() {
    return *static_cast<CIEC_UINT*>(getVarInternal(3));
  };

  CIEC_BOOL &LostCNF() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(4));
  };

  CIEC_BOOL &isCompleted() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(5));
  };

  CIEC_USINT &CurrentOP() {
    return *static_cast<CIEC_USINT*>(getVarInternal(6));
  };

  CIEC_USINT &MaxOP() {
    return *static_cast<CIEC_USINT*>(getVarInternal(7));
  };

  CIEC_BOOL &inError() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(8));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(8, 3, 5, 9, 0);

virtual void setInitialValues();
  void alg_REQ(void);
  void alg_UPDT(void);
  void alg_NEXT(void);
  void alg_SENDOP(void);
  void alg_CNF(void);
  void alg_NEWREQ(void);
  void alg_DT(void);
  void alg_IND(void);
  void alg_EIE(void);
  void alg_EIW(void);
  static const TForteInt16 scm_nStateNotReady = 0;
  static const TForteInt16 scm_nStateToReady = 1;
  static const TForteInt16 scm_nStateReady = 2;
  static const TForteInt16 scm_nStatetoError = 3;
  static const TForteInt16 scm_nStateREQ = 4;
  static const TForteInt16 scm_nStateExecuting = 5;
  static const TForteInt16 scm_nStateNextOP = 6;
  static const TForteInt16 scm_nStateCompleted = 7;
  static const TForteInt16 scm_nStateSendNext = 8;
  static const TForteInt16 scm_nStateNewREQ = 9;
  static const TForteInt16 scm_nStateLostCNF = 10;
  static const TForteInt16 scm_nStateWAIT = 11;
  static const TForteInt16 scm_nStateRSP = 12;
  static const TForteInt16 scm_nStateErroInExecution = 13;

  void enterStateNotReady(void);
  void enterStateToReady(void);
  void enterStateReady(void);
  void enterStatetoError(void);
  void enterStateREQ(void);
  void enterStateExecuting(void);
  void enterStateNextOP(void);
  void enterStateCompleted(void);
  void enterStateSendNext(void);
  void enterStateNewREQ(void);
  void enterStateLostCNF(void);
  void enterStateWAIT(void);
  void enterStateRSP(void);
  void enterStateErroInExecution(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_MachineCore(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_MachineCore(){};

};

#endif //close the ifdef sequence from the beginning of the file

