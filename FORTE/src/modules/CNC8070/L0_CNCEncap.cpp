/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CNCEncap
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "L0_CNCEncap.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_CNCEncap_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_CNCEncap, g_nStringIdL0_CNCEncap)

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdCmdID, g_nStringIdSD, g_nStringIdPN};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdsBlock};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_L0_CNCEncap::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_L0_CNCEncap::scm_anEIWith[] = {0, 255, 0, 2, 1, 3, 255};
const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L0_CNCEncap::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_L0_CNCEncap::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L0_CNCEncap::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L0_CNCEncap::executeEvent(int pa_nEIID){
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
  }
}



