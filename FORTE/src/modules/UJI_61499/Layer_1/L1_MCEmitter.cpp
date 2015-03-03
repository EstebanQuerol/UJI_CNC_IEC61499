/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_MCEmitter
 *** Description: Layer 1 multicast emitter
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_MCEmitter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_MCEmitter_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_MCEmitter, g_nStringIdL1_MCEmitter)

const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anDataInputNames[] = {g_nStringIdOperationIn, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anDataOutputNames[] = {g_nStringIdOperationOut, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_MCEmitter::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_MCEmitter::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_MCEmitter::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_MCEmitter::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_MCEmitter::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_MCEmitter::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_L1_MCEmitter::alg_REQ(void){
OperationIn() = OperationOut();
L1MIDIn() = L1MIDOut();
}


void FORTE_L1_MCEmitter::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L1_MCEmitter::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_L1_MCEmitter::executeEvent(int pa_nEIID){
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
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


