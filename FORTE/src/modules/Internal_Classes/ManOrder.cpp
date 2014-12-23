#include "ManOrder.h"


ManOrder::ManOrder(TForteUInt16 pa_nID, TForteUInt16 pa_nFamily, TForteUInt16 pa_nType, TForteUInt16 pa_nSize, TForteUInt64 pa_nDeadline) :
m_nID(pa_nID), m_nFamily(pa_nFamily), m_nType(pa_nType), m_nRemaining(pa_nSize), m_nDeadline(pa_nDeadline) {}

ManOrder::ManOrder(const ManOrder &order) :
m_nID(order.m_nID), m_nFamily(order.m_nFamily), m_nType(order.m_nType), m_nRemaining(order.m_nRemaining), m_nDeadline(order.m_nDeadline){}

ManOrder::~ManOrder()
{
}
