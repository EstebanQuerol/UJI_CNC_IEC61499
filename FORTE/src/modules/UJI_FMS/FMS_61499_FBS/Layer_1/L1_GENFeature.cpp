#include "L1_GENFeature.h"


L1_GENFeature::L1_GENFeature()
{
}


L1_GENFeature::~L1_GENFeature()
{
}

CIEC_STRING L1_GENFeature::SerializeCmdList(const std::list<std::string> & pa_thelist){
	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << pa_thelist;
	return oss.str().c_str();
}
iso14649::setup * L1_GENFeature::DeserializeSetup(const CIEC_STRING & pa_theString){
	std::istringstream iss;
	iso14649::setup * rvalue = NULL;
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (pa_theString.length() + 1));
	if (pacTempString != NULL){
		if (-1 != pa_theString.toString(pacTempString, static_cast<unsigned int>(pa_theString.length() + 1), 1)){
			iss.str(std::string(pacTempString));
			boost::archive::text_iarchive IArchive(iss);
			IArchive >> rvalue;
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while deserializing in L1 Feature\n");
	}
	return rvalue;
}

iso14649::workingstep * L1_GENFeature::DeserializeWorkingstep(const CIEC_STRING & pa_theString){
	std::istringstream iss;
	iso14649::workingstep * rvalue = NULL;
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (pa_theString.length() + 1));
	if (pacTempString != NULL){
		if (-1 != pa_theString.toString(pacTempString, static_cast<unsigned int>(pa_theString.length() + 1), 1)){
			iss.str(std::string(pacTempString));
			boost::archive::text_iarchive IArchive(iss);
			IArchive >> rvalue;
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while deserializing in L1 Feature\n");
	}
	return rvalue;
}