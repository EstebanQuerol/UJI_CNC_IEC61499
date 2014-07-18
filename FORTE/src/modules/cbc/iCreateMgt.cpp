/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateMgt
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-15/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateMgt.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateMgt, g_nStringIdiCreateMgt)

const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdMode };

const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCurrentMode, g_nStringIdERR, g_nStringIdConnected };

const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_iCreateMgt::scm_anEIWithIndexes[] = { 0, 2, 4, 6 };
const TDataIOID FORTE_iCreateMgt::scm_anEIWith[] = { 0, 255, 0, 255, 0, 255, 1, 0, 255 };
const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdstart, g_nStringIdgetMode, g_nStringIdsetMode };

const TDataIOID FORTE_iCreateMgt::scm_anEOWith[] = { 0, 2, 3, 255, 0, 255, 0, 1, 255, 0, 255 };
const TForteInt16 FORTE_iCreateMgt::scm_anEOWithIndexes[] = { 0, 4, 6, 9, -1 };
const CStringDictionary::TStringId FORTE_iCreateMgt::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdstartO, g_nStringIdgetModeO, g_nStringIdsetModeO };

const SFBInterfaceSpec FORTE_iCreateMgt::scm_stFBInterfaceSpec = { 4, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 4, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 4, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateMgt::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        //TODO: use clib globals  Use g_create_connected
        if(create_connect() != 0){
          QO() = false;
          Connected() = false;
        }
        else{
          Connected() = true;
        }
      }
      else{ // INIT MINUS
        create_disconnect();
      }
      sendOutputEvent (scm_nEventINITOID);
      break;
    case scm_nEventstartID:
      if(true == QI()){
        create_start();
      }
      sendOutputEvent(scm_nEventstartOID);
      break;
    case scm_nEventgetModeID:
      create_mode();
      //TODO: global, not nice libcbc does not currently have any of the get functions
      CurrentMode() = static_cast<TForteInt16>(gc_mode);
      sendOutputEvent(scm_nEventgetModeOID);
      break;
    case scm_nEventsetModeID:
      switch (gc_mode){ //TODO:  global, not nice libcbc does not currently have any of the get functions
        case 0: // safe
          create_safe();
          break;
        case 1: // passive
          create_passive();
          break;
        case 2: // full
          create_full();
          break;
        default: // off=3 set by disconnect; > error
          QO() = false;
          break;
      }
      sendOutputEvent(scm_nEventsetModeOID);
      break;
  }
}

