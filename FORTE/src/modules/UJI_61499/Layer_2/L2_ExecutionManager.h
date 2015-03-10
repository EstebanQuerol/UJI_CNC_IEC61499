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

#define PART_NOT_FIXED 0
#define PART_BEING_FIXED 1
#define PART_FIXED 2
#define MAX_EXECUTION_RETRY 3


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
#include "boost\archive\text_oarchive.hpp"
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

  CIEC_USINT &L1MID() {
    return *static_cast<CIEC_USINT*>(getDO(2));
  };

  CIEC_USINT &SetupENDID() {
    return *static_cast<CIEC_USINT*>(getDO(3));
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

   FORTE_FB_DATA_ARRAY(3, 3, 4, 0);

  void executeEvent(int pa_nEIID);

  //SIFB own memebers
  workplan * m_poCurrentWP;
  BOOL m_bSetupLoaded;
  boost::archive::text_iarchive * m_poIArchive;
  TForteUInt8 m_nPartState; //UINT to track part state;0 not fixed, 1 being fixed, 2 fixed
  TForteUInt8 m_nExecutionErrors; //UINT to track the number of back to back execution errors
  std::list<executable *>::iterator m_itCurrentElement; //Iterator to the current element of the workplan's list
  //Methods
  /*!\Retrieve the new workplan and map it to m_poCurrentWP
  */
  void RetreiveWP();
  /*!\Delete the current workplan
  */
  void DeleteCurrentWP();
  /*!\INLINED Retreive the setup of the current workplan
  *	\return string to be sent to the machine to fix the part
  */
  setup * GetSetup(){
	  return m_poCurrentWP->get_itsSetup();
  }
  /*!\Retreive the next workingstep to be exeuted
  *	\return string to be sent to the machine
  */
  workingstep * GetWorkingStep();
  /*!\INLINED check if there is any remaining action in the current workplan list
  *	\return boo, true elements remaining, false otherwise
  */
  BOOL ElementsToDo(){
	  if (m_itCurrentElement != m_poCurrentWP->get_itsElements()->get_theList()->end()){
		  return TRUE;
	  }
	  return FALSE;
  }
  /*!\Get the L1MID of a workingstep
  *	\return USINT with the ID
  */
  TForteUInt8 GetWSL1MID(const iso14649CppBase * obj);
  /*!\serialize an iso14649 object into a string using boost serialization
  *	\return serialized string
  */
  std::string stringSerialize(const iso14649CppBase * obj);
public:
  FUNCTION_BLOCK_CTOR(FORTE_L2_ExecutionManager){
	  m_poCurrentWP = NULL;
	  m_bSetupLoaded = FALSE;
	  m_nPartState = PART_NOT_FIXED;
	  m_nExecutionErrors = 0;
  };

  virtual ~FORTE_L2_ExecutionManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

