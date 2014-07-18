/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: FB_ADD_REAL
 *** Description: Adds two REAL values
 *** Version:
 ***     1.0: 2007-06-26/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "FB_ADD_REAL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_ADD_REAL_gen.cpp"
#endif
#include <devlog.h>

DEFINE_FIRMWARE_FB(FB_ADD_REAL, g_nStringIdFB_ADD_REAL)

const CStringDictionary::TStringId FB_ADD_REAL::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FB_ADD_REAL::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId FB_ADD_REAL::scm_aunDIDataTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FB_ADD_REAL::scm_aunDODataTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FB_ADD_REAL::scm_anEIWithIndexes[] = {0};
const TDataIOID FB_ADD_REAL::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FB_ADD_REAL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FB_ADD_REAL::scm_anEOWith[] = {0, 255};
const TForteInt16 FB_ADD_REAL::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FB_ADD_REAL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FB_ADD_REAL::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  2,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void FB_ADD_REAL::alg_REQ(void){
OUT() = IN1()+IN2();
}

void FB_ADD_REAL::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FB_ADD_REAL::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FB_ADD_REAL::executeEvent(int pa_nEIID){
  bool bRetVal;
  do{
    bRetVal = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
        	enterStateREQ();
        else
          bRetVal = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
        	enterStateSTART();
        else
          bRetVal = false; //no transition cleared
        break;
      default:
    	DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is allways the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behvior
  }while(bRetVal);
}

FB_ADD_REAL::FB_ADD_REAL(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CBasicFB(
           pa_poSrcRes,
           &scm_stFBInterfaceSpec, pa_nInstanceNameId,
            0, m_anFBConnData, m_anFBVarsData) {
}

FB_ADD_REAL::~FB_ADD_REAL(){
}



