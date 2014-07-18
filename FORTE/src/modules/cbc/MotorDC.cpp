/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MotorDC
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "MotorDC.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_MotorDC, g_nStringIdMotorDC)

const CStringDictionary::TStringId FORTE_MotorDC::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdFREEZE, g_nStringIdPWR, g_nStringIdVEL, g_nStringIdPOS, g_nStringIdRELPOS, g_nStringIdPID, g_nStringIdPWM, g_nStringIdDUTY_CYCLE };

const CStringDictionary::TStringId FORTE_MotorDC::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdARRAY, 6, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_MotorDC::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdERRNUM, g_nStringIdPOS_OUT };

const CStringDictionary::TStringId FORTE_MotorDC::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_MotorDC::scm_anEIWithIndexes[] = { 0, 6, 12, 16, 21, 24 };
const TDataIOID FORTE_MotorDC::scm_anEIWith[] = { 1, 7, 0, 9, 8, 255, 3, 2, 8, 9, 0, 255, 2, 4, 0, 255, 5, 2, 6, 0, 255, 0, 2, 255, 2, 3, 5, 255 };
const CStringDictionary::TStringId FORTE_MotorDC::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQPWR, g_nStringIdREQVEL, g_nStringIdREQPOS, g_nStringIdSTOP, g_nStringIdRSP };

const TDataIOID FORTE_MotorDC::scm_anEOWith[] = { 0, 1, 255, 0, 255, 0, 255, 2, 0, 255, 0, 255, 2, 255 };
const TForteInt16 FORTE_MotorDC::scm_anEOWithIndexes[] = { 0, 3, 5, 7, 10, 12, -1 };
const CStringDictionary::TStringId FORTE_MotorDC::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNFPWR, g_nStringIdCNFVEL, g_nStringIdCNFPOS, g_nStringIdSTOPO, g_nStringIdIND };

const SFBInterfaceSpec FORTE_MotorDC::scm_stFBInterfaceSpec = { 6, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 6, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 10, scm_anDataInputNames, scm_anDataInputTypeIds, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_MotorDC::executeEvent(int pa_nEIID){
  QO() = QI();
  //TODO PWM and DUTYCYCLE
  //TODO MOTORDC add error checks and  messages
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if((PORT() >= 0) && (PORT() <= 3)){
          libcbc_init(); //TODO: only call once //initialises the CBC Library :)
          m_nPort = PORT();
        }
        else{
          QO() = false;
        }
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQPWRID:
      if(true == QI()){
        motor(m_nPort, PWR());
      }
      sendOutputEvent(scm_nEventCNFPWRID);
      break;
    case scm_nEventREQVELID:
      if(true == QI()){
        mav(m_nPort, VEL());
      }
      sendOutputEvent(scm_nEventCNFVELID);
      break;
    case scm_nEventREQPOSID:
      if(true == QI()){
        if(true == RELPOS())
          mrp(m_nPort, 1000, POS());
        else
          mtp(m_nPort, 1000, POS());
      }
      sendOutputEvent(scm_nEventCNFPOSID);
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
    case scm_nEventRSPID:
//TODO: MOTORDC RSP
      break;
  }
}

