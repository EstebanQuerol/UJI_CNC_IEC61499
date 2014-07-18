SET(SOURCE_GROUP ${SOURCE_GROUP}\\fbtests)

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})


forte_test_add_sourcefile_cpp(fbtester.cpp)
forte_test_add_sourcefile_cpp(fbtestdoconn.cpp fbtestdiconn.cpp)
forte_test_add_sourcefile_cpp(fbtestsmanager.cpp)
