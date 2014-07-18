/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef BSDSOCKETINTERF_H_
#define BSDSOCKETINTERF_H_


class CBSDSocketInterface{
  public:
    typedef int TSocketDescriptor;
    typedef struct sockaddr_in TUDPDestAddr;

    static void closeSocket(TSocketDescriptor pa_nSockD);
//TODO: does pa_nPort really need to be long? unsigned short should be sufficient!
    static TSocketDescriptor openTCPServerConnection(char *pa_acIPAddr, unsigned short pa_nPort);
    static TSocketDescriptor openTCPClientConnection(char *pa_acIPAddr, unsigned short pa_nPort);
    static TSocketDescriptor acceptTCPConnection(TSocketDescriptor pa_nListeningSockD);
    static int sendDataOnTCP(TSocketDescriptor pa_nSockD, char* pa_pcData, unsigned int pa_unSize);
    static int receiveDataFromTCP(TSocketDescriptor pa_nSockD, char* pa_pcData, unsigned int pa_unBufSize);

    static TSocketDescriptor openUDPSendPort(char *pa_acIPAddr, unsigned short pa_nPort, TUDPDestAddr *m_ptDestAddr);
    static TSocketDescriptor openUDPReceivePort(char *pa_acIPAddr, unsigned short pa_nPort);
    static int sendDataOnUDP(TSocketDescriptor pa_nSockD, TUDPDestAddr *pa_ptDestAddr, char* pa_pcData, unsigned int pa_unSize);
    static int receiveDataFromUDP(TSocketDescriptor pa_nSockD, char* pa_pcData, unsigned int pa_unBufSize);

  private:
    CBSDSocketInterface(); //this function is not implemented as we don't want instances of this class
};

#endif /* BSDSOCKETINTERF_H_ */
