/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_LED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2011-08-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_LED.h"
#include "L_S_PORT.h"
#include <cyg/hal/hal_io.h>
DEFINE_FIRMWARE_FB(FORTE_L_LED, g_nStringIdL_LED)

const CStringDictionary::TStringId FORTE_L_LED::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdQ, g_nStringIdT };

const CStringDictionary::TStringId FORTE_L_LED::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_L_LED::scm_anDataOutputNames[] = { g_nStringIdQO };

const CStringDictionary::TStringId FORTE_L_LED::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_L_LED::scm_anEIWithIndexes[] = { 0, 4 };
const TDataIOID FORTE_L_LED::scm_anEIWith[] = { 0, 1, 3, 255, 0, 2, 255 };
const CStringDictionary::TStringId FORTE_L_LED::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_L_LED::scm_anEOWith[] = { 0, 255, 0, 255 };
const TForteInt16 FORTE_L_LED::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_L_LED::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_LED::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

// TODO: rename to L_DO for digital output
void FORTE_L_LED::executeEvent(int pa_nEIID){
  unsigned int nPort = PORT() - 1; /** HW port # (not LMS port #) */
  unsigned int nType = T();

  QO() = QI();

  switch (pa_nEIID){

    case scm_nEventINITID:
      if(true == QI()){
        if(!FORTE_L_S_PORT::lmsIsLTsensor(nType))
          QO() = false;
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      /* void CL_Sltled::lmsLtLedInit(cyg_int32 pa_unPortNum) */
      if(true == QI()){
        if(true == Q())
          lmsLtLedOn(nPort);
        else
          lmsLtLedOff(nPort);
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

void FORTE_L_LED::lmsLtLedOn(TForteUInt32 pa_unPortNum){
  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_SODR, FORTE_L_S_PORT::sc_anSensorPortPin[pa_unPortNum]); // pin high (led on) Set
  //alternative:  // HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PA23, (1<<AT91_GPIO_PA23));
}

void FORTE_L_LED::lmsLtLedOff(TForteUInt32 pa_unPortNum){
  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_CODR, FORTE_L_S_PORT::sc_anSensorPortPin[pa_unPortNum]); // pin low (led off)  Clear
  // alternative:   // HAL_ARM_AT91_GPIO_PUT(AT91_GPIO_PA23, (0<<AT91_GPIO_PA23));
}

