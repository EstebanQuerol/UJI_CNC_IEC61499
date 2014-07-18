/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L_BATTERY
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-12-26/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/
#include "L_BATTERY.h"
#include "avrctl.h"

DEFINE_FIRMWARE_FB(FORTE_L_BATTERY, g_nStringIdL_BATTERY)

const CStringDictionary::TStringId FORTE_L_BATTERY::scm_anDataOutputNames[] = { g_nStringIdRD, g_nStringIdRE };

const CStringDictionary::TStringId FORTE_L_BATTERY::scm_anDataOutputTypeIds[] = { g_nStringIdUINT, g_nStringIdBOOL };

const TForteInt16 FORTE_L_BATTERY::scm_anEIWithIndexes[] = { -1 };
const CStringDictionary::TStringId FORTE_L_BATTERY::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_L_BATTERY::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_L_BATTERY::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_L_BATTERY::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_L_BATTERY::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, 0, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 0, 0, 0, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_L_BATTERY::executeEvent(int pa_nEIID){
  unsigned int nBatteryBits = CL_AVR_ctl::getBattery( );

  switch (pa_nEIID){
    case scm_nEventREQID:
      // p.20 Lego Mindstorms NXT (TM)  Hardware Developers Kit (bits 0-9)*13.848 = mV
      // Float type is not supported so since voltage is 10 bits multiply by 1024 (1024*13.848=14180)
      //                                                  and then divide by 1024 (>>1024)
      //             (zero non-voltage bits         ) * (avoid float)
      RD() = (((nBatteryBits & 0x3ff) * 14180) >> 10);

      // p.20 Lego Mindstorms NXT (TM)  Hardware Developers Kit bit 15 0=AA batteries 1=Accu Pack inserted
      if(0 == ((nBatteryBits >> 15) & 0x01)){
        RE() = false;
      }
      else{
        RE() = true;
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}
