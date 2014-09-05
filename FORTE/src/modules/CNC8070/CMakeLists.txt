forte_add_module(CNC8070 "CNC8070 Function Blocks")

#############################################################################
# CNC8070 FB
#############################################################################
forte_add_sourcefile_hcpp( T1_Adapter T1_Counter T1_InsArray T1_SIFB T2_Counter T2_SIFB test1 )
forte_add_sourcefile_hcpp( L0_SendBlk L0_State L0_StateHandler L0_8070Service )
forte_add_sourcefile_hcpp( L0_CNCEncap L0_CompletedEx L0_ReqManager)



