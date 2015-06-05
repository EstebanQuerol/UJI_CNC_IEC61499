/*************************************************************************
*** Name: Tool_Table
*** Description: Class containing all the tools used by a machine of the
***				 manufacturing system
*** Version: 0
*************************************************************************/
#ifndef _TOOL_TABLE_H_
#define _TOOL_TABLE_H_
#include <unordered_map>
#include <string>
#include "Tool.h"
#include "devlog.h"
#include "forte_dint.h"

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
	static void addTool(const Tool& pa_oTool);
	/*!\ Update a tool in the table
	*/
	static void updateTool(const Tool& pa_oTool);
	/*!\ Delete a tool from the table
	*/
	static void deleteTool(const Tool& pa_oTool);
	/*!\ Delete a tool from the table
	*/
	static void deleteTool(const std::string &pa_sID);

	/*!\ Delete the tool table
	*/
	static void deleteTable();
	/*!\ Check if a tool is available or not
	* return positive 32bit int with the position of the tool in the cnc magazine if available
	* return 0 if the tool is available and currently in the cnc spindle
	* return -1  if the tool exist but its not loaded in the cnc magazine
	* return -2  if the tool is not available at all
	*/
	static TForteInt32 isAvailable(const std::string &pa_sToolID);
	/*!\ Retreive the local identifier of a tool in the map
	* return -1 If ID can not be retreived
	* return Tool ID otherwise
	*/
	static long getToolLocalID(const std::string &pa_sToolID);
	/*!\ Retreive a Tool from the map
	* return null if the tool can not be retreived
	* return requested tool object otherwise
	*/
	static const Tool * getTool(const std::string &pa_sToolID);
};

#endif