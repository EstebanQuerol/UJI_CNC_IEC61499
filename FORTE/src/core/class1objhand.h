/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _CLASS1OBJHAND_H_
#define _CLASS1OBJHAND_H_

#include "stringdict.h"
#include "funcbloc.h"
#include "conn.h"
#include "fortelist.h"
#include "mgmcmdstruct.h"

/**\ingroup CORE
 *Class handling all management commands and handling created objects like, FBs, Resources, Connections,...
 *
 */
class C61499Class1ObjectHandler{
  public:
    C61499Class1ObjectHandler(CResource& pa_roHandlerOwner);

    virtual ~C61499Class1ObjectHandler();

    /*!\brief Execute the given management command
     *
     * Evaluates the m_sDestination parameter of the command if empty the resource tries
     * to execute the management command if not it tries to apply the mgm command to a
     * contained FB if possible.
     * \param pa_oCommand internal representation of the management command
     * \return response of the MGMCommand execution as defined in IEC 61499
     */
    virtual EMGMResponse executeMGMCommand(SManagementCMD &pa_oCommand);

    /*!\brief Create a new FB instance of given type and name
     *
     * @param pa_nFBNameId  StringId of instance name of the new FB
     * @param pa_nFBTypeId  StringId of type name of the new FB
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse createFB(CStringDictionary::TStringId pa_nFBNameId, CStringDictionary::TStringId pa_nFBTypeId);

    /*!\brief Delete a FB instance with given name
     *
     * @param pa_nFBNameId  StringId of instance name of the new FB
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse deleteFB(CStringDictionary::TStringId pa_nFBNameId);

    /*!\brief Create a new connection between source and destination
     *
     * @param pa_nSrcId   ID of source of the connection fb.output
     * @param pa_nDestId  ID of destination of the connection fb.input
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse deleteConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDestId);

    /*!\brief Adds a created function block to the FB-List
     *
     * @param pa_poFuncBlock new function block to add to the FB-List
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse addFB(CFunctionBlock *pa_poFuncBlock);

    /*!\brief Gets a function block from the FB-List
     *
     * @param pa_nFBInstanceNameId Stringdictonary ID of the requested function block
     * @return pointer to the requested function block, returns 0 if function block is not in the list
     */
    CFunctionBlock* getFB(CStringDictionary::TStringId pa_nFBInstanceNameId);

    /*!\brief Write a parameter value to a given FB-input
     *
     * @param pa_oCommand Structure including management-command and response
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse writeValue(SManagementCMD &pa_oCommand);

    /*!\brief Read a parameter value from a given FB
     *
     * @param  pa_oCommand Structure including management-command and response
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse readValue(SManagementCMD &pa_oCommand);

    EMGMResponse queryTypeList(SManagementCMD &pa_oCommand, CTypeLib::CTypeEntry * pa_LibTypeListStart);
    EMGMResponse queryTypeVersion(TForteUInt32 pa_nSource, char* pa_sValue);

    /*!\brief Read a parameter value from a given FB
     *
     * @param pa_oCommand Structure including management-command and response
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse executeQueryReq(SManagementCMD &pa_oCommand);

    /*! \brief query connections
     *
     * @param pa_oCommand Structure including management-command and response
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse executeQueryCon(SManagementCMD &pa_oCommand);

    /*!\brief Create a new connection between source and destination
     *
     * @param pa_nSrcId   source of the connection fb.output
     * @param pa_nDestId  destination of the connection fb.input
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse createConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDestId);

    /*!\brief check if there exists an connection with given source identifier in this resource
     *
     * \param pa_nSrcId  source identifier of connection (FB.Output)
     * \return pointer to connection if connection does not exist 0
     */
    CConnection* getConnection(TConnectionID pa_nSrcId);

    EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

  protected:
    /** \brief Delete all FB instances
     *
     * @return e_RDY on success
     */
    EMGMResponse deleteWholeFBNetwork();

    /*! \brief Owner resource/device of the objecthandler
     */
    CResource& m_roHandlerOwner;

    /*! \brief Type for storing the list of FB objects.
     */

    typedef CSinglyLinkedList<CFunctionBlock*> TObjInstanceList;
    /*! \brief List of the current instantiated FBs in this 61499 Object Handler (may also contain Resources).
     *
     */
    TObjInstanceList m_lstpoObjectInstanceList;

    /*! \brief Type for storing the list of connection.
     */
    typedef CSinglyLinkedList<CConnection*> TConnectionList;

    /*! \brief List of the current connections in this 61499 Object Handler.
     */
    TConnectionList m_lstpoConnectionList;

  private:
    C61499Class1ObjectHandler();

#ifdef FORTE_SUPPORT_MONITORING

    struct SDataWatchEntry{
        SDataWatchEntry( CStringDictionary::TStringId pa_unPortId, CIEC_ANY *pa_poDataValue) :
          m_unPortId(pa_unPortId), m_poDataValue(pa_poDataValue){

        }

        CStringDictionary::TStringId m_unPortId;
        CIEC_ANY *m_poDataValue;

    };

    struct SEventWatchEntry{
        SEventWatchEntry(CStringDictionary::TStringId pa_unPortId, SMonitorEvent &pa_roEventData):
          m_unPortId(pa_unPortId), m_roEventData(pa_roEventData){
        }

        CStringDictionary::TStringId m_unPortId;
        SMonitorEvent &m_roEventData;
    };

    typedef CSinglyLinkedList<SDataWatchEntry> TDataWatchList;
    typedef CSinglyLinkedList<SEventWatchEntry> TEventWatchList;

    struct SFBMonitoringEntry{
        CFunctionBlock *m_poFB;
        TDataWatchList m_lstWatchedDataPoints;
        TEventWatchList m_lstWatchedEventPoints;
    };

    typedef CSinglyLinkedList<SFBMonitoringEntry> TFBMonitoringList;


    EMGMResponse addWatch(TConnectionID pa_nWatchPointId);
    EMGMResponse removeWatch(TConnectionID pa_nWatchPointId);
    EMGMResponse readWatches(CIEC_STRING &pa_roResponse);
    EMGMResponse getWatches(CIEC_STRING &pa_roResponse, char pa_cQualifier);
    EMGMResponse forceValue(SManagementCMD &pa_rstCommand);
    EMGMResponse clearForce(TConnectionID pa_nDestId);
    EMGMResponse triggerEvent(TConnectionID pa_nEventPortId);
    EMGMResponse resetEventCount(TConnectionID pa_nEventPortId);


    SFBMonitoringEntry &findOrCreateFBMonitoringEntry(CFunctionBlock *pa_poFB);
    void addDataWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId, CIEC_ANY *pa_poDataVal);
    bool removeDataWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId);
    void addEventWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId, SMonitorEvent &pa_rstEventData);
    bool removeEventWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId);
    void readResourceWatches(CIEC_ANY_STRING &pa_roResponse);
    void getResourceWatches(CIEC_ANY_STRING &pa_roResponse, char pa_cQualifier);

    static void appendDataWatch(CIEC_ANY_STRING &pa_roResponse, SDataWatchEntry &pa_roDataWatchEntry);
    static void appendPortTag(CIEC_ANY_STRING &pa_roResponse, CStringDictionary::TStringId pa_unPortId);
    static void appendEventWatch(CIEC_ANY_STRING &pa_roResponse, SEventWatchEntry &pa_roEventWatchEntry);

    //!List storing all FBs which are currently monitored
    TFBMonitoringList m_lstFBMonitoringList;
    //!Event entry for triggering input events
    SEventEntry m_stTriggerEvent;

#endif
};

#endif
