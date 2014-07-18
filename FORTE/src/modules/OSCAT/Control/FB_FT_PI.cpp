/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_PI
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2011-07-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_PI.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_PI_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_PI, g_nStringIdFB_FT_PI)

const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anDataInputNames[] = {g_nStringIdIn, g_nStringIdKP, g_nStringIdKI, g_nStringIdIlim_L, g_nStringIdIlim_H, g_nStringIdrst};

const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anDataOutputNames[] = {g_nStringIdY, g_nStringIdlim};

const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_FT_PI::scm_anEIWithIndexes[] = {0, 7};
const TDataIOID FORTE_FB_FT_PI::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255, 0, 1, 2, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_PI::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_FB_FT_PI::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_FB_FT_PI::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_FT_PI::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_FB_FT_PI::setInitialValues(){
  KP() = 1.0f;
  KI() = 1.0f;
  Ilim_L() = -1E38f;
  Ilim_H() = 1E38f;
}


const SCFB_FBInstanceData FORTE_FB_FT_PI::scm_astInternalFBs[] = {
  {g_nStringIdFB_FT_INT, g_nStringIdFB_FT_INT},
  {g_nStringIdF_ADD, g_nStringIdFB_ADD_REAL},
  {g_nStringIdF_MUL, g_nStringIdF_MUL},
};

const SCFB_FBConnectionData FORTE_FB_FT_PI::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_FB_FT_PI::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdInput), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdK), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdrst), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdrst), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIlim_L), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdOut_min), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIlim_H), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdOut_max), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdlim), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdlim), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdIN1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdIN1), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_INT, g_nStringIdOutput), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdIN2), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_ADD, g_nStringIdOUT), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdY), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_FT_PI::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_MUL, g_nStringIdIN2), 2},
};

const SCFB_FBNData FORTE_FB_FT_PI::scm_stFBNData = {
  3, scm_astInternalFBs,
  6, scm_astEventConnections,
  0, 0,
  10, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


