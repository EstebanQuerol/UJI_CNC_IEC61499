/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: OUT_ANY_CONSOLE
 *** Description: Service Interface Function Block Type for debugging, tracing, etc.
 *** Version: 
 ***     0.0: 2011-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "OUT_ANY_CONSOLE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "OUT_ANY_CONSOLE_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_OUT_ANY_CONSOLE, g_nStringIdOUT_ANY_CONSOLE)

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataInputNames[] =
		{ g_nStringIdQI, g_nStringIdLABEL, g_nStringIdIN };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataInputTypeIds[] =
		{ g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdANY };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataOutputNames[] =
		{ g_nStringIdQO };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataOutputTypeIds[] =
		{ g_nStringIdBOOL };

const TForteInt16 FORTE_OUT_ANY_CONSOLE::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_OUT_ANY_CONSOLE::scm_anEIWith[] = { 0, 2, 1, 255 };
const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anEventInputNames[] =
		{ g_nStringIdREQ };

const TDataIOID FORTE_OUT_ANY_CONSOLE::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_OUT_ANY_CONSOLE::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anEventOutputNames[] =
		{ g_nStringIdCNF };

const SFBInterfaceSpec FORTE_OUT_ANY_CONSOLE::scm_stFBInterfaceSpec = { 1,
		scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1,
		scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3,
		scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames,
		scm_anDataOutputTypeIds, 0, 0 };

void FORTE_OUT_ANY_CONSOLE::executeEvent(int pa_nEIID) {
	switch (pa_nEIID) {
	case scm_nEventREQID:
		QO() = QI();
		if (true == QI()) {
			char strbuf1[100];
			char strbuf2[100];
			LABEL().toString(strbuf1, sizeof(strbuf1));
			IN().toString(strbuf2, sizeof(strbuf2));
			DEVLOG_INFO(" %s = %s\n", strbuf1,
					strbuf2);
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	}
}

