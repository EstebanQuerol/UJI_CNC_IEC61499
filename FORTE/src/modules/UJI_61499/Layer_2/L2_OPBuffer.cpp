/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_OPBuffer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2014-11-28/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_OPBuffer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_OPBuffer_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_OPBuffer, g_nStringIdL2_OPBuffer)

const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anDataInputNames[] = {g_nStringIdOPIDIn, g_nStringIdOPParamsIn, g_nStringIdFixtureIn, g_nStringIdNextOP};

const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 20, g_nStringIdUINT, g_nStringIdARRAY, 20, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anDataOutputNames[] = {g_nStringIdOPIDOut, g_nStringIdOPParamsOut, g_nStringIdFixtureOut};

const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_L2_OPBuffer::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_L2_OPBuffer::scm_anEIWith[] = {0, 1, 2, 255, 3, 255};
const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anEventInputNames[] = {g_nStringIdRENEW, g_nStringIdNEXT};

const TDataIOID FORTE_L2_OPBuffer::scm_anEOWith[] = {2, 255, 0, 1, 255};
const TForteInt16 FORTE_L2_OPBuffer::scm_anEOWithIndexes[] = {-1, 0, 2, -1};
const CStringDictionary::TStringId FORTE_L2_OPBuffer::scm_anEventOutputNames[] = {g_nStringIdCNF0, g_nStringIdCNF1, g_nStringIdCNF2};

const SFBInterfaceSpec FORTE_L2_OPBuffer::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L2_OPBuffer::setInitialValues(){
  OPIDIn_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
  OPIDOut() = 0;
}

void FORTE_L2_OPBuffer::alg_SetFixture(void){
FixtureOut() = FixtureIn();
}

void FORTE_L2_OPBuffer::alg_SetOP(void){
OPIDOut() = OPIDIn()[NextOP()-1];
OPParamsOut() = OPParamsIn()[NextOP()-1];
}


void FORTE_L2_OPBuffer::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_L2_OPBuffer::enterStateRENEW(void){
  m_nECCState = scm_nStateRENEW;
  sendOutputEvent( scm_nEventCNF0ID);
}

void FORTE_L2_OPBuffer::enterStateSetFixture(void){
  m_nECCState = scm_nStateSetFixture;
  alg_SetFixture();
  sendOutputEvent( scm_nEventCNF1ID);
}

void FORTE_L2_OPBuffer::enterStateSetOP(void){
  m_nECCState = scm_nStateSetOP;
  alg_SetOP();
  sendOutputEvent( scm_nEventCNF2ID);
}

void FORTE_L2_OPBuffer::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventRENEWID == pa_nEIID)
          enterStateRENEW();
        else
        if((scm_nEventNEXTID == pa_nEIID) && (NextOP() == 0))
          enterStateSetFixture();
        else
        if((scm_nEventNEXTID == pa_nEIID) && (NextOP() != 0))
          enterStateSetOP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRENEW:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSetFixture:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSetOP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


