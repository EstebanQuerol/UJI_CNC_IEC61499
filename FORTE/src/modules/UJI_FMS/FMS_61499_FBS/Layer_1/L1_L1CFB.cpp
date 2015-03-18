/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_L1CFB
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2015-03-18/EQUEROL - UJI - 
 *************************************************************************/

#include "L1_L1CFB.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L1_L1CFB_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L1_L1CFB, g_nStringIdL1_L1CFB)

const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anDataInputNames[] = {g_nStringIdOperationIn, g_nStringIdL1MIDIn};

const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anDataOutputNames[] = {g_nStringIdCmdOut, g_nStringIdENDOPID};

const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdUSINT};

const TForteInt16 FORTE_L1_L1CFB::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_L1_L1CFB::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anEventInputNames[] = {g_nStringIdL2REQ, g_nStringIdL0RSP};

const TDataIOID FORTE_L1_L1CFB::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_L1_L1CFB::scm_anEOWithIndexes[] = {0, 2, -1, -1};
const CStringDictionary::TStringId FORTE_L1_L1CFB::scm_anEventOutputNames[] = {g_nStringIdL0Send, g_nStringIdL2IND, g_nStringIdL2CNF};

const SFBInterfaceSpec FORTE_L1_L1CFB::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_L1_L1CFB::scm_astInternalFBs[] = {
  {g_nStringIdE_DELAY_0, g_nStringIdE_DELAY},
  {g_nStringIdL1_MCEmitter_1, g_nStringIdL1_MCEmitter},
  {g_nStringIdL1_FSetup_1, g_nStringIdL1_FSetup},
  {g_nStringIdL1_SendCmd_1, g_nStringIdL1_SendCmd},
  {g_nStringIdL1_FClosedPocket_1, g_nStringIdL1_FClosedPocket},
  {g_nStringIdL1_FRoundHole_1, g_nStringIdL1_FRoundHole},
  {g_nStringIdL1_Merge2Cmd, g_nStringIdL1_Merge2Cmd},
  {g_nStringIdL1_Merge2Cmd_1, g_nStringIdL1_Merge2Cmd},
  {g_nStringIdL1_Merge2Cmd_2, g_nStringIdL1_Merge2Cmd},
  {g_nStringIdL1_Merge2Cmd_3, g_nStringIdL1_Merge2Cmd},
};

const SCFB_FBConnectionData FORTE_L1_L1CFB::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_0, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdTimeout), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdStop), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_0, g_nStringIdSTOP), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdStart), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_0, g_nStringIdSTART), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0RSP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdRSP), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL0Send), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdIND), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL2IND), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdE1), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdEO), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdE2), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdCNF), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdE1), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdEO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdE2), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdCNF), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdE1), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdEO), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL2CNF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL2REQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdE1), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdEO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdREQ), 1},
};

const SCFB_FBFannedOutConnectionData FORTE_L1_L1CFB::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdREQ), 5},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdREQ), 3},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdREQ), 4},
  {12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdE2), 9},
};

const SCFB_FBConnectionData FORTE_L1_L1CFB::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdOperationOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdOperation), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdL1MIDOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdL1MIDIn), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdDelay), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_0, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdCmdOut), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCmdOut), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdENDOPID), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDOPID), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdCmdOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdCmd2), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdL1MIDOut), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdL1MID2), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdCmd), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdCmd1), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdL1MIDOut), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdL1MID1), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdCmd), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdCmd1), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdL1MIDOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdL1MID1), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdCmdOut), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdCmd2), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdL1MIDOut), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_1, g_nStringIdL1MID2), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdCmd), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdCmd1), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdL1MIDOut), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_2, g_nStringIdL1MID1), 8},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOperationIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdCmd1), 9},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL1MIDIn), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdL1MID1), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdCmdOut), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdCmd2), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd, g_nStringIdL1MIDOut), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdL1MID2), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdCmdOut), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdOperationIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_Merge2Cmd_3, g_nStringIdL1MIDOut), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_MCEmitter_1, g_nStringIdL1MIDIn), 1},
};

const SCFB_FBFannedOutConnectionData FORTE_L1_L1CFB::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdCmdIn), 3},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FRoundHole_1, g_nStringIdOperation), 5},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdOperation), 4},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_SendCmd_1, g_nStringIdL1MID), 3},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FClosedPocket_1, g_nStringIdL1MIDIn), 4},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL1_FSetup_1, g_nStringIdL1MIDIn), 2},
};

const SCFB_FBNData FORTE_L1_L1CFB::scm_stFBNData = {
  10, scm_astInternalFBs,
  15, scm_astEventConnections,
  4, scm_astFannedOutEventConnections,
  21, scm_astDataConnections,
  6, scm_astFannedOutDataConnections,
  0, 0
};


