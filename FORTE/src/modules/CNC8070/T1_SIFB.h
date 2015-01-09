/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_SIFB
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _T1_SIFB_H_
#define _T1_SIFB_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_wstring.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <CNC8070.h>
#include "stdio.h"

class FORTE_T1_SIFB : public CFunctionBlock, public CCNC8070CommunicationHandler{
  DECLARE_FIRMWARE_FB(FORTE_T1_SIFB)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_WSTRING &PARAMS() {
    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_STRING &SD() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_WSTRING &STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  };

  CIEC_INT &RD() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRSPID = 2;
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

   FORTE_FB_DATA_ARRAY(3, 3, 3, 0);

virtual void setInitialValues();

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_T1_SIFB){
  };

  virtual ~FORTE_T1_SIFB(){};

  //Metodos provinientes deCNC8070COmmunicationHandler
  virtual void Log(LOGTYPE a_lType, const char * a_lMsg);
  virtual void OnNotReady();
  virtual void OnReady();
  virtual void OnStarted();
  virtual void OnExecuting();
  virtual void OnInterrupted();
  virtual void OnInterruptedByError();
  virtual void OnMagazineUpdate(long pa_lITool);

};

#endif //close the ifdef sequence from the beginning of the file

