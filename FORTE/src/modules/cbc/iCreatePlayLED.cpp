/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreatePlayLED
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreatePlayLED.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreatePlayLED, g_nStringIdiCreatePlayLED)

const CStringDictionary::TStringId FORTE_iCreatePlayLED::scm_anDataInputNames[] = { g_nStringIdQ };

const CStringDictionary::TStringId FORTE_iCreatePlayLED::scm_anDataInputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_iCreatePlayLED::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_iCreatePlayLED::scm_anEIWith[] = { 0, 255 };
const CStringDictionary::TStringId FORTE_iCreatePlayLED::scm_anEventInputNames[] = { g_nStringIdREQ };

const TForteInt16 FORTE_iCreatePlayLED::scm_anEOWithIndexes[] = { -1, -1 };
const CStringDictionary::TStringId FORTE_iCreatePlayLED::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreatePlayLED::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, 0, 0, 1, scm_anDataInputNames, scm_anDataInputTypeIds, 0, 0, 0, 0, 0 };

void FORTE_iCreatePlayLED::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_play_led(Q());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

