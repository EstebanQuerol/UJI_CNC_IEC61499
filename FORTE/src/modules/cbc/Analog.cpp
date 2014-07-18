/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Analog
 *** Description: Analog sensor that return a 10 bit 0-255
 *** Version: 
 ***     0.0: 2012-06-16/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Analog.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Analog, g_nStringIdAnalog)

const CStringDictionary::TStringId FORTE_Analog::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdOUT_BITS };

const CStringDictionary::TStringId FORTE_Analog::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdINT };

const CStringDictionary::TStringId FORTE_Analog::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdOUT };

const CStringDictionary::TStringId FORTE_Analog::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_Analog::scm_anEIWithIndexes[] = { 0, 4 };
const TDataIOID FORTE_Analog::scm_anEIWith[] = { 0, 1, 2, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_Analog::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_Analog::scm_anEOWith[] = { 0, 1, 255, 0, 2, 1, 255 };
const TForteInt16 FORTE_Analog::scm_anEOWithIndexes[] = { 0, 3, -1 };
const CStringDictionary::TStringId FORTE_Analog::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_Analog::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Analog::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        STATUS() = 0;
        libcbc_init(); //TODO: only call once //initialises the CBC Library :)
        if(PORT() <= 7){ //analog PORTS!!
          m_nPort = PORT();
          if((OUT_BITS() == 8) || (OUT_BITS() == 10)){
            m_nOUT_BITS = OUT_BITS();
          }
          else{
            QO() = false;
            STATUS() = 3;
          }
        }
        else{
          QO() = false;
          STATUS() = 1;
        }
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        if(8 == m_nOUT_BITS){
          OUT() = static_cast<TForteInt16>(analog(m_nPort));
        }
        else{
          OUT() = static_cast<TForteInt16>(analog10(m_nPort));
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

