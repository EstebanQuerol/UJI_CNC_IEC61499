/*************************************************************************
 *** FORTE Library Element
 ***
 *** Name: INT2INT
 *** Description: Basic Function Block Type
 *** Version:
 ***     1.0: 2006-11-14/TS - PROFACTOR GmbH -
 *************************************************************************/

#include "INT2INT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "INT2INT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(INT2INT, g_nStringIdINT2INT)

const CStringDictionary::TStringId INT2INT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId INT2INT::scm_anDataOutputNames[] = {g_nStringIdOUT};
const CStringDictionary::TStringId INT2INT::scm_aunDIDataTypeIds[] = {g_nStringIdINT};
const CStringDictionary::TStringId INT2INT::scm_aunDODataTypeIds[] = {g_nStringIdINT};

const TForteInt16 INT2INT::scm_anEIWithIndexes[] = {0};
const TDataIOID INT2INT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId INT2INT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID INT2INT::scm_anEOWith[] = {0, 255};
const TForteInt16 INT2INT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId INT2INT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec INT2INT::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  1,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  1,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void INT2INT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = IN();
    sendOutputEvent(scm_nEventCNFID);
  }
}

INT2INT::~INT2INT(){
}



