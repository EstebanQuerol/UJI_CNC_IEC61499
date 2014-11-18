/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ASetup
 *** Description: null
 *** Version: 
 *************************************************************************/

#ifndef _L3_ASETUP_H_
#define _L3_ASETUP_H_

#include <adapter.h>
#include <typelib.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_array.h>

class FORTE_L3_ASetup: public CAdapter{
  DECLARE_ADAPTER_TYPE(FORTE_L3_ASetup)

private:
 private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
 public:
  CIEC_UINT *PartInfoS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDI(0) : getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDI(0) : getDO(0));
  };

  CIEC_USINT &ENDID() {
    return *static_cast<CIEC_USINT*>((isSocket()) ? getDI(1) : getDO(1));
  };

 private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
 public:
  CIEC_UINT *PartInfoP() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(0) : getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoP_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(0) : getDI(0));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>((isSocket()) ? getDO(1) : getDI(1));
  };

  CIEC_UINT *OPIDS() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(2) : getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &OPIDS_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(2) : getDI(2));
  };

  CIEC_STRING *OPParams() {
    return (CIEC_STRING*)(*static_cast<CIEC_ARRAY *>((isSocket()) ? getDO(3) : getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &OPParams_Array() {
    return *static_cast<CIEC_ARRAY*>((isSocket()) ? getDO(3) : getDI(3));
  };

  CIEC_STRING &Fixture() {
    return *static_cast<CIEC_STRING*>((isSocket()) ? getDO(4) : getDI(4));
  };

 public:
  static const TEventID scm_nEventCNFID = 0;
  int CNF() {
    return m_nParentAdapterListEventID + scm_nEventCNFID;
  }
  static const TEventID scm_nEventINDID = 1;
  int IND() {
    return m_nParentAdapterListEventID + scm_nEventINDID;
  }
 private:
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

 public:
  static const TEventID scm_nEventREQID = 0;
  int REQ() {
    return m_nParentAdapterListEventID + scm_nEventREQID;
  }
  static const TEventID scm_nEventRSPID = 1;
  int RSP() {
    return m_nParentAdapterListEventID + scm_nEventRSPID;
  }
 private:
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpecSocket;

  static const SFBInterfaceSpec scm_stFBInterfaceSpecPlug;

   FORTE_ADAPTER_DATA_ARRAY(2, 2, 2, 5, 0);

public:
  ADAPTER_CTOR(FORTE_L3_ASetup){
  };

  virtual ~FORTE_L3_ASetup(){};

};

#endif //close the ifdef sequence from the beginning of the file

