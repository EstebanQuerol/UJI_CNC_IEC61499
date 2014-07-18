/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_PD
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2011-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PD, g_nStringIdFB_FT_PD)

const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdKP, g_nStringIdTV};

const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anDataOutputNames[] = {g_nStringIdY};

const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_PD::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_FB_FT_PD::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_PD::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_FT_PD::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_FB_FT_PD::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_FT_PD::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_FB_FT_PD::scm_astInternalFBs[] = {
  {g_nStringIdFB_FT_DERIV, g_nStringIdFB_FT_DERIV},
  {g_nStringIdFB_ADD_REAL, g_nStringIdFB_ADD_REAL},
  {g_nStringIdFB_MUL_REAL, g_nStringIdFB_MUL_REAL},
};

const SCFB_FBConnectionData FORTE_FB_FT_PD::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdrun), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_ADD_REAL, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_ADD_REAL, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_FB_FT_PD::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTV), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdK), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdin), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdout), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_ADD_REAL, g_nStringIdIN1), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_ADD_REAL, g_nStringIdOUT), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdIN1), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdIN2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdY), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_FT_PD::scm_astFannedOutDataConnections[] = {
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_ADD_REAL, g_nStringIdIN2), 1},
};

const SCFB_FBNData FORTE_FB_FT_PD::scm_stFBNData = {
  3, scm_astInternalFBs,
  6, scm_astEventConnections,
  0, 0,
  6, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};

void FORTE_FB_FT_PD::setInitialValues(){
  KP() = 1.0;
  TV() = 1.0;
}

