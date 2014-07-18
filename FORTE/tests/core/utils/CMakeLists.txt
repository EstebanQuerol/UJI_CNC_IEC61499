

forte_test_add_inc_directories(${CMAKE_CURRENT_SOURCE_DIR})
forte_test_add_link_directories(${CMAKE_BINARY_DIR}/src/core/utils)

forte_test_add_sourcefile_cpp(string_utils_test.cpp)


forte_test_add_sourcefile_cpp(testsingleton.cpp singeltontest.cpp singletontest2ndunit.cpp)