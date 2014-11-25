/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ReceivePart
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_ReceivePart.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_ReceivePart_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_ReceivePart, g_nStringIdL3_ReceivePart)

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anDataInputNames[] = {g_nStringIdPartIDIn, g_nStringIdFamilyIn, g_nStringIdTypeIn, g_nStringIdDeadline};

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anDataOutputNames[] = {g_nStringIdPartIDOut, g_nStringIdFamilyOut, g_nStringIdTypeOut, g_nStringIdFamilyS, g_nStringIdTypeS, g_nStringIdDeadlineS};

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_ReceivePart::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_L3_ReceivePart::scm_anEIWith[] = {0, 1, 2, 255, 3, 255};
const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_L3_ReceivePart::scm_anEOWith[] = {0, 1, 2, 255, 5, 4, 3, 255};
const TForteInt16 FORTE_L3_ReceivePart::scm_anEOWithIndexes[] = {0, 4, -1};
const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anInternalsNames[] = {g_nStringIdCurrentID, g_nStringIdCurrentFamily, g_nStringIdCurrentType, g_nStringIdLostIND, g_nStringIdCompletedIDS, g_nStringIdCompletedFamilies, g_nStringIdCompletedTypes, g_nStringIdCompletedDeadlines, g_nStringIdIndex, g_nStringIdi};

const CStringDictionary::TStringId FORTE_L3_ReceivePart::scm_anInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdARRAY, 25, g_nStringIdUINT, g_nStringIdARRAY, 25, g_nStringIdUINT, g_nStringIdARRAY, 25, g_nStringIdUINT, g_nStringIdARRAY, 25, g_nStringIdDATE_AND_TIME, g_nStringIdUINT, g_nStringIdUINT};

const SFBInterfaceSpec FORTE_L3_ReceivePart::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  6,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_ReceivePart::scm_stInternalVars = {10, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_ReceivePart::setInitialValues(){
  CompletedIDS_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
  Index() = 0;
}

void FORTE_L3_ReceivePart::alg_REQ(void){
/* Update current action data*/
CurrentID() = PartIDIn();
CurrentFamily() = FamilyIn();
CurrentType() = TypeIn();
/* Map input to output*/
PartIDOut() = PartIDIn();
FamilyOut() = FamilyIn();
TypeOut() = TypeIn();
}

void FORTE_L3_ReceivePart::alg_HDL(void){
/* New request arrived while processing one*/
/* Verify if the request is a previously completed action*/
i() = 0;
LostIND() = false;
while((((i() < 25)))){

	if((((PartIDIn() == CompletedIDS()[i()])))){
		/* Received request has already been processed*/
		/* Send IND*/
		LostIND() = true;
		/* Update output values*/
		FamilyS() = CompletedFamilies()[i()];
		TypeS() = CompletedTypes()[i()];
		DeadlineS() = CompletedDeadlines()[i()];
		/* exit loop*/
		i() = 26;
	}
else{
		i() = i()+1;
	};
};
}

void FORTE_L3_ReceivePart::alg_RSP(void){
/* Completed Action*/
CompletedIDS()[Index()] = CurrentID();
CompletedFamilies()[Index()] = CurrentFamily();
CompletedTypes()[Index()] = CurrentType();
CompletedDeadlines()[Index()] = Deadline();

/* Increase Index*/
Index() = (Index() + 1) % 25;

/* Map input to output*/
FamilyS() = CurrentFamily();
TypeS() = CurrentType();
DeadlineS() = Deadline();


}


void FORTE_L3_ReceivePart::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_ReceivePart::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_ReceivePart::enterStateREQUESTING(void){
  m_nECCState = scm_nStateREQUESTING;
}

void FORTE_L3_ReceivePart::enterStateREQHANDLER(void){
  m_nECCState = scm_nStateREQHANDLER;
  alg_HDL();
}

void FORTE_L3_ReceivePart::enterStateLOSTIND(void){
  m_nECCState = scm_nStateLOSTIND;
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L3_ReceivePart::enterStateRSP(void){
  m_nECCState = scm_nStateRSP;
  alg_RSP();
  sendOutputEvent( scm_nEventINDID);
}

void FORTE_L3_ReceivePart::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateREQUESTING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQUESTING:
        if(scm_nEventRSPID == pa_nEIID)
          enterStateRSP();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQHANDLER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQHANDLER:
        if(LostIND() == true)
          enterStateLOSTIND();
        else
        if(LostIND() == false)
          enterStateREQUESTING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLOSTIND:
        if(1)
          enterStateREQUESTING();
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
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


