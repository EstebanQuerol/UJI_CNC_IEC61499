forte_add_module(BachmannM1 "Function Blocks for Bachmann electronic M1")



if(NOT FORTE_ARCHITECTURE_BE_M1)

if(FORTE_MODULE_BachmannM1)
 MESSAGE("Module BachmannM1 was enabled although compiling for not BE M1 architecture. Disabled Module!")
 set(FORTE_MODULE_BachmannM1 OFF) 
endif(FORTE_MODULE_BachmannM1)

endif(NOT FORTE_ARCHITECTURE_BE_M1)


if(FORTE_MODULE_BachmannM1)
#############################################################################
# Bachmann M1
#############################################################################
forte_add_sourcefile_hcpp(GET_CHAN_INFO)
forte_add_sourcefile_hcpp(GET_VALUE)
forte_add_sourcefile_hcpp(SET_VALUE)
forte_add_sourcefile_hcpp(BE_SVIFB SVIsend_1 SVIreceive_1 BE_RMT_DEV)


endif(FORTE_MODULE_BachmannM1)