/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateDemo
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-08/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateDemo.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateDemo, g_nStringIdiCreateDemo)

const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdSCRIPT, g_nStringIdD };

const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anDataOutputNames[] = { g_nStringIdQO };

const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateDemo::scm_anEIWithIndexes[] = { 0, 2, 4, 6, 9, 11 };
const TDataIOID FORTE_iCreateDemo::scm_anEIWith[] = { 0, 255, 0, 255, 0, 255, 0, 2, 255, 0, 255, 0, 1, 255 };
const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdSpot, g_nStringIdCover, g_nStringIdDemo, g_nStringIdCoverDock, g_nStringIdSendScript };

const TDataIOID FORTE_iCreateDemo::scm_anEOWith[] = { 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255 };
const TForteInt16 FORTE_iCreateDemo::scm_anEOWithIndexes[] = { 0, 2, 4, 6, 8, 10, -1 };
const CStringDictionary::TStringId FORTE_iCreateDemo::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdSpotO, g_nStringIdCoverO, g_nStringIdDemoO, g_nStringIdCoverDockO, g_nStringIdSendScriptO };

const SFBInterfaceSpec FORTE_iCreateDemo::scm_stFBInterfaceSpec = { 6, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 6, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateDemo::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        //TODO: add code for INIT event! or delete event
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventSpotID:
      if(true == QI()){
        create_spot();
      }
      sendOutputEvent(scm_nEventSpotOID);
      break;
    case scm_nEventCoverID:
      if(true == QI()){
        create_cover();
      }
      sendOutputEvent(scm_nEventCoverOID);
      break;
    case scm_nEventDemoID:
      if(true == QI()){
        create_demo(D());
      }
      sendOutputEvent(scm_nEventDemoOID);
      break;
    case scm_nEventCoverDockID:
      if(true == QI()){
        create_cover_dock();
      }
      sendOutputEvent(scm_nEventCoverDockOID);
      break;
    case scm_nEventSendScriptID:
      if(true == QI()){
//TODO: Delete create.h does not support adding code for SendScript event!
      }
      sendOutputEvent(scm_nEventSendScriptOID);
      break;
  }
}

