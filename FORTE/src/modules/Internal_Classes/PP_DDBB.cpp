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
		//TODO: Add code to initialize the data base
	
		char * pacTempID;

		//Test code
		//Ceate Family "1"
		PP_Family newFamiliy = PP_Family(1);
		ProcessPlan newPP = ProcessPlan(3, 1, 1);

		//Build a new Workplan
		// itsID
		char * l_itsID = (char *)forte_malloc(sizeof(char)* 11);
		strcpy(l_itsID, "WorkPlan 1");

		//parenExecutableList
		executable * l_Ex_1 = new workplan(NULL, NULL, NULL, NULL, NULL);
		pacTempID = (char *)forte_malloc(sizeof(char)* 13);
		strcpy(pacTempID, "WorkPlan 1_1");
		l_Ex_1->set_itsId(pacTempID);


		executable * l_Ex_2 = new workplan(NULL, NULL, NULL, NULL, NULL);
		pacTempID = (char *)forte_malloc(sizeof(char)* 13);
		strcpy(pacTempID, "WorkPlan 1_2");
		l_Ex_2->set_itsId(pacTempID);


		std::list<executable *> * l_theListIn_ex = new std::list<executable *>;
		//polimorfismo executable-workplan
		l_theListIn_ex->push_back(l_Ex_1);
		l_theListIn_ex->push_back(l_Ex_2);

		parenExecutableList * l_itsElementsIn = new parenExecutableList(l_theListIn_ex);

		//channel
		channel * l_channel = CHANNEL("Channel 1");

		//Setup
		//Its sec plane
		cartesianPoint * l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 30.0);
		direction * l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		direction * l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		axis2placement3d * l_positionIn = AXIS2_PLACEMENT_3D("Position", l_locationIn, l_axisIn, l_refDirectionIn);
		elementarySurface * l_itssecplane = ELEMENTARY_SURFACE("Sec Plane", l_positionIn);
		//itsorigin
		l_locationIn = CARTESIAN_POINT("Point", 55.0, 66.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 0.0, 0.0, 1.0);
		axis2placement3d * l_itsOrigin = AXIS2_PLACEMENT_3D("Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		//The workpiece
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		axis2placement3d * l_blockOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		block * itsblock = BLOCK("Block", l_blockOrigin, 100.0, 100.0, 100.0);
		workpiece * l_theworkpiece = WORKPIECE("Bruto", NULL, NULL, NULL, NULL, itsblock, NULL);
		//The workpiece setup
		l_locationIn = CARTESIAN_POINT("Point", 0.0, 0.0, 0.0);
		l_axisIn = DIRECTION("Axis", 0.0, 0.0, 1.0);
		l_refDirectionIn = DIRECTION("Ref_Axis", 1.0, 0.0, 0.0);
		axis2placement3d * l_workpieceSetupOrigin = AXIS2_PLACEMENT_3D("WP Origin", l_locationIn, l_axisIn, l_refDirectionIn);
		parenWorkpieceSetupList * itsWorkpieceSetupIn = SINGLE_WORKPIECE_SETUP(l_theworkpiece, l_workpieceSetupOrigin, NULL, NULL, NULL);
		setup * l_itsSetupIn = SETUP("Setup 1", l_itsOrigin, l_itssecplane, itsWorkpieceSetupIn);

		//Build the Workplan
		workplan * WP1 = new workplan(l_itsID, l_itsElementsIn, l_channel, l_itsSetupIn, NULL);
		newPP.addSubphase(1, 1, WP1);

		workplan * newWP2 = new workplan(NULL, NULL, NULL, NULL, NULL);
		pacTempID = (char *)forte_malloc(sizeof(char)* 11);
		strcpy(pacTempID, "WorkPlan 2");
		newWP2->set_itsId(pacTempID);
		newPP.addSubphase(2, 1, newWP2);

		workplan * newWP3 = new workplan(NULL, NULL, NULL, NULL, NULL);
		pacTempID = (char *)forte_malloc(sizeof(char)* 11);
		strcpy(pacTempID, "WorkPlan 3");
		newWP3->set_itsId(pacTempID);
		newPP.addSubphase(3, 1, newWP3);

		newFamiliy.addProcessPlan(newPP, 1);



		std::pair<TForteUInt16, PP_Family> newpair(1, newFamiliy);
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