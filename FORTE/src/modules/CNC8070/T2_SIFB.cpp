/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T2_SIFB
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "T2_SIFB.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T2_SIFB_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_T2_SIFB, g_nStringIdT2_SIFB)

const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdSD};

const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdINT};

const TForteInt16 FORTE_T2_SIFB::scm_anEIWithIndexes[] = {0, 3, 6};
const TDataIOID FORTE_T2_SIFB::scm_anEIWith[] = {0, 1, 255, 0, 2, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_T2_SIFB::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_T2_SIFB::scm_anEOWithIndexes[] = {0, 3, 7, -1};
const CStringDictionary::TStringId FORTE_T2_SIFB::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SAdapterInstanceDef FORTE_T2_SIFB::scm_astAdapterInstances[] = {
{g_nStringIdT1_Adapter, g_nStringIdATimeOut, false }};

const SFBInterfaceSpec FORTE_T2_SIFB::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};


void FORTE_T2_SIFB::setInitialValues(){
  SD() = "Empty";
  RD() = 0;
}


void FORTE_T2_SIFB::executeEvent(int pa_nEIID){
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



