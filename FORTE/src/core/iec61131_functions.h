/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef IEC61131_FUNCTIONS_H_
#define IEC61131_FUNCTIONS_H_

#include <math.h>
#include <string.h>
//#include <string>
#include "datatypes/forte_real.h"
#include "datatypes/forte_lreal.h"
#include "datatypes/forte_any_int.h"
#include "datatypes/forte_any_bit.h"
#include "../arch/devlog.h"
#include "datatypes/forte_string.h"
//bring in the type conversion functions
#include "convert_functions.h"

#ifdef VXWORKS
#define tanf(x) tan(x)
#define log10f(x) log10(x)
#define logf(x) log(x)
#define cosf(x) cos(x)
#define atanf(x) atan(x)
#define asinf(x) asin(x)
#define acosf(x) acos(x)
#define expf(x) exp(x)
#define sinf(x) sin(x)
#define sqrtf(x) sqrt(x)
#endif

#ifdef FORTE_USE_WSTRING_DATATYPE
#include "datatypes/forte_wstring.h"
#endif

/* numeric functions
 * absolute value
 *            +----------+
 *         	  |    ABS   |
 * ANY_NUM ---| IN   OUT |--- ANY_NUM
 *            +----------+
*/
template<typename T>
const T ABS(const T& pa_roIN){
	return (0 > pa_roIN) ? T(pa_roIN * (-1)) : T((pa_roIN));
}

//CIEC_ANY::TLargestIntValueType ABS(CIEC_ANY::TLargestIntValueType pa_oIN){
//  return (0 > pa_oIN) ? (pa_oIN * -1) : pa_oIN;
//}


/* square root
 *             +----------+
 *   	         |   SQRT   |
 * ANY_REAL ---| IN   OUT |--- ANY_REAL
 *             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL SQRT(const CIEC_REAL &pa_roIN){
    return CIEC_REAL(sqrtf(pa_roIN));
  }

#ifdef FORTE_USE_64BIT_DATATYPES
  inline const CIEC_LREAL SQRT(const CIEC_LREAL &pa_roIN){
    return CIEC_LREAL(sqrt(pa_roIN));
  }
#endif

#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* natural logarithm
*             +----------+
*   		      |    LN    |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL LN(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(logf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL LN(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(log(pa_roIN));
    }
  #endif

#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Logarithm base 10
*             +----------+
*   		      |    LOG   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL LOG(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(log10f(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL LOG(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(log10(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* sine
*             +----------+
*   		      |    SIN   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL SIN(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(sinf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL SIN(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(sin(pa_roIN));
    }
  #endif

#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* cosine in radians
*             +----------+
*   		      |    COS   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL COS(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(cosf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL COS(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(cos(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* tangens in radians
*             +----------+
*   	    	  |    TAN   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL TAN(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(tanf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL TAN(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(tan(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Principal arc sine
*             +----------+
*   		      |   ASIN   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL ASIN(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(asinf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL ASIN(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(asin(pa_roIN));
    }
  #endif

#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Principal arc cosine
*             +----------+
*   	     	  |   ACOS   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL ACOS(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(acosf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL ACOS(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(acos(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Principal arc tangens
*             +----------+
*   		      |   ATAN   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL ATAN(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(atanf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL ATAN(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(atan(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Natural exponential
*             +----------+
*   		      |    EXP   |
* ANY_REAL ---| IN   OUT |--- ANY_REAL
*             +----------+
*/
#ifdef FORTE_USE_REAL_DATATYPE
  inline const CIEC_REAL EXP(const CIEC_REAL &pa_roIN){
      return CIEC_REAL(expf(pa_roIN));
    }

  #ifdef FORTE_USE_64BIT_DATATYPES
    inline const CIEC_LREAL EXP(const CIEC_LREAL &pa_roIN){
      return CIEC_LREAL(exp(pa_roIN));
    }
  #endif
#endif //#ifdef FORTE_USE_REAL_DATATYPE

/* Bit string functions
 * ANY_BIT (LWORD, DWORD, WORD, BYTE, BOOL)
 * ANY_INT (LINT, DINT, INT, SINT, ULINT, UDINT, UINT, USINT)
 *            +-----+
 *            | *** |
 * ANY_BIT ---|IN   |--- ANY_BIT
 * ANY_INT ---|N    |
 *            +-----+
 */
#ifdef FORTE_USE_64BIT_DATATYPES
	template<typename T> const T  ROL(const T& pa_roIn, const CIEC_ULINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)((pa_roIn << pa_roN.getUnsignedValue()) | (pa_roIn >> (sizeof(typename T::TValueType)*8 - pa_roN.getUnsignedValue()))));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}

	template<typename T> const T  ROR(const T& pa_roIn, const CIEC_ULINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)((pa_roIn >> pa_roN.getUnsignedValue()) | (pa_roIn << (sizeof(typename T::TValueType)*8 - pa_roN.getUnsignedValue()))));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}

	template<typename T> const T  SHL(const T& pa_roIn, const CIEC_ULINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		 return T((typename T::TValueType)(pa_roIn << pa_roN.getUnsignedValue()));
	   } DEVLOG_ERROR("value of input N is less than zero");
	   return T((typename T::TValueType)(0));
	}

	template<typename T> const T  SHR(const T& pa_roIn, const CIEC_ULINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)(pa_roIn >> pa_roN.getUnsignedValue()));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}
#else
	template<typename T> const T  ROL(const T& pa_roIn, const CIEC_UDINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)((pa_roIn << pa_roN.getUnsignedValue()) | (pa_roIn >> (sizeof(typename T::TValueType)*8 - pa_roN.getUnsignedValue()))));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}

	template<typename T> const T  ROR(const T& pa_roIn, const CIEC_UDINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)((pa_roIn >> pa_roN.getUnsignedValue()) | (pa_roIn << (sizeof(typename T::TValueType)*8 - pa_roN.getUnsignedValue()))));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}

	template<typename T> const T  SHL(const T& pa_roIn, const CIEC_UDINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		 return T((typename T::TValueType)(pa_roIn << pa_roN.getUnsignedValue()));
	   } DEVLOG_ERROR("value of input N is less than zero");
	   return T((typename T::TValueType)(0));
	}

	template<typename T> const T  SHR(const T& pa_roIn, const CIEC_UDINT& pa_roN){
	  if((true == pa_roN.isSigned() && 0 <= pa_roN.getSignedValue()) || false == pa_roN.isSigned()){
		return T((typename T::TValueType)(pa_roIn >> pa_roN.getUnsignedValue()));
	  } DEVLOG_ERROR("value of input N is less than zero");
	  return T((typename T::TValueType)(0));
	}
#endif //#ifdef FORTE_USE_64BIT_DATATYPES

/* Selection and comparison functions */

/*         +-----+
           | AND |
 ANY_BIT --|IN1  |--- ANY_BIT
       : --|     |
 ANY_BIT --|INn  |
           +-----+                          */
template<typename T> const T AND(const T& pa_roIN1, const T& pa_roIN2){
  return T((typename T::TValueType)(pa_roIN1 & pa_roIN2));
}

/*         +-----+
           | OR  |
 ANY_BIT --|IN1  |--- ANY_BIT
       : --|     |
 ANY_BIT --|INn  |
           +-----+                          */
template<typename T> const T OR(const T& pa_roIN1, const T& pa_roIN2){
  return T((typename T::TValueType)(pa_roIN1 | pa_roIN2));
}

/*         +-----+
           | XOR |
 ANY_BIT --|IN1  |--- ANY_BIT
       : --|     |
 ANY_BIT --|INn  |
           +-----+                          */
template<typename T> const T XOR(const T& pa_roIN1, const T& pa_roIN2){
  return T((typename T::TValueType)(pa_roIN1 ^ pa_roIN2));
}

/*         +-----+
           | NOT |
 ANY_BIT --|IN1  |--- ANY_BIT
       : --|     |
 ANY_BIT --|INn  |
           +-----+                          */
template<typename T> const T NOT(const T& pa_roIN){
  if(pa_roIN.getDataTypeID() == CIEC_ANY::e_BOOL){
      return T((typename T::TValueType)(!pa_roIN));
  }
  else{
      return T((typename T::TValueType)(~pa_roIN));
  }

}

/*                +-----+
                  | GT  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL GT(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 > pa_roIN2){
    temp = true;
  }
  return temp;
}

/*                +-----+
                  | EQ  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL EQ(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 == pa_roIN2){
    temp = true;
  }
  return temp;
}

/*                +-----+
                  | GE  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL GE(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 >= pa_roIN2){
    temp = true;
  }
  return temp;
}

/*                +-----+
                  | LE  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL LE(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 <= pa_roIN2){
    temp = true;
  }
  return temp;
}

/*                +-----+
                  | LT  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL LT(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 < pa_roIN2){
    temp = true;
  }
  return temp;
}

/*                +-----+
                  | NE  |
 ANY_ELEMENTARY --|IN1  |--- BOOL
              : --|     |
 ANY_ELEMENTARY --|INn  |
                  +-----+                   */
template<typename T> const CIEC_BOOL NE(const T& pa_roIN1, const T& pa_roIN2){
  CIEC_BOOL temp = false;
  if(pa_roIN1 != pa_roIN2){
    temp = true;
  }
  return temp;
}

/*
       +-----+
       | SEL |
 BOOL--|G    |--ANY
 ANY---|IN0  |
 ANY---|IN1  |
       +-----+                */
template<typename T> const T SEL(const CIEC_BOOL &G, const T& IN0, const T& IN1){
  return (G.operator bool()) ? IN1 : IN0;
}

/*               +-----+
                 | MAX |
 ANY_ELEMENTARY--|     |--ANY_ELEMENTARY
            : ---|     |
 ANY_ELEMENTARY--|     |
                 +-----+                        */
template<typename T> const T MAX(const T& pa_roIN1, const T& pa_roIN2){
  if(pa_roIN1 > pa_roIN2){
    return pa_roIN1;
  }
  else{
    return pa_roIN2;
  }
}

/*               +-----+
                 | MIN |
 ANY_ELEMENTARY--|     |--ANY_ELEMENTARY
        :     ---|     |
 ANY_ELEMENTARY--|     |
                 +-----+                                */
template<typename T> const T MIN(const T& pa_roIN1, const T& pa_roIN2){
  if(pa_roIN1 < pa_roIN2){
    return pa_roIN1;
  }
  else{
    return pa_roIN2;
  }
}

/*               +-------+
                 | LIMIT |
 ANY_ELEMENTARY--|MN     |--ANY_ELEMENTARY
 ANY_ELEMENTARY--|IN     |
 ANY_ELEMENTARY--|MX     |
                 +-------+                      */
template<typename T> const T LIMIT(const T& pa_roMN, const T& pa_roIN, const T& pa_roMX){
  return MIN(MAX(pa_roIN, pa_roMN), pa_roMX);
}

/*        +-----+
          | MUX |
 ANY_INT--|K    |----ANY
 ANY------|     |
  : ------|     |
 ANY------|     |
          +-----+              */


/*        +-----+
          | MOD |
 ANY_INT--|     |--ANY_NUM
  :    ---|     |
 ANY_INT--|     |
          +-----+                                */
template<typename T> const T MOD(const T& pa_roIN1, const T& pa_roIN2){
	if(0 == pa_roIN2){
		return static_cast<typename T::TValueType>(0);
	}
	return static_cast<typename T::TValueType>(pa_roIN1.getSignedValue() % pa_roIN2.getSignedValue());
}

/*     +------+
       | MOVE |
 ANY --|      |-- ANY
  : ---|      |
 ANY --|      |
       +------+       */
template<typename T> const T MOVE(const T& pa_roIN){
	return static_cast<typename T::TValueType>(pa_roIN);
}

/*     +------+
       | EXPT |
 ANY --|      |-- ANY
  : ---|      |
 ANY --|      |
       +------+       */
template<typename T> const T EXPT(const T& pa_roIN1, const T& pa_roIN2){
	return static_cast<typename T::TValueType>(pow(pa_roIN1, pa_roIN2));
}

/*              +-----+
                | ADD |
 ANY_MAGNITUDE--|     |--ANY_MAGNITUDE
        :    ---|     |
 ANY_MAGNITUDE--|     |
                +-----+                                */
template<typename T> const T ADD(const T& pa_roIN1, const T& pa_roIN2){
  return pa_roIN1 + pa_roIN2;
}

/*        +-----+
          | MUL |
 ANY_NUM--|     |--ANY_NUM
       ---|     |
 ANY_NUM--|     |
          +-----+                                */
template<typename T> const T MUL(const T& pa_roIN1, const T& pa_roIN2){
  return pa_roIN1 * pa_roIN2;
}

/*              +-----+
                | SUB |
 ANY_MAGNITUDE--|     |--ANY_MAGNITUDE
 ANY_MAGNITUDE--|     |
                +-----+                                */
template<typename T> const T SUB(const T& pa_roIN1, const T& pa_roIN2){
  return pa_roIN1 - pa_roIN2;
}

/*        +-----+
          | DIV |
 ANY_NUM--|     |--ANY_NUM
 ANY_NUM--|     |
          +-----+                                */
template<typename T> const T DIV(const T& pa_roIN1, const T& pa_roIN2){
  T temp = static_cast<typename T::TValueType>(pa_roIN1) / static_cast<typename T::TValueType>(pa_roIN2);
  return temp;
}

/*         +-------+
           | TRUNC |
 ANY_REAL--|       |--ANY_INT
           +-------+*/
#ifdef FORTE_USE_REAL_DATATYPE
TForteInt32 TRUNC(const CIEC_REAL& pa_roIN);
#ifdef FORTE_USE_LREAL_DATATYPE
TForteInt64 TRUNC(const CIEC_LREAL& pa_roIN);
#endif
#endif

#ifdef FORTE_USE_64BIT_DATATYPES
/*       +--------------+
         | ADD_TOD_TIME |
  TOD ---|IN1           |--- TOD
 TIME ---|IN2           |
         +--------------+*/
const CIEC_TIME_OF_DAY ADD_TOD_TIME(const CIEC_TIME_OF_DAY& pa_roIN1, const CIEC_TIME& pa_roIN2);

/*       +-------------+
         | ADD_DT_TIME |
   DT ---|IN1          |--- DT
 TIME ---|IN2          |
         +-------------+*/
const CIEC_DATE_AND_TIME ADD_DT_TIME(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_TIME& pa_roIN2);

/*       +--------------+
         | SUB_TOD_TIME |
  TOD ---|IN1           |--- TOD
 TIME ---|IN2           |
         +--------------+*/
const CIEC_TIME_OF_DAY SUB_TOD_TIME(const CIEC_TIME_OF_DAY& pa_roIN1, const CIEC_TIME& pa_roIN2);

/*       +-------------+
         | SUB_DT_TIME |
   DT ---|IN1          |--- DT
 TIME ---|IN2          |
         +-------------+*/
const CIEC_DATE_AND_TIME SUB_DT_TIME(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_TIME& pa_roIN2);

/*       +-----------+
         | SUB_DT_DT |
   DT ---|IN1        |--- TIME
   DT ---|IN2        |
         +-----------+*/
const CIEC_TIME SUB_DT_DT(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_DATE_AND_TIME& pa_roIN2);

/*       +-------------+
         | SUB_TOD_TOD |
  TOD ---|IN1          |--- TIME
  TOD ---|IN2          |
         +-------------+*/
const CIEC_TIME SUB_TOD_TOD(const CIEC_TIME_OF_DAY &pa_roIN1, const CIEC_TIME_OF_DAY &pa_roIN2);

/*       +---------------+
         | SUB_DATE_DATE |
 DATE ---|IN1            |--- TIME
 DATE ---|IN2            |
         +---------------+*/
const CIEC_TIME SUB_DATE_DATE(const CIEC_DATE &pa_roIN1, const CIEC_DATE &pa_roIN2);

/*          +-----------------+
            | CONCAT_DATE_TOD |
    DATE ---|IN1              |--- DT
     TOD ---|IN2              |
            +-----------------+*/
const CIEC_DATE_AND_TIME CONCAT_DATE_TOD(const CIEC_DATE& pa_roIN1, const CIEC_TIME_OF_DAY& pa_roIN2);
#endif

/*          +---------+
            | MULTIME |
    TIME ---|IN1      |--- TIME
 ANY_NUM ---|IN2      |
            +---------+*/
#ifdef FORTE_USE_64BIT_DATATYPES
template<typename T> const CIEC_TIME MULTIME(const CIEC_TIME& pa_roIN1, const T& pa_roIN2){
  return static_cast<TForteInt64>(pa_roIN1 * pa_roIN2);
}
#else
template<typename T> const CIEC_TIME MULTIME(const CIEC_TIME& pa_roIN1, const T& pa_roIN2){
  return static_cast<TForteInt32>(pa_roIN1 * pa_roIN2);
}
#endif

/*          +---------+
            | DIVTIME |
    TIME ---|IN1      |--- TIME
 ANY_NUM ---|IN2      |
            +---------+*/
#ifdef FORTE_USE_64BIT_DATATYPES
template<typename T> const CIEC_TIME DIVTIME(const CIEC_TIME& pa_roIN1, const T& pa_roIN2){
  if(0 != pa_roIN2){
    return static_cast<TForteInt64>(pa_roIN1 / pa_roIN2);
  }else{
    return pa_roIN1;
  }
}
#else
template<typename T> const CIEC_TIME DIVTIME(const CIEC_TIME& pa_roIN1, const T& pa_roIN2 ){
  if(0 != pa_roIN2){
    return static_cast<TForteInt32>(pa_roIN1 / pa_roIN2);
  }else{
    return pa_roIN1;
  }
}
#endif

/* Character string functions
 * ANY_STRING (STRING, WSTRING)
 * ANY_INT (LINT, DINT, INT, SINT, ULINT, UDINT, UINT, USINT)
 * String length function
 *             +-----+
 * ANY_STRING--| LEN |--ANY_INT
 *             +-----+
 */
#ifdef FORTE_USE_64BIT_DATATYPES
template<typename T> CIEC_ULINT LEN(const T& pa_rsVal){
  return CIEC_ULINT(pa_rsVal.length());
}
#else
template<typename T> CIEC_UDINT LEN(const T& pa_rsVal){
  return CIEC_UDINT(pa_rsVal.length());
}
#endif

/* Leftmost L characters of IN
 *             +------+
 *             | LEFT |
 * ANY_STRING--|IN    |--ANY_STRING
 * ANY_INT-----|L     |
 *             +------+
 */
template<typename T> const T LEFT(const T& pa_rsIn, const CIEC_ANY_INT& pa_roL){
  if(true == pa_roL.isSigned() && 0 > pa_roL.getSignedValue()){
    DEVLOG_ERROR("value of input L is less than zero");
    return pa_rsIn;
  }
  else{
    if(pa_rsIn.length() < pa_roL.getUnsignedValue()){
      DEVLOG_ERROR("string shorter than input L");
      return pa_rsIn;
    }
    else{
      T temp;
      temp.reserve(static_cast<TForteUInt16>(pa_roL.getUnsignedValue()));
      memcpy(temp.getValue(), pa_rsIn.getValue(), static_cast<TForteUInt16>(pa_roL.getUnsignedValue()));
      temp.getValue()[pa_roL.getUnsignedValue()] = '\0';
      return temp.getValue();
    }
  }
}

/* Rightmost L characters of IN
 *             +-------+
 *             | RIGHT |
 * ANY_STRING--|IN     |--ANY_STRING
 * ANY_INT-----|L      |
 *             +-------+
 */
template<typename T> const T RIGHT(const T& pa_rsIn, const CIEC_ANY_INT& pa_roL){
  if(true == pa_roL.isSigned() && 0 > pa_roL.getSignedValue()){
    DEVLOG_ERROR("value of input L is less than zero");
    return pa_rsIn;
  }
  else{
    if(pa_rsIn.length() < pa_roL.getUnsignedValue()){
      DEVLOG_ERROR("string shorter than input L");
      return pa_rsIn;
    }
    else{
      T temp;
      temp.reserve(static_cast<TForteUInt16>(pa_roL.getUnsignedValue()));
      memcpy(temp.getValue(), pa_rsIn.getValue() + (pa_rsIn.length() - static_cast<TForteUInt16>(pa_roL.getUnsignedValue())), static_cast<TForteUInt16>(pa_roL.getUnsignedValue()));
      temp.getValue()[pa_roL.getUnsignedValue()] = '\0';
      return temp.getValue();
    }
  }
}

/* L characters of IN, beginning at the P-th
 *             +-------+
 *             |  MID  |
 * ANY_STRING--|IN     |--ANY_STRING
 * ANY_INT-----|L      |
 * ANY_INT-----|P      |
 *             +-------+
 */
template<typename T> const T MID(const T& pa_rsIn, const CIEC_ANY_INT& pa_roL, const CIEC_ANY_INT& pa_roP){
  if(true == pa_roP.isSigned() && 0 > pa_roP.getSignedValue()){
    DEVLOG_ERROR("value of input P is less than zero\n");
    return pa_rsIn;
  }
  else{
    CIEC_INT len_right = static_cast<TForteInt16> (pa_rsIn.length() - pa_roP.getUnsignedValue() + 1);
    CIEC_INT len_left = static_cast<TForteInt16>(pa_roL.getUnsignedValue());
    return LEFT(RIGHT(pa_rsIn, len_right), len_left);
  }
}

/* Extensible concatenation
 *              +--------+
 *              | CONCAT |
 * ANY_STRING---|        |--ANY_STRING
 *        :  ---|        |
 * ANY_STRING---|        |
 *              +--------+
 */
/*
 Example:
 A := CONCAT('AB','CD','E') ;
 is equivalent to
 A := 'ABCDE' ;
 *
 */
template<typename T> const T CONCAT(const T& pa_rsIn1, const T& pa_rsIn2){
  T temp;
  temp.reserve(static_cast<TForteUInt16>(pa_rsIn1.length() + pa_rsIn2.length()));
  strcpy(temp.getValue(), pa_rsIn1.getValue());
  strcat(temp.getValue(), pa_rsIn2.getValue());
  return temp.getValue();
}

/* Insert IN2 into IN1 after the P-th charaolcter position
 *             +--------+
 *             | INSERT |
 * ANY_STRING--|IN1     |--ANY_STRING
 * ANY_STRING--|IN2     |
 * ANY_INT-----|P       |
 *             +--------+
 */
template<typename T> const T INSERT(const T& pa_rsIn1, const T& pa_rsIn2, const CIEC_ANY_INT& pa_roP){
  if(CIEC_UINT::scm_nMaxVal < (pa_rsIn1.length() + pa_rsIn2.length())){
    DEVLOG_ERROR("result would be longer than maximum allowed length");
    return pa_rsIn1;
  }
  CIEC_INT pos_right = static_cast<TForteInt16>(pa_rsIn1.length() - pa_roP.getSignedValue());
  return CONCAT(CONCAT(LEFT(pa_rsIn1, pa_roP), pa_rsIn2), RIGHT(pa_rsIn1, pos_right));
}

/* Delete L characters of IN, beginning at the P-th character position
 *             +--------+
 *             | DELETE |
 * ANY_STRING--|IN      |--ANY_STRING
 * ANY_INT-----|L       |
 * ANY_INT-----|P       |
 *             +--------+
 *
 Example:
 A := DELETE(IN:='ABXYC',L:=2, P:=3) ;
 is equivalent to
 A := 'ABC' ;*/

#ifdef _WIN32
#undef DELETE
#endif

template<typename T> const T DELETE(const T& pa_rsIn, const CIEC_ANY_INT& pa_roL, const CIEC_ANY_INT& pa_roP){
  CIEC_INT pos_right = static_cast<TForteInt16>(pa_rsIn.length() - (pa_roL.getSignedValue() + pa_roP.getSignedValue() - 1));
  CIEC_INT pos_left = static_cast<TForteInt16>(pa_roP.getSignedValue() - 1);
  return CONCAT(LEFT(pa_rsIn, pos_left), RIGHT(pa_rsIn, pos_right));
}

/*           +---------+
             | REPLACE |
 ANY_STRING--|IN1      |--ANY_STRING
 ANY_STRING--|IN2      |
 ANY_INT-----|L        |
 ANY_INT-----|P        |
             +---------+
 Replace L characters of IN1 by IN2, starting at the P-th character position
 Example:
 A := REPLACE(IN1:='ABCDE',IN2:='X',
 L:=2, P:=3) ;
 is equivalent to
 A := 'ABXE' ;*/
template<typename T> const T REPLACE(const T& pa_rsIn1, const T& pa_rsIn2, const CIEC_ANY_INT& pa_roL, const CIEC_ANY_INT& pa_roP){
  CIEC_INT pos_right = static_cast<TForteInt16>(pa_rsIn1.length() - (pa_roL.getSignedValue() + pa_roP.getSignedValue() - 1));
  CIEC_INT pos_left = static_cast<TForteInt16>(pa_roP.getSignedValue() - 1);
  return CONCAT(CONCAT(LEFT(pa_rsIn1, pos_left), pa_rsIn2), RIGHT(pa_rsIn1, pos_right));
}

/*           +-----------+
             |   FIND    |
 ANY_STRING--|IN1    OUT |--ANY_INT
 ANY_STRING--|IN2        |
             +-----------+
 Find the character position of the beginning of the first occurrence of IN2 in IN1.  If no occurrence of IN2 is found, then OUT := 0.
 Example:
 A := FIND(IN1:='ABCBC',IN2:='BC') ;
 is equivalent to A := 2 ;
 */
template<typename T> CIEC_ANY_INT FIND(const T& pa_rsIn1, const T& pa_rsIn2){
  const char* pc_Find = strstr(pa_rsIn1.getValue(), pa_rsIn2.getValue());
  CIEC_ANY_INT temp;
  if (NULL != pc_Find)
  {
	  temp.setSignedValue(pc_Find - pa_rsIn1.getValue());
  } 
  else
  {
	  temp.setSignedValue(0);
  }
  return temp;
}

/*           +-----------+
             |  TOUPPER  |
 ANY_STRING--|IN     OUT |--ANY_STRING    |
             +-----------+
 Changes all characters of an ANY_STRING to its upper case equivalent.
 Example:
 A := TOUPPER(IN1:='abcAB');
 is equivalent to A := 'ABCAB' ;
 */
template<typename T> const T TOUPPER(const T& pa_rsIn){
  T temp;
  temp.reserve(static_cast<TForteUInt16>(pa_rsIn.length()));
  const char* orig = pa_rsIn.getValue();
  char* upper = temp.getValue();
  for (unsigned int i = 0; i <=pa_rsIn.length(); ++i)
  {
	  upper[i] = toupper(orig[i]);
  }
  return temp;
}

/*           +-----------+
             |  TOLOWER  |
 ANY_STRING--|IN     OUT |--ANY_STRING    |
             +-----------+
 Changes all characters of an ANY_STRING to its upper case equivalent.
 Example:
 A := TOUPPER(IN1:='abcAB');
 is equivalent to A := 'abcab' ;
 */
template<typename T> const T TOLOWER(const T& pa_rsIn){
  T temp;
  temp.reserve(static_cast<TForteUInt16>(pa_rsIn.length()));
  const char* orig = pa_rsIn.getValue();
  char* upper = temp.getValue();
  for (unsigned int i = 0; i <=pa_rsIn.length(); ++i)
  {
	  upper[i] = tolower(orig[i]);
  }
  return temp;
}
#endif /* IEC61131_FUNCTIONS_H_ */
