/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_ASetupREQHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 ***     1.0: 2016-01-18/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_ASETUPREQHDLR_H_
#define _L2_ASETUPREQHDLR_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_L2_ASetupREQHDLR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_L2_ASetupREQHDLR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_UINT *PartInfoIn() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDI(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoIn_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(2));
  };

  CIEC_STRING &SetupIn() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &MIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  CIEC_UINT *PartInfoOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfoOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(2));
  };

  CIEC_STRING &SetupOut() {
    return *static_cast<CIEC_STRING*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &Accepted() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  CIEC_USINT &i() {
    return *static_cast<CIEC_USINT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 4, 2, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateIDLE = 1;
  static const TForteInt16 scm_nStateINIT = 2;
  static const TForteInt16 scm_nStateREQ = 3;
  static const TForteInt16 scm_nStateAcceptPacket = 4;
  static const TForteInt16 scm_nStateRejectPacket = 5;

  void enterStateSTART(void);
  void enterStateIDLE(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateAcceptPacket(void);
  void enterStateRejectPacket(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_L2_ASetupREQHDLR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_L2_ASetupREQHDLR(){};

};

#endif //close the ifdef sequence from the beginning of the file

