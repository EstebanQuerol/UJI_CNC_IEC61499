/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_ASetupRSPHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_ASetupRSPHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_ASetupRSPHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_ASetupRSPHDLR, g_nStringIdL2_ASetupRSPHDLR)

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdMID, g_nStringIdPartInfo};

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_L2_ASetupRSPHDLR::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_L2_ASetupRSPHDLR::scm_anEIWith[] = {0, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdRSP};

const TDataIOID FORTE_L2_ASetupRSPHDLR::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L2_ASetupRSPHDLR::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anInternalsNames[] = {g_nStringIdAccepted};

const CStringDictionary::TStringId FORTE_L2_ASetupRSPHDLR::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_L2_ASetupRSPHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_ASetupRSPHDLR::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_ASetupRSPHDLR::setInitialValues(){
  Accepted() = false;
}

void FORTE_L2_ASetupRSPHDLR::alg_INIT(void){
QO() = QI();
}

void FORTE_L2_ASetupRSPHDLR::alg_RSP(void){
if((MID() == PartInfo()[3])){
	Accepted() = true;
}
else{
	Accepted() = false;
};
}


void FORTE_L2_ASetupRSPHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_ASetupRSPHDLR::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L2_ASetupRSPHDLR::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
}

void FORTE_L2_ASetupRSPHDLR::enterStateAccept(void){
  m_nECCState = scm_nStateAccept;
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L2_ASetupRSPHDLR::enterStateReject(void){
  m_nECCState = scm_nStateReject;
}

void FORTE_L2_ASetupRSPHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRSP:
        if(Accepted() == true)
          enterStateAccept();
        else
        if(Accepted() == false)
          enterStateReject();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateAccept:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReject:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


