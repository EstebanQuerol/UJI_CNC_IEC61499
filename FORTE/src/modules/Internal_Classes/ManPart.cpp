#include "ManPart.h"


ManPart::ManPart(TForteUInt16 pa_nIdentifier) : m_nIdentifier(pa_nIdentifier), m_nAMachine(0), m_nCurrentSetup(1), m_nState(0)
{
}
ManPart::ManPart(const ManPart &pa_oManPart) : m_nIdentifier(pa_oManPart.m_nIdentifier), m_nAMachine(pa_oManPart.m_nAMachine), m_nCurrentSetup(pa_oManPart.m_nCurrentSetup),
m_nState(pa_oManPart.m_nState)
{
}

ManPart::ManPart(){

}

ManPart::~ManPart()
{
}

bool ManPart::IsAssigned(){ 
	return m_nAMachine == 0 ? false : true; 
}