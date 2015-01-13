#pragma once

class CTTableChangeSink : public CCmdTarget
{
	DECLARE_DYNAMIC(CTTableChangeSink)
public:
	CTTableChangeSink();
	~CTTableChangeSink();
	virtual void OnFinalRelease();

	void OnReport(long pa_nITool);
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

