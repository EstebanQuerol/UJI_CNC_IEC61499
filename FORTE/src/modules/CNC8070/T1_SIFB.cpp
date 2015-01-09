/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T1_SIFB
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-07-10/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "T1_SIFB.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T1_SIFB_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_T1_SIFB, g_nStringIdT1_SIFB)

const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdSD};

const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdINT};

const TForteInt16 FORTE_T1_SIFB::scm_anEIWithIndexes[] = {0, 3, 6};
const TDataIOID FORTE_T1_SIFB::scm_anEIWith[] = {0, 1, 255, 0, 2, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRSP};

const TDataIOID FORTE_T1_SIFB::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_T1_SIFB::scm_anEOWithIndexes[] = {0, 3, 7, -1};
const CStringDictionary::TStringId FORTE_T1_SIFB::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_T1_SIFB::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_T1_SIFB::setInitialValues(){
  SD() = "Empty";
  RD() = 0;
  QO() = TRUE;
}

bool bReady = FALSE;
CIEC_STRING cadena;
char PC[180];

void FORTE_T1_SIFB::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		CNC8070Connect(this);
		sendOutputEvent(scm_nEventINITOID);
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
    case scm_nEventREQID:
		if (QI()){
			bReady = FALSE;
			CNC8070Start();
			while (!bReady);
			QO() = TRUE;
		}
		else{
			/*No more instructions to be executed*/
			QO() = FALSE;
		}
		sendOutputEvent(scm_nEventCNFID);

/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
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
void FORTE_T1_SIFB::Log(LOGTYPE a_lType, const char * a_lMsg)
{
	printf(a_lMsg);
}

void FORTE_T1_SIFB::OnNotReady()
{

}

void FORTE_T1_SIFB::OnReady()
{
	Log(LOG_INFORMATION, "Ready\n");
	bReady = TRUE;
}

void FORTE_T1_SIFB::OnStarted()
{
	Log(LOG_INFORMATION, "Started\n");
	cadena = SD();
	if (-1 != cadena.toString(&PC[0], 180, 1)){
		CNC8070ExecuteBlock(PC);
	}
	else{
		Log(LOG_ERROR, "toString failed\n");
	}
}

void FORTE_T1_SIFB::OnExecuting()
{

}

void FORTE_T1_SIFB::OnInterrupted()
{
	Log(LOG_ERROR, "Execution Interrupted\n");
}

void FORTE_T1_SIFB::OnInterruptedByError()
{
	Log(LOG_ERROR, "unexpected error\n");

}

void FORTE_T1_SIFB::OnMagazineUpdate(long pa_lITool){
	long l = pa_lITool;
	DEVLOG_INFO("Tool Test\n");
}
