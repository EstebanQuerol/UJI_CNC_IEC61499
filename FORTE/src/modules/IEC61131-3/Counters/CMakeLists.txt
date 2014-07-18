#############################################################################
# Counters
#############################################################################
forte_add_sourcefile_hcpp(FB_CTD_DINT)
forte_add_sourcefile_hcpp(FB_CTD_UDINT)
forte_add_sourcefile_hcpp(FB_CTD)
forte_add_sourcefile_hcpp(FB_CTUD_DINT)
forte_add_sourcefile_hcpp(FB_CTU_UDINT)
forte_add_sourcefile_hcpp(FB_CTU)
forte_add_sourcefile_hcpp(FB_CTU_DINT)
forte_add_sourcefile_hcpp(FB_CTUD)

if(FORTE_USE_64BIT_DATATYPES)
	forte_add_sourcefile_hcpp(FB_CTD_LINT)
	forte_add_sourcefile_hcpp(FB_CTD_ULINT)
	forte_add_sourcefile_hcpp(FB_CTU_LINT)
	forte_add_sourcefile_hcpp(FB_CTU_ULINT)
	forte_add_sourcefile_hcpp(FB_CTUD_LINT)
	forte_add_sourcefile_hcpp(FB_CTUD_ULINT)
endif(FORTE_USE_64BIT_DATATYPES)