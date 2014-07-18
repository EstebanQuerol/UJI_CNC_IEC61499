/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ANY_BIT_H_
#define _ANY_BIT_H_

#include "forte_any_elementary.h"

/*!\ingroup COREDTS IIEC_ANY_BIT represents any bit data types according to IEC 61131.
 *  @author tstras & imuell
 *  @version 20081121/mmm - Constructor added, Name changed from IIEC_ANY_BIT to CIEC_ANY_BIT
 *  @version 20060719/tstras - default destructor added
 *  @version 20051205/tstras - derived from IIEC_ANY_ELEMENTARY
 *  @version 20051017/tstras & imuell - Initial version
 */
class CIEC_ANY_BIT : public CIEC_ANY_ELEMENTARY{
  DECLARE_FIRMWARE_DATATYPE(ANY_BIT)

  public:
    virtual ~CIEC_ANY_BIT(){
    }

  protected:
    CIEC_ANY_BIT() :
        CIEC_ANY_ELEMENTARY(){
    }
};

#endif /*_MANY_BIT_H_*/
