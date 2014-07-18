/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_UDINT_H_
#define _FORTE_UDINT_H_

#include "forte_any_int.h"
#include <limits>

/*!\ingroup COREDTS CIEC_UDINT represents the udint data type according to IEC 61131.
 */
class CIEC_UDINT : public CIEC_ANY_INT{
  DECLARE_FIRMWARE_DATATYPE(UDINT)

  public:
    typedef TForteUInt32 TValueType;

    static const TValueType scm_nMinVal = 0;
    static const TValueType scm_nMaxVal;

    CIEC_UDINT(){
    }

    CIEC_UDINT(const CIEC_UDINT& pa_roValue) :
        CIEC_ANY_INT(){
      setValueSimple(pa_roValue);
    }

    CIEC_UDINT(TForteUInt32 pa_nValue){
      setTUINT32(pa_nValue);
    }

    virtual ~CIEC_UDINT(){
    }

    /*! \brief Operator: CIEC_UDINT data type = unsigned long data type
     *
     *   This command implements the assignment operator for the C++ datatype UNSIGNED LONG
     *   The parameter value is represented by a C++ variable (call by value).
     *   \param pa_nValue  Value for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_UDINT& operator =(TForteUInt32 pa_nValue){
      setTUINT32(pa_nValue);
      return *this;
    }

    CIEC_UDINT& operator =(const CIEC_UDINT &pa_roValue){
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Converts CIEC_UDINT to elementary unsigned 32 bit integer
     *
     *   Conversion operator for converting CIEC_UDINT to elementary unsigned 32 bit integer
     */
    operator TForteUInt32() const{
      return getTUINT32();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_UDINT;
    }

    static const TForteUInt16 scm_unMaxStringBufSize;
};

#endif /*_FORTE_UDINT_H_*/
