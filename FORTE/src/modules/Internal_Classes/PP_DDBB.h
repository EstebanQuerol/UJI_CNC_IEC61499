/*************************************************************************
*** Name: PP_DDBB
*** Description: Class containing all the process plans used by the 
***				 manufacturing system
*** Version: 0
*************************************************************************/
#ifndef _PP_DDBB_H_
#define _PP_BBDD_H_
#include <unordered_map>
#include "PP_Family.h"
#include "ProcessPlan.h"
#include "forte_uint.h"

class PP_DDBB
{
private:
	static std::unordered_map<TForteUInt16, PP_Family> sm_umapFamilyMap; //Map holding all the process plans families
	static bool sm_bInitialized; //Initialization flag

public:
	PP_DDBB();
	~PP_DDBB();
	/*!\Initialize the process plan array
	*/
	static void  Initilizate();

	/*!\Get a pointer to a process plan in the DDBB by family and type
	* \param pa_nFamily process plan family
	* \param pa_nType process plan type
	* \return pointer to the target PP
	*/
	static ProcessPlan * getProcessPlan(TForteUInt16 pa_nFamilyID, TForteUInt16 pa_nTypeID);
	static char * SET_NAME(const char * name){
		char * l_name = NULL;
		if (name != NULL){
			l_name = (char *)malloc(sizeof(char)* (strlen(name) + 1));
			strcpy(l_name, name);
		}
		return l_name;
	}
	static cartesianPoint * CARTESIAN_POINT(const char * name, const double &x, const double &y, const double &z){
		std::list<real *> * l_theListIn = new std::list<real *>;
		real * l_x = new real(x);
		real * l_y = new real(y);
		real * l_z = new real(z);
		l_theListIn->push_back(l_x);
		l_theListIn->push_back(l_y);
		l_theListIn->push_back(l_z);
		parenRealListFull * l_coordinates = new parenRealListFull(l_theListIn);
		return new cartesianPoint(SET_NAME(name), l_coordinates);
	}
	static direction * DIRECTION(const char * name, const double &x, const double &y, const double &z){
		std::list<real *> * l_theListIn = new std::list<real *>;
		real * l_x = new real(0.0);
		real * l_y = new real(0.0);
		real * l_z = new real(1.0);
		l_theListIn->push_back(l_x);
		l_theListIn->push_back(l_y);
		l_theListIn->push_back(l_z);
		parenRealListFull * l_coordinates = new parenRealListFull(l_theListIn);
		return new direction(SET_NAME(name), l_coordinates);
	}
	static axis2placement3d * AXIS2_PLACEMENT_3D(const char * name, cartesianPoint * locationIn, direction * axisIn, direction * refDirectionIn){
		return new axis2placement3d(SET_NAME(name), locationIn, axisIn, refDirectionIn);
	}
	static elementarySurface * ELEMENTARY_SURFACE(const char * name, axis2placement3d * itsposition){
		return new elementarySurface(SET_NAME(name), itsposition);
	}
	static block * BLOCK(const char * name, axis2placement3d * itsposition, const double &x, const double &y, const double &z){
		return new block(SET_NAME(name), itsposition, x, y, z);
	}
	static workpiece * WORKPIECE(const char * name, material * itsMaterialIn, real * globalToleranceIn, workpiece * itsRawpieceIn, 
		advancedBrepShapeRepresentation * itsGeometryIn, boundingGeometrySelect * itsBoundingGeometryIn, parenCartesianPointList * clampingPositionsIn){
		return new workpiece(SET_NAME(name), itsMaterialIn, globalToleranceIn, itsRawpieceIn, itsGeometryIn, itsBoundingGeometryIn, clampingPositionsIn);
	}
	static workpieceSetup * WORKPIECE_SETUP(workpiece * itsWorkpieceIn, axis2placement3d * itsOriginIn, offsetVector * itsOffsetIn,
		restrictedAreaSelect * itsRestrictedAreaIn, parenSetupInstructionList * itsInstructionsIn){
		return new workpieceSetup(itsWorkpieceIn, itsOriginIn, itsOffsetIn, itsRestrictedAreaIn, itsInstructionsIn);
	}
	static parenWorkpieceSetupList * SINGLE_WORKPIECE_SETUP(workpiece * itsWorkpieceIn, axis2placement3d * itsOriginIn, offsetVector * itsOffsetIn,
		restrictedAreaSelect * itsRestrictedAreaIn, parenSetupInstructionList * itsInstructionsIn){
		std::list<workpieceSetup *> * theList = new std::list<workpieceSetup *>;
		theList->push_back(WORKPIECE_SETUP(itsWorkpieceIn, itsOriginIn, itsOffsetIn, itsRestrictedAreaIn, itsInstructionsIn));
		return new parenWorkpieceSetupList(theList);
	}
	static setup * SETUP(const char * name, axis2placement3d * itsOriginIn, elementarySurface * itsSecplaneIn, parenWorkpieceSetupList * itsWorkpieceSetupIn){
		return new setup(SET_NAME(name), itsOriginIn, itsSecplaneIn, itsWorkpieceSetupIn);
	}
	static channel * CHANNEL(const char * name){
		return new channel(SET_NAME(name));
	}
};

#endif