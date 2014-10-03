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

#include "L3_OrderTable.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_OrderTable_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_OrderTable, g_nStringIdL3_OrderTable)

const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamily, g_nStringIdType, g_nStringIdLotsize, g_nStringIdDeadlineIn, g_nStringIdPartIDS, g_nStringIdFamilyS, g_nStringIdTypeS};

const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdPartIDP, g_nStringIdFamilyP, g_nStringIdTypeP, g_nStringIdLotsizeP, g_nStringIdDeadlineOut};

const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_OrderTable::scm_anEIWithIndexes[] = {0, 2, 7};
const TDataIOID FORTE_L3_OrderTable::scm_anEIWith[] = {0, 255, 1, 2, 3, 4, 255, 5, 6, 7, 255};
const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdInsert, g_nStringIdUpdate};

const TDataIOID FORTE_L3_OrderTable::scm_anEOWith[] = {0, 255, 1, 2, 3, 4, 5, 255, 5, 255};
const TForteInt16 FORTE_L3_OrderTable::scm_anEOWithIndexes[] = {0, 2, 8, -1};
const CStringDictionary::TStringId FORTE_L3_OrderTable::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF1, g_nStringIdCNF2};

const SFBInterfaceSpec FORTE_L3_OrderTable::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  6,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

std::vector<ManOrder> FORTE_L3_OrderTable::sm_vOrdersTable = std::vector<ManOrder>();
UINT FORTE_L3_OrderTable::sm_nCurrentPartID = 1;
UINT FORTE_L3_OrderTable::sm_nCurrentOrderID = 1;


void FORTE_L3_OrderTable::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		if (QI()){
			//Initialize the OrderTable to default value
			if (!sm_vOrdersTable.empty()){
				sm_vOrdersTable.swap(std::vector<ManOrder>());
			}
		}
		else{
			//Empty the vector
			sm_vOrdersTable.swap(std::vector<ManOrder>());
		}
      sendOutputEvent(scm_nEventINITOID);
      break;

    case scm_nEventInsertID:
		DeadlineOut() = AddEntry(Family(), Type(), Lotsize(), DeadlineIn());
		PartIDP() = sm_nCurrentPartID;
		FamilyP() = Family();
		TypeP() = Type();
		LotsizeP() = Lotsize();
		sm_nCurrentPartID += Lotsize();
		sendOutputEvent(scm_nEventCNF1ID);
      break;

    case scm_nEventUpdateID:
		DeadlineOut() = AddPart(PartIDS(), FamilyS(), TypeS());
		sendOutputEvent(scm_nEventCNF2ID);
      break;
  }
}

TForteUInt64 FORTE_L3_OrderTable::AddEntry(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType, TForteUInt16 pa_nSize, TForteUInt64 pa_nDeadline){
	int nIndex = 0;
	ManOrder neworder = ManOrder(sm_nCurrentOrderID++, pa_nFamily, pa_nType, pa_nSize, pa_nDeadline);
	try{
		sm_vOrdersTable.push_back(neworder);
	}
	catch (std::bad_alloc){
		DEVLOG_ERROR("Memory Allocation failure when inserting an entry into the order's table\n");
		return 0xFFFFFFFFFFFFFFFF;
	}
	nIndex = GetCurrentDeadline(pa_nFamily, pa_nType);
	if (nIndex < 0){
		return 0xFFFFFFFFFFFFFFFF;
	}
	return sm_vOrdersTable[nIndex].getDeadline();
}

int FORTE_L3_OrderTable::GetCurrentDeadline(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType){
	int nIndex = 0;
	int nRetValue = -1;
	TForteUInt64 nCurrentDeadline = 0xFFFFFFFFFFFFFFFF;
	for (std::vector<ManOrder>::iterator it = sm_vOrdersTable.begin(); it != sm_vOrdersTable.end();++it){
		if (it->getFamily() == pa_nFamily && it->getType() == pa_nType && it->getDeadline() < nCurrentDeadline){
			nRetValue = nIndex;
			nCurrentDeadline = it->getDeadline();
		}
		nIndex++;
	}
	return nRetValue;
}

TForteUInt64 FORTE_L3_OrderTable::AddPart(TForteUInt16 pa_nPartID, TForteUInt16 pa_nFamily, TForteUInt16 pa_nType){
	int nIndex = 0;
	nIndex = GetCurrentDeadline(pa_nFamily, pa_nType);
	if (nIndex >= 0){
		if (sm_vOrdersTable[nIndex].AddPart() <= 0){
			//Closest order of this type is complted
			sm_vOrdersTable.erase(sm_vOrdersTable.begin() + nIndex);

			//Get closest deadline for next order with the same pair Family-Type
			nIndex = GetCurrentDeadline(pa_nFamily, pa_nType);
			if (nIndex < 0){
				return 0xFFFFFFFFFFFFFFFF;
			}
			
		}
		return sm_vOrdersTable[nIndex].getDeadline();
	}
	DEVLOG_DEBUG("Completed part doesn't match any active order\n");
	return 0xFFFFFFFFFFFFFFFF;
}


