forte_add_module(UTILS "FORTE UTILITY FBs")

#############################################################################
# FORTE UTILITY FBs
#############################################################################
forte_add_sourcefile_hcpp( OUT_ANY_CONSOLE GEN_F_MUX GEN_CSV_WRITER GEN_APPEND_STRING)
forte_add_sourcefile_hcpp(STEST_END)

forte_add_subdirectory(tests)
