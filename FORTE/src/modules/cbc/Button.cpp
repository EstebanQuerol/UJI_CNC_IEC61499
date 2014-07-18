/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Button
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-20/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Button.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Button, g_nStringIdButton)

const CStringDictionary::TStringId FORTE_Button::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdNAME };

const CStringDictionary::TStringId FORTE_Button::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_Button::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdQ };

const CStringDictionary::TStringId FORTE_Button::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_Button::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_Button::scm_anEIWith[] = { 0, 1, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_Button::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_Button::scm_anEOWith[] = { 0, 255, 0, 1, 255 };
const TForteInt16 FORTE_Button::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_Button::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_Button::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Button::executeEvent(int pa_nEIID){

  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if((0 < NAME()) && (NAME() < 8)){
          m_nButton = NAME();
        }
        else{
          QO() = false;
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        switch (m_nButton){
          case 1:
            Q() = black_button();
            break;
          case 2:
            Q() = a_button();
            break;
          case 3:
            Q() = b_button();
            break;
          case 4:
            Q() = left_button();
            break;
          case 5:
            Q() = right_button();
            break;
          case 6:
            Q() = up_button();
            break;
          case 7:
            Q() = down_button();
            break;
          default:
            QO() = false;
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;

  }
}

