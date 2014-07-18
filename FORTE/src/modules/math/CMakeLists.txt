forte_add_module(MATH "Mathematical Function Blocks")

#############################################################################
# Math FB
#############################################################################
forte_add_sourcefile_hcpp(FB_ADD_DINT  FB_MUL_INT   FB_SUB_DINT)
forte_add_sourcefile_hcpp(FB_ADD_INT   FB_DIV_DINT  FB_SUB_INT)
forte_add_sourcefile_hcpp(FB_DIV_INT   FB_MUL_DINT)

if(FORTE_USE_LREAL_DATATYPE)
  forte_add_sourcefile_hcpp(FB_MUL_LREAL FB_DIV_LREAL FB_ADD_LREAL FB_SUB_LREAL)
endif(FORTE_USE_LREAL_DATATYPE)

if(FORTE_USE_REAL_DATATYPE)
  forte_add_sourcefile_hcpp(FB_MUL_REAL FB_DIV_REAL FB_ADD_REAL FB_SUB_REAL)
  forte_add_sourcefile_hcpp(FB_RANDOM)
endif(FORTE_USE_REAL_DATATYPE)

