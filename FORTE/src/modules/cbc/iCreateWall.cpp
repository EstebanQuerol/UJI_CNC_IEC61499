/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateWall
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateWall.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateWall, g_nStringIdiCreateWall)

const CStringDictionary::TStringId FORTE_iCreateWall::scm_anDataOutputNames[] = { g_nStringIdWALL, g_nStringIdAMT, g_nStringIdVWALL };

const CStringDictionary::TStringId FORTE_iCreateWall::scm_anDataOutputTypeIds[] = { g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_iCreateWall::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateWall::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateWall::scm_anEOWith[] = { 0, 1, 2, 255 };
const TForteInt16 FORTE_iCreateWall::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateWall::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateWall::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateWall::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_wall();
      WALL() = static_cast<TForteInt16>(gc_wall);
      AMT() = static_cast<TForteInt16>(gc_wall_amt);
      VWALL() = static_cast<TForteInt16>(gc_wall_hb);
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

