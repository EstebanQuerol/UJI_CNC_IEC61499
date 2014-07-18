/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateCliffSensors
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-26/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateCliffSensors.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateCliffSensors, g_nStringIdiCreateCliffSensors)

const CStringDictionary::TStringId FORTE_iCreateCliffSensors::scm_anDataOutputNames[] = { g_nStringIdDarkCliff, g_nStringIdState };

const CStringDictionary::TStringId FORTE_iCreateCliffSensors::scm_anDataOutputTypeIds[] = { g_nStringIdARRAY, 4, g_nStringIdBOOL, g_nStringIdARRAY, 4, g_nStringIdINT };

const TForteInt16 FORTE_iCreateCliffSensors::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateCliffSensors::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateCliffSensors::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_iCreateCliffSensors::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateCliffSensors::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateCliffSensors::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateCliffSensors::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_cliffs();

      DarkCliff()[0] = gc_lcliff;
      DarkCliff()[1] = gc_lfcliff;
      DarkCliff()[2] = gc_rfcliff;
      DarkCliff()[3] = gc_rcliff;

      State()[0] = static_cast<TForteInt16>(gc_lcliff_amt);
      State()[1] = static_cast<TForteInt16>(gc_lfcliff_amt);
      State()[2] = static_cast<TForteInt16>(gc_rfcliff_amt);
      State()[3] = static_cast<TForteInt16>(gc_rcliff_amt);
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

