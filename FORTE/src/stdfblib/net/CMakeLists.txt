#############################################################################
# Net FB
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\net)
forte_add_sourcefile_hcpp(GEN_CLIENT GEN_PUBLISH  GEN_SERVER  GEN_SUBSCRIBE)

if (FORTE_COM_LOCAL) 
  forte_add_sourcefile_hcpp(GEN_PUBL GEN_SUBL) 
endif(FORTE_COM_LOCAL)
