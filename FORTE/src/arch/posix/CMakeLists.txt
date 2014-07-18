
SET(SOURCE_GROUP ${SOURCE_GROUP}\\posix)

set(FORTE_ARCHITECTURE_POSIX OFF CACHE BOOL "Use Posix architecture")

if(FORTE_ARCHITECTURE_POSIX)
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  
  forte_add_sourcefile_hcpp(thread pctimeha sync)
  forte_add_sourcefile_cpp(main.cpp)

  if(FORTE_COM_ETH)
   forte_add_sourcefile_hcpp( ../fdselecthand ../bsdsocketinterf)
   forte_add_sourcefile_h(sockhand.h)
  endif(FORTE_COM_ETH)

  forte_add_include_directories(../${CMAKE_CURRENT_SOURCE_DIR})
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  #forte_add_link_library(pthread)

  forte_add_definition("-W -Wall -Wextra -Woverloaded-virtual -Wconversion -DFORTE_LITTLE_ENDIAN -O0 -g")
  
  set(FORTE_RTTI_AND_EXCEPTIONS FALSE CACHE BOOL "Enable RTTI and Exceptions")
  mark_as_advanced(FORTE_RTTI_AND_EXCEPTIONS)
  IF(NOT FORTE_RTTI_AND_EXCEPTIONS)
    forte_add_definition("-fno-rtti -fno-exceptions")
  ENDIF(NOT FORTE_RTTI_AND_EXCEPTIONS)
  
  
  set(FORTE_POSIX_GENERATE_MAP_FILE FALSE CACHE BOOL "Enable the generation of map files")
  mark_as_advanced(FORTE_POSIX_GENERATE_MAP_FILE)
  IF(FORTE_POSIX_GENERATE_MAP_FILE)
  	forte_add_link_flags("-Wl,-M -Wl,-Map -Wl,forte.map -Wl,-cref")
  ENDIF(FORTE_POSIX_GENERATE_MAP_FILE)	
  
  forte_add_link_library("-lpthread") 


  forte_add_network_layer(SER OFF "ser" CSerCommLayer sercommlayer "Enable Forte serial line communication")
  forte_add_network_layer(MUXSER OFF "muxser" CMuxedSerCommLayer muxedsercommlayer "Enable Forte multiplexed serial line communication")
  	
endif(FORTE_ARCHITECTURE_POSIX)