/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_DINT_H_
#define _FORTE_DINT_H_

#include "forte_any_int.h"
#include <limits>

/*!\ingroup COREDTS CIEC_DINT represents the dint data type according to IEC 61131.
 */
class CIEC_DINT : public CIEC_ANY_INT{
  DECLARE_FIRMWARE_DATATYPE(DINT)

  public:
    typedef TForteInt32 TValueType;

    static const TValueType scm_nMinVal;
    static const TValueType scm_nMaxVal;

    CIEC_DINT(){
    }

    CIEC_DINT(const CIEC_DINT& pa_roValue) : CIEC_ANY_INT() {
      setValueSimple(pa_roValue);
    }

    CIEC_DINT(TForteInt32 pa_nValue){
      setTINT32(pa_nValue);
    }

    virtual ~CIEC_DINT(){
    }

    /*! \brief Operator: CIEC_DINT data type = long data type
     *
     *   This command implements the assignment operator for the C++ datatype LONG.
     *   The parameter value is represented by a C++ variable (call by value).
     *   \param pa_nValue  Value for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_DINT& operator =(TForteInt32 pa_nValue){
      setTINT32(pa_nValue);
      return *this;
    }

    CIEC_DINT& operator =(const CIEC_DINT &pa_roValue){
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Converts CIEC_DINT to elementary byte
     *
     *   Conversion operator for converting CIEC_DINT to elementary 32 bit integer
     */
    operator TForteInt32() const{
      return getTINT32();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_DINT;
    }

    static const TForteUInt16 scm_unMaxStringBufSize;
};

#endif /*_FORTE_DINT_H_*/
