#############################################################################
# WORD_TO_xxx Conversion
#############################################################################
forte_add_sourcefile_hcpp(F_WORD_TO_BOOL)
forte_add_sourcefile_hcpp(F_WORD_TO_BYTE)
forte_add_sourcefile_hcpp(F_WORD_TO_DINT)
forte_add_sourcefile_hcpp(F_WORD_TO_DWORD)
forte_add_sourcefile_hcpp(F_WORD_TO_INT)
forte_add_sourcefile_hcpp(F_WORD_TO_SINT)
forte_add_sourcefile_hcpp(F_WORD_TO_UDINT)
forte_add_sourcefile_hcpp(F_WORD_TO_UINT)
forte_add_sourcefile_hcpp(F_WORD_TO_USINT)
forte_add_sourcefile_hcpp(F_WORD_TO_STRING)
forte_add_sourcefile_hcpp(F_WORD_TO_TIME)

if(FORTE_USE_64BIT_DATATYPES)       
  forte_add_sourcefile_hcpp(F_WORD_TO_LINT)
  forte_add_sourcefile_hcpp(F_WORD_TO_LWORD)
  forte_add_sourcefile_hcpp(F_WORD_TO_ULINT)
endif(FORTE_USE_64BIT_DATATYPES)

if(FORTE_USE_REAL_DATATYPE)
  forte_add_sourcefile_hcpp(F_WORD_TO_REAL)
endif(FORTE_USE_REAL_DATATYPE)

if(FORTE_USE_LREAL_DATATYPE)  
  forte_add_sourcefile_hcpp(F_WORD_TO_LREAL)
endif(FORTE_USE_LREAL_DATATYPE)

if(FORTE_USE_WSTRING_DATATYPE) 
  forte_add_sourcefile_hcpp(F_WORD_TO_WSTRING)
endif(FORTE_USE_WSTRING_DATATYPE) 