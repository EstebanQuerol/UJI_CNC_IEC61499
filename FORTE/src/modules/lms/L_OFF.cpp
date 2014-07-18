/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_OFF
 *** Description: SIFB to Turn off power to LMS
 *** Version: 
 ***     0.0: 2011-10-05/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_OFF.h"
#include "avrctl.h"
DEFINE_FIRMWARE_FB(FORTE_L_OFF, g_nStringIdL_OFF)

const CStringDictionary::TStringId FORTE_L_OFF::scm_anDataInputNames[] = { g_nStringIdQI };

const CStringDictionary::TStringId FORTE_L_OFF::scm_anDataInputTypeIds[] = { g_nStringIdBOOL };

const TForteInt16 FORTE_L_OFF::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_L_OFF::scm_anEIWith[] = { 0, 255 };
const CStringDictionary::TStringId FORTE_L_OFF::scm_anEventInputNames[] = { g_nStringIdREQ };

const TForteInt16 FORTE_L_OFF::scm_anEOWithIndexes[] = { -1 };
const SFBInterfaceSpec FORTE_L_OFF::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 0, 0, 0, 0, 1, scm_anDataInputNames, scm_anDataInputTypeIds, 0, 0, 0, 0, 0 };

void FORTE_L_OFF::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      if(true == QI()){
        // add back later          usbs_serial_tx(&usbs_ser0, "LMS off\n", 8);
        CL_AVR_ctl::setShutdownMode();
      }
      break;
  }
}

