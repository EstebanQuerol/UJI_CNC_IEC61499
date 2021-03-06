/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateAdvButton
 *** Description: LMS LED on Light Sensor
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateAdvButton.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateAdvButton, g_nStringIdiCreateAdvButton)

const CStringDictionary::TStringId FORTE_iCreateAdvButton::scm_anDataOutputNames[] = { g_nStringIdQ };

const CStringDictionary::TStringId FORTE_iCreateAdvButton::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateAdvButton::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateAdvButton::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateAdvButton::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_iCreateAdvButton::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateAdvButton::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateAdvButton::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateAdvButton::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_buttons();
      Q() = gc_advance_button;
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

