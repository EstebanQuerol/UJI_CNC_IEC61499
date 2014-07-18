/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CBC_OFF
 *** Description: SIFB to Turn off power to LMS
 *** Version: 
 ***     0.0: 2012-06-23/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "CBC_OFF.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_CBC_OFF, g_nStringIdCBC_OFF)

const CStringDictionary::TStringId FORTE_CBC_OFF::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdDT };

const CStringDictionary::TStringId FORTE_CBC_OFF::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdTIME };

const TForteInt16 FORTE_CBC_OFF::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_CBC_OFF::scm_anEIWith[] = { 0, 1, 255 };
const CStringDictionary::TStringId FORTE_CBC_OFF::scm_anEventInputNames[] = { g_nStringIdREQ };

const TForteInt16 FORTE_CBC_OFF::scm_anEOWithIndexes[] = { -1 };
const SFBInterfaceSpec FORTE_CBC_OFF::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 0, 0, 0, 0, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 0, 0, 0, 0, 0 };

void FORTE_CBC_OFF::executeEvent(int pa_nEIID){
  float fWaitTime = 0.0;
  switch (pa_nEIID){
    case scm_nEventREQID:
      if(true == QI()){
        // ref'd http://publib.boulder.ibm.com/infocenter/comphelp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8a.doc%2Flanguage%2Fref%2Fkeyword_static_cast.htm
        fWaitTime = static_cast<float>(DT()) / FORTE_TIME_BASE_UNITS_PER_SECOND;
        shut_down_in(fWaitTime);
      }
      break;
  }
}

