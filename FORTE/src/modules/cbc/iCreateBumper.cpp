/*************************************************************************
 s *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateBumper
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateBumper.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateBumper, g_nStringIdiCreateBumper)

const CStringDictionary::TStringId FORTE_iCreateBumper::scm_anDataOutputNames[] = { g_nStringIdLtBump, g_nStringIdRtBump };

const CStringDictionary::TStringId FORTE_iCreateBumper::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateBumper::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateBumper::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateBumper::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_iCreateBumper::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateBumper::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateBumper::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateBumper::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_bumpdrop();
      LtBump() = gc_lbump;
      RtBump() = gc_rbump;
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

