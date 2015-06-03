#include "ProcessPlan.h"


ProcessPlan::ProcessPlan(TForteUInt16 pa_NOS, TForteUInt16 pa_FamilyID, TForteUInt16 pa_TypeID) : 
	m_nNumberOfSubphases(pa_NOS), m_nFamilyID(pa_FamilyID), m_nTypeID(pa_TypeID)
{
	m_vSubphases.resize(pa_NOS);
}
ProcessPlan::ProcessPlan(const ProcessPlan &pa_PP) : 
	m_nNumberOfSubphases(pa_PP.m_nNumberOfSubphases), m_nFamilyID(pa_PP.m_nFamilyID), m_nTypeID(pa_PP.m_nTypeID)
{
	m_vSubphases = pa_PP.m_vSubphases;
}
ProcessPlan::ProcessPlan() 
{

}
ProcessPlan::~ProcessPlan()
{
}
iso14649::workplan * ProcessPlan::getWorkplaneByIndex(TForteUInt16 pa_nIndex)
{
	if (pa_nIndex >= 1 && pa_nIndex <= m_nNumberOfSubphases){
		return m_vSubphases[pa_nIndex - 1].getWorkplan();
	}
	return  NULL;
}
TForteUInt8 ProcessPlan::getSubphaseTypeByIndex(TForteUInt16 pa_nIndex){
	if (pa_nIndex >= 1 && pa_nIndex <= m_nNumberOfSubphases){
		return m_vSubphases[pa_nIndex - 1].getSubphaseType();
	}
	return  0;
}
bool ProcessPlan::addSubphase(int pa_nSetupIndex, TForteUInt8 pa_nMTypeID, iso14649::workplan * pa_poWorkplan)
{
	if (pa_nSetupIndex >= 1 && pa_nSetupIndex <= m_nNumberOfSubphases){
		m_vSubphases[pa_nSetupIndex - 1] = Subphase(pa_nMTypeID, pa_poWorkplan);
		return true;
	}
	return false;
}

