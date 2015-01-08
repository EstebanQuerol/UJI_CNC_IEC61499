/*************************************************************************
*** Name: Subphase
*** Description: Class containing all the information related with a
***				 manufacturing subphase
*** Version: 0
*************************************************************************/
#ifndef _SUBPHASE_H_
#define _SUBPHASE_H_

#include <forte_uint.h>
#include <vector>
#include "Operation.h"
#include <string>
#include "iso14649classes.h"
class Subphase
{
private :
	TForteUInt8 m_nMTypeID; //Type of the machine needed to execute the Subphase
	workplan * m_poWorkplan; //Workplan to be executed in this subphase
public:
	Subphase(TForteUInt8 pa_nMTypeID,workplan * pa_poWorkplan);
	Subphase(const Subphase &pa_Subphase);
	Subphase::Subphase();
	~Subphase();
	/*!\Get Subphase Type
	*	Inlined function
	* \return Subphase size
	*/
	TForteUInt8 getSubphaseType(){ return m_nMTypeID; };
	/*!\Get the workplan of the subphase
	*	Inlined function
	* \return Subphase size
	*/
	workplan * getWorkplan(){ return m_poWorkplan; };
};
#endif
