#############################################################################
# Conversion
#############################################################################
forte_add_subdirectory(BOOL)
forte_add_subdirectory(BYTE)
forte_add_subdirectory(DINT)
forte_add_subdirectory(DWORD)
forte_add_subdirectory(INT)
forte_add_subdirectory(SINT)
forte_add_subdirectory(STRING)
forte_add_subdirectory(TIME)
forte_add_subdirectory(UDINT)
forte_add_subdirectory(UINT)
forte_add_subdirectory(USINT)
forte_add_subdirectory(WORD)
forte_add_subdirectory(BCD)

if(FORTE_USE_WSTRING_DATATYPE)
  forte_add_subdirectory(WSTRING)
endif(FORTE_USE_WSTRING_DATATYPE)

if(FORTE_USE_REAL_DATATYPE)
  forte_add_subdirectory(REAL)
endif(FORTE_USE_REAL_DATATYPE)

if(FORTE_USE_LREAL_DATATYPE)
  forte_add_subdirectory(LREAL)
endif(FORTE_USE_LREAL_DATATYPE)

if(FORTE_USE_64BIT_DATATYPES) 
  forte_add_subdirectory(ULINT)
  forte_add_subdirectory(LWORD)
  forte_add_subdirectory(LINT)
  forte_add_subdirectory(DT)
endif(FORTE_USE_64BIT_DATATYPES)