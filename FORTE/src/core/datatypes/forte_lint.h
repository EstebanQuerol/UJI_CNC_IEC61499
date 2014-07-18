/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_LINT_H_
#define _FORTE_LINT_H_

#include "forte_any_int.h"
#include <limits>

#ifdef FORTE_USE_64BIT_DATATYPES

/*!\ingroup COREDTS CIEC_LINT represents the dint data type according to IEC 61131.
 *  @version 20051116/mw & az - Initial version
 */
class CIEC_LINT : public CIEC_ANY_INT{
  DECLARE_FIRMWARE_DATATYPE(LINT)

  public:
    typedef TForteInt64 TValueType;

    static const TValueType scm_nMinVal;
    static const TValueType scm_nMaxVal;

    CIEC_LINT(){
    }

    CIEC_LINT(const CIEC_LINT& pa_roValue) :
        CIEC_ANY_INT(){
      setValueSimple(pa_roValue);
    }

    CIEC_LINT(TForteInt64 pa_nValue){
      setTINT64(pa_nValue);
    }

    virtual ~CIEC_LINT(){
    }

    /*! \brief Operator: CIEC_LINT data type = long data type
     *
     *   This command implements the assignment operator for the C++ datatype LONG.
     *   The parameter value is represented by a C++ variable (call by value).
     *   \param pa_nValue  Value for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_LINT& operator =(TForteInt64 pa_nValue){
      setTINT64(pa_nValue);
      return *this;
    }

    CIEC_LINT& operator =(const CIEC_LINT &pa_roValue){
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Converts CIEC_LINT to elementary byte
     *
     *   Conversion operator for converting CIEC_LINT to elementary 64 bit integer
     */
    operator TForteInt64() const{
      return getTINT64();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_LINT;
    }

    static const TForteUInt16 scm_unMaxStringBufSize;
};

#endif
#endif /*_FORTE_LINT_H_*/
