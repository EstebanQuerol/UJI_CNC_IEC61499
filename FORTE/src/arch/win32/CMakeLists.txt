
SET(SOURCE_GROUP ${SOURCE_GROUP}\\win32)

set(FORTE_ARCHITECTURE_WIN32 OFF CACHE BOOL "Use WIN32 architecture")

if(FORTE_ARCHITECTURE_WIN32)
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})  
  
  forte_add_sourcefile_h(fortealloc.h)
  forte_add_sourcefile_hcpp(thread sync)
  forte_add_sourcefile_cpp(main.cpp)

  if(${FORTE_BUILD_TYPE} STREQUAL SHARED_LIBRARY)
    set(FORTE_EXTERNAL_TIMEHA ON CACHE BOOL "Use External Time Handler")
	if(FORTE_EXTERNAL_TIMEHA)
      forte_add_sourcefile_hcpp(externtimeha)
	else(FORTE_EXTERNAL_TIMEHA)
	  forte_add_sourcefile_hcpp(pctimeha)
	endif(FORTE_EXTERNAL_TIMEHA)
  else(${FORTE_BUILD_TYPE} STREQUAL SHARED_LIBRARY)
    unset(FORTE_EXTERNAL_TIMEHA CACHE)
    forte_add_sourcefile_hcpp(pctimeha)
  endif(${FORTE_BUILD_TYPE} STREQUAL SHARED_LIBRARY)


  if(FORTE_COM_ETH)
   forte_add_sourcefile_hcpp( ../fdselecthand ../bsdsocketinterf)
   forte_add_sourcefile_h(sockhand.h)
  endif(FORTE_COM_ETH)

  forte_add_include_directories(../${CMAKE_CURRENT_SOURCE_DIR})
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  
  SET(CMAKE_CXX_FLAGS_RELEASE "/MT" ) 
  forte_add_definition("-DFORTE_LITTLE_ENDIAN") # -DNONAMESPACE -DWITH_NONAMESPACES)  

# TODO this flag was originaly wrongly added to the definitions. May be necessary to be added as link flag. However currently working fine.
# forte_add_link_flags("/NODEFAULTLIB:MSVCRT.lib")

  forte_add_link_library(comctl32.lib)
  forte_add_link_library(rpcrt4.lib)
  forte_add_link_library(winmm.lib)
  forte_add_link_library(Ws2_32.lib)
  forte_add_link_library(version.lib)
  
 
endif(FORTE_ARCHITECTURE_WIN32)
