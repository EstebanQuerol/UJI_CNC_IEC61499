#############################################################################
# OPC Com Layer
#############################################################################

forte_add_network_layer(OPC OFF "opc" COpcComLayer opccomlayer "Enable OPC communication")
SET(FORTE_COM_OPC_LIB_ROOT "" CACHE PATH "Path to OPC library root directory")
SET(FORTE_COM_OPC_BOOST_ROOT "" CACHE PATH "Path to Boost library root directory")

if(FORTE_COM_OPC)	
	if(FORTE_ARCHITECTURE_WIN32)
		forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
		forte_add_sourcefile_hcpp( opcconnection opcconnectionhandler opceventhandler 
								   opcconnectionimpl opcprocessvar Cmd_AddConnection 
								   Cmd_AddOPCProcessVar Cmd_SetProcessVarValue )
	
		forte_add_include_directories( ${FORTE_COM_OPC_BOOST_ROOT} )
		
		forte_add_include_directories( ${FORTE_COM_OPC_LIB_ROOT}/include )
		forte_add_link_directories( ${FORTE_COM_OPC_LIB_ROOT}/lib )
		forte_add_link_library( OPCClientToolKit.lib )
	else(FORTE_ARCHITECTURE_WIN32)
		# Generate error since OPC only works with Windows
		MESSAGE(SEND_ERROR "FORTE_ARCHITECTURE_WIN32 must be checked to OPC Com Layer")
	endif(FORTE_ARCHITECTURE_WIN32)	
endif(FORTE_COM_OPC)
