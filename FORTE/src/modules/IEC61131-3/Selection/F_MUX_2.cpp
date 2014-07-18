/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MUX_2
 *** Description: multiplexer
 *** Version: 
 ***     1.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_MUX_2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_MUX_2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_MUX_2, g_nStringIdF_MUX_2)

const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anDataInputNames[] = {g_nStringIdK, g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anDataInputTypeIds[] = {g_nStringIdANY_INT, g_nStringIdANY, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anDataOutputTypeIds[] = {g_nStringIdANY};

const TForteInt16 FORTE_F_MUX_2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_MUX_2::scm_anEIWith[] = {1, 2, 0, 255};
const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_MUX_2::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_MUX_2::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_MUX_2::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_MUX_2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_MUX_2::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    if(K().isSigned() && (K().getSignedValue() < 0 || K().getSignedValue() > 1)){
        DEVLOG_ERROR("value of input K is not between 0 and 1");
    }else{
      OUT().saveAssign(*static_cast<CIEC_ANY*>(getDI( static_cast<TForteUInt16>(K().getUnsignedValue() + 1))));
      sendOutputEvent(scm_nEventCNFID);
    }
  }
}



