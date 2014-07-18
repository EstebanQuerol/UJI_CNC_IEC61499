/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DownButton
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "DownButton.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_DownButton, g_nStringIdDownButton)

const CStringDictionary::TStringId FORTE_DownButton::scm_anDataOutputNames[] = { g_nStringIdQ };

const CStringDictionary::TStringId FORTE_DownButton::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_DownButton::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_DownButton::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_DownButton::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_DownButton::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_DownButton::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_DownButton::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_DownButton::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      Q() = down_button();
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

