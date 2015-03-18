/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_OrderTable
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-09-29/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L3_ORDERTABLE_H_
#define _L3_ORDERTABLE_H_

#include <funcbloc.h>
#include <forte_date_and_time.h>
#include <forte_uint.h>
#include <forte_bool.h>
#include "ManOrder.h"
#include <vector>
class FORTE_L3_OrderTable: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L3_OrderTable)

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

  CIEC_UINT &Lotsize() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_DATE_AND_TIME &DeadlineIn() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(4));
  };

  CIEC_UINT &PartIDS() {
    return *static_cast<CIEC_UINT*>(getDI(5));
  };

  CIEC_UINT &FamilyS() {
    return *static_cast<CIEC_UINT*>(getDI(6));
  };

  CIEC_UINT &TypeS() {
    return *static_cast<CIEC_UINT*>(getDI(7));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_UINT &PartIDP() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_UINT &FamilyP() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  };

  CIEC_UINT &TypeP() {
    return *static_cast<CIEC_UINT*>(getDO(3));
  };

  CIEC_UINT &LotsizeP() {
    return *static_cast<CIEC_UINT*>(getDO(4));
  };

  CIEC_DATE_AND_TIME &DeadlineOut() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDO(5));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventInsertID = 1;
  static const TEventID scm_nEventUpdateID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNF1ID = 1;
  static const TEventID scm_nEventCNF2ID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 8, 6, 0);

  void executeEvent(int pa_nEIID);

  static std::vector<ManOrder> sm_vOrdersTable;
  static UINT sm_nCurrentPartID;
  static UINT sm_nCurrentOrderID;

public:
  FUNCTION_BLOCK_CTOR(FORTE_L3_OrderTable){
  };

  virtual ~FORTE_L3_OrderTable(){};

  /*!\Add a new entry into the order's table
  * \return Closest deadline for the pair Family-Type of the new order
  *	 0xFFFFFFFFFFFFFFFF in case of error
  */
  TForteUInt64 AddEntry(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType, TForteUInt16 pa_nSize, TForteUInt64 pa_nDeadline);

  /*!\Get the closest deadline for a pair Family-Type
  * \return the position in the order's vector of the Order with the closest deadline
  * -1 if no match is found
  */
  int GetCurrentDeadline(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType);

  /*!\Add a completed part to the order table
  * \return Closest deadline for the pair Family-Type of the completed part
  *	 0xFFFFFFFFFFFFFFFF if no more parts of this Family-type need to be done
  */
  TForteUInt64 AddPart(TForteUInt16 pa_nPartID, TForteUInt16 pa_nFamily, TForteUInt16 pa_nType);

};

#endif //close the ifdef sequence from the beginning of the file

