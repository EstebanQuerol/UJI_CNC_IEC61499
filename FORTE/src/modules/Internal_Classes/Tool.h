/*************************************************************************
*** Name: Tool
*** Description: Class containing information of a machining tool
*** Version: 0
*************************************************************************/
#ifndef _TOOL_H_
#define _TOOL_H_
#include <string>
typedef enum : int { 
	TOOL_AVAILABLE = 0,
	TOOL_REJECTED = 1, 
	TOOL_WARN_OUT = 2, 
	TOOL_WARNING = 4 
}Tool_State;

class Tool {
public:
	Tool();
	Tool(std::string pa_sID, int pa_nPos, Tool_State pa_nState) : m_sIdentifier(pa_sID), m_nPosition(pa_nPos), m_nToolState(pa_nState){};
	Tool(std::string pa_sID, int pa_nPos, Tool_State pa_nState, long pa_nLID) : m_sIdentifier(pa_sID), m_nPosition(pa_nPos), m_nToolState(pa_nState), 
		m_nLocalIdentifier(pa_nLID){};
	~Tool();
	int getToolPosition(){ return m_nPosition; };
	void setToolPosition(int pa_nPos){ m_nPosition = pa_nPos; };
	std::string getToolID(){ return m_sIdentifier; };
	void setToolID(std::string pa_sID){ m_sIdentifier = pa_sID; };
	Tool_State getToolSate(){ return m_nToolState; };
	void setToolState(Tool_State pa_nState){ m_nToolState = pa_nState; };
	long getLocalID(){ return m_nLocalIdentifier; };
	void setLocalID(long pa_nLocalID){ m_nLocalIdentifier = pa_nLocalID; };

private:
	std::string m_sIdentifier; //Tool identifier
	int m_nPosition; //Position in the CNC table
	Tool_State m_nToolState;//Current state of the tool
	long  m_nLocalIdentifier; //Identifier of the tool in the machine

};

	

#endif
