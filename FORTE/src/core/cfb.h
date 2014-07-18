/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _CFB_H_
#define _CFB_H_

#include "funcbloc.h"
#include "if2indco.h"

struct SCFB_FBInstanceData {
    CStringDictionary::TStringId m_nFBInstanceNameId;
    CStringDictionary::TStringId m_nFBTypeNameId;
};

struct SCFB_FBConnectionData {
    TConnectionID m_nSrcId;
    int m_nSrcFBNum;
    TConnectionID m_nDstId;
    int m_nDstFBNum;
};

/*! \ingroup CORE
 * \brief Connection data for a fanned out connection of a composite's FB network
 *
 * As fanned out connections are attached together they need different data than
 * the first connection.
 */
struct SCFB_FBFannedOutConnectionData {
    int m_nConnectionNum; //!<the connection this fanned out connection should be attached to.
    TConnectionID m_nDstId;
    int m_nDstFBNum;
};

struct SCFB_FBParameter {
    unsigned int m_nFBNum;
    CStringDictionary::TStringId m_nDINameID; //!< the data input id of the input param to set
    const char * const m_acParamValue;
};

struct SCFB_FBNData {
    unsigned int m_nNumFBs;
    const SCFB_FBInstanceData * const m_pstFBInstances;
    //TODO add FB parameters
    unsigned int m_nNumEventConnections;
    const SCFB_FBConnectionData * const m_pstEventConnections;
    unsigned int m_nNumFannedOutEventConnections;
    const SCFB_FBFannedOutConnectionData * const m_pstFannedOutEventConnections;
    unsigned int m_nNumDataConnections;
    const SCFB_FBConnectionData * const m_pstDataConnections;
    unsigned int m_nNumFannedOutDataConnections;
    const SCFB_FBFannedOutConnectionData * const m_pstFannedOutDataConnections;
    unsigned int m_nNumParams;
    const SCFB_FBParameter * const m_pstParams;
};

/*!\ingroup CORE
 * \brief Class for handling firmware composite function blocks.
 *
 * @author GuGr & tstras
 * @version 20090801/mmm - added const CStringDictionary::TStringId pa_nInstanceNameId to constructor parameters
 * @version 20080424/ih - added support for adapters
 * @version 20071220/alil - added support for reading/writing CFB internal elements
 * @version 20060721/tstras - methods for start, stop, kill & reset of internal FBs added
 * @version 20060718/gugr - interface changed to new interface to internal data connection
 * @version 20061707/GuGr & tstras - First version as basis for interface description
 */
class CCompositeFB: public CFunctionBlock {

  public:
    /*! \brief Indicator that the given FB id is an adapter.
     *
     *This will allow for 65535 FBs within an CFB, which should be sufficient.
     */
    static const TForteInt32 scm_nAdapterMarker = 0x10000;

    /*! \brief constant for retrieving an FB Num from an FBId marked with an Adapter Marker
     *
     * needs to correspond to scm_nAdapterMarker
     */
    static const TForteInt32 scm_nAdapterFBRange = 0xFFFF;

    /*!\brief The main constructor for a composite function block.
     *
     * The interface of the constructor has been extended from the basic FB's interface with the following values:
     * \param pa_poSrcRes         pointer to including resource
     * \param pa_pstInterfaceSpec pointer to interface specification
     * \param pa_nInstanceNameId  StringId of instance name
     * \param pa_cpoFBNData       const pointer to description of internal structure of FB (FBs, Connections, ...)
     * \param pa_acFBData         ByteArray for FB-specific data (DI, DO, int. Vars, ...)
     */
    CCompositeFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
        const CStringDictionary::TStringId pa_nInstanceNameId,
        const SCFB_FBNData * const pa_cpoFBNData, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);
    virtual ~CCompositeFB();

    /*!\brief Connects specific data input of a CFB with a specific data connection.
     *
     * \param pa_unDINameId    StringId of input name.
     * \param pa_poDataCon     Pointer to the data connection the CFB should be connected to.
     * \return TRUE on success, FALSE if data output not exists or output is already connected.
     */
    virtual bool connectDI(CStringDictionary::TStringId pa_unDINameId, CDataConnection *pa_poDataCon);
    /*!\brief Connects specific data output of a CFB with a specific data connection.
     *
     * \param pa_unDONameId  StringId of output name.
     * \param pa_poDataCon   Pointer to the data connection the CFB should be connected to.
     * \return TRUE on success, FALSE if data output not exists or output is already connected.
     */
    virtual bool connectDO(CStringDictionary::TStringId pa_unDONameId, CDataConnection *pa_poDataCon);
    //! implement improved version of get Var for CFBs, allowing to read and write to internal elements
    virtual CIEC_ANY* getVar(const char *pa_acVarName);

    virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

  private:
    virtual void executeEvent(int pa_nEIID);

    void createInternalFBs();
    void createEventConnections();
    void createDataConnections();
    void setParams();
    void sendInternal2InterfaceOutputEvent(int pa_nEOID);

    //!Acquire the functionblock for a given function block number this may be a contained fb, an adapter, or the composite itself.
    CFunctionBlock *getFunctionBlock(int pa_nFBNum);

    TCInterface2InternalDataConnectionPtr *m_apoIf2InDConns;
    CDataConnection **m_apoIn2IfDConns;

    const SCFB_FBNData * const cm_cpoFBNData;
    TFunctionBlockPtr *m_apoInternalFBs;

    CEventConnection **m_apoEventConnections;
    CDataConnection **m_apoDataConnections;

    //!Array storing the holding the connections to be used in the exeucte event for triggering the internal FBs
    CEventConnection **m_apstInterface2InternalEventCons;

};

#define COMPOSITE_FUNCTION_BLOCK_CTOR(fbclass) \
 fbclass(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : \
 CCompositeFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stFBNData, m_anFBConnData, m_anFBVarsData)

#endif /*_CFB_H_*/
