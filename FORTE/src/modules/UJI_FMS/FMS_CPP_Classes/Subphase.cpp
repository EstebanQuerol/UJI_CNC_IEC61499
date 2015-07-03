#include "Subphase.h"


Subphase::Subphase(TForteUInt8 pa_nMTypeID, iso14649::workplan * pa_poWorkplan) : m_nMTypeID(pa_nMTypeID)
{
	m_poWorkplan = pa_poWorkplan;
}

Subphase::Subphase(const Subphase &pa_subphase) : m_nMTypeID(pa_subphase.m_nMTypeID){
	m_poWorkplan = pa_subphase.m_poWorkplan;
}

Subphase::Subphase(){

}
Subphase::~Subphase()
{
}


