/*************************************************************************
*** Name: Tool
*** Description: Class containing information of a machining tool
*** Version: 0
*************************************************************************/
#ifndef _TOOL_H_
#define _TOOL_H_
#include <string>
enum Tool_State : int { AVAILABLE = 0, REJECTED = 1, WARN_OUT = 2, WARNING = 4};
class Tool {
public:
	Tool();
	Tool(std::string pa_sID, int pa_nPos, Tool_State pa_nState) : m_sIdentifier(pa_sID), m_nPosition(pa_nPos), m_nToolState(pa_nState){};
	~Tool();
	int getToolPosition(){ return m_nPosition; };
	void setToolPosition(int pa_nPos){ m_nPosition = pa_nPos; };
	std::string getToolID(){ return m_sIdentifier; };
	void setToolID(std::string pa_sID){ m_sIdentifier = pa_sID; };
	Tool_State getToolSate(){ return m_nToolState; };
	void setToolState(Tool_State pa_nState){ m_nToolState = pa_nState; };

private:
	std::string m_sIdentifier; //Tool identifier
	int m_nPosition; //Position in the CNC table
	Tool_State m_nToolState;//Current state of the tool

};

	

#endif
