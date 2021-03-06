/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_ASetupREQHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 ***     1.0: 2016-01-18/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_ASetupREQHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_ASetupREQHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_ASetupREQHDLR, g_nStringIdL2_ASetupREQHDLR)

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdMID, g_nStringIdPartInfoIn, g_nStringIdSetupIn};

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdMIDOut, g_nStringIdPartInfoOut, g_nStringIdSetupOut};

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdSTRING};

const TForteInt16 FORTE_L2_ASetupREQHDLR::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_L2_ASetupREQHDLR::scm_anEIWith[] = {1, 0, 255, 2, 3, 255};
const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L2_ASetupREQHDLR::scm_anEOWith[] = {0, 1, 255, 2, 1, 3, 255};
const TForteInt16 FORTE_L2_ASetupREQHDLR::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anInternalsNames[] = {g_nStringIdAccepted, g_nStringIdi};

const CStringDictionary::TStringId FORTE_L2_ASetupREQHDLR::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L2_ASetupREQHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L2_ASetupREQHDLR::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L2_ASetupREQHDLR::setInitialValues(){
  Accepted() = false;
  i() = 0;
}

void FORTE_L2_ASetupREQHDLR::alg_INIT(void){
QO() = QI();
MIDOut() = MID();
}

void FORTE_L2_ASetupREQHDLR::alg_REQ(void){
if((PartInfoIn()[3] == MID())){
	/* The received packet is for this machine, map outputs*/
	Accepted() = true;
	PartInfoOut()[0] = PartInfoIn()[0];
	PartInfoOut()[1] = PartInfoIn()[1];
	PartInfoOut()[2] = PartInfoIn()[2];
	PartInfoOut()[3] = PartInfoIn()[3];
	SetupOut() = SetupIn();
}
else{
	Accepted() = false;
};
}


void FORTE_L2_ASetupREQHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_ASetupREQHDLR::enterStateIDLE(void){
  m_nECCState = scm_nStateIDLE;
}

void FORTE_L2_ASetupREQHDLR::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_L2_ASetupREQHDLR::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_L2_ASetupREQHDLR::enterStateAcceptPacket(void){
  m_nECCState = scm_nStateAcceptPacket;
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L2_ASetupREQHDLR::enterStateRejectPacket(void){
  m_nECCState = scm_nStateRejectPacket;
}

void FORTE_L2_ASetupREQHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIDLE:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(QI())
          enterStateIDLE();
        else
        if(QI() == false)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(Accepted() == true)
          enterStateAcceptPacket();
        else
        if(Accepted() == false)
          enterStateRejectPacket();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateAcceptPacket:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRejectPacket:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


