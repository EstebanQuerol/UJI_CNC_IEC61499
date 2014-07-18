/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "forte_date.h"
#include "../../arch/timerha.h"
#if defined(WINCE)
#include <wce_time.h>
#endif

DEFINE_FIRMWARE_DATATYPE(DATE, g_nStringIdDATE)

int CIEC_DATE::fromString(const char *pa_pacValue){
  // 2007-12-21
  struct tm tm;
  char *acBuffer = const_cast<char*>(pa_pacValue);

  memset(&tm, 0, sizeof(tm));

  if('d' == tolower(*acBuffer)){
    acBuffer++;
    if(('a' == tolower(acBuffer[0])) && ('t' == tolower(acBuffer[1])) && ('e' == tolower(acBuffer[2]))){
      acBuffer += 3;
    }
    if('#' != *acBuffer){
      return -1;
    }
    acBuffer++;
  }

  if('\0' != *acBuffer){
    //TODO think of using any elementary fromString function instead of strtoul
    tm.tm_year = ::strtoul(acBuffer, &acBuffer, 10) - 1900;
    if('-' == *acBuffer){
      ++acBuffer;
      tm.tm_mon = ::strtoul(acBuffer, &acBuffer, 10) - 1;
      if('-' == *acBuffer){
        ++acBuffer;
        tm.tm_mday = ::strtoul(acBuffer, &acBuffer, 10);
      }
      else{
         return -1;
       }
    }
    else{
       return -1;
     }
  }
  else{
    return -1;
  }

  // If we are east of the UTC, adjust the time now - otherwise
  // we might fall before time representable by time_t. Otherwise adjust
  // after converting - it's easier than to step back in struct tm
  TForteInt32 tzOffset = CIEC_ANY_DATE::getTimeZoneOffset();
  if (tzOffset > 0) {
    tm.tm_hour = tzOffset / 60;
    tm.tm_min =  tzOffset % 60;
  }

  if(!setDateAndTime(tm, 0)){
    return -1;
  }

  if (tzOffset < 0){
    setTUINT64( getTUINT64() + (60*tzOffset * 1000ULL));
  }
  return acBuffer - pa_pacValue;
}

int CIEC_DATE::toString(char* pa_pacValue, unsigned int pa_nBufferSize) const{
  int nRetVal = -1;

  struct tm *ptm = getTimeStruct();

  if (ptm == 0)
    return -1;

#ifdef WIN32
    nRetVal = _snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d", 1900+ptm->tm_year, ptm->tm_mon+1, ptm->tm_mday);
#else
    nRetVal = snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d", 1900 + ptm->tm_year, ptm->tm_mon + 1, ptm->tm_mday);
#endif
    if((nRetVal < -1) || (nRetVal >= (int) pa_nBufferSize)){
      nRetVal = -1;
    }
  return nRetVal;
}
