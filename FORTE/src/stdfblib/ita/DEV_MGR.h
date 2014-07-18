/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _DEV_MGR_H_
#define _DEV_MGR_H_

#include <funcbloc.h>
#include "../../core/resource.h"
#include <forte_bool.h>
#include <forte_string.h>
#include <mgmcmdstruct.h>

/*! \brief Implementation of the DEV_MGR FB.
 *
 * @author AZ
 * @version
 * @version 20090801/mmm - added parameter const CStringDictionary::TStringId pa_nInstanceNameId to constructor
 *  changed functions to take/use/return char* instead of string
 * @version 20060207/AZ - Removed number of EOs in CFunctionBlock-Constructor
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051029/AZ - Initial version as basis for the interface documentation
 */
class DEV_MGR: public CFunctionBlock {
  DECLARE_FIRMWARE_FB(DEV_MGR)

  private:

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;
    static const CStringDictionary::TStringId scm_aunEINameIds[2];
    static const TDataIOID scm_anEIWith[6];
    static const TForteInt16 scm_anEIWithIndexes[2];
    static const CStringDictionary::TStringId scm_aunEONameIds[2];
    static const TDataIOID scm_anEOWith[4];
    static const TForteInt16 scm_anEOWithIndexes[3];
    static const CStringDictionary::TStringId scm_aunDONameIds[2];
    static const CStringDictionary::TStringId scm_aunDIDataTypeIds[];
    static const CStringDictionary::TStringId scm_aunDINameIds[3];
    static const CStringDictionary::TStringId scm_aunDODataTypeIds[];

    static const TEventID csm_nEventINITOID = 0;
    static const TEventID csm_nEventCNFID = 1;

    static const TEventID csm_nEventINITID = 0;
    static const TEventID csm_nEventREQID = 1;

    FORTE_FB_DATA_ARRAY(2, 3, 2, 0);

    //! The device the block is contained in
    CDevice &m_poDevice;

    void executeRQST(void);
    /*! \brief Parse the given request header to determine the ID and the requested command
     *
     * \param pa_acRequestString data of the request
     * \param pa_rstCommand the command structure for holding command information
     * \return pointer to the next part of the command zero on error
     */
    static char* parseRequest(char *pa_acRequestString, SManagementCMD &pa_rstCommand);
    /*! \brief Parse the given request that is left after parsing the header to parse FB data
     *
     * \param pa_acRequestPartLeft  data of the request that has been left after parsing the header
     * \param pa_rstCommand the command structure for holding command information
     * \return true if the FB data could be parsed
     */
    static bool parseFBData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    /*! \brief Parse the given request that is left after parsing the header to parse connection data
     *
     * \param pa_acRequestPartLeft   data of the request that has been left after parsing the header
     * \param pa_rstCommand the command structure for holding command information
     * \return true if the connection data could be parsed
     */
    static bool parseConnectionData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    static bool parseWriteConnectionData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);

	static bool parseTypeListData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);

    static void parseCreateData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    static void parseDeleteData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    //! Check if an FB is given for a state change command (i.e., START, STOP, KILL, RESET)
    static void parseAdditionalStateCommandData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    static void parseReadData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    static void parseWriteData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    static void parseQueryData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);


    static CStringDictionary::TStringId getIdentifierId(char *pa_acIdentifierStart, char pa_cEndChar, int &pa_nCharsUsed);
    static TConnectionID getConnectionEndPointIdentifier(char *pa_acIdentifierStart, int &pa_nCharsUsed);
  
    virtual void executeEvent(int pa_nEIID);

#ifdef FORTE_SUPPORT_MONITORING
    static bool parseMonitoringData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
    void generateMonitorResponse(EMGMResponse pa_eResp, SManagementCMD &pa_stCMD);
    static bool parseConnectionStarStarData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand);
#endif //FORTE_SUPPORT_MONITORING    virtual void executeEvent(int pa_nEIID);

    /*! \brief set the RESP output of the DEV_MGR according to the given response data
     *
     * \param pa_acID id of the response
     * \param pa_eResp qualifier of the response
     */
    void generateResponse(const char *pa_acID, EMGMResponse pa_eResp);
    /*! \brief set the RESP output of the DEV_MGR according to the given response data
     *
     * \param pa_acID id of the response
     * \param pa_eResp qualifier of the response
     * \param pa_stCMD the command type
     */
    void generateLongResponse(EMGMResponse pa_eResp, SManagementCMD &pa_stCMD);

    CIEC_BOOL& QI() {
     	return *static_cast<CIEC_BOOL*>(getDI(0));
    }

    CIEC_STRING& DST() {
     	return *static_cast<CIEC_STRING*>(getDI(1));
    }

    CIEC_STRING& RQST() {
     	return *static_cast<CIEC_STRING*>(getDI(2));
    }

    CIEC_BOOL& QO() {
     	return *static_cast<CIEC_BOOL*>(getDO(0));
    }

    CIEC_STRING& RESP() {
     	return *static_cast<CIEC_STRING*>(getDO(1));
    }


  public:
    /*!\brief Type for the response of MGM command messages
     *
     * TODO fully define all responses as defined in IEC 61499 inc. numbers.
     */
    static const char * const scm_sMGMResponseTexts[13];

    FUNCTION_BLOCK_CTOR(DEV_MGR),
        m_poDevice(pa_poSrcRes->getDevice()) {
      m_stCommand.m_oAdditionalParams.reserve(255);
      m_stCommand.m_oAdditionalParams.clear();
    };
    virtual ~DEV_MGR();

  private:
#ifdef FORTE_SUPPORT_BOOT_FILE
    void loadForteBootFile();
#endif
    EMGMResponse parseAndExecuteMGMCommand(char *pa_acDest, char *pa_acCommand);

    SManagementCMD m_stCommand;

  };

#endif /*DEV_MGR_H_*/
