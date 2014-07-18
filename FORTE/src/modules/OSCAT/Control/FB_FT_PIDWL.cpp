/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PIDWL
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2013-10-19/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PIDWL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PIDWL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PIDWL, g_nStringIdFB_FT_PIDWL)

const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdKP, g_nStringIdTN, g_nStringIdTV, g_nStringIdLIM_L, g_nStringIdLIM_H};

const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_FT_PIDWL::scm_anEIWithIndexes[] = {0, 2, 9};
const TDataIOID FORTE_FB_FT_PIDWL::scm_anEIWith[] = {0, 255, 0, 5, 4, 3, 2, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_FB_FT_PIDWL::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_FB_FT_PIDWL::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_FB_FT_PIDWL::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_FT_PIDWL::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_FB_FT_PIDWL::setInitialValues(){
  KP() = 1.0;
  TN() = 1.0;
  TV() = 1.0;
  LIM_L() = -1.0E38;
  LIM_H() = 1.0E38;
}


const SCFB_FBInstanceData FORTE_FB_FT_PIDWL::scm_astInternalFBs[] = {
  {g_nStringIdFB_FT_PIWL, g_nStringIdFB_FT_PIWL},
  {g_nStringIdFB_FT_DERIV, g_nStringIdFB_FT_DERIV},
  {g_nStringIdF_ADD, g_nStringIdF_ADD},
  {g_nStringIdF_MUL, g_nStringIdF_MUL},
  {g_nStringIdF_MUL_0, g_nStringIdF_MUL},
  {g_nStringIdF_DIV, g_nStringIdF_DIV},
  {g_nStringIdF_FT_LIMIT, g_nStringIdF_FT_LIMIT},
};

const SCFB_FBParameter FORTE_FB_FT_PIDWL::scm_astParamters[] = {
  {0, g_nStringIdKP, "1.0"},
  {5, g_nStringIdIN1, "REAL#1.0"},
};

const SCFB_FBConnectionData FORTE_FB_FT_PIDWL::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdrun), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdREQ), 3},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRST), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdRST), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL_0, g_nStringIdREQ), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL_0, g_nStringIdCNF), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_DIV, g_nStringIdREQ), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_DIV, g_nStringIdCNF), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdREQ), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdCNF), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_FB_FT_PIDWL::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_L), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdLIM_L), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_H), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdLIM_H), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdout), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdIN1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdY), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdIN2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdOUT), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdK), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_DERIV, g_nStringIdin), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdIN1), 3},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTV), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdIN2), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL_0, g_nStringIdOUT), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdIN), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_DIV, g_nStringIdOUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdKI), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_DIV, g_nStringIdIN2), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdOUT), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdY), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdVAL), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdLIM), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_FT_PIDWL::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdLIM_L), 6},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_FT_LIMIT, g_nStringIdLIM_H), 6},
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL_0, g_nStringIdIN1), 4},
  {6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL_0, g_nStringIdIN2), 4},
};

const SCFB_FBNData FORTE_FB_FT_PIDWL::scm_stFBNData = {
  7, scm_astInternalFBs,
  12, scm_astEventConnections,
  0, 0,
  14, scm_astDataConnections,
  4, scm_astFannedOutDataConnections,
  2, scm_astParamters
};


