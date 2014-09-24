/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_8070Service
 *** Description: FAGOR 8070 CNC service FB
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_8070Service.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_8070Service_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_8070Service, g_nStringIdL0_8070Service)

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdCmdID, g_nStringIdSD, g_nStringIdPN};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdRID, g_nStringIdRD, g_nStringIdServiceState};

const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_8070Service::scm_anEIWithIndexes[] = {0, 2, -1};
const TDataIOID FORTE_L0_8070Service::scm_anEIWith[] = {0, 255, 0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdREQS};

const TDataIOID FORTE_L0_8070Service::scm_anEOWith[] = {0, 255, 1, 255, 3, 255, 2, 255};
const TForteInt16 FORTE_L0_8070Service::scm_anEOWithIndexes[] = {0, 2, 4, 6};
const CStringDictionary::TStringId FORTE_L0_8070Service::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdCNFS};

const SFBInterfaceSpec FORTE_L0_8070Service::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_L0_8070Service::scm_astInternalFBs[] = {
  {g_nStringIdL0_SendBlk, g_nStringIdL0_SendBlk},
  {g_nStringIdL0_CNCEncap, g_nStringIdL0_CNCEncap},
  {g_nStringIdL0_StateHandler, g_nStringIdL0_StateHandler},
  {g_nStringIdL0_CompletedEx, g_nStringIdL0_CompletedEx},
  {g_nStringIdCM_Merge2E2USINT, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdCM_Merge2E2USINT_0, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdCM_Merge2E2USINT_1, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdL0_ReqManager, g_nStringIdL0_ReqManager},
  {g_nStringIdCM_Merge2E2USINT_2, g_nStringIdCM_Merge2E2USINT},
  {g_nStringIdCM_ChkService, g_nStringIdCM_ChkService},
  {g_nStringIdL0_State_0, g_nStringIdL0_State},
};

const SCFB_FBParameter FORTE_L0_8070Service::scm_astParamters[] = {
  {5, g_nStringIdE1In, "3"},
  {5, g_nStringIdE2In, "4"},
  {8, g_nStringIdE1In, "1"},
  {8, g_nStringIdE2In, "2"},
};

const SCFB_FBConnectionData FORTE_L0_8070Service::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnReady), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnReady), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnExecution), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnExecuting), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnNotReady), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdOnNotReady), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdSuccess), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE1), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdIND), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdE1), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdUPDT), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdCNF), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdINIT), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdINITO), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdEO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE2), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnInterrupted), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdE1), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdOnIntError), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdE2), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_0, g_nStringIdEO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdE2), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdEO), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdUP), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdREQ), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdDOWN), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_0, g_nStringIdE1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdBUSY), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_0, g_nStringIdE2), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdREQ), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdREQS), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdREQ1), 10},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQS), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdREQ2), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdCNF1), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdRSP), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdCNF2), 10, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNFS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdUPDTO), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdIND), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdUPDT), 10},
};

const SCFB_FBConnectionData FORTE_L0_8070Service::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCmdID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdCmdID), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdSD), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdPN), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdsBlock), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdsBlock), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdQO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CompletedEx, g_nStringIdRID), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE1In), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_0, g_nStringIdOut), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdE2In), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdRIDOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdE1In), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdRIDIn), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_CNCEncap, g_nStringIdQI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdQI), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_ReqManager, g_nStringIdQO), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_2, g_nStringIdOut), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT, g_nStringIdE2In), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_Merge2E2USINT_1, g_nStringIdOut), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRID), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdServiceState), 10, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdServiceState), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdStateOut), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_StateHandler, g_nStringIdCNCState), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_SendBlk, g_nStringIdCNCState), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL0_State_0, g_nStringIdStateIn), 10},
};

const SCFB_FBFannedOutConnectionData FORTE_L0_8070Service::scm_astFannedOutDataConnections[] = {
  {14, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCM_ChkService, g_nStringIdServiceState), 9},
};

const SCFB_FBNData FORTE_L0_8070Service::scm_stFBNData = {
  11, scm_astInternalFBs,
  27, scm_astEventConnections,
  0, 0,
  17, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  4, scm_astParamters
};


