/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _CONN_H_
#define _CONN_H_

#include "fortelist.h"
#include "mgmcmd.h"
#include "stringdict.h"

//forward declaration of a few classes to reduce includefile dependencies
class CFunctionBlock;

/*!\ingroup CORE \brief Base class for handling a connection.
 *
 *
 * @author AZ
 * @version 20090818/mmm - Disable disconnect functions if FORTE_CLASS_0 switch is set
 * @version 20090801/mmm - changed TDestinationIdList to type CSinglyLinkedList<TConnectioID>, changed connect
 * and disconnect functions
 * @version 20050920/AZ - Initial version as basis for the interface documentation
 */

class CConnection{
public:

  typedef CSinglyLinkedList<TConnectionID> TDestinationIdList;

	CConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDstId):
    m_nSourceId(pa_nSrcId){
    m_lstDestinationIds.push_back(pa_nDstId);

  };
	virtual ~CConnection() {
  };
/*! \brief Establishes a fanned out connection.
 *
 * With this command the connection is created and the FBs are set to appropriate states.
 * This mainly effects the destination of the connection (because of the fan-out).
 * If the referenced connection through the pa_sDst parameter is the first destination
 * also the src reference is created as necessary.
 * \param pa_nDstId     stringId of the destination of the connection
 * \param pa_roSrcFB  reference to the source FB of this connection
 * \param pa_roDstFB  reference to the destination FB of this connection
 * \return can be the following response:
 *     - e_RDY... creation went well.
 *     - e_NO_SUCH_OBJECT... The destination is not a valid input.
 *     - e_INVALID_STATE... The specified connection already exists.
 */
 virtual EMGMResponse connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);

#ifndef FORTE_CLASS_0
/*! \brief Disconnects the connection.
 *
 * With this command the connection is removed and the FBs are set to appropriate states.
 * This mainly effects the destination of the connection (because of the fan-out).
 * If the referenced connection through the pa_sDst parameter is the last destination
 * also the src reference is removed.
 * \param pa_nDstId     string of the destination of the connection
 * \param pa_roSrcFB  reference to the source FB of this connection
 * \param pa_roDstFB  reference to the destination FB of this connection
 * \return can be the following response:
 *     - e_RDY... creation went well.
 *     - e_NO_SUCH_OBJECT... The destionation is not a valid input.
 */
  virtual EMGMResponse disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);
#endif
/*! \brief Check if there are destinations added to this connection
 *
 * \return TRUE if there is no destination in the connection.
 */
  bool isEmpty(void) const {return m_lstDestinationIds.isEmpty(); };
/*! \brief Get the source string of the connection
 */
  TConnectionID getSourceId(void) const { return m_nSourceId; };
/*! \brief find the dot in the source string and get the name of the output it is referencing to
 * \return returns a pointer to the first character of the source output name
 */
  CStringDictionary::TStringId getOutputNameId(void) const {
    return (CStringDictionary::TStringId)(0xFFFFFFFF & m_nSourceId);
  };

  TDestinationIdList &getDestinationIds() { return m_lstDestinationIds; };
/*! Generate a connection port id for a given fb-name / port-name combination
 */

  static TConnectionID genConPortId(CStringDictionary::TStringId pa_unFBNameId, CStringDictionary::TStringId pa_unPortNameId) {
      return (((((TConnectionID)pa_unFBNameId) << 32) & 0xFFFFFFFF00000000ULL) +
              (((TConnectionID)pa_unPortNameId) & 0xFFFFFFFF));
    };

  /*! Generate a connection port id for a given fb-nameid / port-nameid combination
   *  This template will generate a constant and will therefore be very efficient
   */
  #define GENERATE_CONNECTION_PORT_ID_2_ARG(FBNameId, PortNameId)\
		(((((TConnectionID)FBNameId) << 32) & 0xFFFFFFFF00000000ULL) + \
		(((TConnectionID)PortNameId) & 0xFFFFFFFF))

  /*! Generate a connection port id for a connection with a single source id e.g. interface connections
   *  This template will generate a constant and will therefore be very efficient
   */
  #define GENERATE_CONNECTION_PORT_ID_1_ARG(PortNameId)\
		GENERATE_CONNECTION_PORT_ID_2_ARG(CStringDictionary::scm_nInvalidStringId, PortNameId)

//  static TConnectionID genConPortIdSingle(CStringDictionary::TStringId pa_unPortNameId) {
//    return genConPortId(CStringDictionary::scm_nInvalidStringId, pa_unPortNameId);  // a 0 will result in a invalid string id for the fb name
//  }

  /** Extract the FB name id from a combined connection Id
   *
   * @param pa_nConnId given connection id
   * @return fb name id
   */
  static CStringDictionary::TStringId extractFBNameId(TConnectionID pa_nConnId) {
    TConnectionID nRetval = (pa_nConnId >> 32);
    return (CStringDictionary::TStringId)(nRetval & 0xFFFFFFFF);
  }

  /** Extract the port name id from a combined connection Id
   *
   * @param pa_nConnId given connection id
   * @return port name id
   */
  static CStringDictionary::TStringId extractPortNameId(TConnectionID pa_nConnId) {
    return (CStringDictionary::TStringId)((pa_nConnId) & 0xFFFFFFFF);
  }
protected:
/*!\brief a list of destinations the connection is connected to.
 *
 * By storing a list of destinations an implicit support for fan-out is given.
 * The destination is represented as string id the same way os the sourceId
 */
  TDestinationIdList m_lstDestinationIds;
/*!\brief An identifier for the source of this connection
 *
 * The source string int the form of "FBName.OutputName" is represented as StringId of the
 * the two string parts. As stringIds are 16bit the source string id is 32bit. in the high
 * byte we store the StringId of the FB name and in the low byte the output name.
 */
  TConnectionID m_nSourceId;
private:

//! Check if there is already a connection within this connection with the same dst.
  bool dstExists(TConnectionID pa_nDstId){
    bool bRetVal = false;
    for(TDestinationIdList::Iterator it = m_lstDestinationIds.begin(); it != m_lstDestinationIds.end();++it)  {
      if((*it) == pa_nDstId)  {
        bRetVal = true;
        break;
      }
    }
    return bRetVal;
  };

};

#endif /*_CONN_H_*/
