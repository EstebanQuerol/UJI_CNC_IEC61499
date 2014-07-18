/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateIR
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateIR.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateIR, g_nStringIdiCreateIR)

const CStringDictionary::TStringId FORTE_iCreateIR::scm_anDataOutputNames[] = { g_nStringIdIRbyte };

const CStringDictionary::TStringId FORTE_iCreateIR::scm_anDataOutputTypeIds[] = { g_nStringIdINT };

const TForteInt16 FORTE_iCreateIR::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateIR::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateIR::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_iCreateIR::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateIR::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateIR::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateIR::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_read_IR();
      IRbyte() = static_cast<TForteInt16>(gc_IR);
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

