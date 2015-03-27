/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_GEN_Machine
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2015-03-17/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "L2_GEN_Machine.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L2_GEN_Machine_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L2_GEN_Machine, g_nStringIdL2_GEN_Machine)

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdMID, g_nStringIdPartInfoIn1, g_nStringIdSetupIn, g_nStringIdPartInfoIn2, g_nStringIdQI2, g_nStringIdServiceStateIn, g_nStringIdENDOPIDIn};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdOperationOut, g_nStringIdL1MIDOut, g_nStringIdPartInfoOut, g_nStringIdENDID, g_nStringIdMachineState, g_nStringIdQO2};

const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUSINT, g_nStringIdARRAY, 4, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_L2_GEN_Machine::scm_anEIWithIndexes[] = {0, 3, 6, 8, 10, -1, 12};
const TDataIOID FORTE_L2_GEN_Machine::scm_anEIWith[] = {0, 1, 255, 2, 3, 255, 4, 255, 5, 255, 6, 255, 7, 255};
const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdL3REQ, g_nStringIdL3RSP, g_nStringIdL0RSP1, g_nStringIdL0RSP2, g_nStringIdL1RSP, g_nStringIdL1IND};

const TDataIOID FORTE_L2_GEN_Machine::scm_anEOWith[] = {0, 255, 1, 2, 255, 3, 255, 3, 4, 255, 5, 255, 6, 255, 6, 255};
const TForteInt16 FORTE_L2_GEN_Machine::scm_anEOWithIndexes[] = {0, 2, 5, 7, -1, 10, 12, 14, -1};
const CStringDictionary::TStringId FORTE_L2_GEN_Machine::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdSend, g_nStringIdCNF, g_nStringIdIND, g_nStringIdFREE, g_nStringIdERROR, g_nStringIdL0INITO, g_nStringIdL0IND1};

const SFBInterfaceSpec FORTE_L2_GEN_Machine::scm_stFBInterfaceSpec = {
  7,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  8,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  7,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_L2_GEN_Machine::scm_astInternalFBs[] = {
  {g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdL2_ASetupRSPHDLR},
  {g_nStringIdL2_StateTracker_1, g_nStringIdL2_StateTracker},
  {g_nStringIdL2_ExecutionManager_0, g_nStringIdL2_ExecutionManager},
  {g_nStringIdL2_MachineCore_0, g_nStringIdL2_MachineCore},
  {g_nStringIdE_DELAY_1, g_nStringIdE_DELAY},
  {g_nStringIdL2_L1Comm_1, g_nStringIdL2_L1Comm},
  {g_nStringIdE_DELAY_3, g_nStringIdE_DELAY},
  {g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdL2_ASetupREQHDLR},
  {g_nStringIdE_DELAY_2, g_nStringIdE_DELAY},
};

const SCFB_FBConnectionData FORTE_L2_GEN_Machine::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdStart), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTART), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdCNF), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdREQ), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdINITO), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdUPDT), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdUPDT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdStop), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdSTOP), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdEO), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdTimeout), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdStart), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdSTART), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdstop), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdSTOP), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdStop), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTOP), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdRENEW), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdRENEW), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdCompleted), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCompletedSetup), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdTimeout), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdstart), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdSTART), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdNEXT), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdNEXT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdEO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdtimeout), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdCompletedOP), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCompletedOP), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdRSP), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdExecuteOP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdREQ), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdSend), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSend), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdIND), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIND), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdFREE), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFREE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdERROR), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdERROR), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0INITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdIND), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0IND1), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdINIT), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL3REQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdREQ), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL3RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdRSP), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0RSP1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdRSP1), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0RSP2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdRSP2), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdRSP), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1IND), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdIND), 5},
};

const SCFB_FBFannedOutConnectionData FORTE_L2_GEN_Machine::scm_astFannedOutEventConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdINIT), 2},
};

const SCFB_FBConnectionData FORTE_L2_GEN_Machine::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdMIDOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdMID), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdENDOPIDOut), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDOPID), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdL1MID), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdL1MIDIn), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdPartInfoOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdPartInfoIn), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdENDSetupID), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDSetupID), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdQO), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdQI), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdOperation), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdOperationIn), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdDelay), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdDT), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdSetupOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdSetup), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdNextCode), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdNextCode), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdServiceStateOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdServiceState), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdQI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdDelay), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_2, g_nStringIdDT), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdOperationOut), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOperationOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdL1MIDOut), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1MIDOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdPartInfoOut), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdENDID), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDID), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_MachineCore_0, g_nStringIdMachineState), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMachineState), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdQO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO2), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ExecutionManager_0, g_nStringIdQO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdQI), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdMID), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoIn1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdPartInfoIn), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSetupIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupREQHDLR_1, g_nStringIdSetupIn), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoIn2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdPartInfo), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdQI2), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdServiceStateIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdServiceStateIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_StateTracker_1, g_nStringIdDelay), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_3, g_nStringIdDT), 6},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDOPIDIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_L1Comm_1, g_nStringIdENDOPIDIn), 5},
};

const SCFB_FBFannedOutConnectionData FORTE_L2_GEN_Machine::scm_astFannedOutDataConnections[] = {
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL2_ASetupRSPHDLR_1, g_nStringIdQI), 0},
};

const SCFB_FBNData FORTE_L2_GEN_Machine::scm_stFBNData = {
  9, scm_astInternalFBs,
  34, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  29, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


