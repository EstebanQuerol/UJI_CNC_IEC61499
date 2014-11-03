#include "ProcessPlan.h"


ProcessPlan::ProcessPlan(TForteUInt16 pa_NOS, TForteUInt16 pa_Family, TForteUInt16 pa_Type) : 
	m_nNumberOfSetups(pa_NOS), m_nFamily(pa_Family), m_nType(pa_Type), m_vSetups(pa_NOS,Setup(0,""))
{
}
ProcessPlan::ProcessPlan(const ProcessPlan &pa_PP) : 
m_nNumberOfSetups(pa_PP.m_nNumberOfSetups), m_nFamily(pa_PP.m_nFamily), m_nType(pa_PP.m_nType), m_vSetups(pa_PP.m_nNumberOfSetups, Setup(0, ""))
{
}
ProcessPlan::ProcessPlan() : 
	m_nNumberOfSetups(0), m_nFamily(0), m_nType(0), m_vSetups(0, Setup(0, ""))
{

}
ProcessPlan::~ProcessPlan()
{
}
Setup * ProcessPlan::getSetupByIndex(TForteUInt16 pa_nIndex)
{
	if (pa_nIndex >= 1 && pa_nIndex <= m_nNumberOfSetups){
		return &m_vSetups[pa_nIndex - 1];
	}
	return  NULL;
}
bool ProcessPlan::addSetup(int pa_nSetupIndex, TForteUInt16 pa_nSize, std::string pa_sFixture)
{
	if (pa_nSetupIndex >= 1 && pa_nSetupIndex <= m_nNumberOfSetups){
		m_vSetups[pa_nSetupIndex - 1] = Setup(pa_nSize, pa_sFixture);
		return true;
	}
	return false;
}
bool ProcessPlan::addOperation(int pa_nSetupIndex, int pa_nOperationIndex, TForteUInt16 pa_nOPID, std::string pa_sParams)
{
	if (pa_nSetupIndex >= 1 && pa_nSetupIndex <= m_nNumberOfSetups){
		m_vSetups[pa_nSetupIndex - 1].addOperation(pa_nOperationIndex, pa_nOPID, pa_sParams);
		return true;
	}
	return false;
}
