/*************************************************************************
*** Name: ProcessPlan
*** Description: Class containing all the information related with a
***				 manufacturing processplan
*** Version: 0
*************************************************************************/
#ifndef _PROCESSPLAN_H_
#define _PROCESSPLAN_H_
#include <vector>
#include "forte_uint.h"
#include "Setup.h"
class ProcessPlan
{
private :
	TForteUInt16 m_nNumberOfSetups;
	TForteUInt16 m_nFamily;
	TForteUInt16 m_nType;
	std::vector<Setup> m_vSetups;
public:
	ProcessPlan(TForteUInt16 pa_NOS, TForteUInt16 pa_Family, TForteUInt16 pa_Type);
	ProcessPlan(const ProcessPlan &pa_PP);
	ProcessPlan();
	~ProcessPlan();
	/*!\Get setup by index
	* \param pa_nIndex 1-based vector index
	* \return setup 
	*/
	Setup * getSetupByIndex(TForteUInt16 pa_nIndex);
	/*!\Get the number of setups in the processplan
	*	Inlined function
	* \return number of setups
	*/
	TForteUInt16 getNumberOfSetups(){ return m_nNumberOfSetups; };
	/*!\Add a setup to the processplan
	* \param pa_nSetupIndex position within the vector where to insert the operation, 1-based index
	* \param pa_nSize number of operations in the setup
	* \param pa_sFixture setpu's fixture
	* \return true if success, false otherwhise
	*/
	bool addSetup(int pa_nSetupIndex, TForteUInt16 pa_nSize, std::string pa_sFixture);
	/*!\Add a operation to a setup
	* \param pa_nSetupIndex position within the setups vector where to insert the operation, 1-based index
	* \param pa_nOperationIndex position within the operation vector  where to insert the operation, 1-based index
	* \param pa_nOID operation identifier
	* \param pa_sPArams operation parameters
	* \return true if success, false otherwhise
	*/
	bool addOperation(int pa_nSetupIndex, int pa_nOperationIndex, TForteUInt16 pa_nOPID, std::string pa_sParams);
};

#endif