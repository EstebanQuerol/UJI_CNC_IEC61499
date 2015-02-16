forte_add_module(Internal_Classes "C++ classes used in FORTE")

forte_add_subdirectory(STEP_NC_Lib)
#############################################################################
# Internal_Classes
#############################################################################
forte_add_sourcefile_hcpp( Operation Subphase ProcessPlan ManOrder )
forte_add_sourcefile_hcpp( PP_DDBB PP_Family ManPart Tool_Table Tool GlobalUtils)


