/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _WBXML_DEV_MGR_H_
#define _WBXML_DEV_MGR_H_

#include <funcbloc.h>
#include "../../core/resource.h"
#include <forte_bool.h>
#include <forte_string.h>

/*! \brief A device manager FB that handles WAP Binary XML encoded management commands
 *
 */
class WBXML_DEV_MGR : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(WBXML_DEV_MGR)

  public:
    FUNCTION_BLOCK_CTOR(WBXML_DEV_MGR), m_poDevice(pa_poSrcRes->getDevice()){
    }

    virtual ~WBXML_DEV_MGR() {}

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


    static const TForteUInt8 scm_nItemHasAttribs = 0x80;
    static const TForteUInt8 scm_nItemHasChildren = 0x40;

    static const TForteUInt8 scm_nEmbeddedStringMarker = 0x03;
    static const TForteUInt8 scm_nEndOfItemMarker = 0x01;

    static const TForteUInt8 scm_nRequestTagId =    0x05;
    static const TForteUInt8 scm_nFBTagId =         0x06;
    static const TForteUInt8 scm_nConnectionTagId = 0x07;
    static const TForteUInt8 scm_nReponseTagId =    0x08;

    static const TForteUInt8 scm_nIDAttribId =          0x05;
    static const TForteUInt8 scm_nActionAttribId =      0x06;
    static const TForteUInt8 scm_nNameAttribId =        0x07;
    static const TForteUInt8 scm_nTypeAttribId =       0x08;
    static const TForteUInt8 scm_nSourceAttribId =      0x09;
    static const TForteUInt8 scm_nDestinationAttribId = 0x0A;
    static const TForteUInt8 scm_nReasonAttribId =      0x0B;


    virtual void executeEvent(int pa_nEIID);

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

    void executeRQST(void);

    /*!\brief parse the start of the given command and extract ID and requested command
     *
     * If the request indicates a child element a check on size and tags is performed and a index to the start of the child element is returned.
     * @param pa_acID retrieved id value directly in the WAPBXML integer format
     * @param pa_nRequestedCommand the extracted command. on error cg_nMGM_CMD_INVALID
     * @return index to the start of the child element or 0
     */
    unsigned int parseRequestTag(char *pa_acID, EMGMCommandType &pa_nRequestedCommand);


    bool parseFBInstanceData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand);

    bool parseConnectionData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand);

    bool parseWriteData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand);

    static TConnectionID getConnectionEndPointIdentifier( char *pa_acIdentifierStart, unsigned int &pa_nCharsUsed);

    /*! \brief set the RESP output of the DEV_MGR according to the given response data
     *
     * \param pa_acID id of the response
     * \param pa_eResp qualifier of the response
     */
    void generateResponse(const char *pa_acID, EMGMResponse pa_eResp);


    FORTE_FB_DATA_ARRAY(2, 3, 2, 0);

    //! The device the block is contained in
    CDevice &m_poDevice;

  };

#endif /*DEV_MGR_H_*/
