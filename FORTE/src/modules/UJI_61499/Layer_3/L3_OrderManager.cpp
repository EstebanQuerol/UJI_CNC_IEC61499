/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_OrderManager
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_OrderManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_OrderManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_OrderManager, g_nStringIdL3_OrderManager)

const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFamily, g_nStringIdType, g_nStringIdLotsize, g_nStringIdDeadline};

const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdDATE_AND_TIME};

const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_L3_OrderManager::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_L3_OrderManager::scm_anEIWith[] = {0, 255, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L3_OrderManager::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_L3_OrderManager::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_L3_OrderManager::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SAdapterInstanceDef FORTE_L3_OrderManager::scm_astAdapterInstances[] = {
{g_nStringIdL3_APart, g_nStringIdL3_APart, true }};

const SFBInterfaceSpec FORTE_L3_OrderManager::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};


const SCFB_FBInstanceData FORTE_L3_OrderManager::scm_astInternalFBs[] = {
  {g_nStringIdL3_OrderTable, g_nStringIdL3_OrderTable},
  {g_nStringIdL3_ReceivePart, g_nStringIdL3_ReceivePart},
  {g_nStringIdL3_SendPart, g_nStringIdL3_SendPart},
  {g_nStringIdSend_Timeout, g_nStringIdE_TimeOut},
  {g_nStringIdL3_OrderInput, g_nStringIdL3_OrderInput},
  {g_nStringIdL3_PartMerge, g_nStringIdL3_PartMerge},
};

const SCFB_FBConnectionData FORTE_L3_OrderManager::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdCNF1), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdUpdate), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdCNF2), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdRSP), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdCNF), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdInsert), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdIND), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdRSP), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdIND), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdCNF), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdRSP), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdREQIN), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdIND), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdRSPIN), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdREQOUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdREQ), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdRSPOUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdRSP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdREQ), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdIND), 4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_L3_OrderManager::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdPartIDP), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdPartIDIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdFamilyP), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdFamilyIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdTypeP), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdTypeIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdLotsizeP), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdLotsizeIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdDeadlineOut), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdDeadlineIn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdATimeOut), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSend_Timeout, g_nStringIdTimeOutSocket), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdPartIDOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdPartIDS), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdFamilyOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdFamilyS), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdTypeOut), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdTypeS), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdFamilyOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdFamily), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdTypeOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdType), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdLotsizeOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdLotsize), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdDeadlineOut), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdDeadlineIn), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdPartIDS), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdPartIDIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdFamilyS), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdFamilyIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdTypeS), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdTypeIn), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdPartIDP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdPartIDP1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdFamilyP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdFamilyP1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdTypeP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdTypeP1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdLotsizeP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdLotsize1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_SendPart, g_nStringIdDeadlineP), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdDeadline1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdFamilyS), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdFamilyP2), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdTypeS), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdTypeP2), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdDeadlineS), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdDeadline2), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdPartIDP), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdPartIDP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdFamilyP), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdFamilyP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdTypeP), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdTypeP), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdLotsize), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdLotsize), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_PartMerge, g_nStringIdDeadline), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_APart, g_nStringIdDeadline), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFamily), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdFamilyIn), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdType), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdTypeIn), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdLotsize), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdLotsizeIn), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDeadline), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderInput, g_nStringIdDeadlineIn), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdQI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_OrderTable, g_nStringIdQO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_L3_OrderManager::scm_astFannedOutDataConnections[] = {
  {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ReceivePart, g_nStringIdDeadline), 1},
};

const SCFB_FBNData FORTE_L3_OrderManager::scm_stFBNData = {
  6, scm_astInternalFBs,
  15, scm_astEventConnections,
  0, 0,
  35, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


