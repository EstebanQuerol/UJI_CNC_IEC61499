/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MotorPOS
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-03/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "MotorPOS.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_MotorPOS, g_nStringIdMotorPOS)

const CStringDictionary::TStringId FORTE_MotorPOS::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdFREEZE, g_nStringIdPOS, g_nStringIdRELPOS };

const CStringDictionary::TStringId FORTE_MotorPOS::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_MotorPOS::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdPOS_OUT, g_nStringIdCBC_RC };

const CStringDictionary::TStringId FORTE_MotorPOS::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_MotorPOS::scm_anEIWithIndexes[] = { 0, 3, 7, 10 };
const TDataIOID FORTE_MotorPOS::scm_anEIWith[] = { 1, 0, 255, 3, 2, 4, 255, 2, 3, 255, 0, 2, 255 };
const CStringDictionary::TStringId FORTE_MotorPOS::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP, g_nStringIdSTOP };

const TDataIOID FORTE_MotorPOS::scm_anEOWith[] = { 0, 2, 255, 1, 2, 255, 1, 255, 0, 1, 255 };
const TForteInt16 FORTE_MotorPOS::scm_anEOWithIndexes[] = { 0, 3, 6, 8, -1 };
const CStringDictionary::TStringId FORTE_MotorPOS::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND, g_nStringIdSTOPO };

const SFBInterfaceSpec FORTE_MotorPOS::scm_stFBInterfaceSpec = { 4, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 4, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 5, scm_anDataInputNames, scm_anDataInputTypeIds, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_MotorPOS::executeEvent(int pa_nEIID){
  //TODO MotorPOS add error checks and  messages
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if(PORT() <= 3){
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
        if(true == RELPOS())
          mrp(m_nPort, 1000, POS());
        else
          mtp(m_nPort, 1000, POS());
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
    case scm_nEventRSPID:
//TODO respond to IND
      break;
    case scm_nEventSTOPID:
      if(true == QI()){
        motor(m_nPort, 0);
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

