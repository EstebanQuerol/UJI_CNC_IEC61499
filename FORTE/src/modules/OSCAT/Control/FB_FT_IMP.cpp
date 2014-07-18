/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_FT_IMP
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2011-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "FB_FT_IMP.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_FT_IMP_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_FB_FT_IMP, g_nStringIdFB_FT_IMP)

const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdT, g_nStringIdK};

const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdTIME, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_FB_FT_IMP::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_FB_FT_IMP::scm_anEIWith[] = {1, 2, 0, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_FB_FT_IMP::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_FB_FT_IMP::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_FB_FT_IMP::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_FB_FT_IMP::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_FB_FT_IMP::scm_astInternalFBs[] = {
  {g_nStringIdFB_FT_PT1, g_nStringIdFB_FT_PT1},
  {g_nStringIdFB_MUL_REAL, g_nStringIdFB_MUL_REAL},
  {g_nStringIdFB_SUB_REAL, g_nStringIdFB_SUB_REAL},
};

const SCFB_FBConnectionData FORTE_FB_FT_IMP::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_SUB_REAL, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_SUB_REAL, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_FB_FT_IMP::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdIN), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_FT_PT1, g_nStringIdOUT), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_SUB_REAL, g_nStringIdIN2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_SUB_REAL, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdIN1), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdK), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdIN2), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_MUL_REAL, g_nStringIdOUT), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOUT), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_FB_FT_IMP::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB_SUB_REAL, g_nStringIdIN1), 2},
};

const SCFB_FBNData FORTE_FB_FT_IMP::scm_stFBNData = {
  3, scm_astInternalFBs,
  6, scm_astEventConnections,
  0, 0,
  6, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};

void FORTE_FB_FT_IMP::setInitialValues(){
  K() = 1.0;
}

