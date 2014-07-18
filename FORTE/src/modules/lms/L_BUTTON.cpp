/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_BUTTON
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_BUTTON.h"
#include "avrctl.h"
#include <cyg/hal/hal_io.h>
DEFINE_FIRMWARE_FB(FORTE_L_BUTTON, g_nStringIdL_BUTTON)

const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdB };

const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdQ };

const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_L_BUTTON::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_L_BUTTON::scm_anEIWith[] = { 1, 0, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_L_BUTTON::scm_anEOWith[] = { 0, 255, 1, 255 };
const TForteInt16 FORTE_L_BUTTON::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_L_BUTTON::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_BUTTON::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_L_BUTTON::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(12 > B())
        QO() = true;
      else
        QO() = false;
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        Q() = false; // assume false, saves 2 elses
        if(isAButtonPressed()){
          if(B() == buttonsDecode())
            Q() = true;
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

const TForteUInt16 FORTE_L_BUTTON::sc_nButton_Shutdown = sc_nButton_ENTERandESC;

TForteUInt16 FORTE_L_BUTTON::sm_unButtonVal = 0; // Debounce sets
TForteUInt16 FORTE_L_BUTTON::sm_unPrevButtonVal = 0; //Debounce sets
bool FORTE_L_BUTTON::s_bInDebounceState = false;
TForteUInt16 FORTE_L_BUTTON::sm_unDebounceCounter = 3; // Debounce   now 1= no debouncing was 3 orig was 25 (timing problem so 3) scm_unButtonDebounceCnt;

//TODO: Does this have to be static? or is local variable ok?
TForteUInt16 FORTE_L_BUTTON::s_ButtonNum = 0; //Decode sets

// ----------------------------------------------------------------------------------
//--- Buttons ------------------------------------------------------------------------

TForteUInt16 FORTE_L_BUTTON::getButtonVal(void){
  return sm_unButtonVal;
}

TForteUInt16 FORTE_L_BUTTON::getButtonNum(void){
  return s_ButtonNum;
}

const bool FORTE_L_BUTTON::isAButtonPressed(){
  return ((sm_unButtonVal > (sc_nButton_LOWEST / 2)) || (s_ButtonNum));
}

cyg_uint16 FORTE_L_BUTTON::buttonsDecode(){
  // Work out which buttons are down. We allow chording of the enter
  // button with other buttons via ORs
  TForteUInt16 nButtonVal2Decode = sm_unButtonVal;

  s_ButtonNum = 0;
  if(((sc_nButton_ENTER + sc_nButton_ESC) / 2) < nButtonVal2Decode){ // around 1500 was 1500   ENTER 2053 after OR is 6
    s_ButtonNum |= sc_nENTERButtonPushed;
    nButtonVal2Decode -= 0x7ff; // changes the ENTER + a key to almost the same
    //   as if the 2nd key was press by itself
  }

  if (((sc_nButton_ESC + sc_nButton_RIGHT) / 2) < nButtonVal2Decode){ // =710 was 720 ESC 1017
    s_ButtonNum |= sc_nESCButtonPushed;
  }
  else if (((sc_nButton_RIGHT + sc_nButton_LEFT) / 2) < nButtonVal2Decode){ // =264 was 270  RIGHT 403  LEFTandRIGHT 200-230
    s_ButtonNum |= sc_nLEFTButtonPushed;
  }
  else if ((sc_nButton_LEFT / 2) < nButtonVal2Decode){ // = 62 was 60 LEFT 125
    s_ButtonNum |= sc_nRIGHTButtonPushed;
  }
  return s_ButtonNum;
}

// Debounce things...
void FORTE_L_BUTTON::updateButtons(TForteUInt16 pa_unCurrentButtonVal){
  // first do debouncing of the buttons
  // if (above threshold showing a button(s) is pressed) or (in debounce state because button(s) pressed)
  if(pa_unCurrentButtonVal < sc_nButton_HIGH){ // ignore if random large number
    if((pa_unCurrentButtonVal == 0) && (sm_unButtonVal != 0)){
      s_bInDebounceState = true;
    }

    if((pa_unCurrentButtonVal > (sc_nButton_LOWEST / 2) || s_bInDebounceState)){
      // Process the buttons. First we drop any noisy inputs
      // Check if button value has changed, but don't process yet because when a button is pressed
      //  the signal bounces up and down. We wait for the signal to settle out by counting down
      if(sm_unPrevButtonVal == pa_unCurrentButtonVal){
        if(s_bInDebounceState){
          if(sm_unDebounceCounter > 0)
            sm_unDebounceCounter--;
          else{
            s_bInDebounceState = false;
            sm_unButtonVal = pa_unCurrentButtonVal;
          }
        }
        else{
          s_bInDebounceState = true;
          sm_unDebounceCounter = scm_unButtonDebounceCnt;
        }
      }
    }
    sm_unPrevButtonVal = pa_unCurrentButtonVal; // want to debounce enough that the same value is received twice
  }

  checkShutdown();
}

void FORTE_L_BUTTON::checkShutdown(){
  if(s_bInDebounceState == false){
    if(((sc_nButton_Shutdown - 8) <= sm_unPrevButtonVal) && (sm_unPrevButtonVal <= (sc_nButton_Shutdown + 8))){
      CL_AVR_ctl::setShutdownMode();
    }
  }
}
