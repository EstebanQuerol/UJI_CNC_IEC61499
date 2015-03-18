forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}) 
#############################################################################
# UJI_61499 FB/ Layer 1
#############################################################################
forte_add_sourcefile_hcpp(L1_MCEmitter L1_GENFeature L1_SendCmd)
forte_add_sourcefile_hcpp(L1_Merge2Cmd L1_L1CFB)