/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateBattery
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-02/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateBattery.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateBattery, g_nStringIdiCreateBattery)

const CStringDictionary::TStringId FORTE_iCreateBattery::scm_anDataOutputNames[] = { g_nStringIdCharging, g_nStringIdVoltage, g_nStringIdCurrent, g_nStringIdTemperature, g_nStringIdCharge, g_nStringIdCapacity };

const CStringDictionary::TStringId FORTE_iCreateBattery::scm_anDataOutputTypeIds[] = { g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_iCreateBattery::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_iCreateBattery::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_iCreateBattery::scm_anEOWith[] = { 0, 1, 2, 3, 4, 5, 255 };
const TForteInt16 FORTE_iCreateBattery::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_iCreateBattery::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_iCreateBattery::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 6, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_iCreateBattery::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventREQID:
      create_battery_charge();
      Charging() = static_cast<TForteInt16>(gc_charge_state); //get_create_charging_state(LAG());
      Voltage() = static_cast<TForteInt16>(gc_batt_voltage);
      Current() = static_cast<TForteInt16>(gc_current_flow);
      Temperature() = static_cast<TForteInt16>(gc_batt_temp);
      Charge() = static_cast<TForteInt16>(gc_batt_charge);
      Capacity() = static_cast<TForteInt16>(gc_batt_capacity);
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

