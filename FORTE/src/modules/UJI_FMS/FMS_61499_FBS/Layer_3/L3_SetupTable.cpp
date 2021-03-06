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

#include "L3_SetupTable.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_SetupTable_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_SetupTable, g_nStringIdL3_SetupTable)

const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamily, g_nStringIdType, g_nStringIdPartID, g_nStringIdSetupID, g_nStringIdMID};

const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdPartInfo, g_nStringIdSetup};

const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdSTRING};

const TForteInt16 FORTE_L3_SetupTable::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_L3_SetupTable::scm_anEIWith[] = {0, 1, 2, 255, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L3_SetupTable::scm_anEOWith[] = {0, 255, 1, 2, 255};
const TForteInt16 FORTE_L3_SetupTable::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L3_SetupTable::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L3_SetupTable::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L3_SetupTable::executeEvent(int pa_nEIID){
	switch (pa_nEIID){
	case scm_nEventINITID:
		if (QI() == true){
			m_nFamily = Family();
			m_nType = Type();
			PP_DDBB::Initilizate();
			m_poThisPP = PP_DDBB::getProcessPlan(m_nFamily, m_nType);
			if (m_poThisPP != NULL){
				QO() = true;
			}
			else{
				//Failed to retrieve the Process plan for the specified family and type 
				QO() = false;
			}
		}
		else{
			QO() = false;
		}
		sendOutputEvent(scm_nEventINITOID);
		break;
	case scm_nEventREQID:
		//Map destination machine
		PartInfo()[0] = PartID();
		PartInfo()[1] = m_nFamily;
		PartInfo()[2] = m_nType;
		PartInfo()[3] = MID();
		//Get a pointer to the requested Setup
		if (m_poThisPP != NULL){
			m_poCurrentSetup = m_poThisPP->getWorkplaneByIndex(SetupID());
			if (m_poCurrentSetup != NULL){
				//Boost Serialization
				std::ostringstream oss;
				boost::archive::text_oarchive oa(oss);
				oa << m_poCurrentSetup;
				Setup() = oss.str().c_str();
			}
			else{
				//Invalid setup requested, mark setup as invalid
				PartInfo()[1] = 0;
				PartInfo()[2] = 0;
				Setup() = "NULL";
			}
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	}
}
