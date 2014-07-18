/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/
#include <cyg/kernel/kapi.h>
#include <fortealloc.h>
#include <EMB_RMT_DEV.h>

#include "L_LED.h"
#include "L_S_PORT.h"
#include "avrctl.h"
#include "LMSUSBLayer.h"

externC void cyg_user_start(void);

void delay(unsigned int i){
  while(i){
    --i;
  }
}

const char * const g_acId = "fbdk[].usb[1]";

void cyg_user_start(void){
  FORTE_L_S_PORT::lmsInit1Port(1);
  FORTE_L_LED::lmsLtLedOff(0);
  CL_AVR_ctl::initAVR();

  // Blink to show booting
  int i = 3;
  while(i--){
    delay(3000000);
    FORTE_L_LED::lmsLtLedOn(0);
    delay(3000000);
    FORTE_L_LED::lmsLtLedOff(0);
  }

  EMB_RMT_DEV *poDev = new EMB_RMT_DEV(g_acId);
  poDev->startDevice();
}

//get the stuff that fixes some ecos cpp problems which have to be near the main
#include "../../arch/ecos/ecoscppinit.cpp"

//we removed clib style startup but the cleanup of the singleton expects somehow an atexit func TODO find out how to avoid this
externC int atexit(void (*func)(void)){
  (void) func; //Suppress compiler warning
  return 0;
}

//currently we have no logging facility on LMS so we provide an empty implementation
void logMessage(E_MsgLevel , const char *pa_acMessage, ...){
//TODO chekc if this is possible on lms
//  va_list pstArgPtr;
//  va_start(pstArgPtr, pa_acMessage);
//  vsnprintf(sm_acMsgBuf, scm_nMsgBufSize, pa_acMessage, pstArgPtr);
//  va_end(pstArgPtr);
  CLMSUSBLayer::sendUSBData(0, pa_acMessage, strlen(pa_acMessage));
}
