/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Digital
 *** Description: Analog sensor that return a 10 bit 0-255
 *** Version: 
 ***     0.0: 2012-06-16/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Digital.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Digital, g_nStringIdDigital)

const CStringDictionary::TStringId FORTE_Digital::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT };

const CStringDictionary::TStringId FORTE_Digital::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_Digital::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdQ };

const CStringDictionary::TStringId FORTE_Digital::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL };

const TForteInt16 FORTE_Digital::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_Digital::scm_anEIWith[] = { 0, 1, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_Digital::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_Digital::scm_anEOWith[] = { 0, 1, 255, 0, 2, 1, 255 };
const TForteInt16 FORTE_Digital::scm_anEOWithIndexes[] = { 0, 3, -1 };
const CStringDictionary::TStringId FORTE_Digital::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_Digital::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 3, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Digital::executeEvent(int pa_nEIID){
  QO() = QI();
  STATUS() = 0;
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        libcbc_init(); //TODO: only call once //initialises the CBC Library :)
        if(PORT() >= 8 && PORT() <= 15){ //digital PORTS!!
          m_nPort = PORT();
        }
      }
      else{
        QO() = false;
        STATUS() = 1;
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        STATUS() = digital(m_nPort);
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

