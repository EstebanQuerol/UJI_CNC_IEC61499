
SET(SOURCE_GROUP ${SOURCE_GROUP}\\phycoreat91)

set(FORTE_ARCHITECTURE_PHYCOREAT91 OFF CACHE BOOL "Use phycoreAT91 architecture")

if(FORTE_ARCHITECTURE_PHYCOREAT91)
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
  
  forte_add_sourcefile_hcpp(../thread ../ecostiha ../sync)
  forte_add_sourcefile_cpp(phycoreAT91main.cpp)

  if(FORTE_COM_ETH)
   forte_add_sourcefile_hcpp( ../../fdselecthand ../../bsdsocketinterf)
   forte_add_sourcefile_h(../sockhand.h)
  endif(FORTE_COM_ETH)

  forte_add_include_directories(../${CMAKE_CURRENT_SOURCE_DIR})
  
  forte_add_definition("-Wpointer-arith -Wundef -Woverloaded-virtual -Wno-write-strings")
  forte_add_definition("-W -Wall -Wextra -D_KERNEL -D__ECOS -DFORTE_LITTLE_ENDIAN")
  forte_add_definition("-mcpu=arm7tdmi -msoft-float -mno-thumb-interwork -g -O2")
  forte_add_definition("-ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-rtti -fno-exceptions")


  forte_add_link_flags("-mcpu=arm7tdmi -msoft-float -W,--gc-sections -g -nostartfiles -nostdlib -fno-threadsafe-statics -mno-thumb-interwork -Wl,-static -Wl,-M -Wl,-Map -Wl,forte.map -Wl,-cref")
  
  

endif(FORTE_ARCHITECTURE_PHYCOREAT91)