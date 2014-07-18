#############################################################################
# Conversion when bit-string variable contains data encoded in BCD
# x_BCD_TO_xx 
# xx_TO_BCD_x
#############################################################################
forte_add_sourcefile_hcpp(F_BYTE_BCD_TO_USINT)
forte_add_sourcefile_hcpp(F_WORD_BCD_TO_UINT)
forte_add_sourcefile_hcpp(F_DWORD_BCD_TO_UDINT)

forte_add_sourcefile_hcpp(F_USINT_TO_BCD_BYTE)
forte_add_sourcefile_hcpp(F_UINT_TO_BCD_WORD)
forte_add_sourcefile_hcpp(F_UDINT_TO_BCD_DWORD)

if(FORTE_USE_64BIT_DATATYPES) 
	forte_add_sourcefile_hcpp(F_LWORD_BCD_TO_ULINT)
	forte_add_sourcefile_hcpp(F_ULINT_TO_BCD_LWORD)
endif(FORTE_USE_64BIT_DATATYPES)