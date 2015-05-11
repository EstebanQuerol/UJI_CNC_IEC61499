/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ReleasedMHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_ReleasedMHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_ReleasedMHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_ReleasedMHDLR, g_nStringIdL3_ReleasedMHDLR)

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anDataInputNames[] = {g_nStringIdMID};

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anDataOutputNames[] = {g_nStringIdMReleased};

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT};

const TForteInt16 FORTE_L3_ReleasedMHDLR::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_L3_ReleasedMHDLR::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anEventInputNames[] = {g_nStringIdREQ1, g_nStringIdREQ2};

const TDataIOID FORTE_L3_ReleasedMHDLR::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L3_ReleasedMHDLR::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anEventOutputNames[] = {g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anInternalsNames[] = {g_nStringIdReleasedMachines, g_nStringIdi};

const CStringDictionary::TStringId FORTE_L3_ReleasedMHDLR::scm_anInternalsTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_ReleasedMHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_ReleasedMHDLR::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_ReleasedMHDLR::setInitialValues(){
  ReleasedMachines_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
}

void FORTE_L3_ReleasedMHDLR::alg_REQ2(void){
/* This algo send to the core the released machines and resets the internal vector*/
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (14))) ||
            ((!isi_Up) && (i() < (14))))){

		MReleased()[i()] = ReleasedMachines()[i()];
		ReleasedMachines()[i()] = 0;

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

void FORTE_L3_ReleasedMHDLR::alg_REQ1(void){
if((MID() > 0) && (MID() < 15)){
	ReleasedMachines()[MID()-1] = 2;
};
}


void FORTE_L3_ReleasedMHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_ReleasedMHDLR::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  alg_REQ2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_ReleasedMHDLR::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ1();
}

void FORTE_L3_ReleasedMHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateREQ2();
        else
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateREQ1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ1:
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


