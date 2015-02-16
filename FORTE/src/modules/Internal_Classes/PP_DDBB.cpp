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
		workplan * l_Ex_1 = new workplan();
		pacTempID = (char *)forte_malloc(sizeof(char)* 13);
		strcpy(pacTempID, "WorkPlan 1_1");
		l_Ex_1->set_itsId(pacTempID);
		l_Ex_1->set_itsElements(NULL);

		workplan * l_Ex_2 = new workplan();
		pacTempID = (char *)forte_malloc(sizeof(char)* 13);
		strcpy(pacTempID, "WorkPlan 1_2");
		l_Ex_2->set_itsId(pacTempID);
		l_Ex_2->set_itsElements(NULL);

		std::list<executable *> * l_theListIn_ex = new std::list<executable *>;
		l_theListIn_ex->push_back(l_Ex_2);
		l_theListIn_ex->push_back(l_Ex_1);

		parenExecutableList * l_itsElementsIn = new parenExecutableList(l_theListIn_ex);

		//channel
		pacTempID = (char *)forte_malloc(sizeof(char)* 10);
		strcpy(pacTempID, "channel_1");
		channel * l_channel = new channel(pacTempID);
		//channel * l_channel = new channel();
		//setup
			//itsorigin
		std::list<real *> * l_theListIn = new std::list<real *>;
		real * l_x = new real(0.0);
		real * l_y = new real(1.0);
		real * l_z = new real(1.0);
		(*l_theListIn).emplace_back(l_z);
		(*l_theListIn).emplace_back(l_y);
		(*l_theListIn).emplace_back(l_x);
		parenRealListFull * l_coordinates = new parenRealListFull(l_theListIn);
		cartesianPoint * l_locationIn = new cartesianPoint(NULL, l_coordinates);
		std::list<real *> * l_theListIn_d = new std::list<real *>;
		real * l_dx = new real(0.0);
		real * l_dy = new real(0.0);
		real * l_dz = new real(1.0);
		(*l_theListIn_d).emplace_back(l_dz);
		(*l_theListIn_d).emplace_back(l_dy);
		(*l_theListIn_d).emplace_back(l_dx);
		parenRealListFull * l_coordinates_d = new parenRealListFull(l_theListIn_d);
		direction * l_axisIn = new direction(NULL, l_coordinates_d);
		std::list<real *> * l_theListIn_ref = new std::list<real *>;
		real * l_refx = new real(0.0);
		real * l_refy = new real(0.0);
		real * l_refz = new real(1.0);
		(*l_theListIn_ref).emplace_back(l_refz);
		(*l_theListIn_ref).emplace_back(l_refy);
		(*l_theListIn_ref).emplace_back(l_refx);
		parenRealListFull * l_coordinates_ref = new parenRealListFull(l_theListIn_ref);
		direction * l_refDirectionIn = new direction(NULL, l_coordinates_ref);
		axis2placement3d * l_itsOrigin = new axis2placement3d(NULL, l_locationIn, l_axisIn, l_refDirectionIn);

		std::list<real *> * l_theListIn_2 = new std::list<real *>;
		real * l_x_2 = new real(0.0);
		real * l_y_2 = new real(1.0);
		real * l_z_2 = new real(1.0);
		(*l_theListIn_2).emplace_back(l_z_2);
		(*l_theListIn_2).emplace_back(l_y_2);
		(*l_theListIn_2).emplace_back(l_x_2);
		parenRealListFull * l_coordinates_2 = new parenRealListFull(l_theListIn_2);
		cartesianPoint * l_locationIn_2 = new cartesianPoint(NULL, l_coordinates_2);
		std::list<real *> * l_theListIn_d_2 = new std::list<real *>;
		real * l_dx_2 = new real(0.0);
		real * l_dy_2 = new real(0.0);
		real * l_dz_2 = new real(1.0);
		(*l_theListIn_d_2).emplace_back(l_dz_2);
		(*l_theListIn_d_2).emplace_back(l_dy_2);
		(*l_theListIn_d_2).emplace_back(l_dx_2);
		parenRealListFull * l_coordinates_d_2 = new parenRealListFull(l_theListIn_d_2);
		direction * l_axisIn_2 = new direction(NULL, l_coordinates_d_2);
		std::list<real *> * l_theListIn_ref_2 = new std::list<real *>;
		real * l_refx_2 = new real(0.0);
		real * l_refy_2 = new real(0.0);
		real * l_refz_2 = new real(1.0);
		(*l_theListIn_ref_2).emplace_back(l_refz_2);
		(*l_theListIn_ref_2).emplace_back(l_refy_2);
		(*l_theListIn_ref_2).emplace_back(l_refx_2);
		parenRealListFull * l_coordinates_ref_2 = new parenRealListFull(l_theListIn_ref_2);
		direction * l_refDirectionIn_2 = new direction(NULL, l_coordinates_ref_2);
		axis2placement3d * l_positionIn = new axis2placement3d(NULL, l_locationIn_2, l_axisIn_2, l_refDirectionIn_2);

		elementarySurface * l_itssecplane = new elementarySurface(NULL, l_positionIn);
		setup * l_itsSetupIn = new setup(NULL, l_itsOrigin, l_itssecplane, NULL);

		//Build the Workplan
		workplan * WP1 = new workplan(l_itsID, l_itsElementsIn, l_channel, l_itsSetupIn, NULL);
		newPP.addSubphase(1, 1, WP1);

		workplan * newWP2 = new workplan();
		pacTempID = (char *)forte_malloc(sizeof(char)* 11);
		strcpy(pacTempID, "WorkPlan 2");
		newWP2->set_itsId(pacTempID);
		newWP2->set_itsElements(NULL);
		newPP.addSubphase(2, 1, newWP2);

		workplan * newWP3 = new workplan();
		pacTempID = (char *)forte_malloc(sizeof(char)* 11);
		strcpy(pacTempID, "WorkPlan 3");
		newWP3->set_itsId(pacTempID);
		newWP3->set_itsElements(NULL);
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