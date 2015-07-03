forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}) 
forte_add_subdirectory(STEP_NC_Lib)
forte_add_subdirectory(Eigen)
#############################################################################
# C++ classes used in FORTE 
#############################################################################
forte_add_sourcefile_hcpp( Operation Subphase ProcessPlan ManOrder )
forte_add_sourcefile_hcpp( PP_DDBB PP_Family ManPart Tool_Table Tool GlobalUtils)