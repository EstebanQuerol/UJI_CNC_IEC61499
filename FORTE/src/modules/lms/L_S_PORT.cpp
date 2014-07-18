/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_S_PORT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-08-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_S_PORT.h"
#include <cyg/hal/hal_io.h>  /* Needed for sc_anSensorPortPin */
DEFINE_FIRMWARE_FB(FORTE_L_S_PORT, g_nStringIdL_S_PORT)

const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdT };

const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdST };

const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const TForteInt16 FORTE_L_S_PORT::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_L_S_PORT::scm_anEIWith[] = { 0, 1, 255, 0, 2, 255 };
const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_L_S_PORT::scm_anEOWith[] = { 0, 1, 255, 0, 1, 255 };
const TForteInt16 FORTE_L_S_PORT::scm_anEOWithIndexes[] = { 0, 3, -1 };
const CStringDictionary::TStringId FORTE_L_S_PORT::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_S_PORT::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_L_S_PORT::executeEvent(int pa_nEIID){
  /* Ports # start with 1 since mapped to writing on the outside of LMS itself */
  unsigned int  nPort; /** HW port # (not LMS port #) */
  unsigned int  nType = T();
  bool bQO = QI();
  //TODO: Saves size now, but recheck when using -O3
  if(true == bQO){
    if((0 < PORT()) || (sc_nNXTSensorPortsMax > PORT()))
      nPort = PORT() - 1;
    else
      bQO = false;
  }

  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == bQO){
        lmsInit1Port(PORT());
        bQO = lmsPlugIntoPort(nPort, nType);
        ST() = lmsGetSensorPluggedIntoPort(nPort);
      }
      QO() = bQO;
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == bQO){
        ST() = lmsGetSensorPluggedIntoPort(nPort);
      }
      QO() = bQO;
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

// ---------------------------------------------------------------------------------
// LMS Sensor port management -------------------------------------------------------------
// sensors
const TForteUInt32 FORTE_L_S_PORT::sc_anSensorPortPin[4] = { (1 << AT91_GPIO_PA23), // SENSOR_PORT1_PIN,
    (1 << AT91_GPIO_PA28), // SENSOR_PORT2_PIN,
    (1 << AT91_GPIO_PA29), // SENSOR_PORT3_PIN,
    (1 << AT91_GPIO_PA30) // SENSOR_PORT4_PIN
    };

static TForteUInt32 aenSensorPortsMgr[FORTE_L_S_PORT::sc_nNXTSensorPortsMax] = { FORTE_L_S_PORT::e_UNUSED, FORTE_L_S_PORT::e_UNUSED, FORTE_L_S_PORT::e_UNUSED, FORTE_L_S_PORT::e_UNUSED };

// Sensor Port 4 is an RS485 port and needs extra initialization
void FORTE_L_S_PORT::lmsRS485PortInit(void){
  HAL_WRITE_UINT32(AT91_PIOA|AT91_PIO_PER, ((1<<AT91_GPIO_PA5) | (1<<AT91_GPIO_PA6) | (1<<AT91_GPIO_PA7)) );
  HAL_WRITE_UINT32(AT91_PIOA|AT91_PIO_PPUDR,((1<<AT91_GPIO_PA5) | (1<<AT91_GPIO_PA6) | (1<<AT91_GPIO_PA7)) );
  HAL_WRITE_UINT32(AT91_PIOA|AT91_PIO_OER, ((1<<AT91_GPIO_PA5) | (1<<AT91_GPIO_PA6) | (1<<AT91_GPIO_PA7)) );
  HAL_WRITE_UINT32(AT91_PIOA|AT91_PIO_CODR, ((1<<AT91_GPIO_PA5) | (1<<AT91_GPIO_PA6) | (1<<AT91_GPIO_PA7)) );
}

void FORTE_L_S_PORT::lmsInit1Port(TForteUInt32 pa_nPort){
  /* Ports start with 0 since mapped to HW */
  if((0 != pa_nPort) && (sc_nNXTSensorPortsMax >= pa_nPort)){
    unsigned int nPort = pa_nPort - 1;
    // power on                             /* ENABLE_PARALLEL_IOCTLR_CLK;*/ /* enable parallel io-controller clock */
    HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_PIOA); //enable pwr to parallel io-ctlr (PIOA) clk
    // Sensor Port initialization
    HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_IDR, sc_anSensorPortPin[nPort]); /* Interrupt disable  sc_anSensorPortPin[PORT]*/
    /* if interrupts were enabled a signal would be sent for value chg */HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_OER, sc_anSensorPortPin[nPort]); /* Output enable */
    HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_PER, sc_anSensorPortPin[nPort]); /* Port enable (in charge of the pin) */

    // Sensor Port 4 is an RS485 port and needs extra initialization
    if(sc_nRS485Port4 == nPort)
      lmsRS485PortInit();

    // led should be off by default even before port is reserved
    HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_CODR, sc_anSensorPortPin[nPort]); // pin low (led off)  Clear
    aenSensorPortsMgr[nPort] = e_UNUSED;
  }
  // else port number NOT in range - ignore! Error checking done elsewhere, but taking no chances
}

bool FORTE_L_S_PORT::lmsPlugIntoPort(TForteUInt32 pa_nPort, TForteUInt32 pa_nInputType){

  if(sc_nNXTSensorPortsMax <= pa_nPort)
    return false;

  if(e_UNUSED == aenSensorPortsMgr[pa_nPort]){
    aenSensorPortsMgr[pa_nPort] = (TForteUInt32) pa_nInputType;
    return true;
  }
  else{
    if(((e_LIGHTLED == aenSensorPortsMgr[pa_nPort]) && (e_LIGHTDETECTOR == pa_nInputType)) || ((e_LIGHTDETECTOR == aenSensorPortsMgr[pa_nPort]) && (e_LIGHTLED == pa_nInputType))){
      aenSensorPortsMgr[pa_nPort] = e_LIGHTSENSOR;
      return true;
    }
    else
      return false;
  }
}

TForteUInt32 FORTE_L_S_PORT::lmsGetSensorPluggedIntoPort(TForteUInt32 pa_nPort){
  return aenSensorPortsMgr[pa_nPort];
}

bool FORTE_L_S_PORT::lmsIsADsensor(TForteUInt32 pa_nInputType){
  bool bRetVal = false;

  switch (pa_nInputType){
    case e_LIGHTDETECTOR:
    case e_TOUCH:
    case e_SOUND:
    case e_ADSENSOR:
      bRetVal = true;
      break;
    default:
      break;
  }

  return bRetVal;
}

bool FORTE_L_S_PORT::lmsIsLTsensor(TForteUInt32 pa_nInputType){

  switch (pa_nInputType){
    case e_LIGHTLED:
    case e_LIGHTDETECTOR:
    case e_LIGHTSENSOR:
      return true;
    default:
      return false;
  }

}

