/*************************************************************************
*** Name: ManOrder
*** Description: Class containing all the information related with a
***				 manufacturing order
*** Version: 0
*************************************************************************/
#ifndef _MANORDER_H_
#define _MANORDER_H_
#include <forte_uint.h>

class ManOrder
{
public:
	ManOrder(TForteUInt16 pa_nID, TForteUInt16 pa_nFamily, TForteUInt16 pa_nType, TForteUInt16 pa_nSize, TForteUInt64 pa_nDeadline);
	ManOrder(const ManOrder &order);
	~ManOrder();

	/*!\Add a completed part to the order
	*	Inlined function
	* \return number of remaining parts to complete the order
	*/
	TForteInt16 ManOrder::AddPart(){
		return --m_nRemaining;
	}
	/*!\Get order family
	*	Inlined function
	* \return order family
	*/
	TForteInt16 getFamily(){return m_nFamily; }
	/*!\Get order Type
	*	Inlined function
	* \return order Type
	*/
	TForteInt16 getType(){return m_nType; }
	/*!\Get order Deadline
	*	Inlined function
	* \return order Deadline
	*/
	TForteUInt64 getDeadline(){return m_nDeadline; }

private:
	TForteUInt16 m_nID; //Order identifier
	TForteUInt16 m_nFamily; //Family of ordered parts
	TForteUInt16 m_nType;//Type of ordered parts
	TForteUInt16 m_nRemaining;//Parts still to be manufactured
	TForteUInt64 m_nDeadline;//Order delivery time
};
#endif

