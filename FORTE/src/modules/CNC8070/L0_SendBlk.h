/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_SendBlk
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-08-25/EQUEROL - UJI - null
 *************************************************************************/

#ifndef _L0_SENDBLK_H_
#define _L0_SENDBLK_H_

#include <funcbloc.h>
#include <forte_usint.h>
#include <forte_wstring.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <CNC8070.h>
#include <stdio.h>

class FORTE_L0_SendBlk : public CFunctionBlock, public CCNC8070CommunicationHandler{
  DECLARE_FIRMWARE_FB(FORTE_L0_SendBlk)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_WSTRING &PARAMS() {
    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_STRING &sBlock() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &CNCState() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 3, 2, 0);

virtual void setInitialValues();

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_L0_SendBlk){
  };

  virtual ~FORTE_L0_SendBlk(){};

  //CNC8070COmmunicationHandler methods
  virtual void Log(LOGTYPE a_lType, const char * a_lMsg);
  virtual void OnNotReady();
  virtual void OnReady();
  virtual void OnStarted();
  virtual void OnExecuting();
  virtual void OnInterrupted();
  virtual void OnInterruptedByError();

};

#endif //close the ifdef sequence from the beginning of the file

