forte_add_module(CNC8070 "CNC8070 Function Blocks")
#This module uses CNC8070API libraries and includes
SET(CNC8070_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../CNCResources/CNC8070API/" CACHE PATH "Path to CNC8070 root directory.")
forte_add_include_directories("${CNC8070_ROOT_DIR}/include")

SET(CNC8070_SIMULATED_8070  CACHE BOOL "Using simulated 8070 CNC")
if(CNC8070_SIMULATED_8070)
forte_add_definition("-DSIMULATED_8070")
endif(CNC8070_SIMULATED_8070)

forte_add_link_directories(${CNC8070_ROOT_DIR}/Debug)
forte_add_link_library(CNC8070API.lib)

forte_add_subdirectory(Layer_0)
forte_add_subdirectory(Layer_1)
#############################################################################
# *UJI_61499 FB/ Common FBs
#############################################################################