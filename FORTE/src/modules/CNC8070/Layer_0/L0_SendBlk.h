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

#ifndef _L0_SENDBLK_H_
#define _L0_SENDBLK_H_

#include <esfb.h>
#include <forte_usint.h>
#include <forte_wstring.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <CNC8070.h>
#include <extevhan.h>
#include <resource.h>
#include <devexec.h>
#include "Tool.h"
#include "Tool_Table.h"
#include <list>
#include <string>
#include <sstream>
#include "boost\serialization\access.hpp"
#include "boost\archive\text_iarchive.hpp"
#include "boost\archive\text_oarchive.hpp"
#include "boost\serialization\list.hpp"
#include "boost\serialization\string.hpp"

class FORTE_L0_SendBlk : public CEventSourceFB, public CCNC8070CommunicationHandler, public CExternalEventHandler {
  DECLARE_FIRMWARE_FB(FORTE_L0_SendBlk)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };
  CIEC_WSTRING &PARAMS() {

    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_STRING &sBlock() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_USINT &CNCState() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 3, 2, 0);

virtual void setInitialValues();

  void executeEvent(int pa_nEIID);
  int m_nExtEvHandID_inh;
  std::string m_sNBlock;

public:
	EVENT_SOURCE_FUNCTION_BLOCK_CTOR(FORTE_L0_SendBlk){
		m_sNBlock = "";
		m_stEventSourceEventEntry.m_poFB = this; 
		setEventChainExecutor(pa_poSrcRes->getResourceEventExecution());
		m_nExtEvHandID_inh = getDeviceExecution()->registerExternalEventHandler(this);
  };

  virtual ~FORTE_L0_SendBlk(){};

  /*!\brief deserializes the command vector
  *
  */
  void RetrieveCmd();

  //CNC8070COmmunicationHandler methods

  /*!\brief maps the CNC API logs to FORTE DEVLOG
  *
  * \param a_lType type of information to log
  * \param a_lMsg string to be printed
  */
  virtual void Log(LOGTYPE a_lType, const char * a_lMsg);
  /*!\brief handler for CNC Not Ready state
  */
  virtual void OnNotReady();
  /*!\brief handler for CNC Ready state
  */
  virtual void OnReady();
  /*!\brief handler for CNC started state
  */
  virtual void OnStarted();
  /*!\brief handler for CNC Executing state
  */
  virtual void OnExecuting();
  /*!\brief handler for CNC Interrupted state
  */
  virtual void OnInterrupted();
  /*!\brief handler for CNC Interrupted by error state
  */
  virtual void OnInterruptedByError();
  /*!\brief Enable this event source
  */
  virtual void OnMagazineUpdateAdd(const tool8070 &pa_stTool);
  virtual void OnMagazineUpdateDelete();
  virtual void OnMagazineUpdateDelete(const tool8070 &pa_stTool);


  virtual void enableHandler(void);
  /*!\brief Disable this event source
  */
  virtual void disableHandler(void);
  /*!\brief Sets the priority of the event source
  *
  * \param pa_nPriority new priority of the event source
  */
  virtual void setPriority(int pa_nPriority);
  /*!\brief Get the current priority of the event source
  *
  * \return current priority
  */
  virtual int getPriority(void) const;
};

#endif //close the ifdef sequence from the beginning of the file

