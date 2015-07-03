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
#include "Subphase.h"
#include "iso14649classes.h"
class ProcessPlan
{
private :
	TForteUInt16 m_nNumberOfSubphases;
	TForteUInt16 m_nFamilyID;
	TForteUInt16 m_nTypeID;
	std::vector<Subphase> m_vSubphases;
public:
	ProcessPlan(TForteUInt16 pa_NOS, TForteUInt16 pa_FamilyID, TForteUInt16 pa_TypeID);
	ProcessPlan(const ProcessPlan &pa_PP);
	ProcessPlan();
	~ProcessPlan();
	/*!\Get subphase by index
	* \param pa_nIndex 1-based vector index
	* \return pointer to a workplan 
	*/
	iso14649::workplan * ProcessPlan::getWorkplaneByIndex(TForteUInt16 pa_nIndex);
	/*!\Get the number of subphases in the processplan
	*	Inlined function
	* \return number of subphases
	*/
	TForteUInt16 getNumberOfSubphases(){ return m_nNumberOfSubphases; };
	/*!\Get subphase type by index
	* \param pa_nIndex 1-based vector index
	* \return subphase
	*/
	TForteUInt8 getSubphaseTypeByIndex(TForteUInt16 pa_nIndex);
	/*!\Add a Subphase to the processplan
	* \param pa_nSetupIndex position within the vector where to insert the operation, 1-based index
	* \return true if success, false otherwise
	*/
	bool ProcessPlan::addSubphase(int pa_nSetupIndex, TForteUInt8 pa_nMTypeID, iso14649::workplan * pa_poWorkplan);

};

#endif