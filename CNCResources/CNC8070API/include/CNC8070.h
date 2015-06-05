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

/*	The fields of this struct are equivalent to the
*	attributes of tools and edges described in FAGOR8070 API
*	documentation
*	All length measures are expressed in tens of micrometers
*	(0.0001 mm) and stored in a 4 byte signed integer. 
*	For example the double value 75.1234 is 751234 integer
*	Angular measures are expressed the same way in 
*   tenthousandths of degree
*/
typedef struct tool8070{
	char * m_acToolName = NULL;
	long m_lToolState = -1;
	long m_lToolID = -1;
	long m_lToolPos = -1;
	long m_lNumEdges = -1;
	long m_lLength = -1;
	long m_lLengthWear = -1;
	long m_lLengthCut = -1;
	long m_lRadius = -1;
	long m_lRadiusWear = -1;
	long m_lNoseRadius = -1;
	long m_lNoseRadiusWear = -1;
	long m_lEntryAngle = -1;
}tool8070;

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
	virtual void OnMagazineUpdateAdd(const tool8070 &pa_stTool) = 0;
	virtual void OnMagazineUpdateDelete(const tool8070 &pa_stTool) = 0;
	virtual void OnMagazineUpdateDelete() = 0;
};

extern void CNC8070Connect(CCNC8070CommunicationHandler * a_oHandler);
extern void CNC8070Disconnect();
extern bool CNC8070IsConnected();
extern void CNC8070Start();
extern bool CNC8070ExecuteBlock(const char * a_sBlock);

#endif
