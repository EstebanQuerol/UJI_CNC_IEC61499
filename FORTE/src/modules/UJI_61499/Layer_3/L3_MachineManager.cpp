/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_MachineManager
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-06/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_MachineManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_MachineManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_MachineManager, g_nStringIdL3_MachineManager)

const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPeriod, g_nStringIdMType, g_nStringIdMID1, g_nStringIdMID2, g_nStringIdState};

const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_L3_MachineManager::scm_anEIWithIndexes[] = {0, 4, 6};
const TDataIOID FORTE_L3_MachineManager::scm_anEIWith[] = {0, 2, 1, 255, 3, 255, 4, 5, 255};
const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ1, g_nStringIdREQ2};

const TDataIOID FORTE_L3_MachineManager::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L3_MachineManager::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_L3_MachineManager::scm_anEventOutputNames[] = {g_nStringIdINITO};

const SAdapterInstanceDef FORTE_L3_MachineManager::scm_astAdapterInstances[] = {
{g_nStringIdL3_AAssignMachine, g_nStringIdAMachine_Plug, true },
{g_nStringIdL3_AAssignMachine, g_nStringIdAMachine_Socket, false }};

const SFBInterfaceSpec FORTE_L3_MachineManager::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  2,scm_astAdapterInstances};


void FORTE_L3_MachineManager::setInitialValues(){
  Period().fromString("T#1000ms");
  MType_Array().fromString("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]");
}


const SCFB_FBInstanceData FORTE_L3_MachineManager::scm_astInternalFBs[] = {
  {g_nStringIdL3_ReleasedMHDLR, g_nStringIdL3_ReleasedMHDLR},
  {g_nStringIdL3_FaultyMHDLR, g_nStringIdL3_FaultyMHDLR},
  {g_nStringIdCORE_TIMEOUT, g_nStringIdE_DELAY},
  {g_nStringIdL3_MMCore, g_nStringIdL3_MMCore},
};

const SCFB_FBConnectionData FORTE_L3_MachineManager::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReleasedMHDLR, g_nStringIdREQ1), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdREQ2), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdINIT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReleasedMHDLR, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdRSP1), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdRSP2), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdINITO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdIND1), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReleasedMHDLR, g_nStringIdREQ2), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdIND2), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdREQ1), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdIND3), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdCHK), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdIND4), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdASG), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdStart), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCORE_TIMEOUT, g_nStringIdSTART), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdStop), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCORE_TIMEOUT, g_nStringIdSTOP), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCORE_TIMEOUT, g_nStringIdEO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdTimeOut), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Socket, g_nStringIdCHK), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdRSP3), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Socket, g_nStringIdASG), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdRSP4), 3},
};

const SCFB_FBConnectionData FORTE_L3_MachineManager::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMID1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReleasedMHDLR, g_nStringIdMID), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMID2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdMID), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdState), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdState), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMType), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdMTypeP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdQI), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReleasedMHDLR, g_nStringIdMReleased), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMReleased), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_FaultyMHDLR, g_nStringIdMFaulty), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMFaulty), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdQO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMStateP), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdMStateP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMPriority), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdMPriorityP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMAssignP), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdMAssignP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMFinalAssignP), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Plug, g_nStringIdMFinalAssignP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPeriod), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCORE_TIMEOUT, g_nStringIdDT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Socket, g_nStringIdMAssignP), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMAssignS), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAMachine_Socket, g_nStringIdMFinalAssignP), CCompositeFB::scm_nAdapterMarker |1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_MMCore, g_nStringIdMFinalAssignS), 3},
};

const SCFB_FBNData FORTE_L3_MachineManager::scm_stFBNData = {
  4, scm_astInternalFBs,
  15, scm_astEventConnections,
  0, 0,
  15, scm_astDataConnections,
  0, 0,
  0, 0
};


