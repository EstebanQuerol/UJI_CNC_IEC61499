/*************************************************************************
*** Name: Operation
*** Description: Class containing all the information related with a
***				 manufacturing operation
*** Version: 0
*************************************************************************/
#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <forte_uint.h>
#include <string>

class Operation
{
private: 
	TForteUInt16 m_nIdentifier;
	std::string m_sParameters;
public:
	Operation(TForteUInt16 pa_nID, std::string pa_sParams);
	Operation(const Operation &pa_oper);
	~Operation();
	/*!\Get operation identifier
	*	Inlined function
	* \return operation identifier
	*/
	TForteUInt16 getIdentifier(){ return m_nIdentifier; };
	/*!\Get operation parameters
	*	Inlined function
	* \return operation parameters
	*/
	std::string getParameters(){ return m_sParameters; };
};

#endif

