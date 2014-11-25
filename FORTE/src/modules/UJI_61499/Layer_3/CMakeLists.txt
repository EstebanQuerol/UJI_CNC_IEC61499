#############################################################################
# UJI_61499 FB/ Layer 3
#############################################################################
forte_add_sourcefile_hcpp( L3_APart L3_PartRouterF L3_PartRouterT L3_PartDesEncap)
forte_add_sourcefile_hcpp( L3_PartMerge L3_OrderTable ManORder L3_OrderInput)
forte_add_sourcefile_hcpp( L3_SendPart L3_ReceivePart L3_OrderManager)
forte_add_sourcefile_hcpp( L3_AAssignMachine L3_FaultyMHDLR L3_MachineManager L3_MMCore L3_ReleasedMHDLR)
forte_add_sourcefile_hcpp( Operation Setup ProcessPlan PPArray L3_SetupTable)
forte_add_sourcefile_hcpp( L3_CompletedPartHDLR L3_CompletedSetupHDLR L3_MachineAllocator L3_MachineChecker)
forte_add_sourcefile_hcpp( L3_NewPartHDLR L3_PPTable ManPart L3_ProcessPlan L3_ASetup)
forte_add_sourcefile_hcpp ( L3_SetupRouterF L3_SetupRouterT L3_SetupRouterM L3_L2CommPlug)

