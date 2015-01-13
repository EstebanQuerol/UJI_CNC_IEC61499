#include "afxwin.h"
#include "stdafx.h"
#include "TTableChangeSink.h"
#include "CNC8070API.h"
#include <comdef.h>


// MTableChangeSink

IMPLEMENT_DYNAMIC(CTTableChangeSink, CCmdTarget)

CTTableChangeSink::CTTableChangeSink()
{
	EnableAutomation();
}


CTTableChangeSink::~CTTableChangeSink()
{

}

void CTTableChangeSink::OnFinalRelease(){
	// Cuando se libera la �ltima referencia para un objeto de automatizaci�n,
	// se llama a OnFinalRelease.  La clase base eliminar� autom�ticamente
	// el objeto.  Se requiere limpieza adicional para el
	// objeto antes de llamar a la clase base.

	CCmdTarget::OnFinalRelease();
}

void CTTableChangeSink::OnReport(long pa_nITool){
	//Same code that CMTableChangeSink::OnReport
	BSTR l_sToolName;
	long l_lRetVal;
	long l_lToolState;
	long l_lToolID;
	long l_lToolPos;
	HRESULT l_hr;
	int l_ii;
	long l_lMzNumber = 1;//Magazine number, using 1 by default
	IFCDualITool * l_poTool = NULL;
	BOOL l_bRet;
	SAFEARRAY * l_paToolArray;
	long l_lLBound;//Array lower bound
	long l_lUBound;//Array upper bound

	l_hr = theLib.m_oTTable->ReadAllToolIds(&l_paToolArray, &l_lRetVal);
	// since we don't know which tool was modified in the magazine we need to update the whole table
	theLib.m_oHandler->OnMagazineUpdateDelete();
	//Verify that the SafeArray is the proper shape
	if (SUCCEEDED(SafeArrayGetLBound(l_paToolArray, 1, &l_lLBound)) && SUCCEEDED(SafeArrayGetUBound(l_paToolArray, 1, &l_lUBound))){
		long l_lElements = l_lUBound - l_lLBound + 1;
		if (l_lElements > 0){
			long * l_plIDS;
			l_hr = SafeArrayAccessData(l_paToolArray, (void HUGEP* FAR*)&l_plIDS);
			if (SUCCEEDED(l_hr)){
				for (l_ii = 0; l_ii < l_lElements; l_ii++){
					l_lToolID = l_plIDS[l_ii];
					theLib.m_oTTable->ReadTool(l_lToolID, &l_poTool, &l_bRet);
					if (l_bRet == true){
						//Retreive tool info
						l_poTool->get_Name(&l_sToolName);
						l_poTool->GetStatus(&l_lToolState);
						l_poTool->Release();
						//Retrive tool position into the Mz
						theLib.m_oMagazine->GetToolInfo(l_lMzNumber, l_lToolID, &l_lRetVal);
						if (l_lRetVal > 0){
							//The tool is currently in the magazine
							l_lToolPos = l_lRetVal;
						}
						else if (l_lRetVal == POSACTIVE){
							//the tool is in the spindle
							l_lToolPos = 0;
						}
						else{
							//The tool is not int the magazine
							l_lToolPos = -1;
						}
						//Add an entry in the table
						char * cstring = _com_util::ConvertBSTRToString(l_sToolName);
						if (cstring != NULL){
							theLib.m_oHandler->OnMagazineUpdateAdd(cstring, l_lToolPos, l_lToolState, l_lToolID);
							delete[] cstring;
						}
					}

				}
				SafeArrayUnaccessData(l_paToolArray);
			}
		}
	}
}

BEGIN_MESSAGE_MAP(CTTableChangeSink, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTTableChangeSink, CCmdTarget)
	DISP_FUNCTION_ID(CTTableChangeSink, "ToolReport", 1, OnReport, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// Nota: suministramos compatibilidad con IID_IMTableChangeSink para admitir enlaces de seguridad de tipos
//  desde VBA.  Este IID debe coincidir con el GUID asociado a la interfaz Dispinterface 
//  del archivo .IDL.

BEGIN_INTERFACE_MAP(CTTableChangeSink, CCmdTarget)
	INTERFACE_PART(CTTableChangeSink, DIID_IToolReport, Dispatch)
END_INTERFACE_MAP()


// Controladores de mensajes de CMTableChangeSink