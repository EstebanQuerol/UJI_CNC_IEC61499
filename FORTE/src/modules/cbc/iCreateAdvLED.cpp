/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateAdvLED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateAdvLED.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateAdvLED, g_nStringIdiCreateAdvLED)

const CStringDictionary::TStringId FORTE_iCreateAdvLED::scm_anDataInputNames[] = { g_nStringIdQ };

const CStringDictionary::TStringId FORTE_iCreateAdvLED::scm_anDataInputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateAdvLED::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_iCreateAdvLED::scm_anEIWith[] = { 0, 255 };
const CStringDictionary::TStringId FORTE_iCreateAdvLED::scm_anEventInputNames[] = { g_nStringIdREQ };

const TForteInt16 FORTE_iCreateAdvLED::scm_anEOWithIndexes[] = { -1, -1 };
const CStringDictionary::TStringId FORTE_iCreateAdvLED::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateAdvLED::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, 0, 0, 1, scm_anDataInputNames, scm_anDataInputTypeIds, 0, 0, 0, 0, 0 };

void FORTE_iCreateAdvLED::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_advance_led(Q()); // Turn LED on or off
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

