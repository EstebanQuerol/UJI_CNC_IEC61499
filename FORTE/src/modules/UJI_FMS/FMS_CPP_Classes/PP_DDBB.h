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
#include <cstdarg>

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

	/*! INLINED functions to ease creating process plans
	***
	*/
	static char * SET_NAME(const char * name){
		char * l_name = NULL;
		if (name != NULL){
			l_name = (char *)malloc(sizeof(char)* (strlen(name) + 1));
			strcpy(l_name, name);
		}
		return l_name;
	}
	static boolean * SET_BOOL(bool value){
		if (value)
			return new booleanTrue();
		return new booleanFalse();
	}
	static real * SET_REAL(double value){
		return new real(value);
	}
	static cartesianPoint * CARTESIAN_POINT(const char * name, const double &x, const double &y, const double &z){
		std::list<real *> * l_theListIn = new std::list<real *>;
		l_theListIn->push_back(SET_REAL(x));
		l_theListIn->push_back(SET_REAL(y));
		l_theListIn->push_back(SET_REAL(z));
		parenRealListFull * l_coordinates = new parenRealListFull(l_theListIn);
		return new cartesianPoint(SET_NAME(name), l_coordinates);
	}
	static direction * DIRECTION(const char * name, const double &x, const double &y, const double &z){
		std::list<real *> * l_theListIn = new std::list<real *>;
		l_theListIn->push_back(SET_REAL(x));
		l_theListIn->push_back(SET_REAL(y));
		l_theListIn->push_back(SET_REAL(z));
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
	static closedPocket * CLOSED_POCKET(const char * itsIdIn, workpiece * itsWorkpieceIn, parenMachiningOperationList * itsOperationsIn,
		axis2placement3d * featurePlacementIn, elementarySurface * depthIn, parenBossList * itsBossIn, double slopeIn, pocketBottomCondition * bottomConditionIn,
		double planarRadiusIn, double orthogonalRadiusIn, closedProfile * featureBoundaryIn){

		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(planarRadiusIn, NULL);
		tolerancedLengthMeasure * l_TL2 = new tolerancedLengthMeasure(orthogonalRadiusIn, NULL);
		return new closedPocket(SET_NAME(itsIdIn), itsWorkpieceIn, itsOperationsIn, featurePlacementIn, depthIn, itsBossIn, SET_REAL(slopeIn), bottomConditionIn,
			l_TL1, l_TL2, featureBoundaryIn);
	}
	static roundHole * ROUND_HOLE(const char * itsIdIn, workpiece * itsWorkpieceIn, parenMachiningOperationList * itsOperationsIn,
		axis2placement3d * featurePlacementIn, elementarySurface * depthIn, double diameterIn, taperSelect * changeInDiameterIn,
		holeBottomCondition * bottomConditionIn){

		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(diameterIn, NULL);
		return new roundHole(SET_NAME(itsIdIn), itsWorkpieceIn, itsOperationsIn, featurePlacementIn, depthIn, l_TL1, changeInDiameterIn, bottomConditionIn);
	}
	static rectangularClosedProfile * RECTANGURAL_CLOSED_PROFILE(double profileWidthIn, double profileLengthIn)
	{
		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(profileWidthIn, NULL);
		tolerancedLengthMeasure * l_TL2 = new tolerancedLengthMeasure(profileLengthIn, NULL);
		return new rectangularClosedProfile(NULL, l_TL1, l_TL2);
	}
	static circularClosedProfile * CIRCULAR_CLOSED_PROFILE(double diameter)
	{
		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(diameter, NULL);
		return new circularClosedProfile(NULL, l_TL1);
	}
	static machiningWorkingstep * MACHINING_WORKINGSTEP(const char * itsIdIn, elementarySurface * itsSecplaneIn, manufacturingFeature * itsFeatureIn,
		machiningOperation * itsOperationIn, inProcessGeometry * itsEffectIn){
		return new machiningWorkingstep(SET_NAME(itsIdIn), itsSecplaneIn, itsFeatureIn, itsOperationIn, itsEffectIn);
	}
	static bottomAndSideRoughMilling * BOTTOM_AND_SIDE_ROUGH_MILLING(char * itsIdIn, double retractPlaneIn, cartesianPoint * startPointIn, machiningTool * itsToolIn,
		technology * itsTechnologyIn, machineFunctions * itsMachineFunctionsIn, double overcutLengthIn, approachRetractStrategy * approachIn,
		approachRetractStrategy * retractIn, two5DmillingStrategy * itsMachiningStrategyIn, double axialCuttingDepthIn, double radialCuttingDepthIn,
		double allowanceSideIn, double allowanceBottomIn){

		return new bottomAndSideRoughMilling(NULL, NULL, SET_NAME(itsIdIn), SET_REAL(retractPlaneIn), startPointIn, itsToolIn, itsTechnologyIn, itsMachineFunctionsIn,
			SET_REAL(overcutLengthIn), approachIn, retractIn, itsMachiningStrategyIn, SET_REAL(axialCuttingDepthIn), SET_REAL(radialCuttingDepthIn),
			SET_REAL(allowanceSideIn), SET_REAL(allowanceBottomIn));
	}

	static drilling * DRILLING(char * itsIdIn, double retractPlaneIn, cartesianPoint * startPointIn, machiningTool * itsToolIn,technology * itsTechnologyIn, 
		machineFunctions * itsMachineFunctionsIn, double overcutLengthIn, double cuttingDepthIn, double previousDiameterIn, double dwellTimeBottomIn,
		double feedOnRetractIn, drillingTypeStrategy * itsMachiningStrategyIn){

		return new drilling(NULL, NULL, SET_NAME(itsIdIn), SET_REAL(retractPlaneIn), startPointIn, itsToolIn, itsTechnologyIn, itsMachineFunctionsIn,
			SET_REAL(overcutLengthIn), SET_REAL(cuttingDepthIn), SET_REAL(previousDiameterIn), SET_REAL(dwellTimeBottomIn), SET_REAL(feedOnRetractIn), 
			itsMachiningStrategyIn);
	}
	static millingCuttingTool * MILLING_CUTTING_TOOL(const char * name){
		return new millingCuttingTool(SET_NAME(name), NULL, NULL, NULL, NULL, NULL);
	}
	static workplan * WORKPLAN(const char * name, parenExecutableList * itsElementsIn, channel * itsChannelIn, setup * itsSetupIn, inProcessGeometry * itsEffectIn){
		return new workplan(SET_NAME(name), itsElementsIn, itsChannelIn, itsSetupIn, itsEffectIn);
	}
	static parenExecutableList * PAREN_EXECUTABLE_LIST(int nArgs, ...){
		va_list ap;
		va_start(ap, nArgs);
		std::list<executable *> * l_theListIn_ex = new std::list<executable *>;
		executable * current;
		for (int i = 0; i < nArgs; i++) {
			current = va_arg(ap, executable *);
			l_theListIn_ex->push_back(current);
		}
		va_end(ap);
		return new parenExecutableList(l_theListIn_ex);
	}
	static millingTechnology * MILLING_TECHNOLOGY(double feedrateIn, const char * feedrateReferenceIn, double cutspeedIn,
		double spindleIn, double feedratePerToothIn, bool synchronizeSpindleWithFeedIn, bool inhibitFeedrateOverrideIn,
		bool inhibitSpindleOverrideIn, bool itsAdaptiveControlIn){
		toolReferencePoint * referencepoint = NULL;
		if (strncmp(feedrateReferenceIn, "CCP", 3) == 0 || strncmp(feedrateReferenceIn, "ccp", 3) == 0)
			referencepoint = new toolReferencePointCcp();
		if (strncmp(feedrateReferenceIn, "TCP", 3) == 0 || strncmp(feedrateReferenceIn, "tcp", 3) == 0)
			referencepoint = new toolReferencePointTcp;
		return new millingTechnology(SET_REAL(feedrateIn), referencepoint, SET_REAL(cutspeedIn), SET_REAL(spindleIn), SET_REAL(feedratePerToothIn),
			SET_BOOL(synchronizeSpindleWithFeedIn), SET_BOOL(inhibitFeedrateOverrideIn), SET_BOOL(inhibitSpindleOverrideIn), SET_BOOL(itsAdaptiveControlIn));
	}
	static diameterTaper * DIAMETER_TAPER(double finalDiameter){
		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(finalDiameter, NULL);
		return new diameterTaper(l_TL1);
	}
	static angleTaper * ANGLE_TAPER(double angle){
		return new angleTaper(SET_REAL(angle));
	}
	static planarFace * PLANAR_FACE(char * itsIdIn, workpiece * itsWorkpieceIn, parenMachiningOperationList * itsOperationsIn, axis2placement3d * featurePlacementIn,
		elementarySurface * depthIn, linearPath * courseOfTravelIn, linearProfile * removalBoundaryIn, closedProfile * faceBoundaryIn, parenBossList * itsBossIn){
		return new planarFace(SET_NAME(itsIdIn), itsWorkpieceIn, itsOperationsIn, featurePlacementIn, depthIn, courseOfTravelIn, removalBoundaryIn, faceBoundaryIn,
			itsBossIn);
	}
	static apRetractAngle * AP_RETRACT_ANLGE(const char * name, const double &x, const double &y, const double &z, const double &angleIn, const double &travelLengthIn){
		return new apRetractAngle(DIRECTION(name, x, y, z), angleIn, travelLengthIn);
	}
	static linearPath * LINEAR_PATH(axis2placement3d * placementIn, const double &distanceIn, direction * itsDirectionIn){
		tolerancedLengthMeasure * l_TL1 = new tolerancedLengthMeasure(distanceIn, NULL);
		return new linearPath(placementIn, l_TL1, itsDirectionIn);
	}
	static linearProfile * LINEAR_PROFILE(axis2placement3d * placementIn, const double &profileLengthIn){
			return new linearProfile(placementIn, NUMERIC_PERAMETER(profileLengthIn));
	}
	static numericParameter * NUMERIC_PERAMETER(const double &itsParameterValueIn){
		return new numericParameter(NULL, itsParameterValueIn, NULL);
	}
	static unidirectionalMilling * UNIDIRECTIONAL_MILLING(const double  &overlapIn, const bool &allowMultiplePassesIn, direction * feedDirectionIn, cutmodeType * cutmodeIn){

		return new unidirectionalMilling(SET_REAL(overlapIn), SET_BOOL(allowMultiplePassesIn), feedDirectionIn, cutmodeIn);
	}
};
#endif