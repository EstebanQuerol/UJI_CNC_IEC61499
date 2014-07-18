#############################################################################
# Tests for the standard Event FBs
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\events)


if(FORTE_FUNCTIONBLOCK_TESTS)

forte_add_sourcefile_hcpp(F_EQ_TIME_tester F_GT_TIME_tester)

endif(FORTE_FUNCTIONBLOCK_TESTS)
