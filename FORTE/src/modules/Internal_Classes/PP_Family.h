/*************************************************************************
*** Name: PP_Family
*** Description: Class containing all the process plans of a same family
*** Version: 0
*************************************************************************/

#ifndef _PP_FAMILY_H_
#define _PP_FAMILY_H_
#include <unordered_map>
#include "ProcessPlan.h"
#include "devlog.h"
class PP_Family
{
private:
	std::unordered_map<TForteUInt16, ProcessPlan> m_umapFamilyMap; //Map holding all the process plans of a same family
	TForteUInt16 m_nFamilyID; // Identifier of the family of process plans
public:
	PP_Family();
	~PP_Family();
	/*!\Add a process plan into the family
	* \param	Process plan to be added
	* \param	TypeID of the plan to be added
	* \return	TRUE if success; FALSE otherwise
	*/
	bool addProcessPlan(ProcessPlan pa_oPP, TForteUInt16 pa_nTypeID);
	/*!\Delete a process plan from the family
	* \param	TypeID of the plan to be removed
	* \return	TRUE if success; FALSE otherwise
	*/
	bool delProcessPlan(TForteUInt16 pa_nTypeID);
	/*!\Get a process plan from the family
	* \param	TypeID of the plan to be removed
	* \return	Pointer to the process plan if success; NULL otherwise
	*/
	ProcessPlan * getProcesPlanByType(TForteUInt16 pa_nType_ID);
};
#endif

