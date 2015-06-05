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

	/* Members getters
	*/
	int getToolPosition() const{ return m_nPosition; };
	const std::string& getToolID() const{ return m_sIdentifier; };
	Tool_State getToolSate() const{ return m_nToolState; };
	long getLocalID() const{ return m_nLocalIdentifier; };
	double getLength() const{ return m_dLength; };
	double getLengthwear() const{ return m_dLengthWear; };
	double getLengthCut() const{ return m_dLengthCut; };
	double getRadius() const{ return m_dRadius; };
	double getRadiusWear() const{ return m_dRadiusWear; };
	double getnoseRadius() const{ return m_dNoseRadius; };
	double getnoseRadiusWear() const{ return m_dNoseRadiusWear; };
	double getEntryAngle() const{ return m_dEntryAngle; };
	/* Set the edge parameters of a tool
	*/
	void writeEdge(double pa_dLength, double pa_dLengthWear, double pa_dLengthCut, double pa_dRadius, double pa_dRadiusWear, double pa_dNoseRadius,
		double pa_dNoseRadiusWear, double pa_dEntryAngle){
		m_dLength = pa_dLength;
		m_dLengthWear = pa_dLengthWear;
		m_dLengthCut = pa_dLengthCut;
		m_dRadius = pa_dRadius;
		m_dRadiusWear = pa_dRadiusWear;
		m_dNoseRadius = pa_dNoseRadius;
		m_dNoseRadiusWear = pa_dNoseRadiusWear;
		m_dEntryAngle = pa_dEntryAngle;
	};
private:
	std::string m_sIdentifier; //Tool identifier
	int m_nPosition; //Position in the CNC magazine table
	Tool_State m_nToolState;//Current state of the tool
	long  m_nLocalIdentifier; //Identifier of the tool in the machine
	double m_dLength;
	double m_dLengthWear;
	double m_dLengthCut;
	double m_dRadius;
	double m_dRadiusWear;
	double m_dNoseRadius;
	double m_dNoseRadiusWear;
	double m_dEntryAngle;
};

	

#endif
