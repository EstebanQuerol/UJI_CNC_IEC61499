/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ANY_DER_H_
#define _ANY_DER_H_

#include "forte_any.h"

/*!\ingroup COREDTS CIEC_ANY_DERIVED represents the user defined data types according to
 *  IEC 61131.
 *  @author tstras & imuell
 *  @version 20081121/ mmm - Constructor added, Name changed from IIEC_ANY_DERIVED to CIEC_ANY_DERIVED
 *  @version 20060719/tstras - default destructor added
 *  @version 20051205/tstras - Name changed from IIEC_UserDefDT to CIEC_ANY_DERIVED
 *  @version 20051017/tstras & imuell - Initial version
 */
class CIEC_ANY_DERIVED : public CIEC_ANY{
  public:
    virtual ~CIEC_ANY_DERIVED(){
    }

  protected:
    CIEC_ANY_DERIVED() {
    }
};

#endif /*_MANY_DER_H_*/
