/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_Adapter
 *** Description: null
 *** Version: 
 *************************************************************************/

#ifndef _T1_ADAPTER_H_
#define _T1_ADAPTER_H_

#include <adapter.h>
#include <typelib.h>
#include <forte_string.h>

class FORTE_T1_Adapter: public CAdapter{
  DECLARE_ADAPTER_TYPE(FORTE_T1_Adapter)

private:
 private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
 public:
  CIEC_STRING &REQD() {
    return *static_cast<CIEC_STRING*>((isSocket()) ? getDI(0) : getDO(0));
  };

  CIEC_STRING &RSPD() {
    return *static_cast<CIEC_STRING*>((isSocket()) ? getDI(1) : getDO(1));
  };

 private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
 public:
  CIEC_STRING &CNFD() {
    return *static_cast<CIEC_STRING*>((isSocket()) ? getDO(0) : getDI(0));
  };

  CIEC_STRING &INDD() {
    return *static_cast<CIEC_STRING*>((isSocket()) ? getDO(1) : getDI(1));
  };

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
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

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
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpecSocket;

  static const SFBInterfaceSpec scm_stFBInterfaceSpecPlug;

   FORTE_ADAPTER_DATA_ARRAY(2, 2, 2, 2, 0);

public:
  ADAPTER_CTOR(FORTE_T1_Adapter){
  };

  virtual ~FORTE_T1_Adapter(){};

};

#endif //close the ifdef sequence from the beginning of the file

