/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _ANY_INT_H_
#define _ANY_INT_H_

#include "forte_any_num.h"

/*!\ingroup COREDTS CIEC_ANY_INT represents all integer data types according to IEC 61131.

 */
class CIEC_ANY_INT : public CIEC_ANY_NUM{
	DECLARE_FIRMWARE_DATATYPE(ANY_INT)

  public:
	  CIEC_ANY_INT(TLargestIntValueType paVal);

    virtual ~CIEC_ANY_INT(){
    }

    bool isSigned() const{
      bool bRetVal = false;
      if(e_LINT <= getDataTypeID()){
        bRetVal = true;
      }
      return bRetVal;
    }

    TLargestUIntValueType getUnsignedValue() const{
      return getLargestUInt();
    }

    TLargestIntValueType getSignedValue() const{
      return getLargestInt();
    }

     void setSignedValue(TLargestIntValueType m_nVal){
       setLargestInt(m_nVal);
     }

     void setUnsignedValue(TLargestIntValueType m_nVal){
       setLargestInt(m_nVal);
     }

    CIEC_ANY_INT() {
    }
};

#endif /*_MANY_INT_H_*/
