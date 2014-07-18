/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_SR
 *** Description: Bistable Function Block (set dominant)
 *** Version:
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/

#include "FB_SR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_SR_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FB_SR, g_nStringIdFB_SR)

const CStringDictionary::TStringId FB_SR::scm_anDataInputNames[] = {g_nStringIdS1, g_nStringIdR};

const CStringDictionary::TStringId FB_SR::scm_anDataOutputNames[] = {g_nStringIdQ1};
const CStringDictionary::TStringId FB_SR::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const CStringDictionary::TStringId FB_SR::scm_aunDODataTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FB_SR::scm_anEIWithIndexes[] = {0};
const TDataIOID FB_SR::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FB_SR::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FB_SR::scm_anEOWith[] = {0, 255};
const TForteInt16 FB_SR::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FB_SR::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FB_SR::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  2,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void FB_SR::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
    	Q1() = S1() || (!R() && Q1());
    	sendOutputEvent(scm_nEventCNFID);
    	break;
  }
}
