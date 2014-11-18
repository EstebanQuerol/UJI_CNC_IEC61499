/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineChecker
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-06/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_MachineChecker.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_MachineChecker_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_MachineChecker, g_nStringIdL3_MachineChecker)

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anDataInputNames[] = {g_nStringIdMTypeIn, g_nStringIdMStateIn, g_nStringIdMPriorityIn, g_nStringIdMAssignIn, g_nStringIdPriority, g_nStringIdPartID};

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anDataOutputNames[] = {g_nStringIdMTypeOut, g_nStringIdMStateOut, g_nStringIdMPriorityOut, g_nStringIdMAssignOut};

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const TForteInt16 FORTE_L3_MachineChecker::scm_anEIWithIndexes[] = {0, 5};
const TDataIOID FORTE_L3_MachineChecker::scm_anEIWith[] = {0, 1, 2, 3, 255, 4, 5, 255};
const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_L3_MachineChecker::scm_anEOWith[] = {0, 1, 2, 3, 255, 0, 255};
const TForteInt16 FORTE_L3_MachineChecker::scm_anEOWithIndexes[] = {0, 5, -1};
const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anInternalsNames[] = {g_nStringIdi};

const CStringDictionary::TStringId FORTE_L3_MachineChecker::scm_anInternalsTypeIds[] = {g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_MachineChecker::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_MachineChecker::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_MachineChecker::setInitialValues(){
  i() = 0;
}

void FORTE_L3_MachineChecker::alg_RSP(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

	MTypeOut()[i()] = MTypeIn()[i()];
	MStateOut()[i()] = MStateIn()[i()];
	if((Priority()[i()] < MPriorityIn()[i()])){
		/* 1st to get into the vector has preference when prios are equal*/
		MPriorityOut()[i()] = Priority()[i()];
		MAssignOut()[i()] = PartID()[i()];
	}
else{
		MPriorityOut()[i()] = MPriorityIn()[i()];
		MAssignOut()[i()] = MAssignIn()[i()];		
	};

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;
}


void FORTE_L3_MachineChecker::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_MachineChecker::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L3_MachineChecker::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_MachineChecker::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


