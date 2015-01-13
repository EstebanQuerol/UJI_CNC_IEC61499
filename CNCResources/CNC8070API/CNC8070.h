// CNC8070.h: archivo de encabezado principal para la aplicación CNC8070FBRT
//
#ifndef CNC8070_H
#define CNC8070_H

typedef enum {
	LOG_OUTPUT = 0,
	LOG_INFORMATION = 1,
	LOG_WARNING = 2,
	LOG_ERROR = 3
} LOGTYPE;

class CCNC8070CommunicationHandler
{
public:
	virtual void Log(LOGTYPE a_ltLogType, const char * a_sText) = 0;
	virtual void OnNotReady() = 0;
	virtual void OnReady() = 0;
	virtual void OnStarted() = 0;
	virtual void OnExecuting() = 0;
	virtual void OnInterrupted() = 0;
	virtual void OnInterruptedByError() = 0;
	virtual void OnMagazineUpdateAdd(const char * pa_sID,int pa_nPos, int pa_nState, long pa_nLocalID) = 0;
	virtual void OnMagazineUpdateDelete(const char * pa_sID, int pa_nPos, int pa_nState, long pa_lITool) = 0;
	virtual void OnMagazineUpdateDelete() = 0;
};

extern void CNC8070Connect(CCNC8070CommunicationHandler * a_oHandler);
extern void CNC8070Disconnect();
extern bool CNC8070IsConnected();
extern void CNC8070Start();
extern bool CNC8070ExecuteBlock(const char * a_sBlock);

#endif
