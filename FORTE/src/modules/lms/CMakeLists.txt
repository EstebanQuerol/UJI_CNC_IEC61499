
set(FORTE_ARCHITECTURE_LMS OFF CACHE BOOL "Lego-Mindstorms architecture and Service Interface Function Blocks")

if(FORTE_ARCHITECTURE_LMS)
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
forte_add_include_directories(${CMAKE_SOURCE_DIR}/src/arch/ecos/)


forte_add_network_layer(LMS_USB ON "usb" CLMSUSBLayer LMSUSBLayer "Enable Forte Com LMS usb")

forte_add_sourcefile_hcpp(../../arch/ecos/thread ../../arch/ecos/ecostiha ../../arch/ecos/sync)
forte_add_sourcefile_h(../../arch/ecos/fortealloc.h)

forte_add_sourcefile_cpp(lmsmain.cpp)

forte_add_definition("-Wpointer-arith -Wundef -Woverloaded-virtual -Wno-write-strings")
forte_add_definition("-W -Wall -Wextra -D_KERNEL -D__ECOS -DFORTE_LITTLE_ENDIAN")
forte_add_definition("-mcpu=arm7tdmi -msoft-float -mno-thumb-interwork -g -O0")
forte_add_definition("-ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-rtti -fno-exceptions")
forte_add_definition("-DFORTE_EXTERNAL_LOG_HANDLER")


forte_add_link_flags("-mcpu=arm7tdmi -msoft-float -W,--gc-sections -g -nostartfiles -nostdlib -fno-threadsafe-statics -mno-thumb-interwork -Wl,-static -Wl,-M -Wl,-Map -Wl,forte.map -Wl,-cref")

#Add commands for creating target image
forte_add_post_build_command(COMMAND arm-eabi-objcopy ARGS --gap-fill 0xFF -O binary forte.elf forte.bin
                             COMMAND echo ARGS "Size of forte.elf:"
                             COMMAND arm-eabi-size ARGS forte.elf
                             WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src
                             COMMENT "Create target image (forte.bin)...")
  
############################################################################
### Remove sourcefiles not necessary for LMS to save flash space    ########
############################################################################

## TODO develop means to do this here currently you have to add them to exclude list
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "RMT_DEV") 
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "RMT_RES") 
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "DM_KRNL") 
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_CLIENT")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_PUBL")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_SUBL")

SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_D_FF")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_MERGE")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_REND")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_SPLIT")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_DEMUX")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_RS")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_D_FF")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_E_DEMUX")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_E_MUX")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_CTU")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_SELECT")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_F_TRIG")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_R_TRIG")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_PERMIT")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_DELAY")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_CYCLE")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "E_SWITCH")

SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_SUBSCRIBE")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "GEN_PUBLISH")

SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "forte_dword")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "forte_byte")
SET_PROPERTY(GLOBAL APPEND PROPERTY FORTE_PLATFORM_REMOVES "forte_struct")
  
#############################################################################
# LMS Device and FB
#############################################################################
forte_add_sourcefile_hcpp(../../stdfblib/ita/EMB_RMT_DEV  ../../stdfblib/ita/EMB_RMT_RES ../../stdfblib/ita/SERVER_1_2)

forte_add_sourcefile_hcpp(avrctl L_LED L_AD L_M_PWR L_BUTTON  L_OFF)
forte_add_sourcefile_hcpp(LC_LED LC_LT LC_TOUCH LC_AD)
forte_add_sourcefile_hcpp(LC_SOUND)
forte_add_sourcefile_hcpp(L_BATTERY)
forte_add_sourcefile_hcpp(L_S_PORT)
forte_add_sourcefile_h(../IEC61131-3/Comparison/F_GT.h)
forte_add_sourcefile_cpp(../IEC61131-3/Comparison/F_GT.cpp)

endif(FORTE_ARCHITECTURE_LMS)
