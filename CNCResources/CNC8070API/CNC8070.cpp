
// CNC8070.cpp : define los comportamientos de las clases para la aplicación.
//

#include "stdafx.h"
#include "CNC8070.h"
#include "CNC8070API.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CNC8070Connect(CCNC8070CommunicationHandler * a_oHandler)
{
	theLib.ConnectCNC(a_oHandler);
}

void CNC8070Disconnect()
{
	theLib.DisconnectCNC();
}

bool CNC8070IsConnected() 
{
	return theLib.IsConnected();
}

void CNC8070Start()
{
	theLib.Start();
}

bool CNC8070ExecuteBlock(const char * a_sBlock)
{
	return theLib.ExecuteBlock(a_sBlock);
}
