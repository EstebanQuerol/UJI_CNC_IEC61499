#include "Setup.h"


Setup::Setup(TForteUInt8 pa_nType, TForteUInt16 pa_size, std::string pa_fixture) : m_nType(pa_nType), m_nSize(pa_size), m_sFixture(pa_fixture), m_vOperations(pa_size, Operation(0, ""))
{
}

Setup::Setup(const Setup &pa_setup) : m_nType(pa_setup.m_nType), m_nSize(pa_setup.m_nSize), m_sFixture(pa_setup.m_sFixture), m_vOperations(pa_setup.m_nSize, Operation(0, ""))
{
}

Setup::~Setup()
{
}

bool Setup::addOperation(int pa_nIndex, TForteUInt16 pa_nOPID, std::string pa_sParams)
{
	if (pa_nIndex >= 1 && pa_nIndex <= m_nSize){
		m_vOperations[pa_nIndex - 1] = Operation(pa_nOPID, pa_sParams);
		return true;
	}
	return false;
}

Operation * Setup::getOperationByIndex(int pa_nIndex)
{
	if (pa_nIndex >= 1 && pa_nIndex <= m_nSize){
		 return &m_vOperations[pa_nIndex - 1];
	}
	return NULL;
}
