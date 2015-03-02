/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineChecker
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_MACHINECHECKER_H_
#define _L3_MACHINECHECKER_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_L3_MachineChecker: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L3_MachineChecker)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT *MTypeIn() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MTypeIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_USINT *MStateIn() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MStateIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  CIEC_INT *MPriorityIn() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MPriorityIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(2));
  };

  CIEC_UINT *MAssignIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(3));
  };

  CIEC_INT *Priority() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDI(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &Priority_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(4));
  };

  CIEC_UINT *PartID() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(5)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartID_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_USINT *MTypeOut() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MTypeOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(0));
  };

  CIEC_USINT *MStateOut() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MStateOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_INT *MPriorityOut() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MPriorityOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(2));
  };

  CIEC_UINT *MAssignOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(3));
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
  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 6, 4, 1, 0);

virtual void setInitialValues();
  void alg_RSP(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateRSP = 2;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateRSP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L3_MachineChecker(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L3_MachineChecker(){};

};

#endif //close the ifdef sequence from the beginning of the file

