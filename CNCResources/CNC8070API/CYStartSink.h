
#pragma once


// Destino del comando de CCYStartSink

class CCYStartSink : public CCmdTarget
{
	DECLARE_DYNAMIC(CCYStartSink)

public:
	CCYStartSink();
	virtual ~CCYStartSink();

	virtual void OnFinalRelease();

	void OnReport(long a_nChannel);

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


