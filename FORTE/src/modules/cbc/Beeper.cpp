/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Beeper
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Beeper.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Beeper, g_nStringIdBeeper)

const CStringDictionary::TStringId FORTE_Beeper::scm_anDataInputNames[] = { g_nStringIdQI };

const CStringDictionary::TStringId FORTE_Beeper::scm_anDataInputTypeIds[] = { g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_Beeper::scm_anDataOutputNames[] = { g_nStringIdQO };

const CStringDictionary::TStringId FORTE_Beeper::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_Beeper::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_Beeper::scm_anEIWith[] = { 0, 255 };
const CStringDictionary::TStringId FORTE_Beeper::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_Beeper::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_Beeper::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_Beeper::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_Beeper::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 1, scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Beeper::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      beep();
      sendOutputEvent(scm_nEventCNFID);

      break;
  }
}

