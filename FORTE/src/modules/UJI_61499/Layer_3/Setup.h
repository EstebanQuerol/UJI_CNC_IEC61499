/*************************************************************************
*** Name: Operation
*** Description: Class containing all the information related with a
***				 manufacturing setup
*** Version: 0
*************************************************************************/
#ifndef _SETUP_H_
#define _SETUP_H_

#include <forte_uint.h>
#include <vector>
#include "Operation.h"
#include <string>
class Setup
{
private :
	TForteUInt16 m_nSize; //Number of operations in the setup
	std::vector<Operation> m_vOperations; //Vector holding all the operations of the setup
	std::string m_sFixture; //String with the setup fixture information
public:
	Setup(TForteUInt16 pa_size, std::string pa_fixture);
	Setup(const Setup &pa_setup);
	~Setup();
	/*!\Get setup size
	*	Inlined function
	* \return setup size
	*/
	TForteUInt16 getSetupSize(){ return m_nSize; };
	/*!\Get setup operation by index
	* \param pa_nIndex 1-based vector index
	* \return operation
	*/
	Operation * getOperationByIndex(int pa_nIndex);
	/*!\Get setup fixture
	*	Inlined function
	* \return setup fixture
	*/
	std::string getFixture(){ return m_sFixture; };
	/*!\Add a operation to the setup
	* \param pa_nOID operation identifier
	* \param pa_sPArams operation parameters
	* \param pa_nIndex position within the operation vector where to insert the operation, 1-based index
	* \return true if success, false otherwhise
	*/
	bool addOperation(int pa_nIndex, TForteUInt16 pa_nOPID, std::string pa_sParams);
};
#endif
