/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_8070Service
 *** Description: FAGOR 8070 CNC service FB
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - 
 ***     1.0: 2015-03-03/EQUEROL - UJI - Service rework
 *************************************************************************/

#include "L0_8070Service.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_8070Service_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_8070Service, g_nStringIdL0_8070Service)

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdCmd};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdENDOPID, g_nStringIdRD, g_nStringIdServiceState};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_8070Service::scm_anEIWithIndexes[] = {0, 2, -1};
const TDataIOID FORTE_L0_8070Service::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdREQS};

const TDataIOID FORTE_L0_8070Service::scm_anEOWith[] = {0, 255, 1, 255, 3, 255, 2, 255};
const TForteInt16 FORTE_L0_8070Service::scm_anEOWithIndexes[] = {0, -1, 2, 4, 6};
const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND, g_nStringIdCompletedOP, g_nStringIdCNFS};

const SFBInterfaceSpec FORTE_L0_8070Service::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_L0_8070Service::scm_astInternalFBs[] = {
  {g_nStringIdL0_SendBlk, g_nStringIdL0_SendBlk},
  {g_nStringIdL0_StateHandler, g_nStringIdL0_StateHandler},
  {g_nStringIdL0_CompletedEx, g_nStringIdL0_CompletedEx},
  {g_nStringIdCM_Merge2E2USINT, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdCM_Merge2E2USINT_2, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdL0_State_0, g_nStringIdL0_State},
  {g_nStringIdL0_ReqManager, g_nStringIdL0_ReqManager},
};

const SCFB_FBParameter FORTE_L0_8070Service::scm_astParamters[] = {
  {4, g_nStringIdE1In, "1"},
  {4, g_nStringIdE2In, "2"},
};

const SCFB_FBConnectionData FORTE_L0_8070Service::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnReady), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnReady), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnExecution), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnExecuting), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnNotReady), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnNotReady), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdSuccess), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE1), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE2), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnInterrupted), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdE1), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnIntError), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdE2), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQS), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdREQ2), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdCNF2), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNFS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdUPDTO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdIND), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdUPDT), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdREQ1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdINIT), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdCNF1), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdREQ), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdEO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdUPDT), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdINITO), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdCNF), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdIND), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIND), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdCompleted), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCompletedOP), -1},
};

const SCFB_FBConnectionData FORTE_L0_8070Service::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdRID), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE1In), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE2In), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdServiceState), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdServiceState), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdStateOut), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdCNCState), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdCNCState), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdStateIn), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdQI), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdRIDIn), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdQO), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdENDOPID), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDOPID), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_L0_8070Service::scm_astFannedOutDataConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdServiceState), 6},
};

const SCFB_FBNData FORTE_L0_8070Service::scm_stFBNData = {
  7, scm_astInternalFBs,
  20, scm_astEventConnections,
  0, 0,
  10, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  2, scm_astParamters
};


