#############################################################################
# Numerical
#############################################################################
forte_add_sourcefile_hcpp(F_ABS)

if(FORTE_USE_REAL_DATATYPE)
	forte_add_sourcefile_hcpp(F_SQRT)
	forte_add_sourcefile_hcpp(F_LN)
	forte_add_sourcefile_hcpp(F_LOG)
	forte_add_sourcefile_hcpp(F_SIN)
	forte_add_sourcefile_hcpp(F_COS)
	forte_add_sourcefile_hcpp(F_TAN)
	forte_add_sourcefile_hcpp(F_ASIN)
	forte_add_sourcefile_hcpp(F_ACOS)
	forte_add_sourcefile_hcpp(F_ATAN)
	forte_add_sourcefile_hcpp(F_EXP)
endif(FORTE_USE_REAL_DATATYPE)