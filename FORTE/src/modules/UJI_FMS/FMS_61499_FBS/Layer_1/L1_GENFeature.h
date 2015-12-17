/*************************************************************************
*** This is the base class for FB of layer 1 of type "Feature"
***
*** Name: L0_GENFeature
*** Version:
***     0.0: 2015-03-03/EQUEROL - UJI -
*************************************************************************/
#ifndef L1_GENFEATURE_H
#define L1_GENFEATURE_H
//Macros
#define PARAM_ERROR_EXIT Cmd() = "";\
						 L1MIDOut() = L1MID_PARAM_ERROR;\
						 sendOutputEvent(scm_nEventCNFID);\
						 break;\

#include "boost\serialization\access.hpp"
#include "boost\serialization\list.hpp"
#include "boost\serialization\string.hpp"
#include "boost\archive\text_iarchive.hpp"
#include "boost\archive\text_oarchive.hpp"
#include <sstream>
#include <list>
#include <string>
#include <forte_string.h>
#include "iso14649classes.h"
#include "GlobalUtils.h"

class L1_GENFeature
{

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
	iso14649::setup * DeserializeSetup(const CIEC_STRING & pa_theString);
	iso14649::workingstep * DeserializeWorkingstep(const CIEC_STRING & pa_theString);
	/*!\brief destroys the objects created by the IArchive when deserializing
	*
	*/
};
#endif;
