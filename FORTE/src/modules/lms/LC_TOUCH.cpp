/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: LC_TOUCH
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2012-01-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "LC_TOUCH.h"

DEFINE_FIRMWARE_FB(FORTE_LC_TOUCH, g_nStringIdLC_TOUCH)

const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPORT};

const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdQ};

const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_LC_TOUCH::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_LC_TOUCH::scm_anEIWith[] = {0, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_LC_TOUCH::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_LC_TOUCH::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_LC_TOUCH::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_LC_TOUCH::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_LC_TOUCH::scm_astInternalFBs[] = {
  {g_nStringIdL_AD, g_nStringIdL_AD},
  {g_nStringIdL_S_PORT, g_nStringIdL_S_PORT},
  {g_nStringIdF_GT, g_nStringIdF_GT},
};

const SCFB_FBParameter FORTE_LC_TOUCH::scm_astParamters[] = {
  {1, g_nStringIdT, "4"},
  {2, g_nStringIdIN1, "UINT#512"},
};

const SCFB_FBConnectionData FORTE_LC_TOUCH::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_LC_TOUCH::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdQO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdST), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdQI), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPORT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdPORT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdRD), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdIN2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdOUT), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQ), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_LC_TOUCH::scm_astFannedOutDataConnections[] = {
  {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_AD, g_nStringIdPORT), 0},
};

const SCFB_FBNData FORTE_LC_TOUCH::scm_stFBNData = {
  3, scm_astInternalFBs,
  7, scm_astEventConnections,
  0, 0,
  7, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  2, scm_astParamters
};


