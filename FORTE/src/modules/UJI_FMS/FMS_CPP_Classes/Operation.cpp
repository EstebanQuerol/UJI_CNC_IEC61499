#include "Operation.h"


Operation::Operation(TForteUInt16 pa_nID, std::string pa_sParams) : m_nIdentifier(pa_nID), m_sParameters(pa_sParams)
{
}

Operation::Operation(const Operation &pa_oper) : m_nIdentifier(pa_oper.m_nIdentifier), m_sParameters(pa_oper.m_sParameters)
{
}

Operation::~Operation()
{
}
