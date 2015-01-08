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

#include "L3_PPTable.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_PPTable_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_PPTable, g_nStringIdL3_PPTable)

const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamily, g_nStringIdType, g_nStringIdMType, g_nStringIdPartIDIn1, g_nStringIdLotsizeIn, g_nStringIdDeadlineIn1, g_nStringIdPartIDIn2, g_nStringIdDeadlineIn2, g_nStringIdPartIDIn3, g_nStringIdMID};

const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME, g_nStringIdUINT, g_nStringIdDATE_AND_TIME, g_nStringIdUINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdvPartIDOut, g_nStringIdvPriority, g_nStringIdvSetup, g_nStringIdPartIDOut};

const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdUINT};

const TForteInt16 FORTE_L3_PPTable::scm_anEIWithIndexes[] = {0, 4, 6, 9, 13, 15};
const TDataIOID FORTE_L3_PPTable::scm_anEIWith[] = {0, 1, 2, 255, 3, 255, 10, 9, 255, 4, 5, 6, 255, 7, 255, 8, 255};
const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdREQ2, g_nStringIdRSP1, g_nStringIdRSP2, g_nStringIdRSP3};

const TDataIOID FORTE_L3_PPTable::scm_anEOWith[] = {0, 255, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_L3_PPTable::scm_anEOWithIndexes[] = {0, 2, -1, -1, -1, 6, -1};
const CStringDictionary::TStringId FORTE_L3_PPTable::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdCNF2, g_nStringIdIND1, g_nStringIdIND2, g_nStringIdIND3};

const SFBInterfaceSpec FORTE_L3_PPTable::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  6,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L3_PPTable::InsertPart(TForteUInt16 pa_nPartID, TForteUInt16 pa_nlotsize){
	int nPartID = pa_nPartID;
	int i = 0;
	for (; i < pa_nlotsize;i++ ){
		try{
			m_Partmap.emplace(nPartID, ManPart(nPartID));
			nPartID++;
			//TODO verify if the insertion succed
		}
		catch (std::bad_alloc e){
			DEVLOG_ERROR("Allocation failure, unable to insert a part into a PPTable \n");
		}
	}
}

void FORTE_L3_PPTable::AddSetup(TForteUInt16 pa_nPartID){
	ManPart oauxPart;
	TForteUInt8 CurrentSetup = 0;
	try{
		oauxPart = m_Partmap.at(pa_nPartID);
		if (oauxPart.IsAssigned()){
			CurrentSetup = oauxPart.GetSetup();
			if (++CurrentSetup > m_nNOS){
				//The part is completed
				m_anSendBuffer[m_nPartsToSend++] = pa_nPartID;
				m_Partmap.erase(pa_nPartID);
				//TODO add protection for array access
			}
			else{
				oauxPart.SetSetup(CurrentSetup);
			}
			oauxPart.UnAssignMachine();
		}
		else{
			DEVLOG_ERROR("Completed setup of non-assigned Part - ERROR\n");
		}
	}
	catch (std::out_of_range e){
		DEVLOG_ERROR("Out of range exception, used an invalid key in the PPTable unorderedmap \n");
	}
}

void FORTE_L3_PPTable::UpdatePartState(TForteUInt16 pa_nPartID, TForteUInt8 pa_nMID){
	ManPart oauxPart = ManPart();
	try{
		oauxPart = m_Partmap.at(pa_nPartID);
		if (oauxPart.IsAssigned()){
			DEVLOG_ERROR("The part is already assigned - ERROR\n");
		}
		else{
			oauxPart.AssignMachine(pa_nMID);
		}
	}
	catch (std::out_of_range e){
		DEVLOG_ERROR("Out of range exception, used an invalid key in the PPTable unorderedmap \n");
	}
}

void FORTE_L3_PPTable::RequestNeededMachines(){
	int i = 0;
	//Update the current priority
	CalculatePriority();
	//clean the output vectors
	for (i = 0; i < 15; i++){
		vPartIDOut()[i] = 0;
		vSetup()[i] = 0;
		vPriority()[i] = 0;
	}
	for (std::unordered_map<TForteUInt16, ManPart>::iterator it = m_Partmap.begin(); it != m_Partmap.end(); ++it){
		if (!it->second.IsAssigned()){
			for (i = 0; i < 15; i++){
				if (MType()[i] > 0 && m_poThisPP->getSubphaseTypeByIndex(it->second.GetSetup()) == MType()[i]){
					//Machine i is needed
					vPartIDOut()[i] = it->second.GetPartID();
					vSetup()[i] = it->second.GetSetup();
					vPriority()[i] = m_nCurrentPriority;
				}
			}
		}
	}
}

void FORTE_L3_PPTable::CalculatePriority(){
	CIEC_DATE_AND_TIME dtCurrentTime;
	TForteUInt64 nAuxUint64;
	dtCurrentTime.setCurrentTime();
	if (dtCurrentTime >= m_dtCurrentDeadline){
		nAuxUint64 = (((TForteUInt64)dtCurrentTime - (TForteUInt64)m_dtCurrentDeadline) / 1000) / 60;
		if (nAuxUint64 > 32766){
			m_nCurrentPriority = - 32766;
		}
		else{
			m_nCurrentPriority = -1 * nAuxUint64;
		}
	}
	else{
		nAuxUint64 = -1 * ((((TForteUInt64)m_dtCurrentDeadline - (TForteUInt64)dtCurrentTime) / 1000) / 60);
		if (nAuxUint64 > 32766){
			m_nCurrentPriority = 32766;
		}
		else{
			m_nCurrentPriority = nAuxUint64;
		}
	}
	
}

void FORTE_L3_PPTable::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventINITID:
		if (!m_Partmap.empty()){
			//Clear the map if it is not empty
			m_Partmap.clear();
		}
		if (QI()){
			PP_DDBB::Initilizate();
			m_poThisPP = PP_DDBB::getProcessPlan(Family(), Type());
			if (m_poThisPP != NULL){
				m_nNOS = m_poThisPP->getNumberOfSubphases();
				QO() = TRUE;
			}
			else{
				DEVLOG_DEBUG("Failed to retrieve the Process plan for the specified family and type\n");
				QO() = FALSE;
			}
		}
		else{
			QO() = FALSE;
		}
		sendOutputEvent(scm_nEventINITOID);
		break;

	case scm_nEventREQID:
		//Request if any NewPart arrived since last REQ event
		sendOutputEvent(scm_nEventIND1ID);
		break;

	case scm_nEventREQ2ID:
		//Mark the input part as assigned
		UpdatePartState(PartIDIn3(),MID());
		sendOutputEvent(scm_nEventCNF2ID);
		break;

	case scm_nEventRSP1ID:
		if (PartIDIn1() != 0){
			//New parts arrived, insert them
			InsertPart(PartIDIn1(), LotsizeIn());
			//Update parts deadline
			m_dtCurrentDeadline = DeadlineIn1();
			//Request more parts
			sendOutputEvent(scm_nEventIND1ID);
		}
		else{
			//No new parts, continue the REQ event execution
			sendOutputEvent(scm_nEventIND2ID);
		}
		break;

	case scm_nEventRSP2ID:
		if (PartIDIn2() != 0){
			//a completed setup needs to be handled
			AddSetup(PartIDIn2());
			//Keep requesting for completed setups
			sendOutputEvent(scm_nEventIND2ID);
		}
		else{
			if (m_nPartsToSend > 0){
				//Send completed parts
				PartIDOut() = m_anSendBuffer[--m_nPartsToSend];
				sendOutputEvent(scm_nEventIND3ID);
			}
			else{
				//Calculate priorities and send CNF
				RequestNeededMachines();
				sendOutputEvent(scm_nEventCNFID);
			}
		}
		break;

	case scm_nEventRSP3ID:
		if (m_nPartsToSend > 0){
			//Send completed parts
			PartIDOut() = m_anSendBuffer[--m_nPartsToSend];
			sendOutputEvent(scm_nEventIND3ID);
		}
		else{
			//Calculate priorities and send CNF
			RequestNeededMachines();
			sendOutputEvent(scm_nEventCNFID);
		}
		break;
	}
}




