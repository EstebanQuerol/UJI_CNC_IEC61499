
#SET(SOURCE_GROUP ${SOURCE_GROUP}\\core)

  forte_test_add_inc_directories(${CMAKE_CURRENT_SOURCE_DIR})
  forte_test_add_link_directories(${CMAKE_BINARY_DIR}/src/core)
  
    forte_test_add_sourcefile_cpp(../../src/core/typelib.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/stringdict.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/funcbloc.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/eventconn.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/conn.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/ecet.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/resource.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/class1objhand.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/dataconn.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/adapterconn.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/if2indco.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/adapter.cpp)
        
    forte_test_add_sourcefile_cpp(../../src/core/devexec.cpp)
    forte_test_add_sourcefile_cpp(../../src/core/extevhan.cpp)
    
    forte_test_add_sourcefile_cpp(../../src/core/utils/string_utils.cpp)
    
    forte_test_add_sourcefile_cpp(../../src/stdfblib/ita/EMB_RES.cpp)
    
  #TODO add here architecture specific adds in order to allow testrunns also on other platforms
     forte_test_add_sourcefile_cpp(../../src/arch/timerha.cpp)
     
if(FORTE_ARCHITECTURE_POSIX)
    forte_test_add_sourcefile_cpp(../../src/arch/posix/sync.cpp)
    forte_test_add_sourcefile_cpp(../../src/arch/posix/thread.cpp)
     forte_test_add_sourcefile_cpp(../../src/arch/posix/pctimeha.cpp)
endif(FORTE_ARCHITECTURE_POSIX)

if(FORTE_ARCHITECTURE_WIN32)
    forte_test_add_sourcefile_cpp(../../src/arch/win32/sync.cpp)
    forte_test_add_sourcefile_cpp(../../src/arch/win32/thread.cpp)
    forte_test_add_sourcefile_cpp(../../src/arch/win32/pctimeha.cpp)
endif(FORTE_ARCHITECTURE_WIN32)

  
  #forte_add_sourcefile_hcpp(thread pctimeha sync)
  #forte_add_sourcefile_cpp(main.cpp)
  #forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

forte_test_add_sourcefile_cpp(../../src/core/stringdict.cpp)
forte_test_add_sourcefile_cpp(stringdicttests.cpp)
forte_test_add_sourcefile_cpp(typelibdatatypetests.cpp)

forte_test_add_subdirectory(datatypes)
forte_test_add_subdirectory(cominfra)
forte_test_add_subdirectory(fbtests)
forte_test_add_subdirectory(utils)
