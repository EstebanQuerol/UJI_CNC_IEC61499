/*************************************************************************
*** Name: Tool_Table
*** Description: Class containing all the tools used by the
***				 manufacturing system
*** Version: 0
*************************************************************************/
#ifndef _TOOL_TABLE_H_
#define _TOOL_TABLE_H_
#include <unordered_map>
#include <string>
#include "Tool.h"
#include "devlog.h"

class Tool_Table
{
private:
	static std::unordered_map<std::string, Tool> sm_umapToolTable; //Map holding all the tools in the machine
	static bool sm_bInitialized; //Initialization flag

public:
	Tool_Table();
	~Tool_Table();

	/*!\Initialize the tool array
	*/
	static void initilizate();
	/*!\Add a tool to the table
	*/
	static void addTool(Tool pa_oTool);
	/*!\ Update a tool in the table
	*/
	static void updateTool(Tool pa_oTool);
	/*!\ Delete a tool from the table
	*/
	static void deleteTool(Tool pa_oTool);
	/*!\ Delete a tool from the table
	*/
	static void deleteTool(std::string pa_sID);

};

#endif