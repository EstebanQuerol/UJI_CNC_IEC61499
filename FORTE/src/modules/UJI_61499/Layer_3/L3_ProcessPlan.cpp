/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_ProcessPlan
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-13/EQUEROL - UJI - 
 ***     1.0: 2015-01-08/EQUEROL - UJI - modified setup adapter
 *************************************************************************/

#include "L3_ProcessPlan.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_ProcessPlan_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_ProcessPlan, g_nStringIdL3_ProcessPlan)

const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamily, g_nStringIdType};

const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_L3_ProcessPlan::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_L3_ProcessPlan::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anEventInputNames[] = {g_nStringIdINIT};

const TDataIOID FORTE_L3_ProcessPlan::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L3_ProcessPlan::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L3_ProcessPlan::scm_anEventOutputNames[] = {g_nStringIdINITO};

const SAdapterInstanceDef FORTE_L3_ProcessPlan::scm_astAdapterInstances[] = {
{g_nStringIdL3_AAssignMachine, g_nStringIdL3_AAssignMachine_P, true },
{g_nStringIdL3_ASetup, g_nStringIdL3_ASetup, true },
{g_nStringIdL3_APart, g_nStringIdL3_APart, false },
{g_nStringIdL3_AAssignMachine, g_nStringIdL3_AAssignMachine_S, false }};

const SFBInterfaceSpec FORTE_L3_ProcessPlan::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  4,scm_astAdapterInstances};


const SCFB_FBInstanceData FORTE_L3_ProcessPlan::scm_astInternalFBs[] = {
  {g_nStringIdL3_PPTable, g_nStringIdL3_PPTable},
  {g_nStringIdL3_NewPartHDLR, g_nStringIdL3_NewPartHDLR},
  {g_nStringIdL3_MachineAllocator, g_nStringIdL3_MachineAllocator},
  {g_nStringIdL3_MachineChecker, g_nStringIdL3_MachineChecker},
  {g_nStringIdL3_CompletedPartHDLR, g_nStringIdL3_CompletedPartHDLR},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdE_DELAY_1, g_nStringIdE_DELAY},
  {g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdL3_CompletedSetupHDLR},
  {g_nStringIdL3_SetupTable, g_nStringIdL3_SetupTable},
};

const SCFB_FBConnectionData FORTE_L3_ProcessPlan::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdCHK), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdREQ), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdIND), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdRSP), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdCHK), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdASG), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdStart), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdStop), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTOP), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdTimeout), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdASG), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdIND2), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdREQ2), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdCNF2), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdRSP2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdREQ), CCompositeFB::scm_nAdapterMarker |2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdREQ1), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdCNF1), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdCNF), CCompositeFB::scm_nAdapterMarker |2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdIND1), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdREQ2), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdCNF2), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdRSP1), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdStart), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTART), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdStop), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTOP), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdEO), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdTimeout), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdCNF), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdRSP3), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdIND3), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdREQ), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdIND), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdIND), CCompositeFB::scm_nAdapterMarker |2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdRSP), CCompositeFB::scm_nAdapterMarker |2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdRSP), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdINITO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdINIT), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdCNF1), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdRSP2), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdIND2), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdREQ1), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdINIT), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdIND1), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdREQ), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdINITO), 8, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdIND), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdREQ), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdCNF), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdRSP1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdCNF), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdREQ), CCompositeFB::scm_nAdapterMarker |1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdCNF), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdRSP), CCompositeFB::scm_nAdapterMarker |1},
};

const SCFB_FBFannedOutConnectionData FORTE_L3_ProcessPlan::scm_astFannedOutEventConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdREQ2), 2},
};

const SCFB_FBConnectionData FORTE_L3_ProcessPlan::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdMTypeP), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMTypeIn), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdMStateP), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMStateIn), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdMPriorityP), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMPriorityIn), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdMAssignP), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMAssignIn), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMTypeOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdMTypeP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMStateOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdMStateP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMPriorityOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdMPriorityP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdMAssignOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdMAssignP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdvPriority), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdPriority), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdDelay), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_S, g_nStringIdMFinalAssignP), CCompositeFB::scm_nAdapterMarker |3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdMFinalAssignIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdMFinalAssignOut), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_AAssignMachine_P, g_nStringIdMFinalAssignP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdvPartIDOut), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineChecker, g_nStringIdPartID), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdvSetup), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdSetupIDIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdPartIDOut), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdPartIDIn3), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdMID), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdMID), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdPartIDP), CCompositeFB::scm_nAdapterMarker |2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdPartIDIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdLotsize), CCompositeFB::scm_nAdapterMarker |2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdLotsizeIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdDeadline), CCompositeFB::scm_nAdapterMarker |2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdDeadlineIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdPartIDOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdPartIDIn1), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdLotsizeOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdLotsizeIn), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_NewPartHDLR, g_nStringIdDeadlineOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdDeadlineIn1), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdDelay), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdDT), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdPartIDOut), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdPartIDIn), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdQO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdPartIDOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdPartIDS), CCompositeFB::scm_nAdapterMarker |2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdFamilyOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdFamilyS), CCompositeFB::scm_nAdapterMarker |2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdTypeOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdTypeS), CCompositeFB::scm_nAdapterMarker |2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdDeadlineOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdDeadlineIn2), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdQI), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFamily), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdFamilyIn), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdType), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdTypeIn), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdPartIDOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdPartIDIn2), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdQI), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdSetupID), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdSetupID), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdQO), 8, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdPartInfoS), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedSetupHDLR_1, g_nStringIdPartInfo), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdPartInfo), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdPartInfoP), CCompositeFB::scm_nAdapterMarker |1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdMID2), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdMID), CCompositeFB::scm_nAdapterMarker |1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdSetup), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdSetup), CCompositeFB::scm_nAdapterMarker |1},
};

const SCFB_FBFannedOutConnectionData FORTE_L3_ProcessPlan::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdMType), 0},
  {12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MachineAllocator, g_nStringIdPartIDIn), 2},
  {14, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdPartID), 8},
  {15, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdMID), 8},
  {18, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_CompletedPartHDLR, g_nStringIdDeadlineIn), 4},
  {30, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdFamily), 0},
  {30, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdFamily), 8},
  {31, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PPTable, g_nStringIdType), 0},
  {31, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SetupTable, g_nStringIdType), 8},
};

const SCFB_FBNData FORTE_L3_ProcessPlan::scm_stFBNData = {
  9, scm_astInternalFBs,
  33, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  40, scm_astDataConnections,
  9, scm_astFannedOutDataConnections,
  0, 0
};


