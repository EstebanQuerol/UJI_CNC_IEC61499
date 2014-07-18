/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MotorVEL
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-03/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "MotorVEL.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_MotorVEL, g_nStringIdMotorVEL)

const CStringDictionary::TStringId FORTE_MotorVEL::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdFREEZE, g_nStringIdVEL };

const CStringDictionary::TStringId FORTE_MotorVEL::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT };

const CStringDictionary::TStringId FORTE_MotorVEL::scm_anDataOutputNames[] = { g_nStringIdQO };

const CStringDictionary::TStringId FORTE_MotorVEL::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_MotorVEL::scm_anEIWithIndexes[] = { 0, 3, 6 };
const TDataIOID FORTE_MotorVEL::scm_anEIWith[] = { 1, 0, 255, 3, 0, 255, 0, 2, 255 };
const CStringDictionary::TStringId FORTE_MotorVEL::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ, g_nStringIdSTOP };

const TDataIOID FORTE_MotorVEL::scm_anEOWith[] = { 0, 255, 0, 255, 0, 255 };
const TForteInt16 FORTE_MotorVEL::scm_anEOWithIndexes[] = { 0, 2, 4, -1 };
const CStringDictionary::TStringId FORTE_MotorVEL::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF, g_nStringIdSTOPO };

const SFBInterfaceSpec FORTE_MotorVEL::scm_stFBInterfaceSpec = { 3, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_MotorVEL::executeEvent(int pa_nEIID){
  //TODO MotorVEL add error checks and  messages
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if(PORT() >= 0 && PORT() <= 3){
          libcbc_init(); //TODO: only call once //initialises the CBC Library :)
          m_nPort = PORT();
          QO() = true; /* Turned on and No Error */
        }
        else{
          QO() = false;
        }
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        mav(m_nPort, VEL());
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
    case scm_nEventSTOPID:
      if(true == QI()){
        mav(m_nPort, 0);
        if(true == FREEZE()){
          freeze(m_nPort);
        }
        else{
          off(m_nPort);
        }
      }
      sendOutputEvent(scm_nEventSTOPOID);
      break;
  }
}

