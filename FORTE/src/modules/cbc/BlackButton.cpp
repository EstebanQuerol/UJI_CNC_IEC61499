/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BlackButton
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-04/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "BlackButton.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_BlackButton, g_nStringIdBlackButton)

const CStringDictionary::TStringId FORTE_BlackButton::scm_anDataOutputNames[] = { g_nStringIdQ };

const CStringDictionary::TStringId FORTE_BlackButton::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_BlackButton::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_BlackButton::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_BlackButton::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_BlackButton::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_BlackButton::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_BlackButton::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_BlackButton::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      Q() = black_button();
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

