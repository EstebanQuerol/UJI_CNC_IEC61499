/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_Counter
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "T1_Counter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T1_Counter_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_T1_Counter, g_nStringIdT1_Counter)

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdsProgram};

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdARRAY, 8, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdsBlock};

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_T1_Counter::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_T1_Counter::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_T1_Counter::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_T1_Counter::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_T1_Counter::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_T1_Counter::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anInternalsNames[] = {g_nStringIdIns_Counter};

const CStringDictionary::TStringId FORTE_T1_Counter::scm_anInternalsTypeIds[] = {g_nStringIdINT};

const SFBInterfaceSpec FORTE_T1_Counter::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_T1_Counter::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_T1_Counter::setInitialValues(){
  QI() = true;
  sProgram_Array().fromString("[0,0,0,0,0,0,0,0]");
  sBlock() = "Empty";
  Ins_Counter() = 0;
}

void FORTE_T1_Counter::alg_INIT(void){
QI() = true;
Ins_Counter() = 0;
}

void FORTE_T1_Counter::alg_REQ(void){
if((Ins_Counter() <= 7)){
	sBlock() = sProgram()[Ins_Counter()];
	Ins_Counter() = Ins_Counter()+1;
	QO() = true;
}
else{
	/* Default instructions here*/
	QO() = false;
}

//ib = (sBlock()).toString(st, 180);
//if (ib == -1){
//	printf("ERROR tostring \n");
//}
//
//printf("sBlock: %s\n", st);
//
//
//
//ib = sProgram_Array().toString(st, 180);
//
////ib = (sProgram()[1]).toString(st, 20);
//if (ib == -1){
//	printf("ERROR tostring \n");
//}
//else{
//
//	printf("sProgram: %s\n", st);
//}
}


void FORTE_T1_Counter::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_T1_Counter::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_T1_Counter::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_T1_Counter::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if((scm_nEventREQID == pa_nEIID) && (QI()))
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
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


