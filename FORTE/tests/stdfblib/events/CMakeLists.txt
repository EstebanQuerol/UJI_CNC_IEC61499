#############################################################################
# Tests for the standard Event FBs
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\events)

forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_DELAY.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_F_TRIG.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_PERMIT.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_R_TRIG.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_SR.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_SWITCH.cpp)
forte_test_add_sourcefile_cpp(../../../src/stdfblib/events/E_SELECT.cpp)

forte_test_add_sourcefile_cpp(E_DELAY_tester.cpp)
forte_test_add_sourcefile_cpp(E_F_TRIG_tester.cpp)
forte_test_add_sourcefile_cpp(E_PERMIT_tester.cpp)
forte_test_add_sourcefile_cpp(E_R_TRIG_tester.cpp)
forte_test_add_sourcefile_cpp(E_SR_tester.cpp)
forte_test_add_sourcefile_cpp(E_SELECT_tester.cpp)
forte_test_add_sourcefile_cpp(E_SWITCH_tester.cpp)
