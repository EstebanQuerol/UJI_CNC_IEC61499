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
#include "forte_time_of_day.h"
#include "../../arch/timerha.h"

DEFINE_FIRMWARE_DATATYPE(TIME_OF_DAY, g_nStringIdTIME_OF_DAY)

int CIEC_TIME_OF_DAY::fromString(const char *pa_pacValue){
  // 15:00:00.000
  struct tm tm;
  int msec = 0;
  char *acBuffer = const_cast<char*>(pa_pacValue);

  memset(&tm, 0, sizeof(tm));

  if('t' == tolower(*acBuffer) ){
    if(('o' == tolower(acBuffer[1])) && ('d' == tolower(acBuffer[2]))){
      acBuffer += 3;
    }
    else{
      //TODO maybe allow to turn this check of for small devices
      if((0 == strncmp("time_of_day", acBuffer, 11)) ||
         (0 == strncmp("TIME_OF_DAY", acBuffer, 11))){
        acBuffer += 11;
      }
    }

    if('#' != *acBuffer){
      return -1;
    }
    acBuffer++;
  }

  if('\0' != *acBuffer){
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
          while (isdigit(*acBuffer)) {
            msec = 10*msec + forte::core::util::charDigitToInt(*acBuffer);
            ++acBuffer;
            ++nNums;
          }

          if(nNums < 3){
            for (unsigned int i=nNums; i < 3; ++i)
              msec *= 10;
          }
          else{
            for (unsigned int i = 0; i < (nNums - 3); ++i)
              msec /= 10;
          }
        }
      }
    }
    else{
      if('\0' != *acBuffer){
        return -1;
      }
    }
  }
  else{
    return -1;
  }

  setTUINT64((tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_sec) * 1000ULL + msec);

  return acBuffer - pa_pacValue;
}

int CIEC_TIME_OF_DAY::toString(char* pa_pacValue, unsigned int pa_nBufferSize) const{
  int nRetVal = -1;
  TForteUInt64 ntoStingBuffer = getTUINT64();
  time_t t = static_cast<time_t>(ntoStingBuffer / 1000);

#ifdef WIN32
    nRetVal = _snprintf(pa_pacValue, pa_nBufferSize, "%02d:%02d:%02d.%03d",
      (int) (t / 3600),
      (int) ((t % 3600) / 60),
      (int) (t % 60),
      (int) (ntoStingBuffer % 1000));
#else
    nRetVal = snprintf(pa_pacValue, pa_nBufferSize, "%02d:%02d:%02d.%03d",
      (int) (t / 3600),
      (int) ((t % 3600) / 60),
      (int) (t % 60),
      (int) (ntoStingBuffer % 1000));
#endif
	if((nRetVal < -1) || (nRetVal >= (int) pa_nBufferSize)){
	  nRetVal = -1;
	}
  return nRetVal;
}

