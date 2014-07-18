// VariableChangeSink.cpp: archivo de implementación
//

#include "stdafx.h"
#include "afxwin.h"
#include "CNC8070API.h"
#include "VariableChangeSink.h"

// CVariableChangeSink

IMPLEMENT_DYNAMIC(CVariableChangeSink, CCmdTarget)


CVariableChangeSink::CVariableChangeSink()
{
	EnableAutomation();
}

CVariableChangeSink::~CVariableChangeSink()
{
}


void CVariableChangeSink::OnFinalRelease()
{
	// Cuando se libera la última referencia para un objeto de automatización,
	// se llama a OnFinalRelease.  La clase base eliminará automáticamente
	// el objeto.  Se requiere limpieza adicional para el
	// objeto antes de llamar a la clase base.

	CCmdTarget::OnFinalRelease();
}

void CVariableChangeSink::OnReport(long param1, LPVARIANT param2) 
{
	BOOL l_bHandle = FALSE;
	HRESULT l_hR = theLib.m_oVars->HandleReport(theLib.m_hVarStatus, param1, *param2, &l_bHandle);
	if (l_bHandle) {
		theLib.m_oVars->ReadInt(theLib.m_hVarStatus, NO_HVAR_INDEX, NO_HVAR_INDEX, &theLib.m_lStatus);
		//CString msg;
		//msg.Format(_T("Status = %i\n"), theApp.m_lStatus);
		//theApp.Log(LOG_INFORMATION, msg);
		switch (theLib.m_lStatus) {
		case 0:
			theLib.OnNotReady();
			break;
		case 1:
			theLib.OnReady();
			break;
		case 2:
			theLib.OnExecuting();
			break;
		case 3:
			theLib.OnInterrupted();
			break;
		case 4:
			theLib.OnInterruptedByError();
			break;
		}
	}
}

BEGIN_MESSAGE_MAP(CVariableChangeSink, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CVariableChangeSink, CCmdTarget)
	DISP_FUNCTION_ID(CVariableChangeSink, "Report", 1, OnReport, VT_EMPTY, VTS_I4 VTS_PVARIANT)
END_DISPATCH_MAP()

// Nota: suministramos compatibilidad con IID_IVariableChangeSink para admitir enlaces de seguridad de tipos
//  desde VBA.  Este IID debe coincidir con el GUID asociado a la interfaz Dispinterface 
//  del archivo .IDL.

BEGIN_INTERFACE_MAP(CVariableChangeSink, CCmdTarget)
	INTERFACE_PART(CVariableChangeSink, DIID_IEventReport, Dispatch)
END_INTERFACE_MAP()


// Controladores de mensajes de CVariableChangeSink
