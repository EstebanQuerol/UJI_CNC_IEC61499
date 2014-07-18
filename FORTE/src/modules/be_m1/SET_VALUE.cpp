/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SET_VALUE
 *** Description: Writes the value to the specified output channel
 *** Version:
 ***     0.0: 2011-10-04/4DIAC-IDE - 4DIAC-Consortium - null 
 *************************************************************************/

#include "SET_VALUE.h"
#include <mtypes.h>                     /* M1 include files    */
#include <msys_e.h>
#include <mio.h>
#include <mio_e.h>

DEFINE_FIRMWARE_FB(FORTE_SET_VALUE, g_nStringIdSET_VALUE)

const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anDataInputNames[] = { g_nStringIdMOD_NB, g_nStringIdCHAN_NB, g_nStringIdVALUE };

const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anDataInputTypeIds[] = { g_nStringIdINT, g_nStringIdINT, g_nStringIdSINT };

const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anDataOutputNames[] = { g_nStringIdRET_CODE };

const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anDataOutputTypeIds[] = { g_nStringIdINT };

const TForteInt16 FORTE_SET_VALUE::scm_anEIWithIndexes[] = { 0, 2 };
const TDataIOID FORTE_SET_VALUE::scm_anEIWith[] = { 0, 255, 2, 1, 255 };
const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_SET_VALUE::scm_anEOWith[] = { 0, 255, 0, 255 };
const TForteInt16 FORTE_SET_VALUE::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_SET_VALUE::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_SET_VALUE::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_SET_VALUE::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(init()){
        sendOutputEvent(scm_nEventINITOID);
      }
      break;
    case scm_nEventREQID:
      RET_CODE() = write();
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

bool FORTE_SET_VALUE::init(){
  driverId = mio_GetDrv((short) MOD_NB());
  return driverId != NULL;
}

SINT32 FORTE_SET_VALUE::write(){
  return mio_SetValue(driverId, static_cast<unsigned int>(CHAN_NB()), VALUE());
}

