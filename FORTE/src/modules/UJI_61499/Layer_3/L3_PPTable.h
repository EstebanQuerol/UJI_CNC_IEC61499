/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_PPTable
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-11-06/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_PPTABLE_H_
#define _L3_PPTABLE_H_

#include <funcbloc.h>
#include <forte_date_and_time.h>
#include <forte_usint.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include <forte_array.h>
#include <unordered_map>
#include "ManPart.h"
#include "ProcessPlan.h"
#include "PP_DDBB.h"

class FORTE_L3_PPTable: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L3_PPTable)

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

  CIEC_USINT *MType() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDI(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &MType_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(3));
  };

  CIEC_UINT &PartIDIn1() {
    return *static_cast<CIEC_UINT*>(getDI(4));
  };

  CIEC_UINT &LotsizeIn() {
    return *static_cast<CIEC_UINT*>(getDI(5));
  };

  CIEC_DATE_AND_TIME &DeadlineIn1() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(6));
  };

  CIEC_UINT &PartIDIn2() {
    return *static_cast<CIEC_UINT*>(getDI(7));
  };

  CIEC_DATE_AND_TIME &DeadlineIn2() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(8));
  };

  CIEC_UINT &PartIDIn3() {
    return *static_cast<CIEC_UINT*>(getDI(9));
  };

  CIEC_USINT &MID() {
    return *static_cast<CIEC_USINT*>(getDI(10));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_UINT *vPartIDOut() {
    return (CIEC_UINT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &vPartIDOut_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_INT *vPriority() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &vPriority_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(2));
  };

  CIEC_USINT *vSetup() {
    return (CIEC_USINT*)(*static_cast<CIEC_ARRAY *>(getDO(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &vSetup_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(3));
  };

  CIEC_UINT &PartIDOut() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventREQ2ID = 2;
  static const TEventID scm_nEventRSP1ID = 3;
  static const TEventID scm_nEventRSP2ID = 4;
  static const TEventID scm_nEventRSP3ID = 5;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventCNF2ID = 2;
  static const TEventID scm_nEventIND1ID = 3;
  static const TEventID scm_nEventIND2ID = 4;
  static const TEventID scm_nEventIND3ID = 5;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  std::unordered_map<TForteUInt16, ManPart> m_Partmap;
  TForteInt16 m_nNOS; //Number of setups
  CIEC_DATE_AND_TIME m_dtCurrentDeadline; 
  CIEC_INT m_nCurrentPriority;
  TForteUInt16 m_anSendBuffer[15]; //Buffer to hold completed parts
  TForteUInt8 m_nPartsToSend;
  ProcessPlan * m_poThisPP; //Pointer to the current process plan 


   FORTE_FB_DATA_ARRAY(6, 11, 5, 0);

  void executeEvent(int pa_nEIID);
  /*!\Insert a new part into the process plan table
  * \param Identifier of the 1st part to be inserted
  * \param Number of parts to be inserted
  */
  void InsertPart(TForteUInt16 pa_nPartID, TForteUInt16 pa_nlotsize);
  /*!\Update the state of a part whose setup is completed
  * \param Identifier of the part to be updated
  */
  void AddSetup(TForteUInt16 pa_nPartID);
  /*!\Update the state of the assigned part 
  * \param Identifier of the part to be updated
  * \param Identifier of the machine that received the part
  */
  void UpdatePartState(TForteUInt16 pa_nPartID, TForteUInt8 pa_nMID);
  /*!\Calculate the needed machines vector
  */
  void FORTE_L3_PPTable::RequestNeededMachines();
  /*!\Calculate the Process plan parts priority
  */
  void FORTE_L3_PPTable::CalculatePriority();

public:
  FUNCTION_BLOCK_CTOR(FORTE_L3_PPTable){
	  m_nNOS = 0;
	  m_dtCurrentDeadline = CIEC_DATE_AND_TIME(0xFFFFFFFFFFFFFFFF);
	  for (int i = 0; i < 15; i++){
		  m_anSendBuffer[i] = 0;
	  }
	  m_nPartsToSend = 0;
	  m_poThisPP = NULL;
  };

  virtual ~FORTE_L3_PPTable(){};

};

#endif //close the ifdef sequence from the beginning of the file

