/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_MachineState
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-01-18/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_MACHINESTATE_H_
#define _L2_MACHINESTATE_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L2_MachineState: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_MachineState)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &EXT_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &M_INIT_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_STRING &M_INIT_STATE() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_UINT *CURRENT_PARTINFO() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &CURRENT_PARTINFO_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(3));
  };

  CIEC_BOOL &M_ERROR_STATE() {
    return *static_cast<CIEC_BOOL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &MUI_STATE() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &MUI_MSG() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_UINT &MUI_PART_ID() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &MUI_PART_FAMILY() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_UINT &MUI_PART_TYPE() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  CIEC_BOOL &M_INIT_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(5));
  };

  CIEC_BOOL &ERROR_STATE() {
    return *static_cast<CIEC_BOOL*>(getDO(6));
  };

  static const TEventID scm_nEventEXT_INITID = 0;
  static const TEventID scm_nEventM_INIT_RSPID = 1;
  static const TEventID scm_nEventM_BUSYID = 2;
  static const TEventID scm_nEventM_FREEID = 3;
  static const TEventID scm_nEventM_ERRORID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventMUI_INDID = 0;
  static const TEventID scm_nEventM_INITID = 1;
  static const TEventID scm_nEventFREEID = 2;
  static const TEventID scm_nEventERRORID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &initRequested() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(4, 5, 7, 1, 0);

virtual void setInitialValues();
  void alg_INIT_START(void);
  void alg_INIT_END(void);
  void alg_IDLE_ENTER(void);
  void alg_ERROR_ENTER(void);
  void alg_DINIT_START(void);
  void alg_ENTER_HALT(void);
  void alg_DINIT_END(void);
  void alg_ENTER_BUSY(void);
  void alg_ERROR_KO(void);
  void alg_HOLD_INIT(void);
  void alg_TO_FREE(void);
  void alg_ERROR_OK(void);
  void alg_TO_BUSY(void);
  void alg_TO_DINIT(void);
  static const TForteInt16 scm_nStateHALT = 0;
  static const TForteInt16 scm_nStateDESINITIALIZING = 1;
  static const TForteInt16 scm_nStateIDLE = 2;
  static const TForteInt16 scm_nStateBUSY = 3;
  static const TForteInt16 scm_nStateERROR = 4;
  static const TForteInt16 scm_nStateINITIALIZING_COMPLETE = 5;
  static const TForteInt16 scm_nStateINITIALIZING_START = 6;
  static const TForteInt16 scm_nStateDINIT_COMPLETE = 7;
  static const TForteInt16 scm_nStateSEND_FREE = 8;
  static const TForteInt16 scm_nStateERROR_OK = 9;
  static const TForteInt16 scm_nStateERROR_KO = 10;
  static const TForteInt16 scm_nStateHOLD_INIT = 11;
  static const TForteInt16 scm_nStateTO_BUSY = 12;
  static const TForteInt16 scm_nStateTO_DINIT = 13;

  void enterStateHALT(void);
  void enterStateDESINITIALIZING(void);
  void enterStateIDLE(void);
  void enterStateBUSY(void);
  void enterStateERROR(void);
  void enterStateINITIALIZING_COMPLETE(void);
  void enterStateINITIALIZING_START(void);
  void enterStateDINIT_COMPLETE(void);
  void enterStateSEND_FREE(void);
  void enterStateERROR_OK(void);
  void enterStateERROR_KO(void);
  void enterStateHOLD_INIT(void);
  void enterStateTO_BUSY(void);
  void enterStateTO_DINIT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_MachineState(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_MachineState(){};

};

#endif //close the ifdef sequence from the beginning of the file

