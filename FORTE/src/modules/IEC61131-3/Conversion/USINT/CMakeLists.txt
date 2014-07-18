#############################################################################
# USINT_TO_xxx Conversion
#############################################################################
forte_add_sourcefile_hcpp(F_USINT_TO_BOOL)
forte_add_sourcefile_hcpp(F_USINT_TO_BYTE)
forte_add_sourcefile_hcpp(F_USINT_TO_DINT)
forte_add_sourcefile_hcpp(F_USINT_TO_DWORD)
forte_add_sourcefile_hcpp(F_USINT_TO_INT)
forte_add_sourcefile_hcpp(F_USINT_TO_SINT)
forte_add_sourcefile_hcpp(F_USINT_TO_UDINT)
forte_add_sourcefile_hcpp(F_USINT_TO_UINT)
forte_add_sourcefile_hcpp(F_USINT_TO_WORD)
forte_add_sourcefile_hcpp(F_USINT_TO_STRING)
forte_add_sourcefile_hcpp(F_USINT_TO_TIME)

if(FORTE_USE_64BIT_DATATYPES)         
  forte_add_sourcefile_hcpp(F_USINT_TO_ULINT)
  forte_add_sourcefile_hcpp(F_USINT_TO_LINT)
  forte_add_sourcefile_hcpp(F_USINT_TO_LWORD)
endif(FORTE_USE_64BIT_DATATYPES)

if(FORTE_USE_REAL_DATATYPE)
  forte_add_sourcefile_hcpp(F_USINT_TO_REAL)
endif(FORTE_USE_REAL_DATATYPE)

if(FORTE_USE_LREAL_DATATYPE)
  forte_add_sourcefile_hcpp(F_USINT_TO_LREAL)
endif(FORTE_USE_LREAL_DATATYPE)

if(FORTE_USE_WSTRING_DATATYPE)
  forte_add_sourcefile_hcpp(F_USINT_TO_WSTRING)
endif(FORTE_USE_WSTRING_DATATYPE)  