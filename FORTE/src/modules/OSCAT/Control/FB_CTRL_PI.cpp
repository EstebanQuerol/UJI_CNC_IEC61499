/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTRL_PI
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2011-08-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_CTRL_PI.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CTRL_PI_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_CTRL_PI, g_nStringIdFB_CTRL_PI)

const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anDataInputNames[] = {g_nStringIdACTUAL, g_nStringIdSET_POINT, g_nStringIdNOISE, g_nStringIdOFFSET, g_nStringIdMAN_IN, g_nStringIdMANUAL, g_nStringIdKP, g_nStringIdKI, g_nStringIdLIM_L, g_nStringIdLIM_H};

const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdDIFF, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_CTRL_PI::scm_anEIWithIndexes[] = {-1, 0, -1};
const TDataIOID FORTE_FB_CTRL_PI::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255};
const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_FB_CTRL_PI::scm_anEOWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_FB_CTRL_PI::scm_anEOWithIndexes[] = {-1, 0};
const CStringDictionary::TStringId FORTE_FB_CTRL_PI::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_CTRL_PI::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  10,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_FB_CTRL_PI::scm_astInternalFBs[] = {
  {g_nStringIdFB_CTRL_OUT, g_nStringIdFB_CTRL_OUT},
  {g_nStringIdFB_FT_PIWL, g_nStringIdFB_FT_PIWL},
  {g_nStringIdF_CTRL_IN, g_nStringIdF_CTRL_IN},
};

const SCFB_FBConnectionData FORTE_FB_CTRL_PI::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRST), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdRST), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
};

const SCFB_FBConnectionData FORTE_FB_CTRL_PI::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdY), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdY), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdY), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdCI), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSET_POINT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdSET_POINT), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdACTUAL), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdACTUAL), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdNOISE), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdNOISE), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdKP), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdKI), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_L), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdLIM_L), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLIM_H), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdLIM_H), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMANUAL), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdMANUAL), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMAN_IN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdMAN_IN), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOFFSET), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdOFFSET), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_CTRL_IN, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDIFF), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_CTRL_PI::scm_astFannedOutDataConnections[] = {
  {8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM_L), 0},
  {9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_CTRL_OUT, g_nStringIdLIM_H), 0},
  {13, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PIWL, g_nStringIdIN), 1},
};

const SCFB_FBNData FORTE_FB_CTRL_PI::scm_stFBNData = {
  3, scm_astInternalFBs,
  7, scm_astEventConnections,
  0, 0,
  14, scm_astDataConnections,
  3, scm_astFannedOutDataConnections,
  0, 0
};

void FORTE_FB_CTRL_PI::setInitialValues(){
  KP() = 1.0;
  KI() = 1.0;
  LIM_L() = -1000.0;
  LIM_H() = 1000.0;
}
