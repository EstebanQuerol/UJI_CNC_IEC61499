/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FClosedPocket
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L1_FClosedPocket.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_FClosedPocket_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_FClosedPocket, g_nStringIdL1_FClosedPocket)

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdSD};

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY};

const TForteInt16 FORTE_L1_FClosedPocket::scm_anEIWithIndexes[] = {0, 3, 6};
const TDataIOID FORTE_L1_FClosedPocket::scm_anEIWith[] = {0, 1, 255, 0, 2, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_L1_FClosedPocket::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_L1_FClosedPocket::scm_anEOWithIndexes[] = {0, 3, 7, -1};
const CStringDictionary::TStringId FORTE_L1_FClosedPocket::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_L1_FClosedPocket::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L1_FClosedPocket::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
//#error add code for INIT event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
    case scm_nEventREQID:
//#error add code for REQ event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
    case scm_nEventRSPID:
//#error add code for RSP event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
  }
}



