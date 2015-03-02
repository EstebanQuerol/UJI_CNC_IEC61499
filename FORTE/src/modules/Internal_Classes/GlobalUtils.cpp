#include "GlobalUtils.h"

//Static memebers initialization
std::vector<void *>  GlobalUtils::sm_vSerallocLog;
GlobalUtils::GlobalUtils()
{
}


GlobalUtils::~GlobalUtils()
{
}

void GlobalUtils::utils_SerFree(){
	if (!sm_vSerallocLog.empty()){
		for (unsigned int i = 0; i < sm_vSerallocLog.size(); i++){
			free(sm_vSerallocLog[i]);
		}
	}
}
