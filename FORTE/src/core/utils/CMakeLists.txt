#############################################################################
# core/util
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

forte_add_sourcefile_h(anyhelper.h staticassert.h singlet.h)    

forte_add_sourcefile_hcpp(string_utils)
