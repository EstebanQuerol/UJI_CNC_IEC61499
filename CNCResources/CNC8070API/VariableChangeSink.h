
#pragma once


// Destino del comando de CVariableChangeSink

class CVariableChangeSink : public CCmdTarget
{
	DECLARE_DYNAMIC(CVariableChangeSink)

public:
	CVariableChangeSink();
	virtual ~CVariableChangeSink();

	virtual void OnFinalRelease();

	void OnReport(long param1, LPVARIANT param2);

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


