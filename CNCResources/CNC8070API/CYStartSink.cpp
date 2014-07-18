// CYStartSink.cpp: archivo de implementación
//

#include "stdafx.h"
#include "afxwin.h"
#include "CNC8070API.h"
#include "CYStartSink.h"

// CCYStartSink

IMPLEMENT_DYNAMIC(CCYStartSink, CCmdTarget)


CCYStartSink::CCYStartSink()
{
	EnableAutomation();
}

CCYStartSink::~CCYStartSink()
{
}


void CCYStartSink::OnFinalRelease()
{
	// Cuando se libera la última referencia para un objeto de automatización,
	// se llama a OnFinalRelease.  La clase base eliminará automáticamente
	// el objeto.  Se requiere limpieza adicional para el
	// objeto antes de llamar a la clase base.

	CCmdTarget::OnFinalRelease();
}

void CCYStartSink::OnReport(long a_nChannel) 
{
	theLib.OnStarted();
}

BEGIN_MESSAGE_MAP(CCYStartSink, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCYStartSink, CCmdTarget)
	DISP_FUNCTION_ID(CCYStartSink, "Report", 2, OnReport, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// Nota: suministramos compatibilidad con IID_ICYStartSink para admitir enlaces de seguridad de tipos
//  desde VBA.  Este IID debe coincidir con el GUID asociado a la interfaz Dispinterface 
//  del archivo .IDL.

BEGIN_INTERFACE_MAP(CCYStartSink, CCmdTarget)
	INTERFACE_PART(CCYStartSink, DIID_ICYStartReport, Dispatch)
END_INTERFACE_MAP()


// Controladores de mensajes de CCYStartSink
