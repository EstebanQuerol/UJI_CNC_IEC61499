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
#define L1MID_ROUND_HOLE 9
#define L1MID_SLOT 10
#define L1MID_STEP 11
#define L1MID_GENERAL_OUT_PROFILE 12
#define L1MID_SENDCMD 150
#define L1MID_PARAM_ERROR 151

#include <vector>
#include "fortealloc.h"
#include "iso14649classes.h"
#include <Eigen\Core>

extern const double pi;
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
	/*!\ Create an Eigen 3 doubles vector from a RealList from iso14649 lib
	* return a vector with x y z components on success
	* rerurn a vector 0.0 0.0 0.0 on error
	*/
	static Eigen::Vector3d V3DFromRealIter(iso14649::parenRealListFull *pa_otheList);
	/*!\ check if two cartesian points are equal
	* return true if both points are equal
	* rerurn false if points are not equal
	*/
	static bool isPlacementEqual(iso14649::cartesianPoint *pa_oA, iso14649::cartesianPoint *pa_oB);
	/*!\ isPlacementEqual overload
	* return true if both points are equal
	* rerurn false if points are not equal
	*/
	static bool isPlacementEqual(iso14649::cartesianPoint *pa_oA, const double &x, const double &y, const double &z);
	/*!\ isPlacementEqual overload in XY plane
	* return true if both points are equal
	* rerurn false if points are not equal
	*/
	static bool isPlacementEqual(iso14649::cartesianPoint *pa_oA, const double &x, const double &y);
private:
	static std::vector<void *> sm_vSerallocLog;
};

#endif