/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "forte_string.h"
#include <devlog.h>
#include "forte_uint.h"
#include "unicode_utils.h"

DEFINE_FIRMWARE_DATATYPE(STRING, g_nStringIdSTRING);

int CIEC_STRING::fromString(const char *pa_pacValue){
  unsigned int nSrcLen = determineEscapedStringLength(pa_pacValue, '\'');
  int nSrcCappedLength = nSrcLen;

  if((nSrcLen >= 7) && (0 == strncmp(pa_pacValue, "STRING#", 7))){
	  pa_pacValue += 7;
	  nSrcCappedLength -= 7;
  }

  if (nSrcLen > scm_unMaxStringLen)
    nSrcCappedLength = scm_unMaxStringLen;


  if (*pa_pacValue == '\'') {
    reserve(static_cast<TForteUInt16>(nSrcCappedLength));
    if (unescapeFromString(pa_pacValue, '\'') < 0)
      return -1;
  } else {
    assign(pa_pacValue, nSrcCappedLength);
  }

  return nSrcLen;
}

int CIEC_STRING::toString(char* pa_acValue, unsigned int pa_nBufferSize) const {
  int nRetVal = -1;
  if(static_cast<unsigned int>(length() + 2) < pa_nBufferSize){  //add 2 for the leading and closing '
    *pa_acValue = '\'';
    pa_acValue++;
    TForteUInt16 nLen = length();
    int nUsedBytes = 0;
    pa_nBufferSize -= 2;
    if(0 < nLen){
      const char * acValue = getValue();
      for(unsigned int i = 0; i < nLen; ++i){
        if(static_cast<unsigned int >(nUsedBytes) >= pa_nBufferSize){
          return -1;
        }
        nUsedBytes += dollarEscapeChar(pa_acValue+nUsedBytes, acValue[i], 2);
      }

    } else{
      *pa_acValue = '\0';
    }
    nRetVal = nUsedBytes;
    pa_acValue[nRetVal] = '\'';
    pa_acValue[nRetVal + 1] = '\0';
  }
  return nRetVal + 2;
}

#ifdef FORTE_UNICODE_SUPPORT
int CIEC_STRING::fromUTF8(const char *pa_pacValue, int pa_nLen, bool pa_bUnescape) {
  unsigned int nMaxWidth;

  int nSrcLen = pa_nLen >= 0 ? pa_nLen : (pa_bUnescape ? determineEscapedStringLength(pa_pacValue, '\'') : strlen(pa_pacValue));
  int nSrcCappedLength = nSrcLen;

  if (nSrcLen == 0) {
    assign("", 0);
    return 0;
  }

  if (nSrcLen > static_cast<int>(scm_unMaxStringLen)) {
    // If we get a to large string we will truncate it
    // This is a conservative guess
    nSrcCappedLength = scm_unMaxStringLen;
    DEVLOG_WARNING("Too large string, destination will be truncated!\n");
  }

  int nLength = CUnicodeUtilities::checkUTF8(pa_pacValue, nSrcCappedLength, nMaxWidth);
  if (nLength < 0) {
    DEVLOG_WARNING("Invalid UTF-8 string given to fromString!\n");
    *this = "***INVALID UTF-8***";
    return -1;
  } else if (nMaxWidth > 8) {
    DEVLOG_WARNING("UTF-8 string with non-representable characters given to fromString!\n");
  }

  reserve(static_cast<TForteUInt16>(nLength));
  if (0 == getGenData())
    return -1;

  TForteUInt32 nCodepoint;
  const char *pRunner = pa_pacValue;
  TForteByte *pEncBuffer = (TForteByte *) getValue();
  TForteByte *pEncRunner = pEncBuffer;

  while (*pRunner && (pRunner-pa_pacValue) < nSrcCappedLength && (pEncRunner-pEncBuffer) < nLength) {
    int nRes;
    nRes = CUnicodeUtilities::parseUTF8Codepoint((const TForteByte *) pRunner, nCodepoint);
    pRunner += nRes;
    if (nCodepoint == CUnicodeUtilities::scm_unBOMMarker)
      continue;
    if (nCodepoint >= 0x100)
      nCodepoint = '?';
    *pEncRunner++ = (TForteByte) nCodepoint;
  }

  *pEncRunner = '\0';
  setLength(static_cast<TForteUInt16>(pEncRunner - pEncBuffer));

  if (pa_bUnescape) {
    nLength = unescapeFromString(getValue(), '\'');
    if (nLength < 0)
      return -1;
  }

  return nSrcLen;
}

int CIEC_STRING::toUTF8(char* pa_pacBuffer, unsigned int pa_nBufferSize, bool pa_bEscape) const {
  // Count the needed space
  unsigned int nNeededLength = pa_bEscape ? 2 : 0; // Leading and trailing delimiter
  int nRes;

  const unsigned char *pRunner = (const unsigned char *) getValue();
  while (*pRunner) {
    nRes = CUnicodeUtilities::encodeUTF8Codepoint(0, 0, (TForteUInt32) *pRunner);
    if (nRes < 0)
      return -1;
    nNeededLength += nRes;
    if (nRes == 1 && pa_bEscape && dollarEscapeChar(0, *pRunner, 0) == 2)
      nNeededLength++;
    ++pRunner;
  }

  if (pa_pacBuffer == 0)
    return nNeededLength;

  if (nNeededLength+1 > pa_nBufferSize)
    return -1;

  char *pEncRunner = pa_pacBuffer;
  char *pDataEnd = pa_pacBuffer + nNeededLength;

  if (pa_bEscape)
    *pEncRunner++ = '\'';

  pRunner = (const unsigned char *) getValue();
  while (*pRunner) {
    nRes = CUnicodeUtilities::encodeUTF8Codepoint((TForteByte *) pEncRunner, pDataEnd-pEncRunner, (TForteUInt32) *pRunner);
    if (nRes == 1 && pa_bEscape)
      nRes = dollarEscapeChar(pEncRunner, *pRunner, pDataEnd-pEncRunner);

    if (nRes < 0)
      return -1;

    pEncRunner += nRes;
    ++pRunner;
  }

  if (pa_bEscape)
    *pEncRunner++ = '\'';
  *pEncRunner = '\0';

  return pEncRunner - pa_pacBuffer;
}

#endif
