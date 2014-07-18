/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Servo
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Servo.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Servo, g_nStringIdServo)

const CStringDictionary::TStringId FORTE_Servo::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdPOS };

const CStringDictionary::TStringId FORTE_Servo::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT };

const CStringDictionary::TStringId FORTE_Servo::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdPOS_OUT };

const CStringDictionary::TStringId FORTE_Servo::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_Servo::scm_anEIWithIndexes[] = { 0, 3, 6 };
const TDataIOID FORTE_Servo::scm_anEIWith[] = { 1, 0, 255, 2, 0, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_Servo::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ, g_nStringIdDISABLE };

const TDataIOID FORTE_Servo::scm_anEOWith[] = { 1, 0, 2, 255, 1, 2, 0, 255, 0, 255 };
const TForteInt16 FORTE_Servo::scm_anEOWithIndexes[] = { 0, 4, 8, -1 };
const CStringDictionary::TStringId FORTE_Servo::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF, g_nStringIdDISABLEO };

const SFBInterfaceSpec FORTE_Servo::scm_stFBInterfaceSpec = { 3, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Servo::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if(PORT() >= 0 && PORT() <= 3){
          libcbc_init(); //TODO: only call once //initialises the CBC Library :)
          enable_servos(); // enables all servo ports
          STATUS() = 0;
          POS_OUT() = get_servo_position(PORT()); //return current Servo Position
          m_nPort = PORT();
        }
      }
      else{
        QO() = false;
        STATUS() = 1;
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        if((POS() >= 0) && (POS() <= 2047)){
          set_servo_position(PORT(), POS());
          STATUS() = 0;
          POS_OUT() = get_servo_position(PORT()); //return current Servo Position
        }
        else{
          QO() = false;
          STATUS() = 2;
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
    case scm_nEventDISABLEID:
      if(true == QI()){
        disable_servos();
      }
      sendOutputEvent(scm_nEventDISABLEOID);
      break;
  }
}

