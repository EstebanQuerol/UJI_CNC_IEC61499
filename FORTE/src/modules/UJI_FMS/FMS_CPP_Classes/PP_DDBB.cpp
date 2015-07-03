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
		/*************************************************************************************************************/
		/************************************Family "1" process plans*************************************************/
		/*************************************************************************************************************/
		PP_Family Family_1 = PP_Family(1);

		/******************Feature 1****************************/
		//Placement
		cartesianPoint *  l_locationIn = CARTESIAN_POINT(NULL, 150.0, 50.0, 50.0);
		direction * l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		direction *  l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		axis2placement3d * l_itsplacement = AXIS2_PLACEMENT_3D("Feature placement", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 10.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		axis2placement3d *  l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Profile
		closedProfile * l_itsprofile = RECTANGURAL_CLOSED_PROFILE(NULL, 40.0, 40.0);
		//Pocket
		closedPocket * l_CPFeature = CLOSED_POCKET("Cajera 1", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 3.0, l_itsprofile);

		/******************Feature 2****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 50.0, 50.0);
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
		l_itsprofile = RECTANGURAL_CLOSED_PROFILE(NULL, 50.0, 40.0);
		//Pocket
		closedPocket * l_CPFeature_2 = CLOSED_POCKET("Cajera 2", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 5.0, l_itsprofile);

		/******************Feature 3****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 15.0, 15.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 25.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		roundHole * l_HoleFeature_1 = ROUND_HOLE("Taladro 1", NULL, NULL, l_itsplacement, l_itsdepth, 10.0, NULL, NULL);

		/******************Feature 4****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 15.0, 85.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 25.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		roundHole * l_HoleFeature_2 = ROUND_HOLE("Taladro 2", NULL, NULL, l_itsplacement, l_itsdepth, 10.0, NULL, NULL);

		/******************Feature 5****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 185.0, 15.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 25.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		roundHole * l_HoleFeature_3 = ROUND_HOLE("Taladro 3", NULL, NULL, l_itsplacement, l_itsdepth, 10.0, NULL, NULL);

		/******************Feature 6****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 185.0, 85.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 25.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		roundHole * l_HoleFeature_4 = ROUND_HOLE("Taladro 4", NULL, NULL, l_itsplacement, l_itsdepth, 10.0, NULL, NULL);

		/******************Feature 7****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 50.0, 50.0);
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
		l_itsprofile = CIRCULAR_CLOSED_PROFILE(60.0);
		//Pocket
		closedPocket * l_CPFeature_3 = CLOSED_POCKET("Cajera 3", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 5.0, l_itsprofile);

		/*****************machining operation 1***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		millingCuttingTool * itstool = MILLING_CUTTING_TOOL("1337");
		millingTechnology * itstechnology = MILLING_TECHNOLOGY(80.0, "TCP", 0.0, 1000.0, 0.0, false, false, false, false);
		machiningOperation * l_itsMoperation_1 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, NULL, NULL, NULL, 5.0, 2.0, 0.0, 0.0);

		/*****************machining operation 2***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		itstool = MILLING_CUTTING_TOOL("1400");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 600.0, 0.0, false, false, false, false);
		machiningOperation * l_itsMoperation_2 = DRILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, 0.0, 0.0, 1.0, 0.0, NULL);

		/*****************machining operation 3***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		itstool = MILLING_CUTTING_TOOL("1337");
		itstechnology = MILLING_TECHNOLOGY(100.0, "TCP", 0.0, 1250.0, 0.0, false, false, false, false);
		machiningOperation * l_itsMoperation_3 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, NULL, NULL, NULL, 5.0, 3.0, 0.0, 0.0);

		/**************machning workingstep****************************/
		//Security plance
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itsSecPlane = ELEMENTARY_SURFACE("SP", l_positionIn);
		machiningWorkingstep * l_itsMWStep_1 = MACHINING_WORKINGSTEP("MWS 1", l_itsSecPlane, l_CPFeature, l_itsMoperation_1, NULL);
		machiningWorkingstep * l_itsMWStep_2 = MACHINING_WORKINGSTEP("MWS 2", l_itsSecPlane, l_CPFeature_2, l_itsMoperation_1, NULL);
		machiningWorkingstep * l_itsMWStep_3 = MACHINING_WORKINGSTEP("MWS 3", l_itsSecPlane, l_HoleFeature_1, l_itsMoperation_2, NULL);
		machiningWorkingstep * l_itsMWStep_4 = MACHINING_WORKINGSTEP("MWS 4", l_itsSecPlane, l_HoleFeature_2, l_itsMoperation_2, NULL);
		machiningWorkingstep * l_itsMWStep_5 = MACHINING_WORKINGSTEP("MWS 5", l_itsSecPlane, l_HoleFeature_3, l_itsMoperation_2, NULL);
		machiningWorkingstep * l_itsMWStep_6 = MACHINING_WORKINGSTEP("MWS 6", l_itsSecPlane, l_HoleFeature_4, l_itsMoperation_2, NULL);
		machiningWorkingstep * l_itsMWStep_7 = MACHINING_WORKINGSTEP("MWS 7", l_itsSecPlane, l_CPFeature_3, l_itsMoperation_3, NULL);

		/***************************Executable list for type 1*****************/
		std::list<executable *> * l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_2);
		l_theListIn_ex->push_back(l_itsMWStep_3);
		l_theListIn_ex->push_back(l_itsMWStep_4);
		l_theListIn_ex->push_back(l_itsMWStep_5);
		l_theListIn_ex->push_back(l_itsMWStep_6);
		parenExecutableList * l_itsElementsIn_1 = new parenExecutableList(l_theListIn_ex);
		//parenExecutableList * l_itsElementsIn = PAREN_EXECUTABLE_LIST(2, l_itsMWStep_1, l_itsMWStep_2);
		/***************************Executable list for type 2*****************/
		l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_7);
		l_theListIn_ex->push_back(l_itsMWStep_3);
		l_theListIn_ex->push_back(l_itsMWStep_4);
		l_theListIn_ex->push_back(l_itsMWStep_5);
		l_theListIn_ex->push_back(l_itsMWStep_6);
		parenExecutableList * l_itsElementsIn_2 = new parenExecutableList(l_theListIn_ex);

		/************************Channel****************************/
		channel * l_channel = CHANNEL("Channel 1");

		/******************Setup****************************/
		//Its sec plane
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 90.0);
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

		/********************Type 1 Process plan*****************/
		workplan * WP = WORKPLAN("Workplan T1", l_itsElementsIn_1, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_1_1 = ProcessPlan(1, 1, 1);
		PP_1_1.addSubphase(1, 1, WP);
		Family_1.addProcessPlan(PP_1_1, 1);

		/********************Type 2 Process plan*****************/
		WP = WORKPLAN("Workplan T2", l_itsElementsIn_2, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_1_2 = ProcessPlan(1, 1, 2);
		PP_1_2.addSubphase(1, 1, WP);
		Family_1.addProcessPlan(PP_1_2, 2);

		/*************************************************************************************************************/
		/************************************Family "2" process plans*************************************************/
		/*************************************************************************************************************/
		PP_Family Family_2 = PP_Family(2);

		/******************Feature 1****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 70.0, 70.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Feature placement", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Profile
		l_itsprofile = RECTANGURAL_CLOSED_PROFILE(NULL, 80.0, 50.0);
		//Pocket
		l_CPFeature = CLOSED_POCKET("Cajera 1", NULL, NULL, l_itsplacement, l_itsdepth, NULL, NULL, NULL, NULL, 10.0, l_itsprofile);

		/******************Feature 2****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 20.0, 60.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		l_HoleFeature_1 = ROUND_HOLE("Taladro 1", NULL, NULL, l_itsplacement, l_itsdepth, 22.0, NULL, NULL);

		/******************Feature 3****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 15.0, 15.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		l_HoleFeature_2 = ROUND_HOLE("Taladro 2", NULL, NULL, l_itsplacement, l_itsdepth, 22.0, NULL, NULL);

		/******************Feature 4****************************/
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 15.0, 105.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Taladro", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE("Depth", l_positionIn);
		//Hole
		l_HoleFeature_3 = ROUND_HOLE("Taladro 3", NULL, NULL, l_itsplacement, l_itsdepth, 22.0, NULL, NULL);

		/******************Feature 5****************************/
		//Linear path
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 1.0, 1.0, 0.0);
		linearPath * l_linearPath = LINEAR_PATH(l_itsplacement, 50.0, l_axisIn);
		//linear profile
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, -1.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		linearProfile * l_linearProfile = LINEAR_PROFILE(l_itsplacement, 50.0);
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 60.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Planeado", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 6.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Planar Face
		planarFace * l_planarFace_1 = PLANAR_FACE("Planeado 1", NULL, NULL, l_itsplacement, l_itsdepth, l_linearPath, l_linearProfile, NULL, NULL);

		/******************Feature 6****************************/
		//Linear path
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 0.0, 1.0, 0.0);
		l_linearPath = LINEAR_PATH(l_itsplacement, 200.0, l_axisIn);
		//linear profile
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_linearProfile = LINEAR_PROFILE(l_itsplacement, 150.0);
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, -25.0, -40.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Planeado", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 2.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Planar Face
		planarFace * l_planarFace_2 = PLANAR_FACE("Planeado 2", NULL, NULL, l_itsplacement, l_itsdepth, l_linearPath, l_linearProfile, NULL, NULL);

		/******************Feature 7****************************/
		//Linear path
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 0.0, 1.0, 0.0);
		l_linearPath = LINEAR_PATH(l_itsplacement, 80.0, l_axisIn);
		//linear profile
		l_locationIn = CARTESIAN_POINT(NULL, 0, 0, 0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_linearProfile = LINEAR_PROFILE(l_itsplacement, 45.0);
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 20.0, 50.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D("Pos Planeado", l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 7.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Planar Face
		planarFace * l_planarFace_3 = PLANAR_FACE("Planeado 3", NULL, NULL, l_itsplacement, l_itsdepth, l_linearPath, l_linearProfile, NULL, NULL);

		/*****************machining operation 1***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		itstool = MILLING_CUTTING_TOOL("1338");
		itstechnology = MILLING_TECHNOLOGY(80.0, "TCP", 0.0, 1000.0, 0.0, false, false, false, false);
		l_itsMoperation_1 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, NULL, NULL, NULL, 10.0, 15.0, 0.0, 0.0);

		/*****************machining operation 2***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		itstool = MILLING_CUTTING_TOOL("1401");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 600.0, 0.0, false, false, false, false);
		l_itsMoperation_2 = DRILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, 0.0, 0.0, 1.0, 0.0, NULL);

		/*****************machining operation 3***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		itstool = MILLING_CUTTING_TOOL("1400");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 600.0, 0.0, false, false, false, false);
		l_itsMoperation_3 = DRILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, 0.0, 0.0, 1.0, 0.0, NULL);

		/*****************machining operation 4***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 40.0, -2.0);
		itstool = MILLING_CUTTING_TOOL("1336");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		approachRetractStrategy * l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 65.0, 50.0);
		two5DmillingStrategy * l_millingStrategy = UNIDIRECTIONAL_MILLING(0.6, false, NULL, NULL);;
		machiningOperation * l_itsMoperation_4 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 3.0, 12.0, 0.0, 0.0);

		/*****************machining operation 5***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 75.0, 40.0, -2.0);
		itstool = MILLING_CUTTING_TOOL("1335");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 65.0, 50.0);
		l_millingStrategy = BIDIRECTIONAL_MILLING(0.0, false, NULL, NULL, NULL);
		machiningOperation * l_itsMoperation_5 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 5.0, 140.0, 0.0, 0.0);

		/*****************machining operation 6***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 40.0, -2.0);
		itstool = MILLING_CUTTING_TOOL("1336");
		itstechnology = MILLING_TECHNOLOGY(50.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 65.0, 50.0);
		l_millingStrategy = BIDIRECTIONAL_MILLING(0.3, false, NULL, NULL, NULL);
		machiningOperation * l_itsMoperation_6 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 3.0, 12.0, 0.0, 0.0);

		/**************machning workingstep****************************/
		//Security plance
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 30.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsSecPlane = ELEMENTARY_SURFACE("SP", l_positionIn);
		l_itsMWStep_1 = MACHINING_WORKINGSTEP("MWS 1", l_itsSecPlane, l_CPFeature, l_itsMoperation_1, NULL);
		l_itsMWStep_2 = MACHINING_WORKINGSTEP("MWS 2", l_itsSecPlane, l_HoleFeature_1, l_itsMoperation_2, NULL);
		l_itsMWStep_3 = MACHINING_WORKINGSTEP("MWS 3", l_itsSecPlane, l_HoleFeature_2, l_itsMoperation_3, NULL);
		l_itsMWStep_4 = MACHINING_WORKINGSTEP("MWS 4", l_itsSecPlane, l_HoleFeature_3, l_itsMoperation_3, NULL);
		l_itsMWStep_5 = MACHINING_WORKINGSTEP("MWS 5", l_itsSecPlane, l_planarFace_2, l_itsMoperation_5, NULL);
		l_itsMWStep_6 = MACHINING_WORKINGSTEP("MWS 6", l_itsSecPlane, l_planarFace_3, l_itsMoperation_4, NULL);
		/***************************Executable list for type 1*****************/
		l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_2);
		l_itsElementsIn_1 = new parenExecutableList(l_theListIn_ex);
		//parenExecutableList * l_itsElementsIn = PAREN_EXECUTABLE_LIST(2, l_itsMWStep_1, l_itsMWStep_2);
		/***************************Executable list for type 2*****************/
		l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_2);
		l_theListIn_ex->push_back(l_itsMWStep_3);
		l_theListIn_ex->push_back(l_itsMWStep_4);
		l_itsElementsIn_2 = new parenExecutableList(l_theListIn_ex);
		/***************************Executable list for type 3*****************/
		l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_5);
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_2);
		parenExecutableList * l_itsElementsIn_3 = new parenExecutableList(l_theListIn_ex);

		/************************Channel****************************/
		l_channel = CHANNEL("Channel 1");

		/******************Setup****************************/
		//Its sec plane
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 120.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D("Position", l_locationIn, l_axisIn, l_refDirectionIn);
		l_itssecplane = ELEMENTARY_SURFACE("Sec Plane", l_positionIn);
		//itsorigin
		l_locationIn = CARTESIAN_POINT("Point", 30.0, 30.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 0.0, 0.0, 1.0);
		l_itsOrigin = AXIS2_PLACEMENT_3D("Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		//The workpiece
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		l_blockOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		itsblock = BLOCK("Block", l_blockOrigin, 100.0, 120.0, 50.0);
		l_theworkpiece = WORKPIECE("Bruto", NULL, NULL, NULL, NULL, itsblock, NULL);
		//The workpiece setup
		l_locationIn = CARTESIAN_POINT("Point", 10.0, 10.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		l_workpieceSetupOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		itsWorkpieceSetupIn = SINGLE_WORKPIECE_SETUP(l_theworkpiece, l_workpieceSetupOrigin, NULL, NULL, NULL);
		l_itsSetupIn = SETUP("Setup 1", l_itsOrigin, l_itssecplane, itsWorkpieceSetupIn);

		/********************Type 1 Process plan*****************/
		WP = WORKPLAN("Workplan T1", l_itsElementsIn_1, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_2_1 = ProcessPlan(1, 2, 1);
		PP_2_1.addSubphase(1, 1, WP);
		Family_2.addProcessPlan(PP_2_1, 1);

		/********************Type 2 Process plan*****************/
		WP = WORKPLAN("Workplan T2", l_itsElementsIn_2, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_2_2 = ProcessPlan(1, 2, 2);
		PP_2_2.addSubphase(1, 1, WP);
		Family_2.addProcessPlan(PP_2_2, 2);

		/********************Type 3 Process plan*****************/
		WP = WORKPLAN("Workplan T3", l_itsElementsIn_3, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_2_3 = ProcessPlan(1, 2, 3);
		PP_2_3.addSubphase(1, 1, WP);
		Family_2.addProcessPlan(PP_2_3, 3);


		/*************************************************************************************************************/
		/************************************Family "3" process plans*************************************************/
		/*************************************************************************************************************/
		PP_Family Family_3 = PP_Family(3);

		/******************Feature 1****************************/
		//Travel path
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, -1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		travelPath * l_travelPath_1 = COMPLETE_CIRCULAR_PATH(l_itsplacement, 30.0);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		openProfile * l_OProfile_1 = SQUARE_U_PROFILE(l_itsplacement, 10.0, 0.0, 0.0, 0.0, 0.0);
		//Placement
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 50.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -5.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Slot
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 50.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		slot * l_Slot_1 = SLOT("Ranurado 1", NULL, NULL, l_itsplacement, l_itsdepth, l_travelPath_1, l_OProfile_1, NULL);
		/******************Feature 2****************************/
		//Travel path
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_travelPath_1 = LINEAR_PATH(l_itsplacement, 100.0, l_axisIn);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_OProfile_1 = SQUARE_U_PROFILE(l_itsplacement, 10.0, 0.0, 0.0, 0.0, 0.0);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -6.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Slot
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 105.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		slot * l_Slot_2 = SLOT("Ranurado 2", NULL, NULL, l_itsplacement, l_itsdepth, l_travelPath_1, l_OProfile_1, NULL);
		/******************Feature 3****************************/
		//Travel path
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, -1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_travelPath_1 = PARTIAL_CIRCULAR_PATH(l_itsplacement, 10.0, 315.0);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_OProfile_1 = SQUARE_U_PROFILE(l_itsplacement, 5.0, 0.0, 0.0, 0.0, 0.0);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -8.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Slot
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 50.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		slot * l_Slot_3 = SLOT("Ranurado 3", NULL, NULL, l_itsplacement, l_itsdepth, l_travelPath_1, l_OProfile_1, NULL);

		/******************Feature 4****************************/
		//Travel path
		//The Polyline
		std::list<cartesianPoint *> * ThePoints = new std::list<cartesianPoint *>;
		ThePoints->push_back(CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0));
		ThePoints->push_back(CARTESIAN_POINT(NULL, 20.0, -20.0, 0.0));
		ThePoints->push_back(CARTESIAN_POINT(NULL, 40.0, 0.0, 0.0));
		ThePoints->push_back(CARTESIAN_POINT(NULL, 60.0, -20.0, 0.0));
		ThePoints->push_back(CARTESIAN_POINT(NULL, 80.0, 0.0, 0.0));
		ThePoints->push_back(CARTESIAN_POINT(NULL, 100.0, -20.0, 0.0));
		boundedCurve * TheCurve = POLYLINE(NULL, ThePoints);
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, -1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_travelPath_1 = GENERAL_PATH(l_itsplacement, TheCurve);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_OProfile_1 = SQUARE_U_PROFILE(l_itsplacement, 5.0, 0.0, 0.0, 0.0, 0.0);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -8.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//Slot
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 140.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		slot * l_Slot_4 = SLOT("Ranurado 4", NULL, NULL, l_itsplacement, l_itsdepth, l_travelPath_1, l_OProfile_1, NULL);
		/******************Feature 5****************************/
		//Travel path
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 0.0, 1.0, 0.0);
		l_linearPath = LINEAR_PATH(l_itsplacement, 140.0, l_axisIn);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		veeProfile * l_VProfile_1 = V_PROFILE(l_itsplacement, 0.0, 90.0, 90.0);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -15.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//step
		l_locationIn = CARTESIAN_POINT(NULL, 80.0, 0.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		step * l_Step_1 = STEP("Escalon 1", NULL, NULL, l_itsplacement, l_itsdepth, l_linearPath, l_VProfile_1, NULL);
		/******************Feature 6****************************/
		//Travel path
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_axisIn = DIRECTION(NULL, 0.0, 1.0, 0.0);
		l_linearPath = LINEAR_PATH(l_itsplacement, 10.0, l_axisIn);
		//Swept profile
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		profile * l_RCP_1 = RECTANGURAL_CLOSED_PROFILE(l_itsplacement, 116.0, 76.0);
		//Depth
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -15.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsdepth = ELEMENTARY_SURFACE(NULL, l_positionIn);
		//general outside profile
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, 70.0, 40.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_itsplacement = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		generalOutsideProfile * l_GOP_1 = GENERAL_OUTSIDE_PROFILE("GOP 1", NULL, NULL, l_itsplacement, l_itsdepth, l_linearPath, l_RCP_1);
		/*****************machining operation 1***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, -30.0, -5.0);
		itstool = MILLING_CUTTING_TOOL("1337");
		itstechnology = MILLING_TECHNOLOGY(80.0, "TCP", 0.0, 1000.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 60.0, 50.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_1 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 10.0, 15.0, 0.0, 0.0);
		/*****************machining operation 2***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -8.0);
		itstool = MILLING_CUTTING_TOOL("1337");
		itstechnology = MILLING_TECHNOLOGY(80.0, "TCP", 0.0, 1000.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 30.0, 25.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_2 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 10.0, 15.0, 0.0, 0.0);
		/*****************machining operation 3***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, -10.0, -2.0);
		itstool = MILLING_CUTTING_TOOL("1334");
		itstechnology = MILLING_TECHNOLOGY(30.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 45.0, 50.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_3 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 10.0, 15.0, 0.0, 0.0);
		/*****************machining operation 4***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, -2.0);
		itstool = MILLING_CUTTING_TOOL("1334");
		itstechnology = MILLING_TECHNOLOGY(30.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 65.0, 60.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_4 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 10.0, 15.0, 0.0, 0.0);
		/*****************machining operation 5***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 12.0, 0.0, -3.0);
		itstool = MILLING_CUTTING_TOOL("1336");
		itstechnology = MILLING_TECHNOLOGY(30.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 65.0, 60.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_5 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 10.0, 15.0, 0.0, 0.0);
		/*****************machining operation 6***************************/
		l_locationIn = CARTESIAN_POINT(NULL, 50.0, -70.0, -7.5);
		itstool = MILLING_CUTTING_TOOL("1336");
		itstechnology = MILLING_TECHNOLOGY(30.0, "TCP", 0.0, 1200.0, 0.0, false, false, false, false);
		l_apRetract = AP_RETRACT_ANLGE(NULL, 0.0, 0.0, 0.0, 0.0, 60.0);
		l_millingStrategy = CENTER_MILLING(0.0, false);
		l_itsMoperation_6 = BOTTOM_AND_SIDE_ROUGH_MILLING(NULL, 80.0, l_locationIn, itstool, itstechnology, NULL, 0.0, l_apRetract, NULL, l_millingStrategy, 5.0, 15.0, 6.0, 0.0);

		/**************machning workingstep****************************/
		//Security plance
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 60.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itsSecPlane = ELEMENTARY_SURFACE("SP", l_positionIn);
		l_itsMWStep_1 = MACHINING_WORKINGSTEP("MWS 1", l_itsSecPlane, l_Slot_1, l_itsMoperation_1, NULL);
		l_itsMWStep_2 = MACHINING_WORKINGSTEP("MWS 2", l_itsSecPlane, l_Slot_2, l_itsMoperation_2, NULL);
		l_itsMWStep_3 = MACHINING_WORKINGSTEP("MWS 3", l_itsSecPlane, l_Slot_3, l_itsMoperation_3, NULL);
		l_itsMWStep_4 = MACHINING_WORKINGSTEP("MWS 4", l_itsSecPlane, l_Slot_4, l_itsMoperation_4, NULL);
		l_itsMWStep_5 = MACHINING_WORKINGSTEP("MWS 5", l_itsSecPlane, l_Step_1, l_itsMoperation_5, NULL);
		l_itsMWStep_6 = MACHINING_WORKINGSTEP("MWS 6", l_itsSecPlane, l_GOP_1, l_itsMoperation_6, NULL);
		/***************************Executable list for type 1*****************/
		l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_itsMWStep_6);
		l_theListIn_ex->push_back(l_itsMWStep_1);
		l_theListIn_ex->push_back(l_itsMWStep_3);
		//l_theListIn_ex->push_back(l_itsMWStep_2);
		//l_theListIn_ex->push_back(l_itsMWStep_4);
		//l_theListIn_ex->push_back(l_itsMWStep_5);
		l_itsElementsIn_1 = new parenExecutableList(l_theListIn_ex);

		/************************Channel****************************/
		l_channel = CHANNEL("Channel 1");

		/******************Setup****************************/
		//Its sec plane
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 100.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_positionIn = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		l_itssecplane = ELEMENTARY_SURFACE("Sec Plane", l_positionIn);
		//itsorigin
		l_locationIn = CARTESIAN_POINT(NULL, 30.0, 30.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_itsOrigin = AXIS2_PLACEMENT_3D("Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		//The workpiece
		l_locationIn = CARTESIAN_POINT(NULL, 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_blockOrigin = AXIS2_PLACEMENT_3D(NULL, l_locationIn, l_axisIn, l_refDirectionIn);
		itsblock = BLOCK("Block", l_blockOrigin, 100.0, 140.0, 40.0);
		l_theworkpiece = WORKPIECE("Bruto", NULL, NULL, NULL, NULL, itsblock, NULL);
		//The workpiece setup
		l_locationIn = CARTESIAN_POINT(NULL, 10.0, 10.0, 0.0);
		l_axisIn = DIRECTION(NULL, 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION(NULL, 1.0, 0.0, 0.0);
		l_workpieceSetupOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		itsWorkpieceSetupIn = SINGLE_WORKPIECE_SETUP(l_theworkpiece, l_workpieceSetupOrigin, NULL, NULL, NULL);
		l_itsSetupIn = SETUP("Setup 1", l_itsOrigin, l_itssecplane, itsWorkpieceSetupIn);

		/********************Type 1 Process plan*****************/
		WP = WORKPLAN("Workplan T1", l_itsElementsIn_1, l_channel, l_itsSetupIn, NULL);

		ProcessPlan PP_3_1 = ProcessPlan(1, 3, 1);
		PP_3_1.addSubphase(1, 1, WP);
		Family_3.addProcessPlan(PP_3_1, 1);

		//Insert Families into the FamilyMap
		try{
			sm_umapFamilyMap.insert(std::pair<TForteUInt16, PP_Family>(1, Family_1));
			sm_umapFamilyMap.insert(std::pair<TForteUInt16, PP_Family>(2, Family_2));
			sm_umapFamilyMap.insert(std::pair<TForteUInt16, PP_Family>(3, Family_3));
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