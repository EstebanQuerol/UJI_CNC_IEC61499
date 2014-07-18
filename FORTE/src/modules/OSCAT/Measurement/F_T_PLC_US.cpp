/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_T_PLC_US
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-06-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_T_PLC_US.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_T_PLC_US_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_T_PLC_US, g_nStringIdF_T_PLC_US)

const CStringDictionary::TStringId FORTE_F_T_PLC_US::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_T_PLC_US::scm_anDataOutputTypeIds[] = {g_nStringIdDWORD};

const TForteInt16 FORTE_F_T_PLC_US::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_F_T_PLC_US::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_T_PLC_US::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_T_PLC_US::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_T_PLC_US::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_T_PLC_US::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_F_T_PLC_US::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
      OUT() = T_PLC_US();
      sendOutputEvent(scm_nEventCNFID);
  }
}



