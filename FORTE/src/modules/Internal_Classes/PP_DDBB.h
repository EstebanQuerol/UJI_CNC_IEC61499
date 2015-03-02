/*************************************************************************
*** Name: PP_DDBB
*** Description: Class containing all the process plans used by the 
***				 manufacturing system
*** Version: 0
*************************************************************************/
#ifndef _PP_DDBB_H_
#define _PP_BBDD_H_
#include <unordered_map>
#include "PP_Family.h"
#include "ProcessPlan.h"
#include "forte_uint.h"

class PP_DDBB
{
private:
	static std::unordered_map<TForteUInt16, PP_Family> sm_umapFamilyMap; //Map holding all the process plans families
	static bool sm_bInitialized; //Initialization flag

public:
	PP_DDBB();
	~PP_DDBB();
	/*!\Initialize the process plan array
	*/
	static void  Initilizate();

	/*!\Get a pointer to a process plan in the DDBB by family and type
	* \param pa_nFamily process plan family
	* \param pa_nType process plan type
	* \return pointer to the target PP
	*/
	static  ProcessPlan * getProcessPlan(TForteUInt16 pa_nFamilyID, TForteUInt16 pa_nTypeID);

};

#endif