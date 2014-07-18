/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _IF2INDCO_H_
#define _IF2INDCO_H_


#include "./datatypes/forte_any.h"
#include "dataconn.h"
#include "funcbloc.h"
#include "fortelist.h"

/*! \ingroup CORE\brief class for handling a interface to internal data connection.
 *  @author GG
 *  @version 20081121/mmm - changed due to elimination of ANY_FACADE
 *  @version 20071029/az - changed constructor of interface data connections
 *  @version 20060718/gugr - Initial version to handle data connections from CFB interface to internal FBs
 */


class CInterface2InternalDataConnection : public CDataConnection {
  private:
    typedef CSinglyLinkedList<CFunctionBlock*> TFunctionBlockList;
    TFunctionBlockList m_lstDstFBPtr;

  protected:
  public:
    CInterface2InternalDataConnection(TConnectionID pa_nSrcId, CFunctionBlock &pa_roSrcFB, TConnectionID pa_nDstId, CFunctionBlock &pa_roDstFB);
    virtual ~CInterface2InternalDataConnection(){
      m_poValue = 0; // in interface data connections we are not allowed to delete the m_poValue
    };
/*! \brief Establishes the connection.
 *
 *   With this command the connection is created and the FBs are set to appropriate states.
 *   This mainly effects the destination of the connection (because of the fan-out).
 *   If the referenced connection through the pa_sDst parameter is the first destination
 *   also the src reference is created as necessary.
 *   \param pa_nDstId     String of the destination of the connection
 *   \param pa_roSrcFB  Reference to the source FB of this connection.
 *   \param pa_roDstFB  Reference to the destination FB of this connection.
  *   \return Can be the following response:
 *     - e_RDY ... creation went well.
 *     - e_NO_SUCH_OBJECT ... The destination is not a valid input.
 *     - e_INVALID_STATE ... The specified connection already exists.
 */
    virtual EMGMResponse connectFannedOut(TConnectionID pa_nDstId, CFunctionBlock &pa_roSrcFB, CFunctionBlock &pa_roDstFB);

/*! \brief Clones interface data value (CFB data input) to internal FB data input.
 *
 */
    void cloneInputInterfaceValue(void);
};

typedef CInterface2InternalDataConnection *TCInterface2InternalDataConnectionPtr;

#endif /*IF2INDCO_H_*/
