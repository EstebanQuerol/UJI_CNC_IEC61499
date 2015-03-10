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
iso14649CppBase * L1_GENFeature::Deserialize(const CIEC_STRING & pa_theString){
	std::istringstream iss;
	iso14649CppBase * rvalue = NULL;
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (pa_theString.length() + 1));
	if (pacTempString != NULL){
		if (-1 != pa_theString.toString(pacTempString, static_cast<unsigned int>(pa_theString.length() + 1), 1)){
			iss.str(std::string(pacTempString));
			m_pIArchive = new boost::archive::text_iarchive(iss);
			if (m_pIArchive != NULL){
				(*m_pIArchive) >> rvalue;
			}
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while deserializing in L1 Feature\n");
	}
	return rvalue;
}

void L1_GENFeature::CleanIArchive(){
	//NOTE: if Layers 2 and 1 are executed in different devices
	//memory allocated with GlobalUtils::utils_SerMalloc()
	//needs to be deleted here, if not it will be deleted
	//in layer 2 when deleting the workplan
#ifdef DISTRIBUTED_LAYER_2_1
	GlobalUtils::utils_SerFree();
#endif
	if (m_pIArchive != NULL){
		m_pIArchive->delete_created_pointers();
	}
	delete m_pIArchive;
	m_pIArchive = NULL;
}