#include "GlobalUtils.h"

const double pi = acos(-1.0);

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
			sm_vSerallocLog[i] = NULL;
		}
	}
}

Eigen::Vector3d GlobalUtils::V3DFromRealIter(iso14649::parenRealListFull *pa_otheList){
	if (pa_otheList != NULL){
		std::list<iso14649::real *>::const_iterator reallistIter = pa_otheList->get_theList()->begin();
		double x = (*reallistIter++)->get_val();
		double y = (*reallistIter++)->get_val();
		double z = (*reallistIter)->get_val();
		return Eigen::Vector3d(x, y, z);
	}
	return Eigen::Vector3d(0.0, 0.0, 0.0);
}