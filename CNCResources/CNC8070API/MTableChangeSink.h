#pragma once

class CMTableChangeSink : public CCmdTarget
{
	DECLARE_DYNAMIC(CMTableChangeSink)
public:
	CMTableChangeSink();
	~CMTableChangeSink();
	virtual void OnFinalRelease();

	void OnReport(long pa_nITool);
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

