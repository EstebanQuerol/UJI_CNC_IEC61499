/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_L2CommPlug
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2014-11-25/EQUEROL - UJI - 
 *************************************************************************/

#include "L3_L2CommPlug.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_L2CommPlug_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L3_L2CommPlug, g_nStringIdL3_L2CommPlug)

const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anDataInputNames[] = {g_nStringIdPartInfoS, g_nStringIdENDID};

const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anDataOutputNames[] = {g_nStringIdPartInfoP, g_nStringIdMID, g_nStringIdOPIDS, g_nStringIdOPParams, g_nStringIdFixture};

const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 3, g_nStringIdUINT, g_nStringIdUSINT, g_nStringIdARRAY, 20, g_nStringIdUINT, g_nStringIdARRAY, 20, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_L3_L2CommPlug::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_L3_L2CommPlug::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anEventInputNames[] = {g_nStringIdCNF, g_nStringIdIND};

const TDataIOID FORTE_L3_L2CommPlug::scm_anEOWith[] = {0, 1, 2, 3, 4, 255, 1, 255};
const TForteInt16 FORTE_L3_L2CommPlug::scm_anEOWithIndexes[] = {0, 6, -1};
const CStringDictionary::TStringId FORTE_L3_L2CommPlug::scm_anEventOutputNames[] = {g_nStringIdREQ, g_nStringIdRSP};

const SAdapterInstanceDef FORTE_L3_L2CommPlug::scm_astAdapterInstances[] = {
{g_nStringIdL3_ASetup, g_nStringIdL3_ASetup, false }};

const SFBInterfaceSpec FORTE_L3_L2CommPlug::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1,scm_astAdapterInstances};


const SCFB_FBConnectionData FORTE_L3_L2CommPlug::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdCNF), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIND), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdIND), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdREQ), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdRSP), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRSP), -1},
};

const SCFB_FBConnectionData FORTE_L3_L2CommPlug::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoS), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdPartInfoS), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdENDID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdENDID), CCompositeFB::scm_nAdapterMarker |0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdPartInfoP), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPartInfoP), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdMID), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdMID), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdOPIDS), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOPIDS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdOPParams), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOPParams), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdL3_ASetup, g_nStringIdFixture), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFixture), -1},
};

const SCFB_FBNData FORTE_L3_L2CommPlug::scm_stFBNData = {
  0, 0,
  4, scm_astEventConnections,
  0, 0,
  7, scm_astDataConnections,
  0, 0,
  0, 0
};


