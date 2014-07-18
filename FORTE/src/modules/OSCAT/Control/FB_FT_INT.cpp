/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: FB_FT_INT
 *** Description: Integrator
 *** Version: 
 ***     0.0: 2011-07-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_INT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_INT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_INT, g_nStringIdFB_FT_INT)

const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anDataInputNames[] = {g_nStringIdInput, g_nStringIdK, g_nStringIdrst, g_nStringIdOut_max, g_nStringIdOut_min};

const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anDataOutputNames[] = {g_nStringIdOutput, g_nStringIdlim};

const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_FB_FT_INT::scm_anEIWithIndexes[] = {0, 6};
const TDataIOID FORTE_FB_FT_INT::scm_anEIWith[] = {0, 1, 2, 3, 4, 255, 0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_INT::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_FB_FT_INT::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_FB_FT_INT::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_FT_INT::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_FB_FT_INT::scm_astInternalFBs[] = {
  {g_nStringIdFB_INTEGRATE, g_nStringIdFB_INTEGRATE},
  {g_nStringIdF_LIMIT2, g_nStringIdF_LIMIT2},
};

const SCFB_FBConnectionData FORTE_FB_FT_INT::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
};

const SCFB_FBConnectionData FORTE_FB_FT_INT::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdInput), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdX), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdK), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdK), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdrst), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdreset), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOut_max), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdMX), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOut_min), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdMN), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_INTEGRATE, g_nStringIdY_OUT), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdIN), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdLIM), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdlim), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_LIMIT2, g_nStringIdOUT), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOutput), -1},
};

const SCFB_FBNData FORTE_FB_FT_INT::scm_stFBNData = {
  2, scm_astInternalFBs,
  5, scm_astEventConnections,
  0, 0,
  8, scm_astDataConnections,
  0, 0,
  0, 0
};


