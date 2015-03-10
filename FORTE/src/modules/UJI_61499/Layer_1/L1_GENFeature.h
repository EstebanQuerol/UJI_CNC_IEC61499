/*************************************************************************
*** This is the base class for FB of layer 1 of type "Feature"
***
*** Name: L0_GENFeature
*** Version:
***     0.0: 2015-03-03/EQUEROL - UJI -
*************************************************************************/
#ifndef L1_GENFEATURE_H
#define L1_GENFEATURE_H

#include "boost\serialization\access.hpp"
#include "boost\archive\text_iarchive.hpp"
#include "boost\archive\text_oarchive.hpp"
#include "boost\serialization\list.hpp"
#include "boost\serialization\string.hpp"
#include <sstream>
#include <list>
#include <string>
#include <forte_string.h>
#include "iso14649classes.h"
class L1_GENFeature
{
private:
	boost::archive::text_iarchive * m_pIArchive; //Input archive used in deserialization
public:
	L1_GENFeature();
	~L1_GENFeature();
	/*!\brief serializes a list of strings into a CIEC_STRING
	*
	* \param the list to serialize
	* \return serialized CIEC_STRING
	*/
	CIEC_STRING SerializeCmdList(const std::list<std::string> & pa_thelist);
	/*!\brief deserializes STEP-NC object through a iso14649cppBase pointer
	*
	* \param CIEC_STRING containing the serialized information
	* \return Pointer to the deserialized pointer
	*/
	iso14649CppBase * Deserialize(const CIEC_STRING & pa_theString);
	/*!\brief destroys the objects created by the IArchive when deserializing
	*
	*/
	void CleanIArchive();
};

#endif;
