/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: DECRYPT_2
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "DECRYPT_2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DECRYPT_2_gen.cpp"
#endif
#include <devlog.h>


DEFINE_FIRMWARE_FB(DECRYPT_2, g_nStringIdDECRYPT_2)

const CStringDictionary::TStringId DECRYPT_2::scm_anDataInputNames[] = {g_nStringIdINPUT};

const CStringDictionary::TStringId DECRYPT_2::scm_anDataOutputNames[] = {g_nStringIdOUTPUT};
const CStringDictionary::TStringId DECRYPT_2::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};
const CStringDictionary::TStringId DECRYPT_2::scm_aunDODataTypeIds[] = {g_nStringIdWSTRING};

const TForteInt16 DECRYPT_2::scm_anEIWithIndexes[] = {0};
const TDataIOID DECRYPT_2::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId DECRYPT_2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID DECRYPT_2::scm_anEOWith[] = {0, 255};
const TForteInt16 DECRYPT_2::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId DECRYPT_2::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec DECRYPT_2::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void DECRYPT_2::alg_REQ(void){
  OUTPUT() = INPUT();
  char *acBuffer = OUTPUT().getValue();
  for(unsigned int i = 0; i < OUTPUT().length(); ++i){
    acBuffer[i] = static_cast<char>(acBuffer[i] -2);
  }
}

void DECRYPT_2::enterStateSTART(){
  m_nECCState = scm_nStateSTART;
}

void DECRYPT_2::enterStateREQ(){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void DECRYPT_2::executeEvent(int pa_nEIID){
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


DECRYPT_2::DECRYPT_2(CStringDictionary::TStringId pa_nFBInstanceNameId, CResource *pa_poSrcRes) :
       CBasicFB(
           pa_poSrcRes,
           &scm_stFBInterfaceSpec, pa_nFBInstanceNameId,
           0, m_anFBConnData, m_anFBVarsData) {
}

DECRYPT_2::~DECRYPT_2(){
}
