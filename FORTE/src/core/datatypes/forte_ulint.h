/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_ULINT_H_
#define _FORTE_ULINT_H_

#include "forte_any_int.h"
#include <limits>

#ifdef FORTE_USE_64BIT_DATATYPES

/*!\ingroup COREDTS CIEC_ULINT represents the ulint data type according to IEC 61131.
 *  @author mw & az
 */
class CIEC_ULINT : public CIEC_ANY_INT{
  DECLARE_FIRMWARE_DATATYPE(ULINT)

  public:
    typedef TForteUInt64 TValueType;

    static const TValueType scm_nMinVal = 0;
    static const TValueType scm_nMaxVal;

    CIEC_ULINT(){
    }

    CIEC_ULINT(const CIEC_ULINT& pa_roValue) : CIEC_ANY_INT() {
      setValueSimple(pa_roValue);
    }

    CIEC_ULINT(TForteUInt64 pa_nValue){
      setTUINT64(pa_nValue);
    }

    virtual ~CIEC_ULINT(){
    }

    /*! \brief Operator: CIEC_ULINT data type = unsigned long data type
     *
     *   This command implements the assignment operator for the C++ datatype UNSIGNED LONG
     *   The parameter value is represented by a C++ variable (call by value).
     *   \param pa_nValue  Value for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_ULINT& operator =(TForteUInt64 pa_nValue){
      setTUINT64(pa_nValue);
      return *this;
    }

    CIEC_ULINT& operator =(const CIEC_ULINT &pa_roValue){
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Converts CIEC_ULINT to elementary unsigned 64 bit integer
     *
     *   Conversion operator for converting CIEC_ULINT to elementary unsigned 64 bit integer
     */
    operator TForteUInt64() const{
      return getTUINT64();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_ULINT;
    }

    static const TForteUInt16 scm_unMaxStringBufSize;
};

#endif
#endif /*_FORTE_ULINT_H_*/
