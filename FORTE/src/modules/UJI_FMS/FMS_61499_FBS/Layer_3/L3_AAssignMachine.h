/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_AAssignMachine
 *** Description: null
 *** Version: 
 *************************************************************************/

#ifndef _L3_AASSIGNMACHINE_H_
#define _L3_AASSIGNMACHINE_H_

#include <adapter.h>
#include <typelib.h>
#include <forte_usint.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L3_AAssignMachine: public CAdapter{
  DECLARE_ADAPTER_TYPE(FORTE_L3_AAssignMachine)

private:
 private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
 public:
  CIEC_USINT *MTypeS() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(0) : getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MTypeS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(0) : getDO(0));
  };

  CIEC_USINT *MStateS() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(1) : getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MStateS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(1) : getDO(1));
  };

  CIEC_INT *MPriorityS() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(2) : getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MPriorityS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(2) : getDO(2));
  };

  CIEC_UINT *MAssignS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(3) : getDO(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(3) : getDO(3));
  };

  CIEC_UINT *MFinalAssignS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(4) : getDO(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(4) : getDO(4));
  };

 private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
 public:
  CIEC_USINT *MTypeP() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(0) : getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MTypeP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(0) : getDI(0));
  };

  CIEC_USINT *MStateP() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(1) : getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MStateP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(1) : getDI(1));
  };

  CIEC_INT *MPriorityP() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(2) : getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MPriorityP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(2) : getDI(2));
  };

  CIEC_UINT *MAssignP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(3) : getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MAssignP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(3) : getDI(3));
  };

  CIEC_UINT *MFinalAssignP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(4) : getDI(4)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MFinalAssignP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(4) : getDI(4));
  };

 public:
  static const TEventID scm_nEventCNF1ID = 0;
  int CNF1() {
    return m_nParentAdapterListEventID + scm_nEventCNF1ID;
  }
  static const TEventID scm_nEventCNF2ID = 1;
  int CNF2() {
    return m_nParentAdapterListEventID + scm_nEventCNF2ID;
  }
 private:
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

 public:
  static const TEventID scm_nEventCHKID = 0;
  int CHK() {
    return m_nParentAdapterListEventID + scm_nEventCHKID;
  }
  static const TEventID scm_nEventASGID = 1;
  int ASG() {
    return m_nParentAdapterListEventID + scm_nEventASGID;
  }
 private:
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpecSocket;

  static const SFBInterfaceSpec scm_stFBInterfaceSpecPlug;

   FORTE_ADAPTER_DATA_ARRAY(2, 2, 5, 5, 0);

public:
  ADAPTER_CTOR(FORTE_L3_AAssignMachine){
  };

  virtual ~FORTE_L3_AAssignMachine(){};

};

#endif //close the ifdef sequence from the beginning of the file

