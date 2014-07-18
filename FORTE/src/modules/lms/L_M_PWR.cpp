/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_M_PWR
 *** Description: LMS Motor control via power
 *** Version: 
 ***     0.0: 2011-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_M_PWR.h"
#include "avrctl.h"
DEFINE_FIRMWARE_FB(FORTE_L_M_PWR, g_nStringIdL_M_PWR)

const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdPORT, g_nStringIdDIR, g_nStringIdPWR };

const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdINT };

const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdRD };

const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUINT };

const TForteInt16 FORTE_L_M_PWR::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_L_M_PWR::scm_anEIWith[] = { 0, 1, 255, 0, 3, 2, 255 };
const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_L_M_PWR::scm_anEOWith[] = { 0, 255, 0, 1, 255 };
const TForteInt16 FORTE_L_M_PWR::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_L_M_PWR::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_M_PWR::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_L_M_PWR::executeEvent(int pa_nEIID){
  unsigned int  nPort = PORT(); // Test if PORT()'s value is available in REQ
  unsigned int  nPwr = PWR();
  QO() = QI();

  switch (pa_nEIID){
    case scm_nEventINITID:
      if((true == QI()) && (CL_AVR_ctl::sc_nNXTMotorPortsMax > nPort))
        CL_AVR_ctl::motorAvrSetPwrBrake(nPort, 0, 0);
      else
        QO() = false;
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      //TODO: Check nPwr is btw 0 and 100 !! otherwise set to 100
      if((true == QI()) && (CL_AVR_ctl::sc_nNXTMotorPortsMax > nPort)){
        if(true == DIR())
          nPwr = -nPwr;
        CL_AVR_ctl::motorAvrSetPwrBrake(nPort, nPwr, false); // always coast if QI=true
      }
      else{
        CL_AVR_ctl::motorAvrSetPwrBrake(nPort, 0, true); // always PWR=0 and brake if QI=false
        QO() = false;
      }
      RD() = CL_AVR_ctl::motorAvrGetPwr(nPort); // power value used by motor (always send as info)
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

