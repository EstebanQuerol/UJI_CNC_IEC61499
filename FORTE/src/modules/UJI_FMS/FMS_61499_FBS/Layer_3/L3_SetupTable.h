/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_SetupTable
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-10-28/EQUEROL - UJI - 
 ***     1.0: 2015-01-08/EQUEROL - UJI - modified data outputs
 *************************************************************************/

#ifndef _L3_SETUPTABLE_H_
#define _L3_SETUPTABLE_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>
#include <forte_uint.h>
#include <forte_array.h>
#include "ProcessPlan.h"
#include "PP_DDBB.h"
#include "Subphase.h"
#include <sstream>
#include "boost/archive/text_oarchive.hpp"

class FORTE_L3_SetupTable : public CFunctionBlock{
	DECLARE_FIRMWARE_FB(FORTE_L3_SetupTable)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_UINT &Family() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &Type() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &PartID() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_USINT &SetupID() {
    return *static_cast<CIEC_USINT*>(getDI(4));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_UINT *PartInfo() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &PartInfo_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_STRING &Setup() {
    return *static_cast<CIEC_STRING*>(getDO(2));
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

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 6, 3, 0);

  void executeEvent(int pa_nEIID);

  TForteUInt16 m_nFamily; //Process plan family
  TForteUInt16 m_nType; //Process plan type
  ProcessPlan * m_poThisPP; // Pointer to the PP of each Setuptable instance
  workplan * m_poCurrentSetup; //Pointer to the current subphase

public:
	FUNCTION_BLOCK_CTOR(FORTE_L3_SetupTable){
		m_nFamily = 0;
		m_nType = 0;
		m_poThisPP = NULL;
		m_poCurrentSetup = NULL;
	};

  virtual ~FORTE_L3_SetupTable(){};

};

#endif //close the ifdef sequence from the beginning of the file

