/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: LC_LED
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2011-08-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "LC_LED.h"

DEFINE_FIRMWARE_FB(FORTE_LC_LED, g_nStringIdLC_LED)

const CStringDictionary::TStringId FORTE_LC_LED::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPORT, g_nStringIdQ};

const CStringDictionary::TStringId FORTE_LC_LED::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_LC_LED::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_LC_LED::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_LC_LED::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_LC_LED::scm_anEIWith[] = {0, 1, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_LC_LED::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_LC_LED::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_LC_LED::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_LC_LED::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_LC_LED::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_LC_LED::scm_astInternalFBs[] = {
  {g_nStringIdL_S_PORT, g_nStringIdL_S_PORT},
  {g_nStringIdL_LED, g_nStringIdL_LED},
};

const SCFB_FBParameter FORTE_LC_LED::scm_astParamters[] = {
  {0, g_nStringIdT, "1"},
};

const SCFB_FBConnectionData FORTE_LC_LED::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_LC_LED::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPORT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdPORT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdQI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_S_PORT, g_nStringIdST), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdT), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdQO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_LC_LED::scm_astFannedOutDataConnections[] = {
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL_LED, g_nStringIdPORT), 1},
};

const SCFB_FBNData FORTE_LC_LED::scm_stFBNData = {
  2, scm_astInternalFBs,
  6, scm_astEventConnections,
  0, 0,
  6, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  1, scm_astParamters
};


