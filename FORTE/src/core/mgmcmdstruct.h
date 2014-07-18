/*******************************************************************************
 * Copyright (c) 2007-2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef MGMCMDSTRUCT_H_
#define MGMCMDSTRUCT_H_

#include <mgmcmd.h>
#include <forte_string.h>

/**  \ingroup CORE \defgroup MGMCommands Management Command Exchange Representation
 * \brief In this section the FORTE-internal data-exchange-structure for management command passing is described.
 */
/*@{*/

/*!\brief All the data necessary for processing a management command.
 *
 * The data of this structure is the internal FORTE representation of an IEC 61499 management command.
 * e.g. create \<FB name="START" type="E_RESTART"\> will result in the following data values:
 *    - m_nCMD = 0x30
 *    - m_sDestination = ""
 *    - m_sFistParam = "START"
 *    - m_sSecondParam = "E_RESTART"
 *    - m_sAdditionalParams = ""
 */
struct SManagementCMD {
    /*!\brief An identification number for the requested command based on the definitons in the standard.
     *
     * See the constants in devadmin.h for the available commands
     */
    EMGMCommandType m_nCMD;
    /*!\brief The destination of the command.
     *
     * if the destination is scm_nInvalidStringID device is the target.
     * Otherwise a the TStringId of the resource's name the command
     * should be exectued in is the target.
     * FIXME if more than the resource should be supported (e.g. composite FBs) the type needs to be changed .
     */
    CStringDictionary::TStringId m_nDestination;
    /*!\brief The first parameter of the command e.g. the FB name to create or the src of an connection.
     * The data is stored as
     *  - single TStringId for a FB name
     *  - as a combined TStringId for connections see CConnection for details
     */
    TConnectionID m_nFirstParam;
    /*!\brief The second parameter of the command e.g. the FB type to create or the dst ("FBName.input") of an connection.
     * The data is stored as
     *  - single TStringId for a FB name
     *  - as a combined TStringId for connections see CConnection for details
     */
    TConnectionID m_nSecondParam;
    /*!\brief Additional params needed by a MGM command (e.g., to return results of query commands)
     */
    CIEC_STRING m_oAdditionalParams;

    /*\brief pointer to the ID to generate the correct response */
    char *m_acID;

#ifdef FORTE_SUPPORT_MONITORING
     /*\brief pointer to the response to generate the correct response */
     CIEC_STRING m_oMonitorResponse;
#endif

};



#endif /* MGMCMDSTRUCT_H_ */
