
SET(SOURCE_GROUP ${SOURCE_GROUP}\\be_m1)

set(FORTE_ARCHITECTURE_BE_M1 OFF CACHE BOOL "Use Bachmann electronic M1 architecture")

if(FORTE_ARCHITECTURE_BE_M1)
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  
  forte_add_sourcefile_hcpp(thread vxworkstimeha sync)
  forte_add_sourcefile_hcpp(fortemodule)
  
  forte_add_sourcefile_h(stdint.h)

  if(FORTE_COM_ETH)
   forte_add_sourcefile_hcpp( ../fdselecthand ../bsdsocketinterf)
   #forte_add_sourcefile_h(vxworkssochan.h)
  endif(FORTE_COM_ETH)

  forte_add_include_directories(../${CMAKE_CURRENT_SOURCE_DIR})
  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

  forte_add_definition("-W -Wall -Wextra -Woverloaded-virtual -Wconversion -DFORTE_LITTLE_ENDIAN  -DVXWORKS -O0 -ggdb")
  forte_add_definition("-fno-rtti")
  
  forte_add_link_flags("-Wl,-M -Wl,-Map -Wl,forte.map -Wl,-cref")
  
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/forte.ver.in ${CMAKE_BINARY_DIR}/forte.new.ver)
  forte_replacefile_if_changed(${CMAKE_BINARY_DIR}/forte.new.ver ${CMAKE_BINARY_DIR}/forte.ver)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/CPPLIB.ver.in ${CMAKE_BINARY_DIR}/CPPLIB.new.ver)
  forte_replacefile_if_changed(${CMAKE_BINARY_DIR}/CPPLIB.new.ver ${CMAKE_BINARY_DIR}/CPPLIB.ver)
  
  
  set(GNU_TOOLS C:/bachmann/SolutionCenter/V1.70Release/cutils/GnuTools)
  set(MSYS_PATH C:/bachmann/SolutionCenter/V1.70Release/cutils/mcsdk/msys)
  set(GNU_TOOLS_PATH ${GNU_TOOLS}/../GnuTools-4.1.2)
  set(MSYS_UTILS_PATH ${MSYS_PATH}/utl)

# Base directory of the compiler installation
  set(GCC_BASE ${GNU_TOOLS_PATH})
  set(CPU_FAMILY I80X86)

# Some settings need to be overwritten
  set(GCC_BIN_DIR ${GCC_BASE}/bin)
  set(BINUTILS_BIN_DIR ${GCC_BASE}/bin)
  set(GCC_EXEC_PREFIX ${GCC_BASE}/lib/gcc/i386-wrs-vxworks/4.1.2/)
  set(COMPILER_LIB_PATHS -L "${GCC_EXEC_PREFIX}" -L "${GCC_BASE}/i386-wrs-vxworks/lib")
  set(BASE_LIB_PATH -L "${GNU_TOOLS_PATH}/lib")
  set(M1_LD_PATH ${BASE_LIB_PATH} ${COMPILER_LIB_PATHS})

# Names of compiler frontends and linkers have changed
  set(M1_CC "${GCC_BIN_DIR}/i386-wrs-vxworks-gcc")
  set(M1_CPP "${GCC_BIN_DIR}/i386-wrs-vxworks-g++")
  set(M1_LD "${BINUTILS_BIN_DIR}/i386-wrs-vxworks-ld")
  set(M1_AR "${BINUTILS_BIN_DIR}/i386-wrs-vxworks-ar")
  set(M1_NM "${BINUTILS_BIN_DIR}/i386-wrs-vxworks-nm")
  set(M1_MUNCH "${MSYS_UTILS_PATH}/munch-new")
  set(M1_MBIND "${MSYS_UTILS_PATH}/mbind")
  set(M1_CONFC "${MSYS_UTILS_PATH}/confc")
  set(M1_SYMCONV "${MSYS_UTILS_PATH}/symconv")
  
  forte_add_post_build_command(COMMAND ${M1_CONFC}  ${CMAKE_CURRENT_SOURCE_DIR}/forte.cru forte.bcr  
                               COMMAND ${M1_LD} ${M1_LD_PATH} -r -d -o forte_all.o --whole-archive libforte.a ${CMAKE_CURRENT_SOURCE_DIR}/forte.lk
                               COMMAND ${M1_SYMCONV} forte_all.o -i
                               COMMAND ${M1_NM} forte_all.o > symbols.txt
                               COMMAND ${M1_MUNCH} -c symbols.txt > ctdt.c
                               COMMAND ${M1_CC} -Wall -Wno-pointer-sign -march=pentium -nostdinc -fno-common -O0 -fno-builtin -fno-defer-pop -DCPU_FAMILY=I80X86 -DFORTE_LITTLE_ENDIAN -D_POSIX_THREAD_ATTR_STACKSIZE -DFORTE_USE_WSTRING_DATATYPE -g  -c -o ctdt.o ctdt.c
                               COMMAND ${M1_LD} ${M1_LD_PATH} -S -r -d -o forte.o forte_all.o ctdt.o                              
                               COMMAND ${M1_MBIND} forte -c ${CMAKE_CURRENT_SOURCE_DIR}/forte.mbs)  

#TODO add dbo generation for debugging:  
# Create a *.dbo file for debugging
#%.dbo: $(OBJECTS) $(LINKER_SCRIPT)
#  $(LD) $(LDFLAGS) -r -d -o "$@" "$(COMPOUND_OBJECT)" $(AUXILIARY_OBJECTS)

endif(FORTE_ARCHITECTURE_BE_M1)
