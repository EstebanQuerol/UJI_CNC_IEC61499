/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _FORTE_TOD_H_
#define _FORTE_TOD_H_

#include "forte_any_date.h"
#include <time.h>
#if defined(WINCE)
#include <wce_time.h>
#endif

#ifdef FORTE_USE_64BIT_DATATYPES

/*!\ingroup COREDTS CIEC_TIME_OF_DAY represents the time data types according to IEC 61131.
 *  @author unknown
 *  @version 20081311/mmm - deleted getDataPtr(), getDataTypeID(); changed IIEC_ANY_STRING to CIEC_ANY_STRING due to class structure change
 *    removed getValue, setValue; added setValueComplex
 */

class CIEC_TIME_OF_DAY : public CIEC_ANY_DATE{
  DECLARE_FIRMWARE_DATATYPE(TIME_OF_DAY)

  public:
    typedef TForteUInt64 TValueType;

    CIEC_TIME_OF_DAY(){
    }

    CIEC_TIME_OF_DAY(const CIEC_TIME_OF_DAY& pa_roValue) :
        CIEC_ANY_DATE(){
      setValueSimple(pa_roValue);
    }

    CIEC_TIME_OF_DAY(TForteUInt64 pa_nValue){
      setTUINT64(pa_nValue);
    }

    virtual ~CIEC_TIME_OF_DAY(){
    }

    /*! \brief Operator: CIEC_TIME_OF_DAY data type = long data type
     *
     *   This command implements the assignment operator for the C++ datatype long long.
     *   The parameter value is represented by a C++ variable (call by value).
     *   \param pa_nValue  Value for assignment.
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_TIME_OF_DAY& operator =(TForteInt64 pa_nValue){
      setTUINT64(pa_nValue);
      return *this;
    }

    CIEC_TIME_OF_DAY& operator =(const CIEC_TIME_OF_DAY &pa_roValue){
      setValueSimple(pa_roValue);
      return *this;
    }

    /*! \brief Operator: CIEC_TIME data type operator++
     *
     *   This command implements the increment operator for the IEC61131 datatype TIME.
     *   The parameter value is represented by a C++ variable (call by value).
     *   \return Can be the following response:
     *     - Pointer to given object.
     */
    CIEC_TIME_OF_DAY& operator ++(void){
      setTUINT64(getTUINT64() + 1);
      return *this;
    }
    /*! \brief Converts CIEC_SINT to elementary 32 bit integer
     *
     *   Conversion operator for converting CIEC_SINT to elementary 32 bit integer
     */
    operator TForteUInt64() const{
      return getTUINT64();
    }

    virtual EDataTypeID getDataTypeID() const{
      return CIEC_ANY::e_TIME_OF_DAY;
    }

    /*! \brief Converts string value to data type value
     *
     *   This command implements a conversion function from IEC61131
     *   data type (string format) to a C++ conform type.
     *   This function is necessary for communication with a proper engineering system.
     *   \param pa_pacValue Pointer to the given String
     *   \return Can be the following response:
     *   \return number of bytes taken used from the buffer
     *        -1 on on error
     */
    virtual int fromString(const char *pa_pacValue);
    /*! \brief Converts data type value to string
     *
     *   This command implements a conversion function from C++ data type
     *   to IEC61131 conform data type (string format).
     *   This function is necessary for communication with a proper engineering system.
     *   \param pa_pacValue Pointer to the buffer String
     *   \param pa_nBufferSize Size of the given buffer
     *   \return number of bytes used in the buffer without trailing 0x00
     *           -1 on error
     */
    virtual int toString(char* pa_pacValue, unsigned int pa_nBufferSize) const;

    /*! \brief Set the variable to current time
     */
    void setCurrentTime(){
#if ! defined(WINCE)
      setTUINT64(time(0) * 1000ULL);
#else
      setTUINT64(wceex_time(0) * 1000ULL);
#endif
    }
    ;
};

#endif /* #ifdef FORTE_USE_64BIT_DATATYPES */

#endif /*_FORTE_TOD_H_*/
