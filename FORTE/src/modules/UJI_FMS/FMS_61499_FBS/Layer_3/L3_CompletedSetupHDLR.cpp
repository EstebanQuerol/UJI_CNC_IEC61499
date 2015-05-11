/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_CompletedSetupHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_CompletedSetupHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_CompletedSetupHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_CompletedSetupHDLR, g_nStringIdL3_CompletedSetupHDLR)

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anDataInputNames[] = {g_nStringIdPartInfo};

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 4, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anDataOutputNames[] = {g_nStringIdPartIDOut, g_nStringIdPartInfoOut};

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdARRAY, 4, g_nStringIdUINT};

const TForteInt16 FORTE_L3_CompletedSetupHDLR::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_L3_CompletedSetupHDLR::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anEventInputNames[] = {g_nStringIdREQ1, g_nStringIdREQ};

const TDataIOID FORTE_L3_CompletedSetupHDLR::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_L3_CompletedSetupHDLR::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anEventOutputNames[] = {g_nStringIdCNF1, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anInternalsNames[] = {g_nStringIdPartBuffer, g_nStringIdTailIndex, g_nStringIdHeadIndex, g_nStringIdBufferSize};

const CStringDictionary::TStringId FORTE_L3_CompletedSetupHDLR::scm_anInternalsTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_CompletedSetupHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_CompletedSetupHDLR::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_CompletedSetupHDLR::setInitialValues(){
  PartBuffer_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
  TailIndex() = 0;
  HeadIndex() = 0;
  BufferSize() = 15;
}

void FORTE_L3_CompletedSetupHDLR::alg_REQ(void){
/* Stack the received part*/
PartBuffer()[HeadIndex()] = PartInfo()[0];

/* PostIncrement HeadIndex*/
HeadIndex() = HeadIndex()+1;
if((HeadIndex() >= BufferSize())){
	/* HeadIndex =% 15*/
	HeadIndex() = 0;
};

/* Check if buffer is full*/
if((HeadIndex() == TailIndex())){
	/* Buffer is full, HeadIndex can't be incremented*/
	if((HeadIndex() == 0)){
		HeadIndex() = BufferSize()-1;
	}
else{
		HeadIndex() = HeadIndex()-1;
	};	
};

/* Map the response to the right machine*/
int h = PartInfo()[3];
PartInfoOut()[0] = PartInfo()[0];
PartInfoOut()[1] = PartInfo()[1];
PartInfoOut()[2] = PartInfo()[2];
PartInfoOut()[3] = PartInfo()[3];
}

void FORTE_L3_CompletedSetupHDLR::alg_REQ1(void){
if((HeadIndex() == TailIndex())){
	/* Buffer is empty*/
	PartIDOut() = 0;
}
else{
	PartIDOut() = PartBuffer()[TailIndex()];
	/* Increase tail index*/
	TailIndex() = TailIndex()+1;
	if((TailIndex() >= BufferSize())){
		/*  TaiIndex =% 15*/
		TailIndex() = 0;
	};
};
}


void FORTE_L3_CompletedSetupHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_CompletedSetupHDLR::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L3_CompletedSetupHDLR::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ1();
  sendOutputEvent( scm_nEventCNF1ID);
}

void FORTE_L3_CompletedSetupHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateREQ1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
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


