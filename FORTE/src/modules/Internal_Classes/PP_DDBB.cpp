#include "PP_DDBB.h"


PP_DDBB::PP_DDBB()
{
}


PP_DDBB::~PP_DDBB()
{
}

void  PP_DDBB::Initilizate(){
	if (!sm_bInitialized){
		sm_bInitialized = true;
		//TODO: Add code to initialize de data base
	}
}

ProcessPlan *  PP_DDBB::getProcessPlan(TForteUInt16 pa_nFamilyID, TForteUInt16 pa_nTypeID){
	ProcessPlan * poRValue = NULL;
	if (sm_bInitialized){
		try{
			poRValue = sm_umapFamilyMap.at(pa_nFamilyID).getProcesPlanByType(pa_nTypeID);
		}
		catch (std::out_of_range e){
			DEVLOG_ERROR("Out of range exception, used an invalid key in the DDBB unorderedmap \n");
			poRValue = NULL;
		}
	}
	return poRValue;
}