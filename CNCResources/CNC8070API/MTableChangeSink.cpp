
#include "stdafx.h"
#include "afxwin.h"
#include "CNC8070API.h"
#include "MTableChangeSink.h"

// MTableChangeSink

IMPLEMENT_DYNAMIC(CMTableChangeSink, CCmdTarget)

CMTableChangeSink::CMTableChangeSink()
{
	EnableAutomation();
}


CMTableChangeSink::~CMTableChangeSink()
{

}

void CMTableChangeSink::OnFinalRelease(){
	// Cuando se libera la última referencia para un objeto de automatización,
	// se llama a OnFinalRelease.  La clase base eliminará automáticamente
	// el objeto.  Se requiere limpieza adicional para el
	// objeto antes de llamar a la clase base.

	CCmdTarget::OnFinalRelease();
}

void CMTableChangeSink::OnReport(long pa_nITool){
	BSTR sToolName;
	long lRetVal;
	theLib.OnMagazineUpdate(theLib.m_oMagazine->GetToolInfo(1, pa_nITool, &lRetVal));

	//	IFCDualIPlaceStorage * posAlmacen = NULL;
	//	BOOL bRet;
	//	if (theLib.m_oMagazine->GetPlaceInfo(1, pa_nITool, &posAlmacen, &bRet)){
	//		if (posAlmacen != NULL){
	//
	//		}
	//	}
}

BEGIN_MESSAGE_MAP(CMTableChangeSink, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CMTableChangeSink, CCmdTarget)
	DISP_FUNCTION_ID(CMTableChangeSink, "MagazineReport", 1, OnReport, VT_EMPTY, VTS_I4 VTS_PVARIANT)
END_DISPATCH_MAP()

// Nota: suministramos compatibilidad con IID_IMTableChangeSink para admitir enlaces de seguridad de tipos
//  desde VBA.  Este IID debe coincidir con el GUID asociado a la interfaz Dispinterface 
//  del archivo .IDL.

BEGIN_INTERFACE_MAP(CMTableChangeSink, CCmdTarget)
	INTERFACE_PART(CMTableChangeSink, DIID_IMagazineReport, Dispatch)
END_INTERFACE_MAP()


// Controladores de mensajes de CMTableChangeSink
