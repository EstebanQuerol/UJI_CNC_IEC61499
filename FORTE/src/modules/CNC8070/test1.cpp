/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: test1
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-07-07/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "stdio.h"
#include "test1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "test1_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_test1, g_nStringIdtest1)

const CStringDictionary::TStringId FORTE_test1::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdSD};

const CStringDictionary::TStringId FORTE_test1::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_test1::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_test1::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY};

const TForteInt16 FORTE_test1::scm_anEIWithIndexes[] = {0, 3, 6};
const TDataIOID FORTE_test1::scm_anEIWith[] = {0, 1, 255, 0, 2, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_test1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_test1::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_test1::scm_anEOWithIndexes[] = {0, 3, 7, -1};
const CStringDictionary::TStringId FORTE_test1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_test1::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};
CIEC_WSTRING * cad;
char * j;

void FORTE_test1::executeEvent(int pa_nEIID){

  switch (pa_nEIID){
    case scm_nEventINITID:
		CNC8070Connect(this);
		cad = (CIEC_WSTRING *)getDataInput(g_nStringIdPARAMS);
		j = cad->getValue();
		sendOutputEvent(scm_nEventINITOID);
		
//#error add code for INIT event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
    case scm_nEventREQID:
//#error add code for REQ event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
	  CNC8070Start();


      break;
    case scm_nEventRSPID:
//#error add code for RSP event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
  }
}

//Implementacion metodos CNC8070ComunicationHandler
void FORTE_test1::Log(LOGTYPE a_lType, const char * a_lMsg)
{
	printf(a_lMsg);
}

void FORTE_test1::OnNotReady()
{

}

void FORTE_test1::OnReady()
{
	Log(LOG_INFORMATION, "Ready\n");
}

void FORTE_test1::OnStarted()
{
	Log(LOG_INFORMATION, "Started\n");

	CNC8070ExecuteBlock(j);
}

void FORTE_test1::OnExecuting()
{

}

void FORTE_test1::OnInterrupted()
{

}

void FORTE_test1::OnInterruptedByError()
{

}

void FORTE_test1::OnMagazineUpdate(long pa_lITool){
	long l = pa_lITool;
	DEVLOG_INFO("Tool Test\n");
}
