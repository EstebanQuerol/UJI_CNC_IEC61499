/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_APart
 *** Description: null
 *** Version: 
 *************************************************************************/

#ifndef _L3_APART_H_
#define _L3_APART_H_

#include <adapter.h>
#include <typelib.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>

class FORTE_L3_APart: public CAdapter{
  DECLARE_ADAPTER_TYPE(FORTE_L3_APart)

private:
 private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
 public:
  CIEC_UINT &PartIDS() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDI(0) : getDO(0));
  };

  CIEC_UINT &FamilyS() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDI(1) : getDO(1));
  };

  CIEC_UINT &TypeS() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDI(2) : getDO(2));
  };

 private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
 public:
  CIEC_UINT &PartIDP() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDO(0) : getDI(0));
  };

  CIEC_UINT &FamilyP() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDO(1) : getDI(1));
  };

  CIEC_UINT &TypeP() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDO(2) : getDI(2));
  };

  CIEC_UINT &Lotsize() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDO(3) : getDI(3));
  };

  CIEC_DATE_AND_TIME &Deadline() {
    return *static_cast<CIEC_DATE_AND_TIME*>((isSocket()) ? getDO(4) : getDI(4));
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

   FORTE_ADAPTER_DATA_ARRAY(2, 2, 3, 5, 0);

public:
  ADAPTER_CTOR(FORTE_L3_APart){
  };

  virtual ~FORTE_L3_APart(){};

};

#endif //close the ifdef sequence from the beginning of the file

