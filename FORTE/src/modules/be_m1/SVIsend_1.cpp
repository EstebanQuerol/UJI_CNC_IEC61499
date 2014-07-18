/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SVIsend_1
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-09-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "SVIsend_1.h"

DEFINE_FIRMWARE_FB(FORTE_SVIsend_1, g_nStringIdSVIsend_1)

const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdID, g_nStringIdSD_1};

const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_SVIsend_1::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_SVIsend_1::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_SVIsend_1::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_SVIsend_1::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_SVIsend_1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SVIsend_1::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SVIsend_1::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	if(true == QI()){
    		QO() = registerSVIvar(ID(),SD_1(),SVI_F_OUT);
    	}
      sendOutputEvent(scm_nEventINITOID);
    	if (true == QO()) {
    		printf("Alles OK send\n");
    	} else {
    		printf("Alles FALSCH send\n");
    	}
      break;

    case scm_nEventREQID:
      sendOutputEvent(scm_nEventCNFID);
      break;
    default:
    	break;
  }
}



