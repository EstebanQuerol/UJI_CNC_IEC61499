/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: POWERLINK_MN
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-05-31/4DIAC-IDE - 4DIAC-Consortium - null
 ***     1.0: 2011-05-31/FA,TS - AIT - null
 *************************************************************************/

#include "POWERLINK_MN.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "POWERLINK_MN_gen.cpp"
#endif

#include "EplWrapper.h"
#include <cstdio>

DEFINE_FIRMWARE_FB(FORTE_POWERLINK_MN, g_nStringIdPOWERLINK_MN)

const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCDC_CFG, g_nStringIdAPP_CFG, g_nStringIdDEV_NAME };

const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING };

const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdSTATUS };

const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING };

const TForteInt16 FORTE_POWERLINK_MN::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_POWERLINK_MN::scm_anEIWith[] = { 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anEventInputNames[] = { g_nStringIdINIT };

const TDataIOID FORTE_POWERLINK_MN::scm_anEOWith[] = { 0, 1, 255 };
const TForteInt16 FORTE_POWERLINK_MN::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_POWERLINK_MN::scm_anEventOutputNames[] = { g_nStringIdINITO };

const SFBInterfaceSpec FORTE_POWERLINK_MN::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 2, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

FORTE_POWERLINK_MN::~FORTE_POWERLINK_MN(){
  shutdownStack();
}

void FORTE_POWERLINK_MN::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:

      if(QI() == true){
        QO() = QI();

        CEplStackWrapper* eplStack = &CEplStackWrapper::getInstance();

        eplStack->waitUntilOperational(false);
        eplStack->eplStackInit(APP_CFG().getValue(), CDC_CFG().getValue(), DEV_NAME().getValue());

        //TODO check if error occured during initialization

      }
      else if(QI() == false){
        QO() = QI();
        shutdownStack();
      }

      sendOutputEvent(scm_nEventINITOID);
      break;
  }
}

void FORTE_POWERLINK_MN::shutdownStack(){
  CEplStackWrapper::getInstance().eplStackShutdown();
}

