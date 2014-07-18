/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _DEVLOG_H_
#define _DEVLOG_H_

/*!\ingroup FORTE_HAL
 * \brief CDeviceLog is the entity that logs messages created by the FORTE Runtime system.
 * They can be printed to a console or archived somewhere (This is implementation dependent).
 *
 * @author SMR
 * @version 20070912/AZ - Added DEVLOG prefix to the DeviceLog macros
 * @version 20060717/SMR - revised version of the DeviceLog
 * @version 20051024/SMR - Initial creation of h-file for defining the interface
 *
*/
#include "datatype.h"
#include "../core/utils/singlet.h"
#include <sync.h>

enum E_MsgLevel {E_INFO, E_WARNING, E_ERROR, E_DEBUG, E_TRACE};

// possible loglevels: NOLOG, LOGERROR, LOGWARNING, LOGINFO, LOGDEBUG
/* Meaning:
 * LOGERROR: log only error messages
 * LOGWARNING: log error and warning messages
 * LOGINFO: log error, warning, and info messages
 * LOGDEBUG: log all messages: error, warning, info, and debug
 * NOLOG: log no messages
 */

#if !(defined(NOLOG) || defined(LOGERROR) || defined(LOGWARNING) || defined(LOGINFO) || defined(LOGDEBUG))
/* Set default loglevel */
# define LOGDEBUG
#endif

#ifdef LOGDEBUG
  #define DEVLOG_ERROR(...) logMessage(E_ERROR, __VA_ARGS__)
  #define DEVLOG_WARNING(...) logMessage(E_WARNING, __VA_ARGS__)
  #define DEVLOG_INFO(...) logMessage(E_INFO, __VA_ARGS__)
  #define DEVLOG_DEBUG(...) logMessage(E_DEBUG, __VA_ARGS__)
#endif

#ifdef LOGERROR
  #define DEVLOG_ERROR(...) logMessage(E_ERROR, __VA_ARGS__)
  #define DEVLOG_WARNING(...)
  #define DEVLOG_INFO(...)
  #define DEVLOG_DEBUG(...)
#endif

#ifdef LOGWARNING
  #define DEVLOG_ERROR(...) logMessage(E_ERROR, __VA_ARGS__)
  #define DEVLOG_WARNING(...) logMessage(E_WARNING, __VA_ARGS__)
  #define DEVLOG_INFO(...)
  #define DEVLOG_DEBUG(...)
#endif

#ifdef LOGINFO
 #define DEVLOG_ERROR(...) logMessage(E_ERROR, __VA_ARGS__)
  #define DEVLOG_WARNING(...) logMessage(E_WARNING, __VA_ARGS__)
  #define DEVLOG_INFO(...) logMessage(E_INFO, __VA_ARGS__)
  #define DEVLOG_DEBUG(...)
#endif

#ifdef NOLOG
  #define DEVLOG_INFO(...)
  #define DEVLOG_WARNING(...)
  #define DEVLOG_ERROR(...)
  #define DEVLOG_DEBUG(...)
#endif

#if (defined(FORTE_TRACE_EVENTS) && !defined(NOLOG))
  #define FORTE_TRACE(...) logMessage(E_TRACE,  __VA_ARGS__)
#else
  #define FORTE_TRACE(...)
#endif

#ifndef NOLOG

/*! \brief Adds an Entry to the LogBook
 *
 */
    void logMessage(E_MsgLevel pa_eLevel, const char *pa_acMessage, ...);
#endif

#endif //_DEVLOG_H_
