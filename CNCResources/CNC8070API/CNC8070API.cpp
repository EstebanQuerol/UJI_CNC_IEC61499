// CNC8070API.cpp: define las rutinas de inicialización del archivo DLL.
//

#include "stdafx.h"
#include "afxctl.h"
#include "CNC8070.h"
#include "CNC8070API.h"
#include <comdef.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: si este archivo DLL se vincula de forma dinámica con los archivos DLL de MFC,
//		las funciones que se exporten desde el archivo DLL y a las que se llame en
//		MFC deben agregar la macro AFX_MANAGE_STATE al
//		principio de la función.
//
//		Por ejemplo:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// colocar aquí el cuerpo de la función estándar
//		}
//
//		Es de suma importancia que esta macro aparezca en todas las funciones
//		antes de que se llamen en MFC.  Esto significa que debe aparecer
//		en la primera instrucción de la función, 
//		antes incluso de cualquier declaración de variables de objetos,
//		ya que sus constructores pueden generar llamadas al archivo DLL de MFC.
//		
//
//		Consulte las notas técnicas 33 y 58 de MFC para obtener
//		detalles adicionales.
//

// CCNC8070APIApp

BEGIN_MESSAGE_MAP(CCNC8070APILib, CWinApp)
END_MESSAGE_MAP()


// Construcción de CCNC8070APILib

CCNC8070APILib::CCNC8070APILib()
{
	// TODO: agregar aquí el código de construcción,
	// Colocar toda la inicialización importante en InitInstance
}


// El único objeto CCNC8070APILib

CCNC8070APILib theLib;


// Inicialización de CCNC8070APILib

BOOL CCNC8070APILib::InitInstance()
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}


static HRESULT CreateRemoteInstance(REFIID a_ridCls, REFIID a_ridItf, LPTSTR a_sHostName, LPDISPATCH & a_pItf)
{
	COSERVERINFO l_csi = { 0, a_sHostName, NULL, 0 };
	MULTI_QI l_mqi[] = { &a_ridItf, NULL, S_OK };
	HRESULT l_hR;

	l_hR = CoCreateInstanceEx(a_ridCls, NULL, CLSCTX_REMOTE_SERVER | CLSCTX_LOCAL_SERVER, &l_csi, 1, l_mqi);
	if (SUCCEEDED(l_hR)) {
		a_pItf = (LPDISPATCH)l_mqi[0].pItf;
	}

	return l_hR;
}

BOOL CCNC8070APILib::ConnectCNC(CCNC8070CommunicationHandler * a_oHandler)
{
	m_oHandler = a_oHandler;

	if (!m_bConnected) {
		LPTSTR l_sHostName = _T("localhost");
		HRESULT l_hR;
		LPDISPATCH l_pItf = NULL;
		LPUNKNOWN l_pUnkSink = NULL;
		BOOL l_bRetVal;
		LONG l_lRetVal;

		CoInitialize(NULL);

		l_hR = CreateRemoteInstance(__uuidof(CNC8070_Kernel), __uuidof(IFCDualKernel8070), l_sHostName, l_pItf);
		if (SUCCEEDED(l_hR)) {
			m_oKernel.Attach((IFCDualKernel8070 *)l_pItf);
			l_hR = CreateRemoteInstance(__uuidof(CNC8070_Variables), __uuidof(IFCDualVar8070), l_sHostName, l_pItf);
			if (SUCCEEDED(l_hR)) {
				m_oVars.Attach((IFCDualVar8070 *)l_pItf);

				l_pUnkSink = m_oVariableChangeSink.GetIDispatch(FALSE);
				l_bRetVal = AfxConnectionAdvise(m_oVars, DIID_IEventReport, l_pUnkSink, FALSE, &m_dwVariableChangeSinkCookie);

				BSTR l_sVarName = SysAllocString(L"[1].G.STATUS");
				l_hR = m_oVars->OpenVariable(l_sVarName, &m_hVarStatus);
				SysFreeString(l_sVarName);

				l_hR = m_oVars->ReadInt(m_hVarStatus, NO_HVAR_INDEX, NO_HVAR_INDEX, &m_lStatus);
				//Actualizamos el estaddo inicial para que el servicio CNC en FORTE sepa que esta listo
				switch (m_lStatus) {
				case 0:
					OnNotReady();
					break;
				case 1:
					OnReady();
					break;
				case 2:
					OnExecuting();
					break;
				case 3:
					OnInterrupted();
					break;
				case 4:
					OnInterruptedByError();
					break;
				}
				l_hR = m_oVars->OpenReport(m_hVarStatus, &l_lRetVal);

				//Add Magazine table server
				l_hR = CreateRemoteInstance(__uuidof(CNC8070_MagazineTable), __uuidof(IFCDualTMagazine), l_sHostName, l_pItf);
				if (SUCCEEDED(l_hR)){
					m_oMagazine.Attach((IFCDualTMagazine *)l_pItf);
					l_pUnkSink = m_oCMTableChangeSink.GetIDispatch(FALSE);
					l_bRetVal = AfxConnectionAdvise(m_oMagazine, DIID_IMagazineReport, l_pUnkSink, FALSE, &m_dwCMTableChangeSinkCookie);
					//Start reporting magazine changes
					l_hR = m_oMagazine->OpenReport(&l_lRetVal);
				}

				//Add Tool table server
				l_hR = CreateRemoteInstance(__uuidof(CNC8070_TTable), __uuidof(IFCDualTTable), l_sHostName, l_pItf);
				if (SUCCEEDED(l_hR)){
					m_oTTable.Attach((IFCDualTTable *)l_pItf);
					l_pUnkSink = m_oCTTableChangeSink.GetIDispatch(FALSE);
					l_bRetVal = AfxConnectionAdvise(m_oTTable, DIID_IToolReport, l_pUnkSink, FALSE, &m_dwCTTableChangeSinkCookie);
					//Start reporting magazine changes
					l_hR = m_oTTable->OpenReport(&l_lRetVal);
				}

				//Add PLC server
				l_hR = CreateRemoteInstance(__uuidof(CNC8070_Plc), __uuidof(IFCDualPlc), l_sHostName, l_pItf);
				if (SUCCEEDED(l_hR)) {
					m_oPlc.Attach((IFCDualPlc *)l_pItf);

					l_pUnkSink = m_oCYStartSink.GetIDispatch(FALSE);
					l_bRetVal = AfxConnectionAdvise(m_oPlc, DIID_ICYStartReport, l_pUnkSink, FALSE, &m_dwCYStartSinkCookie);

					m_oPlc->SetStartManager(TRUE, &l_bRetVal);

					m_bConnected = TRUE;
				}
			}
		}
		if (m_bConnected) {
			//Initialize tool talbe
			MagazineInitialize();
			m_oHandler->Log(LOG_INFORMATION, "CNC Connected!\n");
		}
		else {
			m_oHandler->Log(LOG_ERROR, "CNC is not connected!\n");
		}
	}
	else {
		m_oHandler->Log(LOG_WARNING, "CNC is already connected!\n");
	}

	return m_bConnected;
}

BOOL CCNC8070APILib::DisconnectCNC()
{
	if (m_bConnected) {
		IID iid = IID_IUnknown;
		LPUNKNOWN l_pUnkSink;
		BOOL l_bRetVal;

		m_oPlc->SetStartManager(FALSE, &l_bRetVal);

		l_pUnkSink = m_oVariableChangeSink.GetInterface(&iid);
		l_bRetVal = AfxConnectionUnadvise(m_oVars, DIID_IEventReport, l_pUnkSink, FALSE, m_dwVariableChangeSinkCookie);

		l_pUnkSink = m_oCMTableChangeSink.GetInterface(&iid);
		l_bRetVal = AfxConnectionUnadvise(m_oMagazine, DIID_IMagazineReport, l_pUnkSink, FALSE, m_dwCMTableChangeSinkCookie);

		l_pUnkSink = m_oCTTableChangeSink.GetInterface(&iid);
		l_bRetVal = AfxConnectionUnadvise(m_oTTable, DIID_IToolReport, l_pUnkSink, FALSE, m_dwCTTableChangeSinkCookie);

		l_pUnkSink = m_oCYStartSink.GetInterface(&iid);
		l_bRetVal = AfxConnectionUnadvise(m_oPlc, DIID_ICYStartReport, l_pUnkSink, FALSE, m_dwCYStartSinkCookie);

		m_oPlc.Release();
		m_oMagazine.Release();
		m_oTTable.Release();
		m_oVars.Release();
		m_oKernel.Release();

		m_bConnected = FALSE;

		m_oHandler->Log(LOG_INFORMATION, "CNC Disconnected!\n");
	}

	return !m_bConnected;
}

VOID CCNC8070APILib::Start()
{
	HRESULT l_hR = m_oKernel->ChannelStartRequest(1);
}

BOOL CCNC8070APILib::ExecuteBlock(LPCSTR a_sBlock)
{
	CStringA msg;
	msg.Format("Execute Block: %s\n", a_sBlock);
	m_oHandler->Log(LOG_INFORMATION, msg);

	LONG l_rRetVal;
	CStringA l_sBlock(a_sBlock);
	BSTR l_bsBlock = l_sBlock.AllocSysString();
	HRESULT l_hR = m_oKernel->ExecBlockEx(1, l_bsBlock, &l_rRetVal);
	SysFreeString(l_bsBlock);
	return ChkRV(l_rRetVal);
}

VOID CCNC8070APILib::OnNotReady()
{
	m_oHandler->OnNotReady();
}

VOID CCNC8070APILib::OnReady()
{
	m_oHandler->OnReady();
}

VOID CCNC8070APILib::OnStarted()
{
	m_oHandler->OnStarted();
}

VOID CCNC8070APILib::OnExecuting()
{
	m_oHandler->OnExecuting();
}

VOID CCNC8070APILib::OnInterrupted()
{
	m_oHandler->OnInterrupted();
}

VOID CCNC8070APILib::OnInterruptedByError()
{
	m_oHandler->OnInterruptedByError();
}

BOOL CCNC8070APILib::ChkRV(LONG a_lRetVal)
{
	if (a_lRetVal != API_RET_OK) {
		CStringA msg("API RETURN ERROR: ");
		switch (a_lRetVal) {
		case API_RET_ERROR:
			msg.Append("API_RET_ERROR");
			break;
		case API_CYSTART_NOT_ACTIVE:
			msg.Append("API_CYSTART_NOT_ACTIVE");
			break;
		case API_KERNEL_ALREADY_STARTED:
			msg.Append("API_KERNEL_ALREADY_STARTED");
			break;
		case API_KERNEL_NOT_STARTED:
			msg.Append("API_KERNEL_NOT_STARTED");
			break;
		case API_STATUS_NOT_READY:
			msg.Append("API_STATUS_NOT_READY");
			break;
		case API_INVALID_API_STATUS:
			msg.Append("API_INVALID_API_STATUS");
			break;
		case API_KERNEL_NOT_READY:
			msg.Append("API_KERNEL_NOT_READY");
			break;
		case API_INVALID_KERNEL_MODE:
			msg.Append("API_INVALID_KERNEL_MODE");
			break;
		case API_INVALID_KERNEL_STATUS:
			msg.Append("API_INVALID_KERNEL_STATUS");
			break;
		case API_INVALID_DATABASE:
			msg.Append("API_INVALID_DATABASE");
			break;
		default:
			msg.Append("UNKNOWN!");
			break;
		}
		m_oHandler->Log(LOG_ERROR, msg);
		return FALSE;
	} else {
		return TRUE;
	}
}
VOID CCNC8070APILib::MagazineInitialize(){
	//Initialize tool table using CMTableChangeSink::OnReport code
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
VOID CCNC8070APILib::OnMagazineUpdateAdd(const char * pa_sID, int pa_nPos, int pa_nState, long pa_nLocalID){
	m_oHandler->OnMagazineUpdateAdd(pa_sID,pa_nPos, pa_nState, pa_nLocalID);
}
VOID CCNC8070APILib::OnMagazineUpdateDelete(){
	m_oHandler->OnMagazineUpdateDelete();
}