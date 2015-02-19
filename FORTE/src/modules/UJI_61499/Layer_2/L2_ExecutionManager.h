/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L2_ExecutionManager
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-01-08/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _L2_EXECUTIONMANAGER_H_
#define _L2_EXECUTIONMANAGER_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>
#include "iso14649classes.h"
#include <sstream>
#include <string>
#include <typeinfo>
#include "boost\serialization\access.hpp"
#include "boost\archive\text_iarchive.hpp"
#include "boost\serialization\string.hpp"
#include "GlobalUtils.h"

class FORTE_L2_ExecutionManager: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L2_ExecutionManager)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &Setup() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_USINT &NextCode() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &Operation() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_USINT &SetupENDID() {
    return *static_cast<CIEC_USINT*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventRENEWID = 1;
  static const TEventID scm_nEventNEXTID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventExecuteOPID = 1;
  static const TEventID scm_nEventCompletedID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 3, 3, 0);

  void executeEvent(int pa_nEIID);

  //SIFB own memebers
  workplan * m_poCurrentWP;
  BOOL m_bSetupLoaded;
  boost::archive::text_iarchive * m_poIArchive;

  //Methods
  /*!\Retrieve the new workplan and map it to m_poCurrentWP
  */
  void RetreiveWP();
  /*!\Delete the current workplan
  */
  void DeleteCurrentWP();

public:
  FUNCTION_BLOCK_CTOR(FORTE_L2_ExecutionManager){
	  m_poCurrentWP = NULL;
	  m_bSetupLoaded = FALSE;
  };

  virtual ~FORTE_L2_ExecutionManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

