/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: AdapterTest_P
 *** Description: Composite Function Block Type
 *** Version:
 ***     0.0: 2008-04-22/IH - ACIN -
 *************************************************************************/

#include "AdapterTest_P.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AdapterTest_P_gen.cpp"
#endif
#include <typelib.h>

DEFINE_FIRMWARE_FB(AdapterTest_P, g_nStringIdAdapterTest_P)

const CStringDictionary::TStringId AdapterTest_P::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdSub1_addr, g_nStringIdSub2_addr, g_nStringIdPub1_addr, g_nStringIdPub2_addr};

const CStringDictionary::TStringId AdapterTest_P::scm_anAdapterNames[] = {g_nStringIdmyPlug};
const CStringDictionary::TStringId AdapterTest_P::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdWSTRING};

const TForteInt16 AdapterTest_P::scm_anEIWithIndexes[] = {0};
const TDataIOID AdapterTest_P::scm_anEIWith[] = {0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId AdapterTest_P::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 AdapterTest_P::scm_anEOWithIndexes[] = {-1};
const CStringDictionary::TStringId AdapterTest_P::scm_anEventOutputNames[] = {g_nStringIdINITO};

const SAdapterInstanceDef AdapterTest_P::scm_astAdapterInstances[] = {{g_nStringIdTESTADAPTER, g_nStringIdmyPlug, true}};

const SFBInterfaceSpec AdapterTest_P::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  0,
  scm_anEOWithIndexes,
  5,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  0,
  0,
  0,
  1,
  scm_astAdapterInstances
};

const SCFB_FBInstanceData AdapterTest_P::scm_astInternalFBs[] = {
    {g_nStringIdPlugRec1, g_nStringIdSUBSCRIBE_1},
    {g_nStringIdPlugRec2, g_nStringIdSUBSCRIBE_1},
    {g_nStringIdPlugSend1, g_nStringIdPUBLISH_1},
    {g_nStringIdPlugSend2, g_nStringIdPUBLISH_1}};

const SCFB_FBConnectionData AdapterTest_P::scm_astEventConnections[] = {
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdINITO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdINIT), 1},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdIND), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdIND), CCompositeFB::scm_nAdapterMarker | 0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdINIT), 3},
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdINIT), 0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdREQ), CCompositeFB::scm_nAdapterMarker | 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdREQ), 2},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdIND), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdCNF), CCompositeFB::scm_nAdapterMarker | 0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdRSP), CCompositeFB::scm_nAdapterMarker | 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdREQ), 3},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdINIT), 2}
};

const SCFB_FBConnectionData AdapterTest_P::scm_astDataConnections[] = {
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPub1_addr), -1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdID),2},
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSub2_addr), -1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdID),1},
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSub1_addr), -1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdID), 0},
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPub2_addr), -1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdID),3},
    {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI),-1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdQI),0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdRSPD),CCompositeFB::scm_nAdapterMarker | 0,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdSD_1),3},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdRD_1), 0,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdCNFD),CCompositeFB::scm_nAdapterMarker | 0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdREQD),CCompositeFB::scm_nAdapterMarker | 0,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdSD_1),2},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdRD_1),1,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmyPlug, g_nStringIdINDD),CCompositeFB::scm_nAdapterMarker | 0},
    {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec1, g_nStringIdQO),0,GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugRec2, g_nStringIdQI),1}
};

const SCFB_FBFannedOutConnectionData AdapterTest_P::scm_astFannedOutDataConnections[] = {
    {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend1, g_nStringIdQI),2},
    {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPlugSend2, g_nStringIdQI),3}
};

const SCFB_FBNData AdapterTest_P::scm_stFBNData = {
    4,
    scm_astInternalFBs,
    9,
    scm_astEventConnections,
    0,
    0,
    10,
    scm_astDataConnections,
    2,
    scm_astFannedOutDataConnections,
    0,
    0
};

AdapterTest_P::~AdapterTest_P(){
}



