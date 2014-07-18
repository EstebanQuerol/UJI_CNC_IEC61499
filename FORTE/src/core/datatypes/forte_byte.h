/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_BYTE_H_
#define _FORTE_BYTE_H_

#include "forte_any_bit.h"
#include <limits>

/*!\ingroup COREDTS CIEC_BYTE represents the byte data type according to IEC 61131.
 */
class CIEC_BYTE: public CIEC_ANY_BIT {
  DECLARE_FIRMWARE_DATATYPE(BYTE)

  public:
  typedef TForteByte TValueType;

    static const TValueType scm_nMinVal = 0;
    static const TValueType scm_nMaxVal;

    CIEC_BYTE() {
    }

    CIEC_BYTE(const CIEC_BYTE& pa_roValue) : CIEC_ANY_BIT() {
      setValueSimple(pa_roValue);
    }

    explicit CIEC_BYTE(TForteByte pa_cValue) {
      setTUINT8(pa_cValue);
    }

    virtual ~CIEC_BYTE() {
    }

    /*! \brief Operator: CIEC_BYTE data type = CIEC_BYTE data type
     *
     *   This command implements the assignment operator for the IEC61131 datatype BYTE.
     *   The parameter value is a reference onto a given C++ variable (call by reference).
     *   \param pa_rcValue  Reference for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_BYTE& operator =(TForteByte pa_rcValue) {
      setTUINT8(pa_rcValue);
      return *this;
    }

    CIEC_BYTE& operator =(const CIEC_BYTE &pa_roValue) {
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Converts CIEC_BYTE to elementary byte
     *
     *   Conversion operator for converting CIEC_BYTE to elementary byte
     */
    operator TForteByte() const {
      return getTUINT8();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_BYTE;
    }

    static const TForteUInt16 scm_unMaxStringBufSize;
};

#endif /*_FORTE_BYTE_H_*/
