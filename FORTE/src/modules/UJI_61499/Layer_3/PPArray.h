/*************************************************************************
*** Name: PPArray
*** Description: Class used to hold all the process plans that can be used
***					by the manufacturing cell
*** Version: 0
*************************************************************************/
#ifndef _PPARRAY_H
#define _PPARRAY_H
#include "forte_uint.h"
#include "ProcessPlan.h"
class PPArray
{
private:
	static const TForteUInt16 scm_nFamilyMax = 5; //Number of families that the array can hold
	static const TForteUInt16 scm_nTypeMax = 5; //Number of types in each family that the array can hold
	static ProcessPlan sm_aPParray[scm_nFamilyMax][scm_nTypeMax]; //Array holding all the process plans
	static bool sm_bInitialized; //Initialization flag
public:
	PPArray();
	~PPArray();
	/*!\Initialize the process plan array
	*/
	static void  Initilizate();
	/*!\Get a pointer to a process plan from the array by family and type
	* \param pa_nFamily Process plan family
	* \param pa_nType process plan type
	* \return pointer to the target PP
	*/
	static ProcessPlan * getProcessPlan(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType);
};
#endif

