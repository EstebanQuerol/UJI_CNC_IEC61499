#include "Tool_Table.h"

//Initialize static members
std::unordered_map<std::string, Tool> Tool_Table::sm_umapToolTable;
bool Tool_Table::sm_bInitialized = false; //Initialization flag

Tool_Table::Tool_Table()
{
}


Tool_Table::~Tool_Table()
{
}

void  Tool_Table::initilizate(){
	if (!sm_bInitialized){
		sm_bInitialized = true;
		//TODO: Add code to initialize the tool table
	}
}

void Tool_Table::addTool(Tool pa_oTool){

	try{
		sm_umapToolTable.emplace(pa_oTool.getToolID(), pa_oTool);
	}
	catch (std::bad_alloc e){
		DEVLOG_ERROR("Allocation failure, unable to insert a tool in the tool table \n");
	}
}

void Tool_Table::updateTool(Tool pa_oTool){

}

void Tool_Table::deleteTool(Tool pa_oTool){

}

void Tool_Table::deleteTool(std::string pa_sID){

}

void Tool_Table::deleteTable(){
	sm_umapToolTable.clear();
}