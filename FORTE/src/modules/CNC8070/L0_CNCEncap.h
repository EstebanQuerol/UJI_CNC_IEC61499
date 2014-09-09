/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CNCEncap
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L0_CNCENCAP_H_
#define _L0_CNCENCAP_H_

#include <funcbloc.h>
#include <forte_usint.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <string.h>
#include <iostream>
#include <string>

//CNC Command IDs number of parameters defines
#define CNCID_7_PN 1
#define CNCID_8_PN 1
#define CNCID_9_PN 1
#define CNCID_10_PN 4
#define CNCID_11_PN 4
#define CNCID_16_PN 6
#define CNCID_20_PN_MIN 1
#define CNCID_20_PN_MAX 3

#define ENCAP_CHARBUFFER_SIZE 100


class FORTE_L0_CNCEncap: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L0_CNCEncap)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_UINT &CmdID() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_STRING &SD() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_USINT &PN() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &sBlock() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 4, 2, 0);

  void executeEvent(int pa_nEIID);

  char ** m_ppacParamArray; //Array to hold parameters strings once parsed
  int m_nAllocatedstrings;//Number of allocated strings, used to free memory once done
  char * m_pacParamstr;//Pointer to hold parameters string once converted from CIEC_STRING
  char m_acBuffer[ENCAP_CHARBUFFER_SIZE];// buffer to hold output string while building it

public:
  FUNCTION_BLOCK_CTOR(FORTE_L0_CNCEncap){
  };

  virtual ~FORTE_L0_CNCEncap(){}; 

  /*!\brief Parse the received string containing the operation parameters
  *  This function allocates memory if success, caller must free it when
  *  done 
  * \return number of parsed strings if success, -1 otherwise
  */
  int ParseReceivedData(char * pa_pacValue, UINT pa_nMembers);
  /*!\brief Build the CNC command string for each Command ID
  * \return 1 if build success, -1 otherwise
  */
  int BuildCNCString(UINT pa_nCmdID, UINT pa_nMembers);

};

#endif //close the ifdef sequence from the beginning of the file

