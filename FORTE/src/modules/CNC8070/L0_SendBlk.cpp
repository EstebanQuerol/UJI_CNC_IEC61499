/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_SendBlk
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-08-25/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_SendBlk.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_SendBlk_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_SendBlk, g_nStringIdL0_SendBlk)

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdsBlock};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdCNCState};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_SendBlk::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_L0_SendBlk::scm_anEIWith[] = {0, 1, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L0_SendBlk::scm_anEOWith[] = {0, 255, 0, 255, 1, 255};
const TForteInt16 FORTE_L0_SendBlk::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_L0_SendBlk::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L0_SendBlk::setInitialValues(){
  CNCState() = 0;
}


void FORTE_L0_SendBlk::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		CNC8070Connect(this);
		sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
		if (QI()){
			//bReady = FALSE;
			CNC8070Start();
			//while (!bReady);
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
  }
}

//CNC8070ComunicationHandler methods implementation
void FORTE_L0_SendBlk::Log(LOGTYPE a_lType, const char * a_lMsg)
{
	printf(a_lMsg);
}

void FORTE_L0_SendBlk::OnNotReady()
{
	DEVLOG_INFO("Ready\n");
}

void FORTE_L0_SendBlk::OnReady()
{
	DEVLOG_INFO("Ready\n");
	//Log(LOG_INFORMATION, "Ready\n");
	CNCState() = 1;
	sendOutputEvent(scm_nEventINDID);
	//bReady = TRUE;
}

void FORTE_L0_SendBlk::OnStarted()
{
	DEVLOG_INFO("Started\n");
	//Log(LOG_INFORMATION, "Started\n");
	
	CNC8070ExecuteBlock("T4 D1");
	//if (-1 != cadena.toString(&PC[0], 180, 1)){
	//	CNC8070ExecuteBlock(PC);
	//}
	//else{
	//	DEVLOG_DEBUG("String failed/n");
	//	//Log(LOG_ERROR, "toString failed\n");
	//}
}

void FORTE_L0_SendBlk::OnExecuting()
{
	DEVLOG_INFO("Started\n");
}

void FORTE_L0_SendBlk::OnInterrupted()
{
	DEVLOG_INFO("Execution Interrupted\n");
	//Log(LOG_ERROR, "Execution Interrupted\n");
}

void FORTE_L0_SendBlk::OnInterruptedByError()
{
	DEVLOG_ERROR("unexpected error\n");
	//Log(LOG_ERROR, "unexpected error\n");
}


