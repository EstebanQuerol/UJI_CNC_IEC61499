/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_AD
 *** Description: Read an Analog/Digital LMS  Sensor
 *** Version: 
 ***     0.0: 2011-08-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_AD.h"
#include "avrctl.h"
#include "L_S_PORT.h"
DEFINE_FIRMWARE_FB(FORTE_L_AD, g_nStringIdL_AD)

const CStringDictionary::TStringId FORTE_L_AD::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdT };

const CStringDictionary::TStringId FORTE_L_AD::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_L_AD::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdRD };

const CStringDictionary::TStringId FORTE_L_AD::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const TForteInt16 FORTE_L_AD::scm_anEIWithIndexes[] = { 0, 4 };
const TDataIOID FORTE_L_AD::scm_anEIWith[] = { 0, 1, 2, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_L_AD::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_L_AD::scm_anEOWith[] = { 0, 255, 0, 1, 255 };
const TForteInt16 FORTE_L_AD::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_L_AD::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_AD::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

// TODO: rename to L_AI for analog input
void FORTE_L_AD::executeEvent(int pa_nEIID){
  unsigned int nPort = PORT() - 1; /** HW port # (not LMS port #) */
  unsigned int nType = T();

  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        if(!FORTE_L_S_PORT::lmsIsADsensor(nType))
          QO() = false;
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(true == QI()){
        RD() = CL_AVR_ctl::getSensorState(nPort);
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

