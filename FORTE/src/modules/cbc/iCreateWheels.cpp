/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateWheels
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateWheels.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateWheels, g_nStringIdiCreateWheels)

const CStringDictionary::TStringId FORTE_iCreateWheels::scm_anDataOutputNames[] = { g_nStringIdCasterDrop, g_nStringIdLtDrop, g_nStringIdRtDrop };

const CStringDictionary::TStringId FORTE_iCreateWheels::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateWheels::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateWheels::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateWheels::scm_anEOWith[] = { 0, 1, 2, 255 };
const TForteInt16 FORTE_iCreateWheels::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateWheels::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateWheels::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateWheels::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_bumpdrop();
      CasterDrop() = gc_fdrop;
      LtDrop() = gc_ldrop;
      RtDrop() = gc_rdrop;
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

