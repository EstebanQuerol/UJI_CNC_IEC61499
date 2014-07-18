/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTD_DINT
 *** Description: counters (down-counter)
 *** Version:
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/

#include "FB_CTD_DINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CTD_DINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FB_CTD_DINT, g_nStringIdFB_CTD_DINT)

const CStringDictionary::TStringId FB_CTD_DINT::scm_anDataInputNames[] = {g_nStringIdCD, g_nStringIdLD, g_nStringIdPV};

const CStringDictionary::TStringId FB_CTD_DINT::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdCV};
const CStringDictionary::TStringId FB_CTD_DINT::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdDINT};
const CStringDictionary::TStringId FB_CTD_DINT::scm_aunDODataTypeIds[] = {g_nStringIdBOOL, g_nStringIdDINT};

const TForteInt16 FB_CTD_DINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FB_CTD_DINT::scm_anEIWith[] = {0, 2, 1, 255};
const CStringDictionary::TStringId FB_CTD_DINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FB_CTD_DINT::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FB_CTD_DINT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FB_CTD_DINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FB_CTD_DINT::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  3,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  2,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void FB_CTD_DINT::executeEvent(int pa_nEIID){
  if(pa_nEIID == scm_nEventREQID){
      if(true == LD()){
        CV() = PV();
      }
      else if( (true == CD()) && (CV() > CIEC_DINT::scm_nMinVal)){
        CV() = CV() - 1;
      }
      Q() = (CV() <= 0);
      sendOutputEvent(scm_nEventCNFID);
  }
}



