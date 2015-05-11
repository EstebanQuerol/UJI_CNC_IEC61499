#include "PP_Family.h"


PP_Family::PP_Family() : m_nFamilyID()
{
}

PP_Family::PP_Family(TForteUInt16 nFamilyID) : m_nFamilyID(nFamilyID)
{
}


PP_Family::~PP_Family()
{
}

bool PP_Family::addProcessPlan(ProcessPlan pa_oPP, TForteUInt16 pa_nTypeID){
	//TODO: check if the already exist an PP with the same TypeID
	bool bRValue = true;
	try{
		m_umapFamilyMap.emplace(pa_nTypeID, pa_oPP);
	}
	catch (std::bad_alloc e){
		DEVLOG_ERROR("Allocation failure, unable to insert a process plan in the DDBB \n");
		bRValue = false;
	}
	return bRValue;
}
bool PP_Family::delProcessPlan(TForteUInt16 pa_nTypeID){
	if (m_umapFamilyMap.erase(pa_nTypeID) == 0){
		// Nothing was removed
		return false;
	}
	return true;
}
ProcessPlan * PP_Family::getProcesPlanByType(TForteUInt16 pa_nType_ID){
	ProcessPlan * poRValue;
	try{
		poRValue = &m_umapFamilyMap.at(pa_nType_ID);

	}
	catch (std::out_of_range e){
		DEVLOG_ERROR("Out of range exception, used an invalid key in the Family unorderedmap \n");
		poRValue = NULL;
	}
	return poRValue;
}