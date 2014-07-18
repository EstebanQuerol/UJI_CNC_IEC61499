/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CONTROL_SET2
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-24/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_CONTROL_SET2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CONTROL_SET2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_CONTROL_SET2, g_nStringIdFB_CONTROL_SET2)

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anDataInputNames[] = {g_nStringIdKS, g_nStringIdTU, g_nStringIdTG, g_nStringIdP_K, g_nStringIdPI_K, g_nStringIdPI_TN, g_nStringIdPID_K, g_nStringIdPID_TN, g_nStringIdPID_TV};

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anDataOutputNames[] = {g_nStringIdKP, g_nStringIdTN, g_nStringIdTV, g_nStringIdKI, g_nStringIdKD};

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_FB_CONTROL_SET2::scm_anEIWithIndexes[] = {0, 4, 8};
const TDataIOID FORTE_FB_CONTROL_SET2::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anEventInputNames[] = {g_nStringIdREQ_P, g_nStringIdREQ_PI, g_nStringIdREQ_PID};

const TDataIOID FORTE_FB_CONTROL_SET2::scm_anEOWith[] = {0, 255, 0, 1, 3, 255, 0, 1, 2, 3, 4, 255};
const TForteInt16 FORTE_FB_CONTROL_SET2::scm_anEOWithIndexes[] = {0, 2, 6};
const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anEventOutputNames[] = {g_nStringIdCNF_P, g_nStringIdCNF_PI, g_nStringIdCNF_PID};

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anInternalsNames[] = {g_nStringIdTX};

const CStringDictionary::TStringId FORTE_FB_CONTROL_SET2::scm_anInternalsTypeIds[] = {g_nStringIdREAL};

const SFBInterfaceSpec FORTE_FB_CONTROL_SET2::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  9,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_CONTROL_SET2::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_FB_CONTROL_SET2::setInitialValues(){
  P_K() = 1.0f;
  PI_K() = 0.9f;
  PI_TN() = 3.33f;
  PID_K() = 1.2f;
  PID_TN() = 2.0f;
  PID_TV() = 0.5f;
}

void FORTE_FB_CONTROL_SET2::alg_REQ_P(void){
/*  Testing new idea planed for IEC61499-5 that allows to call other algs */
  alg_CALC_TX();

KP() = P_K()*TX();
}

void FORTE_FB_CONTROL_SET2::alg_REQ_PI(void){
/*  Testing new idea planed for IEC61499-5 that allows to call other algs */
  alg_CALC_TX();

KP() = PI_K()*TX();
TN() = PI_TN()*TU();		

alg_CALC_KI();
}

void FORTE_FB_CONTROL_SET2::alg_REQ_PID(void){
/*  Testing new idea planed for IEC61499-5 that allows to call other algs */
  alg_CALC_TX();

KP() = PID_K()*TX();
TN() = PID_TN()*TU();
TV() = PID_TV()*TU();	

alg_CALC_KI();

KD() = KP()*TV();
}

void FORTE_FB_CONTROL_SET2::alg_CALC_TX(void){
TX() = 0.0;
if((TU() > 0.0) && (KS() > 0.0)){TX() = TG()/TU()/KS();};
}

void FORTE_FB_CONTROL_SET2::alg_CALC_KI(void){
if((TN() > 0.0)){KI() = KP()/TN();}
else{KI() = 0.0;};
}


void FORTE_FB_CONTROL_SET2::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_CONTROL_SET2::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ_P();
  sendOutputEvent( scm_nEventCNF_PID);
}

void FORTE_FB_CONTROL_SET2::enterStateREQ_PI(void){
  m_nECCState = scm_nStateREQ_PI;
  alg_REQ_PI();
  sendOutputEvent( scm_nEventCNF_PIID);
}

void FORTE_FB_CONTROL_SET2::enterStateREQ_PID(void){
  m_nECCState = scm_nStateREQ_PID;
  alg_REQ_PID();
  sendOutputEvent( scm_nEventCNF_PIDID);
}

void FORTE_FB_CONTROL_SET2::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQ_PID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventREQ_PIID == pa_nEIID)
          enterStateREQ_PI();
        else
        if(scm_nEventREQ_PIDID == pa_nEIID)
          enterStateREQ_PID();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ_PI:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ_PID:
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


