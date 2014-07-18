/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_PIWL
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PIWL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PIWL_gen.cpp"
#endif
#include "../Measurement/F_T_PLC_US.h"

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PIWL, g_nStringIdFB_FT_PIWL)

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdKP, g_nStringIdKI, g_nStringIdLIM_L, g_nStringIdLIM_H};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_FT_PIWL::scm_anEIWithIndexes[] = {0, 2, 8};
const TDataIOID FORTE_FB_FT_PIWL::scm_anEIWith[] = {0, 255, 0, 1, 2, 3, 4, 255, 0, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_FB_FT_PIWL::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_FB_FT_PIWL::scm_anEOWithIndexes[] = {-1, 0};
const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anInternalsNames[] = {g_nStringIdT_LAST, g_nStringIdIN_LAST, g_nStringIdI, g_nStringIdINIT};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL::scm_anInternalsTypeIds[] = {g_nStringIdDWORD, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_FB_FT_PIWL::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_FT_PIWL::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_FB_FT_PIWL::setInitialValues(){
  KP() = 1.0f;
  KI() = 1.0f;
  LIM_L() = -1.0E38f;
  LIM_H() = 1.0E38f;
}

void FORTE_FB_FT_PIWL::alg_RESET(void){
INIT() = true;
IN_LAST() = IN();
T_LAST() = T_PLC_US();
I() = 0.0;
}

void FORTE_FB_FT_PIWL::alg_REQ(void){
	CIEC_DWORD tx;
	CIEC_REAL tc;
	CIEC_REAL p;


/*  read last cycle time in Microseconds */
	tx = T_PLC_US();
	tc = DWORD_TO_REAL(tx-T_LAST());
	T_LAST() = tx;

	/*  calculate proportional part */
	p = KP()*IN();

	/*  run integrator */
	I() = (IN()+IN_LAST())*5.0E-7f*KI()*tc+I();
	IN_LAST() = IN();

	/*  calculate output Y */
	Y() = p+I();

	/*  check output for limits */
	if((Y() >= LIM_H())){
		Y() = LIM_H();
		if((KI() != 0.0)){
			I() = LIM_H()-p;
		}
else{
			I() = 0.0;
		};
		LIM() = true;
	}
else
  if((Y() <= LIM_L())){
		Y() = LIM_L();
		if((KI() != 0.0)){
			I() = LIM_L()-p;
		}
else{
			I() = 0.0;
		};
		LIM() = true;
	}
else{
		LIM() = false;
	};
	
}


void FORTE_FB_FT_PIWL::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_FT_PIWL::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_RESET();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_FT_PIWL::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_PIWL::enterStateRST(void){
  m_nECCState = scm_nStateRST;
  alg_RESET();
}

void FORTE_FB_FT_PIWL::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventRSTID == pa_nEIID)
          enterStateRST();
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
      case scm_nStateRST:
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


