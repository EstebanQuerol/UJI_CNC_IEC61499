#############################################################################
# Modbus Com Layer
#############################################################################
forte_add_network_layer(MODBUS OFF "modbus" CModbusComLayer modbuslayer "Enable Modbus Com Layer")
SET(FORTE_COM_MODBUS_LIB_DIR "" CACHE PATH "Path to Modbus library directory (leave empty for installed source code)")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(FORTE_COM_MODBUS)
	forte_add_sourcefile_hcpp( modbushandler 
							   modbusconnection 
							   modbusclientconnection
							   modbuspoll
							   modbustimedevent )
	if(FORTE_ARCHITECTURE_POSIX)
	    if(EXISTS ${FORTE_COM_MODBUS_LIB_DIR})
    		forte_add_include_directories( ${FORTE_COM_MODBUS_LIB_DIR}/include/modbus )
    		forte_add_link_directories( ${FORTE_COM_MODBUS_LIB_DIR}/lib )
	    else(EXISTS ${FORTE_COM_MODBUS_LIB_DIR})
	        forte_add_include_directories( /usr/include/modbus )
    	endif(EXISTS ${FORTE_COM_MODBUS_LIB_DIR})
    	forte_add_link_library( libmodbus.so )
	elseif(FORTE_ARCHITECTURE_WIN32)
		forte_add_include_directories( ${FORTE_COM_MODBUS_LIB_DIR}/include )
		forte_add_link_directories( ${FORTE_COM_MODBUS_LIB_DIR}/lib )
		forte_add_link_library( libmodbus.lib ) 
	endif(FORTE_ARCHITECTURE_POSIX)
endif(FORTE_COM_MODBUS)
