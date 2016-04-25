/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_GEN_Machine
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2015-03-17/EQUEROL - UJI - 
 ***     1.0: 2016-01-19/EQUEROL - UJI - 
 *************************************************************************/

#include "L2_GEN_Machine.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_GEN_Machine_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_GEN_Machine, g_nStringIdL2_GEN_Machine)

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdMID, g_nStringIdCOM_INIT_QI, g_nStringIdPartInfoIn1, g_nStringIdSetupIn, g_nStringIdPartInfoIn2, g_nStringIdQI2, g_nStringIdServiceStateIn, g_nStringIdENDOPIDIn};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdBOOL, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataOutputNames[] = {g_nStringIdMUI_STATE, g_nStringIdMUI_MSG, g_nStringIdMUI_PART_ID, g_nStringIdMUI_PART_FAMILY, g_nStringIdMUI_PART_TYPE, g_nStringIdCOM_INIT_QO, g_nStringIdOperationOut, g_nStringIdL1MIDOut, g_nStringIdPartInfoOut, g_nStringIdENDID, g_nStringIdMachineState, g_nStringIdQO2};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_L2_GEN_Machine::scm_anEIWithIndexes[] = {0, 3, 5, 8, 10, 12, -1, 14};
const TDataIOID FORTE_L2_GEN_Machine::scm_anEIWith[] = {0, 1, 255, 2, 255, 3, 4, 255, 5, 255, 6, 255, 7, 255, 8, 255};
const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCOM_INIT_RSP, g_nStringIdL3REQ, g_nStringIdL3RSP, g_nStringIdL0RSP1, g_nStringIdL0RSP2, g_nStringIdL1RSP, g_nStringIdL1IND};

const TDataIOID FORTE_L2_GEN_Machine::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 5, 255, 6, 7, 255, 8, 255, 8, 9, 255, 10, 255, 11, 255, 11, 255};
const TForteInt16 FORTE_L2_GEN_Machine::scm_anEOWithIndexes[] = {0, 6, 8, 11, 13, -1, 16, 18, 20, -1};
const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anEventOutputNames[] = {g_nStringIdMUI_IND, g_nStringIdCOM_INIT, g_nStringIdSend, g_nStringIdCNF, g_nStringIdIND, g_nStringIdFREE, g_nStringIdERROR, g_nStringIdL0INITO, g_nStringIdL0IND1};

const SFBInterfaceSpec FORTE_L2_GEN_Machine::scm_stFBInterfaceSpec = {
  8,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  9,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  9,  scm_anDataInputNames, scm_anDataInputTypeIds,
  12,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_L2_GEN_Machine::scm_astInternalFBs[] = {
  {g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdL2_ASetupRSPHDLR},
  {g_nStringIdL2_ExecutionManager_0, g_nStringIdL2_ExecutionManager},
  {g_nStringIdL2_MachineCore_0, g_nStringIdL2_MachineCore},
  {g_nStringIdE_DELAY_1, g_nStringIdE_DELAY},
  {g_nStringIdL2_L1Comm_1, g_nStringIdL2_L1Comm},
  {g_nStringIdE_DELAY_3, g_nStringIdE_DELAY},
  {g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdL2_ASetupREQHDLR},
  {g_nStringIdE_DELAY_2, g_nStringIdE_DELAY},
  {g_nStringIdL2_StateTracker, g_nStringIdL2_StateTracker},
  {g_nStringIdL2_MachineINIT, g_nStringIdL2_MachineINIT},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdL2_MachineState, g_nStringIdL2_MachineState},
};

const SCFB_FBConnectionData FORTE_L2_GEN_Machine::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdStart), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTART), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdCNF), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdINITO), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdstop), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdSTOP), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdStop), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTOP), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdRENEW), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdRENEW), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdCompleted), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCompletedSetup), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdEO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdTimeout), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdstart), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdSTART), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdNEXT), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdNEXT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdEO), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdtimeout), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdCompletedOP), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCompletedOP), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdRSP), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdExecuteOP), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdREQ), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdSend), 4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSend), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdIND), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIND), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL3REQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdREQ), 6},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL3RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdRSP), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdRSP), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1IND), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdIND), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdStart), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdSTART), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdStop), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdSTOP), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdEO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdTimeout), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdUPDT), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdUPDT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdIND), 8, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0IND1), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0RSP2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdRSP), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdStart), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdStop), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTOP), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdTimeOut), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL0_INIT), 9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0INITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL2_INIT), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdINIT), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdINIT), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdINITO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL2_INIT_RSP), 9},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0RSP1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL0_INIT_RSP), 9},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCOM_INIT_RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdCOM_INIT_RSP), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdCOM_INIT), 9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCOM_INIT), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdEXT_INIT), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdIND), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_INIT_RSP), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdFREE), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_FREE), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdERROR), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_ERROR), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_INIT), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdINIT), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_IND), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_IND), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdFREE), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFREE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdERROR), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdERROR), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_L2_GEN_Machine::scm_astFannedOutEventConnections[] = {
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_BUSY), 11},
};

const SCFB_FBConnectionData FORTE_L2_GEN_Machine::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdMIDOut), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdMID), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdENDOPIDOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDOPID), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdL1MID), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdL1MIDIn), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdPartInfoOut), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdPartInfoIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdENDSetupID), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDSetupID), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdQO), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdOperation), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdOperationIn), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdDelay), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdDT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdSetupOut), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdSetup), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdNextCode), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdNextCode), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdDelay), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdDT), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdOperationOut), 4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOperationOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdL1MIDOut), 4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1MIDOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdPartInfoOut), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDID), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDID), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdMID), 6},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoIn1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdPartInfoIn), 6},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSetupIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdSetupIn), 6},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoIn2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdPartInfo), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDOPIDIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdENDOPIDIn), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdDelay), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdDT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdServiceStateOut), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdServiceState), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdServiceStateIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdServiceStateIn), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdTODelay), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL0_INIT_QO), 9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO2), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL2_INIT_QO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdQI), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdQI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdQO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdQI), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker, g_nStringIdQO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL2_INIT_QI), 9},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdL0_INIT_QI), 9},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCOM_INIT_QI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdCOM_INIT_QI), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdCOM_INIT_QO), 9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCOM_INIT_QO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdEXT_INIT_QI), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdINIT_QO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_INIT_QI), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdINIT_STATE), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_INIT_STATE), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdMachineState), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_ERROR_STATE), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdM_INIT_QO), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineINIT, g_nStringIdINIT_QI), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_STATE), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_STATE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_MSG), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_MSG), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_PART_ID), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_PART_ID), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_PART_FAMILY), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_PART_FAMILY), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdMUI_PART_TYPE), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMUI_PART_TYPE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdERROR_STATE), 11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMachineState), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_L2_GEN_Machine::scm_astFannedOutDataConnections[] = {
  {13, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineState, g_nStringIdCURRENT_PARTINFO), 11},
};

const SCFB_FBNData FORTE_L2_GEN_Machine::scm_stFBNData = {
  12, scm_astInternalFBs,
  46, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  43, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


