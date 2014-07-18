/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _EPLWRAPPER_H_
#define _EPLWRAPPER_H_

#include "ProcessImageMatrix.h"
#include "EplCNCallback.h"
#include <singlet.h>
#include <fortelist.h>
#include <sync.h>

struct SEplMapping{
    struct SEplMappingValues{
        unsigned int m_nDataSize;
        unsigned int m_nPiOffset;
        unsigned int m_nBitOffset;
        char* m_pchCurrentValue;

        SEplMappingValues(unsigned int pa_nDataSize, unsigned int pa_nPiOffset, unsigned int pa_nBitOffset) :
            m_nDataSize(pa_nDataSize), m_nPiOffset(pa_nPiOffset), m_nBitOffset(pa_nBitOffset){
          m_pchCurrentValue = new char[pa_nDataSize];
          for(unsigned int i = 0; i < pa_nDataSize; i++){
            m_pchCurrentValue[i] = 0x00;
          }
        }

        ~SEplMappingValues(){
          delete[] m_pchCurrentValue;
        }
    };

    typedef CSinglyLinkedList<SEplMappingValues*> TEplMappingList;
    TEplMappingList m_lCurrentValues;

    ~SEplMapping(){
      while(!m_lCurrentValues.isEmpty()){
        delete *(TEplMappingList::Iterator) m_lCurrentValues.begin();
        m_lCurrentValues.pop_front();
      }
    }
};

// CEplStackWrapper implemented as class
class CEplStackWrapper{
  DECLARE_SINGLETON(CEplStackWrapper)
    ;
  public:
    /*! \brief Blocking of real-time signals
     *
     *  This must be called in main.cpp before the event execution thread is started
     */
    static void eplMainInit();

    int eplStackInit(char* pa_chXmlFile, char* pa_chCdcFile, char* pa_chEthDeviceName);

    int eplStackShutdown(void);

    CProcessImageMatrix* getProcessImageMatrixIn();
    CProcessImageMatrix* getProcessImageMatrixOut();

    char* getProcImageIn();
    char* getProcImageOut();

    void waitUntilOperational(bool pa_bWait);

    void registerCallback(IEplCNCallback* pa_pCallback);

    void executeAllCallbacks();

  private:
    char* allocProcImage(unsigned int n_bytes);

    bool findMAC(const char* pa_pchUserMAC, char* pa_pchDevieName);

    bool compareMACs(const char* pa_chMACa, const char* pa_chMACb);

    CProcessImageMatrix m_oProcMatrixIn;
    CProcessImageMatrix m_oProcMatrixOut;

    unsigned int m_nProcInSize;
    char* m_pchAppProcessImageIn_g;
    unsigned int m_nProcOutSize;
    char* m_pchAppProcessImageOut_g;

    bool m_bWait;

    CSinglyLinkedList<IEplCNCallback*> m_lCallbackList;

    CSyncObject m_oSync;

};

#endif
