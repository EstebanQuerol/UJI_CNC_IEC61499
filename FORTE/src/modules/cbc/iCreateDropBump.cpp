/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateDropBump
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateDropBump.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateDropBump, g_nStringIdiCreateDropBump)

const CStringDictionary::TStringId FORTE_iCreateDropBump::scm_anDataOutputNames[] = { g_nStringIdCasterDrop, g_nStringIdLtDrop, g_nStringIdRtDrop, g_nStringIdLtBump, g_nStringIdRtBump };

const CStringDictionary::TStringId FORTE_iCreateDropBump::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateDropBump::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateDropBump::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateDropBump::scm_anEOWith[] = { 0, 1, 2, 3, 4, 255 };
const TForteInt16 FORTE_iCreateDropBump::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateDropBump::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateDropBump::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 5, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateDropBump::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_bumpdrop();
      CasterDrop() = gc_fdrop;
      LtDrop() = gc_ldrop;
      RtDrop() = gc_rdrop;
      LtBump() = gc_lbump;
      RtBump() = gc_rbump;
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

