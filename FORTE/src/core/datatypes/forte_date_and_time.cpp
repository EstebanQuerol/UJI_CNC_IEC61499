/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "forte_date_and_time.h"
#include "forte_date.h"
#include "forte_time_of_day.h"
#include "../../arch/timerha.h"

DEFINE_FIRMWARE_DATATYPE(DATE_AND_TIME, g_nStringIdDATE_AND_TIME)

int CIEC_DATE_AND_TIME::fromString(const char *pa_pacValue){
  // 2007-12-21-15:00:00.000
  int nRetVal = -1;
  char *acBuffer = const_cast<char*>(pa_pacValue);

  if('d' == tolower(*acBuffer)){
    if('t' == tolower(acBuffer[1])){
      acBuffer += 2;
    }
    else{
      //TODO maybe allow to turn this check of for small devices
      if((0 == strncmp("date_and_time", acBuffer, 13))
          || (0 == strncmp("DATE_AND_TIME", acBuffer, 13))){
        acBuffer += 13;
      }
    }

    if('#' != *acBuffer){
      return -1;
    }
    acBuffer++;
  }

  struct tm tm;
  unsigned int msec = 0;

  memset(&tm, 0, sizeof(tm));

  //Duplicate code the same as in forte date
  if('\0' != *acBuffer){
    tm.tm_year = forte::core::util::strtoul(acBuffer, &acBuffer, 10) - 1900;
    if('-' == *acBuffer){
      ++acBuffer;
      tm.tm_mon = forte::core::util::strtoul(acBuffer, &acBuffer, 10) - 1;
      if('-' == *acBuffer){
        ++acBuffer;
        tm.tm_mday = forte::core::util::strtoul(acBuffer, &acBuffer, 10);

        if('-' == *acBuffer){
          ++acBuffer;
          //duplicate code this one can be find in time of day
          tm.tm_hour = forte::core::util::strtoul(acBuffer, &acBuffer, 10);
          if(':' == *acBuffer){
            ++acBuffer;
            tm.tm_min = forte::core::util::strtoul(acBuffer, &acBuffer, 10);
            if(':' == *acBuffer){
              ++acBuffer;
              tm.tm_sec = forte::core::util::strtoul(acBuffer, &acBuffer, 10);
              if('.' == *acBuffer){
                unsigned int nNums = 0;
                ++acBuffer;
                while(isdigit(*acBuffer)){
                  msec = 10 * msec + forte::core::util::charDigitToInt(*acBuffer);
                  ++acBuffer;
                  ++nNums;
                }

                if(nNums < 3){
                  for(unsigned int i = nNums; i < 3; ++i)
                    msec *= 10;
                }
                else{
                  for(unsigned int i = 0; i < (nNums - 3); ++i)
                    msec /= 10;
                }
              }
              nRetVal = static_cast<int>(acBuffer - pa_pacValue);
            }
          }
        }
      }
    }
  }

  if(-1 != nRetVal){
    if(!setDateAndTime(tm, msec)){
      nRetVal = -1;
    }
  }

  return nRetVal;
}

int CIEC_DATE_AND_TIME::toString(char* pa_pacValue, unsigned int pa_nBufferSize) const{
  int nRetVal = -1;

  struct tm *ptm = getTimeStruct();

  if(0 != ptm){

#ifdef WIN32
    nRetVal = _snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d-%02d:%02d:%02d.%03d", 1900+ptm->tm_year, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, getMilliSeconds());
#else
    nRetVal =
        snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d-%02d:%02d:%02d.%03d", 1900
            + ptm->tm_year, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, getMilliSeconds());
#endif

    if((nRetVal < -1) || (nRetVal >= (int) pa_nBufferSize)){
      nRetVal = -1;
    }
  }
  return nRetVal;
}

int CIEC_DATE_AND_TIME::toGMTString(char* pa_pacValue, unsigned int pa_nBufferSize) const{
  int nRetVal = -1;

  TForteUInt64 nToStringBuffer = getTUINT64();
  time_t t = static_cast<time_t>(nToStringBuffer / 1000);
#if ! defined(WINCE)
  struct tm *ptm = gmtime(&t);
#else
  struct tm *ptm = wceex_gmtime(&t);

  if (ptm == 0)
  return -1;

#endif
#ifdef WIN32
  nRetVal = _snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d-%02d:%02d:%02d.%03d", 1900+ptm->tm_year, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, (int) (nToStringBuffer % 1000));
#else
  nRetVal =
      snprintf(pa_pacValue, pa_nBufferSize, "%04d-%02d-%02d-%02d:%02d:%02d.%03d", 1900
          + ptm->tm_year, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, (int) (nToStringBuffer
          % 1000));
#endif

  if((nRetVal < -1) || (nRetVal >= (int) pa_nBufferSize)){
    nRetVal = -1;
  }
  return nRetVal;
}

