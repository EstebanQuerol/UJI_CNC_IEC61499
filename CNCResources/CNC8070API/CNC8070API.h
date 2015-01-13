// CNC8070API.h: archivo de encabezado principal del archivo DLL de CNC8070API
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales

#include <initguid.h>
#include "api8070_i.h"
#include "CYStartSink.h"
#include "VariableChangeSink.h"
#include "MTableChangeSink.h"
#include "TTableChangeSink.h"
#include "CNC8070.h"

// CCNC8070APIApp
// Consultar CNC8070API.cpp para realizar la implementación de esta clase
//

class CCNC8070APILib : public CWinApp
{
public:
	CCNC8070CommunicationHandler * m_oHandler;
	CComPtr<IFCDualKernel8070> m_oKernel;
	CComPtr<IFCDualVar8070> m_oVars;
	CComPtr<IFCDualPlc> m_oPlc;
	CComPtr<IFCDualTMagazine> m_oMagazine;
	CComPtr<IFCDualTTable> m_oTTable;
	CCYStartSink m_oCYStartSink;
	DWORD m_dwCYStartSinkCookie;
	CVariableChangeSink m_oVariableChangeSink;
	DWORD m_dwVariableChangeSinkCookie;
	HVAR m_hVarStatus;
	LONG m_lStatus;
	BOOL m_bConnected;
	CStringA m_sCurrentBlock;
	CMTableChangeSink m_oCMTableChangeSink;
	DWORD m_dwCMTableChangeSinkCookie;
	CTTableChangeSink m_oCTTableChangeSink;
	DWORD m_dwCTTableChangeSinkCookie;

public:
	CCNC8070APILib();

// Reemplazos
public:
	virtual BOOL InitInstance();

	inline BOOL IsConnected() { return m_bConnected; }
	BOOL ConnectCNC(CCNC8070CommunicationHandler * a_oHandler);
	BOOL DisconnectCNC();

	BOOL ChkRV(LONG a_lRetVal);

	VOID Start();
	BOOL ExecuteBlock(LPCSTR a_sBlock);
	
	VOID OnNotReady();
	VOID OnReady();
	VOID OnStarted();
	VOID OnExecuting();
	VOID OnInterrupted();
	VOID OnInterruptedByError();
	VOID OnMagazineUpdateAdd(const char * pa_sID, int pa_nPos, int pa_nState, long pa_nLocalID);
	VOID OnMagazineUpdateDelete(const char * pa_sID, int pa_nPos, int pa_nState, long pa_lITool);
	VOID OnMagazineUpdateDelete();

	DECLARE_MESSAGE_MAP()
};

extern CCNC8070APILib theLib;