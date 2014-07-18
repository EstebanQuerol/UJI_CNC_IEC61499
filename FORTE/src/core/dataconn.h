/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _DATACONN_H_
#define _DATACONN_H_

#include "./datatypes/forte_any.h"
#include "conn.h"

/*! \ingroup CORE\brief Class for handling a data connection.
 *  @author AZ
 *  @version 20090818/mmm - Disable disconnect functions if FORTE_CLASS_0 switch is set
 *  @version 20081121/mmm - removed readDataWithCasting
 *  @version 20081118/mmm - changed getValue, setValue and connect to eliminate ANY_FAC
 *  @version 20071029/az - destrucutor now deletes the m_poValue
 *  @version 20070911/az - Fixed bug in the rollback mechanism of connect data connections if a connection already exists
 *  @version 20060718/az - reworked connect method
 *  @version 20060717/gugr & tstras - setValue() & getValue() method added
 *  @version 20060214/az - fixed some bugs in the connect() regarding the cloning for the m_poValue
 *  @version 20060208/gugr - changed connect() for better readability & validity checks
 *  @version 20060124/smr - in connect(): fixed getDataOutput / getDataInput mismatch
 *  @version 20051202/tstras - member m_poValue, writeData() & readData() added
 *  @version 20050920/AZ - Initial version as basis for the interface documentation
 */
class CDataConnection : public CConnection {

  public:
    CDataConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB);

    virtual ~CDataConnection(){
      if(0 != m_poValue){
        m_poValue->~CIEC_ANY();;
      }
    };
/*! \brief Establishes the connection.
 *
 *   With this command the connection is created and the FBs are set to appropriate states.
 *   This mainly effects the destination of the connection (because of the fan-out).
 *   If the referenced connection through the pa_sDst parameter is the first destination
 *   also the src reference is created as necessary.
 *   \param pa_nDstId   String of the destination of the connection
 *   \param pa_roSrcFB  Reference to the source FB of this connection.
 *   \param pa_roDstFB  Reference to the destination FB of this connection.
 *   \return Can be the following response:
 *     - e_RDY ... creation went well.
 *     - e_NO_SUCH_OBJECT ... The destination is not a valid input.
 *     - e_INVALID_STATE ... The specified connection already exists.
 */
    virtual EMGMResponse connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);


#ifndef FORTE_CLASS_0
/*! \brief Disconnects the connection.
 *
 *   With this command the connection is removed and the FBs are set to appropriate states.
 *   This mainly effects the destination of the connection (because of the fan-out).
 *   If the referenced connection through the pa_sDst parameter is the last destination
 *   also the src reference is removed.
 *   \param pa_nDstId     String of the destination of the connection
 *   \param pa_roSrcFB  Reference to the source FB of this connection.
 *   \param pa_roDstFB  Reference to the destination FB of this connection.
 *   \return Can be the following response:
 *     - e_RDY ... Deletion went well.
 *     - e_NO_SUCH_OBJECT ... The destination is not a valid input.
 */
    virtual EMGMResponse disconnect(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);
#endif
/*! \brief Write connection data value.
 *
 *   Write data value from FB data output to connection data variable.
 *   \param pa_poValue pointer to FB data output
 *   \return Can be the following response:
 *     - TRUE ... write successful
 *     - FALSE ... no such data connection exists
 */
    void writeData(const CIEC_ANY *pa_poValue){
	    if(m_poValue){
	      m_poValue->setValue(*pa_poValue);
		  }
    };

/*! \brief Read connection data value.
 *
 *   Read data value from connection data variable to FB data input.
 *   \param pa_poValue pointer to FB data input
 */
    void readData(CIEC_ANY *pa_poValue) const;

/*! \brief Set class member variable m_poValue.
 *
 *   Set class member variable m_poValue.
 *   \param pa_poValue ... pointer to data variable
 */
    void setValue(CIEC_ANY *pa_poValue) {
      m_poValue = pa_poValue;
    }
/*! \brief Get class member variable m_poValue.
 *
 *   Get class member variable m_poValue.
 *   \return pointer to class member variable m_poValue
 */
    CIEC_ANY* getValue() {
      return m_poValue;
    }

  protected:
    CDataConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDstId) : CConnection(pa_nSrcId, pa_nDstId), m_poValue(0), m_bSpecialCastConnection(false){
    };

    /*! \brief check if the the given data points are compatible so that a connection can be established
     *
     * @param pa_poSrcDataPoint  data point of the connection's source (if 0 than it is a any data type)
     * @param pa_poDstDataPoint  data point of the connection's destination (if 0 than it is a any data type)
     * @param pa_rbSpecialCast   connection requires special cast (e.g., float datatype to int datatype conversion)
     * @return true if a connection between the given end points is valid
     */
    static bool canBeConnected(const CIEC_ANY *pa_poSrcDataPoint, const CIEC_ANY *pa_poDstDataPoint,
        bool &pa_rbSpecialCast);

    /*! \brief check if the the given data type needs special treatment in conversions
         *
         * @param pa_eSrcDTId  data type
         * @return true if special treatment is necessary
         */
    static bool needsSpecialCast(CIEC_ANY::EDataTypeID pa_eSrcDTId);

 /*! \brief Value for storing the current data of the connection
 */
    CIEC_ANY *m_poValue;

    TForteByte m_acDataBuf[sizeof(CIEC_ANY)];

    /*! \brief Flag for indicating that this connections needs special measures for casting.
     *
     * Currently this is only necessary for  (L)REAL to ANY_INT data connections
     */
    bool m_bSpecialCastConnection;
  private:

    /*!\brief Retrieves the destination data point (input or output) from the given FB with given destination ID
     *
     * Depending on the destination ID this will be an input (for internal FBs) or output (when connected to the
     * interface of the CFB).
     * @param pa_nDstId connection destination id
     * @param pa_roDstFB reference to the FB from which the data point should be retrieved
     * @return pointer to the data point or 0 if a data point if given name does not exist
     */
    static CIEC_ANY *getDstDataPoint(TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB);
};

typedef CDataConnection *TDataConnectionPtr;

#endif /*_DATACONN_H_*/
