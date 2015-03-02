#include "PPArray.h"

bool PPArray::sm_bInitialized = false;
ProcessPlan PPArray::sm_aPParray[scm_nFamilyMax][scm_nTypeMax] = { };
PPArray::PPArray()
{
}


PPArray::~PPArray()
{
}

ProcessPlan * PPArray::getProcessPlan(TForteUInt16 pa_nFamily, TForteUInt16 pa_nType){
	if (pa_nFamily >= 1 && pa_nFamily <= scm_nFamilyMax){
		if (pa_nType >= 1 && pa_nType <= scm_nTypeMax){
			return &sm_aPParray[pa_nFamily - 1][pa_nType - 1];
		}
	}
	return NULL;
}

void PPArray::Initilizate()
{
	if (!sm_bInitialized){
		sm_bInitialized = true;
		TForteUInt16 nFamily;
		TForteUInt16 nType;
		TForteUInt16 nSetupIndex;

		//Init process plan array
		//Family 1, Type 1
		nFamily = 1;
		nType = 1;
		sm_aPParray[nFamily - 1][nType - 1] = ProcessPlan(2, nFamily, nType);
			//Setup 1
			nSetupIndex = 1;
			sm_aPParray[nFamily - 1][nType - 1].addSetup(nSetupIndex, 1, 3, "Fixture1");
				//Operation 1
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 1, 1, "Toto");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 2, 1, "Titi");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 3, 1, "Tata");
			//Setup 2
			nSetupIndex = 2;
			sm_aPParray[nFamily - 1][nType - 1].addSetup(nSetupIndex, 1, 3, "Fixture2");
				//Operation 1
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 1, 1, "Toto2");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 2, 1, "Titi2");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 3, 1, "Tata2");

		//Family 1, Type 1
		nFamily = 1;
		nType = 2;
		sm_aPParray[nFamily - 1][nType - 1] = ProcessPlan(2, nFamily, nType);
			//Setup 1
			nSetupIndex = 1;
			sm_aPParray[nFamily - 1][nType - 1].addSetup(nSetupIndex, 1, 3, "Fixture11");
				//Operation 1
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 1, 1, "Toto1");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 2, 1, "Titi2");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 3, 1, "Tata3");
			//Setup 2
			nSetupIndex = 2;
			sm_aPParray[nFamily - 1][nType - 1].addSetup(nSetupIndex, 1, 3, "Fixture22");
				//Operation 1
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 1, 1, "Toto4");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 2, 1, "Titi5");
				//Operation 2
				sm_aPParray[nFamily - 1][nType - 1].addOperation(nSetupIndex, 3, 1, "Tata6");
				


	}
}
