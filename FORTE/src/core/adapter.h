/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "funcbloc.h"

class CAdapterConnection;

#define ADAPTER_CTOR(fbclass) \
 fbclass(CStringDictionary::TStringId pa_anAdapterInstanceName, CResource *pa_poSrcRes, bool pa_bIsPlug) : \
 CAdapter( pa_poSrcRes, &scm_stFBInterfaceSpecSocket, pa_anAdapterInstanceName, &scm_stFBInterfaceSpecPlug, pa_bIsPlug, m_anFBConnData, m_anFBVarsData)


#define FORTE_ADAPTER_DATA_ARRAY(a_nNumEIs, a_nNumEOs, a_nNumDIs, a_nNumDOs, a_nNumAdapters) \
  union{ \
    TForteByte m_anFBConnData[genAdapterFBConnDataSizeTemplate<a_nNumEIs, a_nNumEOs, a_nNumDIs, a_nNumDOs>::value]; \
  };\
  union{ \
    TForteByte m_anFBVarsData[genFBVarsDataSizeTemplate<a_nNumDIs, a_nNumDOs, a_nNumAdapters>::value]; \
  };


/*!\ingroup CORE\brief Class for handling adapters.
 *
 *
 * @author IH
 * @version 20090801/mmm added parameter const CStringDictionary::TStringId pa_nInstanceNameId to constructor
 * @version 20080418/IH - Initial version
 */
class CAdapter: public CFunctionBlock {
  public:
    /*!\brief The main constructor for an adapter instance.
     */
    //TODO: think on interface
    CAdapter(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpecSocket, const CStringDictionary::TStringId pa_nInstanceNameId, const SFBInterfaceSpec *pa_pstInterfaceSpecPlug, bool pa_bIsPlug, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);
    virtual ~CAdapter();

    /*!\brief Returns if Adapter instance is a Plug
     */
    bool isPlug() {
      return m_bIsPlug;
    }
    ;

    /*!\brief Returns if Adapter instance is a Socket
     */
    bool isSocket() {
      return !m_bIsPlug;
    }
    ;

    void setParentFB(CFunctionBlock *pa_poParentFB, TForteUInt8 pa_nParentAdapterlistID);

    /*! \brief Connects adapter to peer adapter
     *
     *   With this command the adapter is connected to a complementary adapter instance (peer).
     *   The data output pointers are "redirected" to the data inputs of the peer.
     *   \param pa_poPeer  Pointer to the peer to connect to.
     *   \param pa_poAdConn Pointer to the connecting adapter connection.
     *   \return success of establishment of connection
     */
    bool connect(CAdapter *pa_poPeer, CAdapterConnection *pa_poAdConn);

    /*! \brief Disconnects adapter from peer adapter
     *
     *   With this command the adapter is disconnected from a complementary adapter instance (peer).
     *   The redirection of data output pointers is removed.
     *   \param pa_poAdConn Pointer to the connecting adapter connection.
     *   \return success of disconnection
     */
    bool disconnect(CAdapterConnection *pa_poAdConn = 0);

    /*! \brief Returns the compatibility of the adapter to another adapter
     *
     *   This method will evaluate the compatibility of this adapter to another one.
     *   Only instances of compatible adapter types may be interconnected.
     *   \param pa_poPeer Pointer to a potential peer, whose compatibility has to be checked.
     *   \return compatibility status
     */
    bool isCompatible(CAdapter *pa_poPeer) {
      return (getFBTypeId() == pa_poPeer->getFBTypeId());
    }
    ;

  protected:
    template<unsigned int ta_nNumEIs, unsigned int ta_nNumEOs, unsigned int ta_nNumDIs, unsigned int ta_nNumDOs>
    struct genAdapterFBConnDataSizeTemplate {
        enum {
          value = genFBConnDataSizeTemplate<((ta_nNumEIs < ta_nNumEOs) ? ta_nNumEOs : ta_nNumEIs), ta_nNumDIs, ta_nNumDOs>::value
        };
    };

    TForteUInt16 m_nParentAdapterListEventID;

  private:
    virtual void executeEvent(int pa_nEIID);
    void setupEventEntryList();

    bool m_bIsPlug;
    CAdapter *m_poPeer;
    CIEC_ANY *m_aoLocalDIs;
    CAdapterConnection *m_poAdapterConn;
    SEventEntry *m_astEventEntry; //! the event entry list to start the event chain
};

#endif /*_ADAPTER_H_*/
