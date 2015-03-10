/*******************************************************************************
* Class containing static methods and attributes used to pack global functions
* and varibales
*
*
*******************************************************************************/
#ifndef GLOBALUTILS_H_
#define GLOBALUTILS_H_

//L1 multicast identifiers defines
#define L1MID_NOT_VALID 0
#define L1MID_SETUP 1
#define L1MID_PLANAR_FACE 5
#define L1MID_CLOSED_POCKET 7
#define L1MID_OPEN_POCKET 8
#define L1MID_SENDCMD 150

#include <vector>
#include "fortealloc.h"


class GlobalUtils
{
public:
	GlobalUtils();
	~GlobalUtils();

#ifdef WIN32
	static void * utils_SerMalloc(size_t pa_nSize){
		//Memory allocated with this function don't have to be freed by the user
		//It will be freed when deleting the objects loaded by the serialization
		void * ptr = malloc(pa_nSize);
		sm_vSerallocLog.push_back(ptr);
		return ptr;
	}
	static void utils_SerFree();
#endif

private:
	static std::vector<void *> sm_vSerallocLog;
};

#endif