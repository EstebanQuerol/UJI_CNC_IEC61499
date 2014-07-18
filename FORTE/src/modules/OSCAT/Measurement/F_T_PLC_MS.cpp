/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_T_PLC_MS
 *** Description: reads the internal PLC timer and returns the time
 *** Version: 
 ***     0.0: 2011-08-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_T_PLC_MS.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_T_PLC_MS_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_T_PLC_MS, g_nStringIdF_T_PLC_MS)

const CStringDictionary::TStringId FORTE_F_T_PLC_MS::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_T_PLC_MS::scm_anDataOutputTypeIds[] = {g_nStringIdDWORD};

const TForteInt16 FORTE_F_T_PLC_MS::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_F_T_PLC_MS::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_T_PLC_MS::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_T_PLC_MS::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_T_PLC_MS::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_T_PLC_MS::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_T_PLC_MS::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
      OUT() = T_PLC_MS();
      sendOutputEvent(scm_nEventCNFID);
  }
}



