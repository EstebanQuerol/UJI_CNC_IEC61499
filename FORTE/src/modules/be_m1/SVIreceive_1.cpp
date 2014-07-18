/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SVIreceive_1
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-10-04/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "SVIreceive_1.h"

DEFINE_FIRMWARE_FB(FORTE_SVIreceive_1, g_nStringIdSVIreceive_1)

const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdID };

const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING };

const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdRD_1 };

const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdANY };

const TForteInt16 FORTE_SVIreceive_1::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_SVIreceive_1::scm_anEIWith[] = { 0, 1, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_SVIreceive_1::scm_anEOWith[] = { 0, 255, 0, 1, 255 };
const TForteInt16 FORTE_SVIreceive_1::scm_anEOWithIndexes[] = { 0, 2, -1 };
const CStringDictionary::TStringId FORTE_SVIreceive_1::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_SVIreceive_1::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_SVIreceive_1::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(true == QI()){
        QO() = registerSVIvar(ID(), RD_1(), SVI_F_IN);
      }
      sendOutputEvent(scm_nEventINITOID);
      break;

    case scm_nEventREQID:
      sendOutputEvent(scm_nEventCNFID);
      break;
    default:
      break;
  }
}

