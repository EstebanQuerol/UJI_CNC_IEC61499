/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreatePowerLED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreatePowerLED.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreatePowerLED, g_nStringIdiCreatePowerLED)

const CStringDictionary::TStringId FORTE_iCreatePowerLED::scm_anDataInputNames[] = { g_nStringIdCOLOR, g_nStringIdBRITE };

const CStringDictionary::TStringId FORTE_iCreatePowerLED::scm_anDataInputTypeIds[] = { g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_iCreatePowerLED::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_iCreatePowerLED::scm_anEIWith[] = { 0, 1, 255 };
const CStringDictionary::TStringId FORTE_iCreatePowerLED::scm_anEventInputNames[] = { g_nStringIdREQ };

const TForteInt16 FORTE_iCreatePowerLED::scm_anEOWithIndexes[] = { -1, -1 };
const CStringDictionary::TStringId FORTE_iCreatePowerLED::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreatePowerLED::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, 0, 0, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 0, 0, 0, 0, 0 };

void FORTE_iCreatePowerLED::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_power_led(COLOR(), BRITE());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

