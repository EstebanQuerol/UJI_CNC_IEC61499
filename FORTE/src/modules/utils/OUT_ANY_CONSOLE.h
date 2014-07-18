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

#ifndef _OUT_ANY_CONSOLE_H_
#define _OUT_ANY_CONSOLE_H_

#include <funcbloc.h>
#include <forte_any.h>

#include <forte_string.h>
#include <forte_bool.h>

class FORTE_OUT_ANY_CONSOLE: public CFunctionBlock {
DECLARE_FIRMWARE_FB(FORTE_OUT_ANY_CONSOLE)

private:
	static const CStringDictionary::TStringId scm_anDataInputNames[];
	static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
	CIEC_BOOL &QI() {
		return *static_cast<CIEC_BOOL*>(getDI(0));
	}
	;

	CIEC_STRING &LABEL() {
		return *static_cast<CIEC_STRING*>(getDI(1));
	}
	;

	CIEC_ANY &IN() {
		return *static_cast<CIEC_ANY*>(getDI(2));
	}
	;

	static const CStringDictionary::TStringId scm_anDataOutputNames[];
	static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
	CIEC_BOOL &QO() {
		return *static_cast<CIEC_BOOL*>(getDO(0));
	}
	;

	static const TEventID scm_nEventREQID = 0;
	static const TForteInt16 scm_anEIWithIndexes[];
	static const TDataIOID scm_anEIWith[];
	static const CStringDictionary::TStringId scm_anEventInputNames[];

	static const TEventID scm_nEventCNFID = 0;
	static const TForteInt16 scm_anEOWithIndexes[];
	static const TDataIOID scm_anEOWith[];
	static const CStringDictionary::TStringId scm_anEventOutputNames[];

	static const SFBInterfaceSpec scm_stFBInterfaceSpec;

	FORTE_FB_DATA_ARRAY(1, 3, 1, 0)
	;

	void executeEvent(int pa_nEIID);

public:
	FUNCTION_BLOCK_CTOR(FORTE_OUT_ANY_CONSOLE){
};

virtual ~FORTE_OUT_ANY_CONSOLE() {};

};

#endif //close the ifdef sequence from the beginning of the file
