#############################################################################
# Ita FB
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\ita)
forte_add_sourcefile_hcpp(DEV_MGR  DM_KRNL  EMB_RES  RMT_DEV  RMT_RES)
