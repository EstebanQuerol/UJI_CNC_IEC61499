#include "PP_DDBB.h"
//Initialize static members
std::unordered_map<TForteUInt16, PP_Family> PP_DDBB::sm_umapFamilyMap;
bool PP_DDBB::sm_bInitialized = false; //Initialization flag

PP_DDBB::PP_DDBB()
{
}


PP_DDBB::~PP_DDBB()
{
}

void  PP_DDBB::Initilizate(){
	if (!sm_bInitialized){
		sm_bInitialized = true;

		//Test code
		//Ceate Family "1"
		PP_Family Family_1 = PP_Family(1);

		/******************Feature 1****************************/
		//Placement
		cartesianPoint *  l_locationIn = CARTESIAN_POINT(NULL, 150.0, 50.0, 50.0);
		direction * l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		direction *  l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		axis2placement3d * l_itsplacement = AXIS2_PLACEMENT_3D("Feature placement", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 15.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		axis2placement3d *  l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Profile
		closedProfile * l_itsprofile = RECTANGURAL_CLOSED_PROFILE(30.0, 20.0);
		//Pocket
		closedPocket * l_CPFeature = CLOSED_POCKET("Cajera 1", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 1.0, l_itsprofile);

		/******************Feature 2****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 25.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Feature placement", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 15.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Profile
		l_itsprofile = RECTANGURAL_CLOSED_PROFILE(15.0, 30.0);
		//Pocket
		closedPocket * l_CPFeature_2 = CLOSED_POCKET("Cajera 1", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 1.0, l_itsprofile);

		/*****************machining operation***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		millingCuttingTool * itstool = MILLING_CUTTING_TOOL("1337");
		millingTechnology * itstechnology = MILLING_TECHNOLOGY(80.0, "TCP", 0.0, 1000.0, 0.0, false, false, false, false);
		bottomAndSideRoughMilling * l_itsMoperation = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 59.0, l_locationIn, itstool, itstechnology, NULL, 0.0, NULL, NULL, NULL, 5.0, 2.0, 0.0, 0.0);

		/**************machning workingstep****************************/
		//Security plance
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 10.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itsSecPlane = ELEMENTARY_SURFACE("SP", l_positionIn);
		machiningWorkingstep * l_itsMWStep_1 = MACHINING_WORKINGSTEP("MWS 1", l_itsSecPlane, l_CPFeature, l_itsMoperation, NULL);
		machiningWorkingstep * l_itsMWStep_2 = MACHINING_WORKINGSTEP("MWS 2", l_itsSecPlane, l_CPFeature_2, l_itsMoperation, NULL);
		//executable * l_itsMWStep_3 = MACHINING_WORKINGSTEP("MWS 3", l_itsSecPlane, l_CPFeature, l_itsMperation, NULL);
		/***************************Executable list*****************/
		std::list<executable *> * l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_2);
		parenExecutableList * l_itsElementsIn = new parenExecutableList(l_theListIn_ex);
		//parenExecutableList * l_itsElementsIn = PAREN_EXECUTABLE_LIST(1, l_itsMWStep_1);
		/************************Channel****************************/
		channel * l_channel = CHANNEL("Channel 1");

		/******************Setup****************************/
		//Its sec plane
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 70.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D("Position", l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itssecplane = ELEMENTARY_SURFACE("Sec Plane", l_positionIn);
		//itsorigin
		l_locationIn = CARTESIAN_POINT("Point", 20.0, 50.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 0.0, 0.0, 1.0);
		axis2placement3d * l_itsOrigin = AXIS2_PLACEMENT_3D("Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		//The workpiece
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		axis2placement3d * l_blockOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		block * itsblock = BLOCK("Block", l_blockOrigin, 200.0, 100.0, 50.0);
		workpiece * l_theworkpiece = WORKPIECE("Bruto", NULL, NULL, NULL, NULL, itsblock, NULL);
		//The workpiece setup
		l_locationIn = CARTESIAN_POINT("Point", 10.0, 10.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		axis2placement3d * l_workpieceSetupOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		parenWorkpieceSetupList * itsWorkpieceSetupIn = SINGLE_WORKPIECE_SETUP(l_theworkpiece, l_workpieceSetupOrigin, NULL, NULL, NULL);
		setup * l_itsSetupIn = SETUP("Setup 1", l_itsOrigin, l_itssecplane, itsWorkpieceSetupIn);

		/********************Workplan*****************/
		workplan * WP1 = WORKPLAN("Workplan 1", l_itsElementsIn, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_1_1 = ProcessPlan(1, 1, 1);
		PP_1_1.addSubphase(1, 1, WP1);
		Family_1.addProcessPlan(PP_1_1, 1);



		std::pair<TForteUInt16, PP_Family> newpair(1, Family_1);
		try{
			sm_umapFamilyMap.insert(newpair);
		}
		catch (std::bad_alloc e){
			DEVLOG_ERROR("Allocation failure, unable to insert a process plan in the DDBB \n");
			
		}
		
	}
}

ProcessPlan *  PP_DDBB::getProcessPlan(TForteUInt16 pa_nFamilyID, TForteUInt16 pa_nTypeID){
	ProcessPlan * poRValue = NULL;
	if (sm_bInitialized){
		try{
			poRValue = sm_umapFamilyMap.at(pa_nFamilyID).getProcesPlanByType(pa_nTypeID);
		}
		catch (std::out_of_range e){
			DEVLOG_ERROR("Out of range exception, used an invalid key in the DDBB unorderedmap \n");
			poRValue = NULL;
		}
	}
	return poRValue;
}