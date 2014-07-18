/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PIWLx
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-07-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PIWL2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PIWL2_gen.cpp"
#endif
#include "../Measurement/F_T_PLC_US.h"

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PIWL2, g_nStringIdFB_FT_PIWL2)

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdKP, g_nStringIdKI, g_nStringIdLIM_L, g_nStringIdLIM_H, g_nStringIdRST, g_nStringIdTRACK, g_nStringIdTRACK_IN};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anDataOutputNames[] = {g_nStringIdLIM, g_nStringIdY};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_PIWL2::scm_anEIWithIndexes[] = {0, 9};
const TDataIOID FORTE_FB_FT_PIWL2::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 255, 0, 1, 3, 2, 4, 5, 6, 7, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_PIWL2::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_FB_FT_PIWL2::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anInternalsNames[] = {g_nStringIdtx, g_nStringIdtc, g_nStringIdt_last, g_nStringIdin_last, g_nStringIdi, g_nStringIdp};

const CStringDictionary::TStringId FORTE_FB_FT_PIWL2::scm_anInternalsTypeIds[] = {g_nStringIdDWORD, g_nStringIdREAL, g_nStringIdDWORD, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_FB_FT_PIWL2::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_FB_FT_PIWL2::scm_stInternalVars = {6, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_FB_FT_PIWL2::setInitialValues(){
  KP() = 1.0f;
  KI() = 1.0f;
  LIM_L() = -1.0E38f;
  LIM_H() = 1.0E38f;
}

void FORTE_FB_FT_PIWL2::alg_INIT(void){
in_last() = IN();
t_last() = T_PLC_US();
i() = 0.0f;
tc() = 0.0f;


}

void FORTE_FB_FT_PIWL2::alg_REQ(void){
if((RST())){
	in_last() = IN();
	t_last() = T_PLC_US();
	i() = 0.0;
	tc() = 0.0;
}
else{
	/*  read last cycle time in Microseconds */
	tx() = T_PLC_US();
	tc() = DWORD_TO_REAL((tx()-t_last()));
	t_last() = tx();

	/*  calculate proportional part */
	p() = KP()*IN();

	/*  run integrator */

	if((TRACK())){
		i() = TRACK_IN()-p();
	}
else{
		i() = ((IN()+in_last()))*5.0E-7f*KI()*tc()+i();
		in_last() = IN();
	}
	/*  calculate output Y */
	Y() = p()+i();

	/*  check output for limits */
	if((Y() >= LIM_H())){
		Y() = LIM_H();
		if((KI() != 0.0)){
			i() = LIM_H()-p();
		}
else{
			i() = 0.0;
		};
		LIM() = true;
	}
else
  if((Y() <= LIM_L())){
		Y() = LIM_L();
		if((KI() != 0.0)){
			i() = LIM_L()-p();
		}
else{
			i() = 0.0;
		};
		LIM() = true;
	}
else{
		LIM() = false;
	};
};
}


void FORTE_FB_FT_PIWL2::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_FB_FT_PIWL2::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_FB_FT_PIWL2::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_FB_FT_PIWL2::executeEvent(int pa_nEIID){
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


