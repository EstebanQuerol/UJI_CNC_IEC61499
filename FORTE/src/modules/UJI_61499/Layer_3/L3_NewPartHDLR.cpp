/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_NewPartHDLR
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-04/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_NewPartHDLR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_NewPartHDLR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_NewPartHDLR, g_nStringIdL3_NewPartHDLR)

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anDataInputNames[] = {g_nStringIdPartIDIn, g_nStringIdLotsizeIn, g_nStringIdDeadlineIn};

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anDataOutputNames[] = {g_nStringIdPartIDOut, g_nStringIdLotsizeOut, g_nStringIdDeadlineOut};

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const TForteInt16 FORTE_L3_NewPartHDLR::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_L3_NewPartHDLR::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anEventInputNames[] = {g_nStringIdREQ1, g_nStringIdREQ2};

const TDataIOID FORTE_L3_NewPartHDLR::scm_anEOWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_L3_NewPartHDLR::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anEventOutputNames[] = {g_nStringIdCNF1, g_nStringIdCNF2};

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anInternalsNames[] = {g_nStringIdPartBuffer, g_nStringIdSizesBuffer, g_nStringIdDeadlinesBuffer, g_nStringIdHeadIndex, g_nStringIdTailIndex, g_nStringIdBufferSize};

const CStringDictionary::TStringId FORTE_L3_NewPartHDLR::scm_anInternalsTypeIds[] = {g_nStringIdARRAY, 10, g_nStringIdUINT, g_nStringIdARRAY, 10, g_nStringIdUINT, g_nStringIdARRAY, 10, g_nStringIdDATE_AND_TIME, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_L3_NewPartHDLR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_L3_NewPartHDLR::scm_stInternalVars = {6, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_L3_NewPartHDLR::setInitialValues(){
  PartBuffer_Array().fromString("[0,0,0,0,0,0,0,0,0,0]");
  SizesBuffer_Array().fromString("[0,0,0,0,0,0,0,0,0,0]");
  HeadIndex() = 0;
  TailIndex() = 0;
  BufferSize() = 10;
}

void FORTE_L3_NewPartHDLR::alg_REQ1(void){
if((PartBuffer()[HeadIndex()] != PartIDIn())){
	/* Stack the received order*/
	PartBuffer()[HeadIndex()] = PartIDIn();
	SizesBuffer()[HeadIndex()] = LotsizeIn();
	DeadlinesBuffer()[HeadIndex()] = DeadlineIn();
	
	/* PostIncrement HeadIndex*/
	HeadIndex() = HeadIndex()+1;
	if((HeadIndex() >= BufferSize())){
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
}
else{
	/* Retransmited Order, RSP event must have been lost*/
	/* Do nothing and send CNF1 event*/
};
}

void FORTE_L3_NewPartHDLR::alg_REQ2(void){
if((HeadIndex() == TailIndex())){
	/* Buffer is empty*/
	PartIDOut() = 0;
	LotsizeOut() = 0;
	DeadlineOut() = 0;
}
else{
	PartIDOut() = PartBuffer()[TailIndex()];
	LotsizeOut() = SizesBuffer()[TailIndex()];
	DeadlineOut() = DeadlinesBuffer()[TailIndex()];
	/* Increase tail index*/
	TailIndex() = TailIndex()+1;
	if((TailIndex() >= BufferSize())){
		TailIndex() = 0;
	};
};
}


void FORTE_L3_NewPartHDLR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L3_NewPartHDLR::enterStateREQ1(void){
  m_nECCState = scm_nStateREQ1;
  alg_REQ1();
  sendOutputEvent( scm_nEventCNF1ID);
}

void FORTE_L3_NewPartHDLR::enterStateREQ2(void){
  m_nECCState = scm_nStateREQ2;
  alg_REQ2();
  sendOutputEvent( scm_nEventCNF2ID);
}

void FORTE_L3_NewPartHDLR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateREQ1();
        else
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateREQ2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ2:
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


