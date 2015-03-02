#ifndef _MANPART_H_
#define _MANPART_H_
#include "forte_uint.h"
class ManPart
{
private :
	TForteUInt16 m_nIdentifier; //Part identifier
	TForteUInt8 m_nAMachine; //Machine to which the part is assigned, 0 if not assigned
	TForteUInt8 m_nCurrentSetup; //Part's current setup
	TForteUInt8 m_nState; //Part current state
public:
	ManPart();
	ManPart(TForteUInt16 pa_nIdentifier);
	ManPart(const ManPart &pa_oManPart);
	~ManPart();
	/*!\Assignate a machine to the part
	*	Inlined function
	*/
	void AssignMachine(TForteUInt8 pa_nMID){ m_nAMachine = pa_nMID; };
	/*!\Remove the assignation of a part
	*	Inlined function
	*/
	void UnAssignMachine(){ m_nAMachine = 0; };
	/*!\Check if the part is assigned to a machine
	* \return false if part is not assigned; true if it is
	*/
	bool IsAssigned();
	/*!\Get the part current setup
	*	Inlined function
	* \return current setup ID
	*/
	TForteUInt8 GetSetup(){ return m_nCurrentSetup; };
	/*!\Set the part current setup
	*	Inlined function
	*/
	void SetSetup(TForteUInt8 pa_nSetup){ m_nCurrentSetup = pa_nSetup; };
	/*!\Get the part identifier
	*	Inlined function
	* \return Part Identifier
	*/
	TForteUInt16 GetPartID(){ return m_nIdentifier; };

};
#endif

