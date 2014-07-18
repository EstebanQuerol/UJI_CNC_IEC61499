/*******************************************************************************
 * Copyright (c) 2007 - 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "iec61131_functions.h"

/*         +-------+
           | TRUNC |
 ANY_REAL--|       |--ANY_INT
           +-------+*/
#ifdef FORTE_USE_REAL_DATATYPE
TForteInt32 TRUNC(const CIEC_REAL& pa_roIN){
  return static_cast<TForteInt32>(pa_roIN);
}

#ifdef FORTE_USE_LREAL_DATATYPE
TForteInt64 TRUNC(const CIEC_LREAL& pa_roIN){
  return static_cast<TForteInt64>(pa_roIN);
}
#endif
#endif

#ifdef FORTE_USE_64BIT_DATATYPES
/*       +--------------+
         | ADD_TOD_TIME |
  TOD ---|IN1           |--- TOD
 TIME ---|IN2           |
         +--------------+*/
const CIEC_TIME_OF_DAY ADD_TOD_TIME(const CIEC_TIME_OF_DAY& pa_roIN1, const CIEC_TIME& pa_roIN2){
  return static_cast<TForteUInt64>(pa_roIN1 + pa_roIN2.getInMiliSeconds());
}

/*       +-------------+
         | ADD_DT_TIME |
   DT ---|IN1          |--- DT
 TIME ---|IN2          |
         +-------------+*/
const CIEC_DATE_AND_TIME ADD_DT_TIME(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_TIME& pa_roIN2){
  return static_cast<TForteUInt64>(pa_roIN1 + pa_roIN2.getInMiliSeconds());
}

/*       +--------------+
         | SUB_TOD_TIME |
  TOD ---|IN1           |--- TOD
 TIME ---|IN2           |
         +--------------+*/
const CIEC_TIME_OF_DAY SUB_TOD_TIME(const CIEC_TIME_OF_DAY& pa_roIN1, const CIEC_TIME& pa_roIN2){
  return static_cast<TForteUInt64>(pa_roIN1 - pa_roIN2.getInMiliSeconds());
}

/*       +-------------+
         | SUB_DT_TIME |
   DT ---|IN1          |--- DT
 TIME ---|IN2          |
         +-------------+*/
const CIEC_DATE_AND_TIME SUB_DT_TIME(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_TIME& pa_roIN2){
  return static_cast<TForteUInt64>(pa_roIN1 - pa_roIN2.getInMiliSeconds());
}

/*       +-----------+
         | SUB_DT_DT |
   DT ---|IN1        |--- TIME
   DT ---|IN2        |
         +-----------+*/
const CIEC_TIME SUB_DT_DT(const CIEC_DATE_AND_TIME& pa_roIN1, const CIEC_DATE_AND_TIME& pa_roIN2){
  CIEC_TIME temp;
  temp.setFromMiliSeconds(pa_roIN1 - pa_roIN2);
  return temp;
}

/*       +-------------+
         | SUB_TOD_TOD |
  TOD ---|IN1          |--- TIME
  TOD ---|IN2          |
         +-------------+*/
const CIEC_TIME SUB_TOD_TOD(const CIEC_TIME_OF_DAY &pa_roIN1, const CIEC_TIME_OF_DAY &pa_roIN2){
  CIEC_TIME temp;
  temp.setFromMiliSeconds(pa_roIN1 - pa_roIN2);
  return temp;
}

/*       +---------------+
         | SUB_DATE_DATE |
 DATE ---|IN1            |--- TIME
 DATE ---|IN2            |
         +---------------+*/
const CIEC_TIME SUB_DATE_DATE(const CIEC_DATE &pa_roIN1, const CIEC_DATE &pa_roIN2){
  CIEC_TIME temp;
  temp.setFromMiliSeconds(pa_roIN1 - pa_roIN2);
  return temp;
}

/*          +-----------------+
            | CONCAT_DATE_TOD |
    DATE ---|IN1              |--- DT
     TOD ---|IN2              |
            +-----------------+*/
const CIEC_DATE_AND_TIME CONCAT_DATE_TOD(const CIEC_DATE& pa_roIN1, const CIEC_TIME_OF_DAY& pa_roIN2){
  CIEC_DATE_AND_TIME retVal;

  struct tm *pstTime = pa_roIN1.getTimeStruct();

  time_t t = static_cast<time_t>( pa_roIN2 / 1000ULL);
  pstTime->tm_hour = (int) (t / 3600);
  pstTime->tm_min = (int) ((t % 3600) / 60);
  pstTime->tm_sec = (int) (t % 60);

  retVal.setDateAndTime(*pstTime, pa_roIN2.getMilliSeconds());
  return retVal;
}

#endif
