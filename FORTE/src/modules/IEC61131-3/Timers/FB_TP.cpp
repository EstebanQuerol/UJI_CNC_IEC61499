/*************************************************************************
*** FORTE Library Element
***
*** This file was generated using the 4DIAC FORTE Export Filter V0.4!
***
*** Name: FB_TP
*** Description: standard timer function block (pulse)
*** Version:
***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium -
*************************************************************************/

#include "FB_TP.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_TP_gen.cpp"
#endif
#include <devlog.h>

DEFINE_FIRMWARE_FB(FB_TP, g_nStringIdFB_TP)

const CStringDictionary::TStringId FB_TP::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdPT};

const CStringDictionary::TStringId FB_TP::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdET};
const CStringDictionary::TStringId FB_TP::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME};
const CStringDictionary::TStringId FB_TP::scm_aunDODataTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME};

const TForteInt16 FB_TP::scm_anEIWithIndexes[] = {0};
const TDataIOID FB_TP::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FB_TP::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FB_TP::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FB_TP::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FB_TP::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FB_TP::scm_stFBInterfaceSpec = {
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
    2,
    scm_anDataOutputNames, scm_aunDODataTypeIds,
    0,
    0
};

void FB_TP::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      if (edgeFlag) {
        if(ET() >= PT()){
          Q() = false;
          edgeFlag = false;
          DEVLOG_DEBUG("TOP\n");
        }else{
          delta = (CTimerHandler::sm_poFORTETimer->getForteTime() - start);
          ET() = delta.m_nLowerValue;
          DEVLOG_DEBUG("rising\n");
        }
      }
      else {
        if(IN() == true && ET() == 0){
          Q() = true;
          edgeFlag = true;
          start = CTimerHandler::sm_poFORTETimer->getForteTime();
          DEVLOG_DEBUG("START\n");
        }
        else
          if((false == IN()) && (ET()>0)) {
            ET() = 0;
            DEVLOG_DEBUG("RESET\n");
          }
      }
      //printf("TON --- myflag: %d -- start: %lu -- delta: %lu -- ET: %lu -- PT: %ld\n",myflag,start.m_nLowerValue,delta.m_nLowerValue,ET.operator TForteInt32(),PT.operator TForteInt32());
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}
