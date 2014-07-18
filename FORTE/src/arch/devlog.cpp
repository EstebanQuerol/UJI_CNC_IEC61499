/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "devlog.h"
#include "timerha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef NOLOG

static const char* cg_acLogLevel[] = {"INFO", "WARNING", "ERROR", "DEBUG", "TRACE" };

//this define allows to provide an own log handler (see LMS for an example of this)
#ifndef FORTE_EXTERNAL_LOG_HANDLER

/*! \brief print the given log message with the error level and a time stamp
 *
 * @param pa_ecLevel the message's log level
 * @param pa_acMessage the message to log
 */
void printLogMessage(E_MsgLevel pa_eLevel, const char *pa_acMessage);

static const int scm_nMsgBufSize = 300;
static char sm_acMsgBuf[scm_nMsgBufSize]; //!<Buffer for the messages created by the variable addMsg function


void logMessage(E_MsgLevel pa_eLevel, const char *pa_acMessage, ...){
  va_list pstArgPtr;

  va_start(pstArgPtr, pa_acMessage);
#ifdef WIN32
  _vsnprintf(sm_acMsgBuf, scm_nMsgBufSize, pa_acMessage, pstArgPtr);
#else
  vsnprintf(sm_acMsgBuf, scm_nMsgBufSize, pa_acMessage, pstArgPtr);
#endif
  va_end(pstArgPtr);

  printLogMessage(pa_eLevel, sm_acMsgBuf);
}

void printLogMessage(E_MsgLevel pa_eLevel, const char *pa_acMessage){
  fprintf(stderr, cg_acLogLevel[pa_eLevel]);

  if (CTimerHandler::sm_poFORTETimer != 0){
    fprintf(stderr,": T#%ld%ldms: ", CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue, CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
  }
  else{
    fprintf(stderr,": T#notime: ");
  }
  fprintf(stderr, pa_acMessage);
}

#endif
#endif
