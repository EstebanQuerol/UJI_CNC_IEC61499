/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_CTRL_PID
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2013-10-19/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_CTRL_PID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CTRL_PID_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_CTRL_PID, g_nStringIdFB_CTRL_PID)

const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anDataInputNames[] = {g_nStringIdACT, g_nStringIdSET, g_nStringIdSUP, g_nStringIdOFS, g_nStringIdM_I, g_nStringIdMAN, g_nStringIdKP, g_nStringIdTN, g_nStringIdTV, g_nStringIdLIM_L, g_nStringIdLIM_H};

const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdDIFF, g_nStringIdLIMT};

const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_CTRL_PID::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_FB_CTRL_PID::scm_anEIWith[] = {0, 255, 0, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255};
const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_FB_CTRL_PID::scm_anEOWith[] = {0, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_FB_CTRL_PID::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_FB_CTRL_PID::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_CTRL_PID::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_FB_CTRL_PID::scm_astInternalFBs[] = {
  {g_nStringIdF_CTRL_IN, g_nStringIdF_CTRL_IN},
  {g_nStringIdFB_FT_PIDWL, g_nStringIdFB_FT_PIDWL},
  {g_nStringIdFB_CTRL_OUT, g_nStringIdFB_CTRL_OUT},
};

const SCFB_FBConnectionData FORTE_FB_CTRL_PID::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRST), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdRST), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_FB_CTRL_PID::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdOUT), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDIFF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSET), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdSET_POINT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdACT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdACTUAL), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSUP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdNOISE), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdKP), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdTN), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTV), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdTV), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_L), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdLIM_L), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_H), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdLIM_H), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdY), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdY), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIMT), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdY), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdCI), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOFS), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdOFFSET), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdM_I), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdMAN_IN), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMAN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdMANUAL), 2},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_CTRL_PID::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIDWL, g_nStringIdIN), 1},
  {7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM_L), 2},
  {8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM_H), 2},
};

const SCFB_FBNData FORTE_FB_CTRL_PID::scm_stFBNData = {
  3, scm_astInternalFBs,
  7, scm_astEventConnections,
  0, 0,
  15, scm_astDataConnections,
  3, scm_astFannedOutDataConnections,
  0, 0
};


