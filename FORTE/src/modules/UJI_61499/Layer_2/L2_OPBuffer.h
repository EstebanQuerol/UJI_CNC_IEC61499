/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_OPBuffer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_OPBUFFER_H_
#define _L2_OPBUFFER_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_array.h>

class FORTE_L2_OPBuffer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_OPBuffer)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT *OPIDIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &OPIDIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_STRING *OPParamsIn() {
    return (CIEC_STRING*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &OPParamsIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  CIEC_STRING &FixtureIn() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_USINT &NextOP() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &OPIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_STRING &OPParamsOut() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_STRING &FixtureOut() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  static const TEventID scm_nEventRENEWID = 0;
  static const TEventID scm_nEventNEXTID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNF0ID = 0;
  static const TEventID scm_nEventCNF1ID = 1;
  static const TEventID scm_nEventCNF2ID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(3, 4, 3, 0, 0);

virtual void setInitialValues();
  void alg_SetFixture(void);
  void alg_SetOP(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateRENEW = 1;
  static const TForteInt16 scm_nStateSetFixture = 2;
  static const TForteInt16 scm_nStateSetOP = 3;

  void enterStateSTART(void);
  void enterStateRENEW(void);
  void enterStateSetFixture(void);
  void enterStateSetOP(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_OPBuffer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_OPBuffer(){};

};

#endif //close the ifdef sequence from the beginning of the file

