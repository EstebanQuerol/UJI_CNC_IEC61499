
#include "stdafx.h"
#include "afxwin.h"
#include "CNC8070API.h"
#include "MTableChangeSink.h"
#include <comdef.h>

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
	//This report used the same code that CTTableChangeSink::OnReport
	//Calling it directly to improve maintainable
	theLib.m_oCTTableChangeSink.OnReport(pa_nITool);
	//IFCDualIPlaceStorage * l_poPlaceInfo = NULL;
	//long l_lPlaces; //Number of places in the magazine
	//theLib.m_oMagazine->GetNumberOfPlaces(l_lMzNumber, &l_lPlaces);
	//for (l_ii = 1; l_ii <= l_lPlaces; l_ii++){
	//	//Get the info of each place in the magazine
	//	theLib.m_oMagazine->GetPlaceInfo(l_lMzNumber, l_ii, &l_poPlaceInfo, &l_bRet);
	//	if (l_bRet){
	//		// Check if there is a tool in the current position
	//		l_poPlaceInfo->GetToolID2(&l_lToolID);
	//		if (l_lToolID != 0){
	//			//A tool in current position
	//			theLib.m_oTTable->ReadTool(l_lToolID, &l_poTool, &l_bRet);
	//			if (l_bRet == true){
	//				l_poTool->get_Name(&l_sToolName);
	//				l_poTool->GetStatus(&l_lToolState);
	//				l_poTool->Release();
	//				//Add an entry in the table
	//				char * cstring = _com_util::ConvertBSTRToString(l_sToolName);
	//				if (cstring != NULL){
	//					theLib.m_oHandler->OnMagazineUpdateAdd(cstring, l_ii, l_lToolState, l_lToolID);
	//					delete[] cstring;
	//				}
	//			}
	//		}
	//		l_poPlaceInfo->Release();
	//	}
	//}
}


BEGIN_MESSAGE_MAP(CMTableChangeSink, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CMTableChangeSink, CCmdTarget)
	DISP_FUNCTION_ID(CMTableChangeSink, "MagazineReport", 1, OnReport, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// Nota: suministramos compatibilidad con IID_IMTableChangeSink para admitir enlaces de seguridad de tipos
//  desde VBA.  Este IID debe coincidir con el GUID asociado a la interfaz Dispinterface 
//  del archivo .IDL.

BEGIN_INTERFACE_MAP(CMTableChangeSink, CCmdTarget)
	INTERFACE_PART(CMTableChangeSink, DIID_IMagazineReport, Dispatch)
END_INTERFACE_MAP()


// Controladores de mensajes de CMTableChangeSink
