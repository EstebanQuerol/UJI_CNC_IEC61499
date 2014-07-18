/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _DATATYPES_H_
#define _DATATYPES_H_


// this define is required to get the limit macros
#define __STDC_LIMIT_MACROS

#include <stdint.h>

/*! \ingroup FORTE-HAL
 *  \brief This are the device-independent data types used by FORTE.
 */

/***************************************************************************
 type definitions
 ***************************************************************************/

typedef uint8_t TForteByte; /**< 8 bit unsigned */
typedef uint16_t TForteWord; /**< 16 bit unsigned */
typedef uint32_t TForteDWord; /**< 32 bit unsigned */
typedef uint64_t TForteLWord; /**< 64 bit unsigned */

typedef int8_t TForteInt8; /**< 8 bit signed */
typedef int16_t TForteInt16; /**< 16 bit signed */
typedef int32_t TForteInt32; /**< 32 bit signed */
typedef int64_t TForteInt64; /**< 64 bit signed */

typedef uint8_t TForteUInt8; /**< 8 bit unsigned */
typedef uint16_t TForteUInt16; /**< 16 bit unsigned */
typedef uint32_t TForteUInt32; /**< 32 bit unsigned */
typedef uint64_t TForteUInt64; /**< 64 bit unsigned */

typedef float TForteFloat; /**< single precision IEEE float (32 Bit) */
typedef double TForteDFloat; /**< double precision IEEE float (64 bit) */

const unsigned int cg_nIdentifierLength = 32; //!<This value holds the length an identifier may have on order that it is unique. Identifiers may be FB-Type Names, FB-Names, var names,...

typedef char TIdentifier[cg_nIdentifierLength + 1]; //!<Type to hold an identifier during runtime. The +1 is for holding a trailing \\0

const unsigned int cg_unInvalidPortId = 255; //!< \ingroup CORE constant defining the max possible number of an FB Port (even or data, in or output)

#endif // DATATYPES_H_
