/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FSetup
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_FSetup.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FSetup_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FSetup, g_nStringIdL1_FSetup)

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataInputNames[] = {g_nStringIdOperation, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataOutputNames[] = {g_nStringIdCmd, g_nStringIdL1MIDOut};

const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_FSetup::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L1_FSetup::scm_anEIWith[] = {1, 0, 255};
const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_L1_FSetup::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_L1_FSetup::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L1_FSetup::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L1_FSetup::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L1_FSetup::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
#error add code for REQ event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
  }
}



